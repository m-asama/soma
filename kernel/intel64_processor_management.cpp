/**
 * @file	intel64_processor_management.cpp
 * @brief	Intel64 CPU の初期化等を行う関数群実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "linked_list.h"
#include "sorted_list.h"
#include "intel64_assembly.h"
#include "memory_management.h"
#include "utf8str.h"
#include "print.h"
#include "util.h"
#include "processor_base.h"
#include "processor_state_base.h"
#include "intel64_processor_state.h"
#include "acpi_management.h"
#include "processor_management.h"
#include "thread.h"
#include "thread_management.h"
#include "io_thread_management.h"
#include "intel64_processor_interrupt_handler_init.h"
#include "spinlock.h"

#include "debug.h"

#include "console_management.h"

#include "intel64_processor.h"

static sorted_list<processor_base> *processors = nullptr;

static intel64_gdt_entry *gdt = nullptr;
static intel64_gdtr *gdtrp = nullptr;

static intel64_idt_entry *idt = nullptr;
static intel64_idtr *idtrp = nullptr;

static intel64_pd_table *global_pd_tables = nullptr;

uint64_t boot_processor_pml4_table_address = 0x0000000000000000ul;
uint64_t boot_processor_stack_pointer = 0x0000000000000000ul;

extern "C" uint64_t subsequent_processor_pml4_table_address;
uint64_t subsequent_processor_pml4_table_address;

extern "C" uint64_t subsequent_processor_stack_pointer;
uint64_t subsequent_processor_stack_pointer;

uint64_t subsequent_processor_status;

void *subsequent_processor_boot_code = nullptr;

extern "C" intel64_processor_state_storage *processor_state_storage[256];
intel64_processor_state_storage *processor_state_storage[256];

static spinlock *thread_lock = nullptr;

static linked_list<struct interrupt_handler> *interrupt_handlers[256];
static spinlock *interrupt_handlers_lock = nullptr;

static void assert_sizeof_entry_classes();

extern "C" void interrupt_handler_dispatcher();

void
interrupt_handler_dispatcher()
{
	uint64_t *gsi, *ssp;
//	uint64_t *error_code, *rip, *cs, *rflags, *rsp, *ss;
//	uint64_t *rax, *rbx, *rcx, *rdx, *rdi, *rsi, *rbp, *cr3;

	intel64_processor_state_storage *curps;
	curps = processor_state_storage[processor_id()];

	if (curps == nullptr) {
		printstr("interrupt_handler: curps == nullptr\n");
	}

	ssp = &curps->stacked_size;
	gsi = &curps->gsi;
/*
	{
		utf8str x;
		x += "IH GSI = 0x";
		x.append_hex64(*gsi, 2);
		x += "\n";
		printstr(x);
	}
*/
	interrupt_handlers_lock->acquire();
	bidir_node<struct interrupt_handler> *bnh;
	for (bnh = interrupt_handlers[*gsi]->head(); bnh != nullptr; bnh = bnh->next()) {
		struct interrupt_handler &ih = bnh->v();
		ih.ih(ih.gsi);
	}
	interrupt_handlers_lock->release();

	thread_lock->acquire();

	bidir_node<thread> *bnt;
	for (bnt = processor_current()->threads().head(); bnt != nullptr; bnt = bnt->next()) {
		if ((bnt->v().state() == thread_state::pending)
		 || ((bnt->v().state() == thread_state::running)
		      && (&bnt->v() == processor_current()->running_thread()))) {
			break;
		}
	}

	thread &oldt = *processor_current()->running_thread();
	thread &newt = (bnt != nullptr) ? bnt->v() : processor_current()->io_thread();
/*
	{
		utf8str x;
		x.append_hex64(processor_id(), 2);
		x += " ";
		x += oldt.name();
		x += " => ";
		x += newt.name();
		x += "\n";
		printstr(x);
	}
*/
	if (oldt.state() != thread_state::idle) {
/*
		utf8str str(oldt.name());
		str += ": ";
		thread_state_append(oldt.state(), str);
		str += " => pending\n";
		printstr(str);
*/
		oldt.state(thread_state::pending);
	}
	{
/*
		utf8str str(newt.name());
		str += ": ";
		thread_state_append(newt.state(), str);
		str += " => running\n";
		printstr(str);
*/
		newt.state(thread_state::running);
	}

	thread_lock->release();

	intel64_processor_state_storage *newps;
	newps = (intel64_processor_state_storage *)newt.processor_state()->processor_state_address();
	newps->gsi = curps->gsi;
	newps->stacked_size = curps->stacked_size;
/*
	newps->cr3 = curps->cr3;
	newps->ss = curps->ss;
//	newps->rsp = curps->rsp;
	newps->rflags = curps->rflags;
	newps->cs = curps->cs;
//	newps->rip = curps->rip;
	newps->error_code = curps->error_code;
*/
	processor_state_storage[processor_id()] = newps;

	processor_current()->running_thread(&newt);

	/* IPI のテスト */
/*
	if (processor_id() == 0) {
		uint32_t *hi, *lo;
		lo = (uint32_t *)0xfee00300ul;
		hi = (uint32_t *)0xfee00310ul;
		*hi = 1 << 24;
		*lo = 0x00000021;
	}
*/

/*
	if (&oldt != &newt) {
		utf8str x;
		x += "GSI: ";
		x.append_hex64(curps->gsi, 16);
		x += " => ";
		x.append_hex64(newps->gsi, 16);
		x += "\n";
		x += "SSZ: ";
		x.append_hex64(curps->stacked_size, 16);
		x += " => ";
		x.append_hex64(newps->stacked_size, 16);
		x += "\n";
		x += "CR3: ";
		x.append_hex64(curps->cr3, 16);
		x += " => ";
		x.append_hex64(newps->cr3, 16);
		x += "\n";
		x += "SS : ";
		x.append_hex64(curps->ss, 16);
		x += " => ";
		x.append_hex64(newps->ss, 16);
		x += "\n";
		x += "RSP: ";
		x.append_hex64(curps->rsp, 16);
		x += " => ";
		x.append_hex64(newps->rsp, 16);
		x += "\n";
		x += "RFG: ";
		x.append_hex64(curps->rflags, 16);
		x += " => ";
		x.append_hex64(newps->rflags, 16);
		x += "\n";
		x += "CS : ";
		x.append_hex64(curps->cs, 16);
		x += " => ";
		x.append_hex64(newps->cs, 16);
		x += "\n";
		x += "RIP: ";
		x.append_hex64(curps->rip, 16);
		x += " => ";
		x.append_hex64(newps->rip, 16);
		x += "\n";
		printstr(x);
	}
*/

	volatile uint32_t *ioapic = (uint32_t *)0x00000000fec00000ul;
	volatile uint32_t eoi = *gsi;
	ioapic[16] = eoi;
}

void
interrupt_handler_register(struct interrupt_handler &ih)
{
	interrupt_handlers_lock->acquire();
	interrupt_handlers[ih.gsi]->insert_tail(ih);
	interrupt_handlers_lock->release();
}

void
interrupt_handler_unregister(struct interrupt_handler &ih)
{
	interrupt_handlers_lock->acquire();
	interrupt_handlers[ih.gsi]->remove(ih);
	interrupt_handlers_lock->release();
}

void
boot_subsequent_processor(uint64_t id)
{
	uint32_t *hi, *lo;
	lo = (uint32_t *)0xfee00300ul;
	hi = (uint32_t *)0xfee00310ul;

	*hi = id << 24;
	*lo = 0x0000c500;

	sleep(100);

	*hi = id << 24;
	*lo = 0x00008500;

	sleep(10000);

	*hi = id << 24;
	*lo = 0x00004600 | ((((uint64_t)subsequent_processor_boot_code) >> 12) & 0xff);

	sleep(200);

	*hi = id << 24;
	*lo = 0x00004600 | ((((uint64_t)subsequent_processor_boot_code) >> 12) & 0xff);

	sleep(200);
}

static void
local_apic_init()
{
	// Enable local APIC; set spurious interrupt vector.
	*((uint32_t *)0x00000000fee000f0ul) = 0x000001ff; sleep(100);

	// The timer repeatedly counts down at bus frequency
	*((uint32_t *)0x00000000fee003e0ul) = 0x00000000; sleep(100);
	*((uint32_t *)0x00000000fee00320ul) = 0x00020020; sleep(100);
	*((uint32_t *)0x00000000fee00380ul) = 0xffffffff; sleep(100);

	// Disable logical interrupt lines.
//	*((uint32_t *)0x00000000fee00350ul) = 0x00010000; sleep(100);
//	*((uint32_t *)0x00000000fee00360ul) = 0x00010000; sleep(100);

	// Disable performance counter overflow interrupts
	*((uint32_t *)0x00000000fee00340ul) = 0x00010000; sleep(100);

	// Map error interrupt to IRQ_ERROR.
	*((uint32_t *)0x00000000fee00370ul) = 0x00000033; sleep(100);

	// Clear error status register (requires back-to-back writes).
	*((uint32_t *)0x00000000fee00280ul) = 0x00000000; sleep(100);
	*((uint32_t *)0x00000000fee00280ul) = 0x00000000; sleep(100);

	// Ack any outstanding interrupts.
	*((uint32_t *)0x00000000fee000b0ul) = 0x00000000; sleep(100);

	// Send an Init Level De-Assert to synchronise arbitration ID's.
	*((uint32_t *)0x00000000fee00310ul) = 0x00000000; sleep(100);
	*((uint32_t *)0x00000000fee00300ul) = 0x00088500; sleep(100);
	while (*((uint32_t *)0x00000000fee00300ul) & 0x00001000);

	// Enable interrupts on the APIC (but not on the processor).
	*((uint32_t *)0x00000000fee00080ul) = 0x00000000; sleep(100);

	// 
	*((uint32_t *)0x00000000fee00350ul) = 0x00000040; sleep(100);
	*((uint32_t *)0x00000000fee00360ul) = 0x00000041; sleep(100);

}

static int
processor_init_one(uint64_t id)
{
	processor_base *processor = nullptr;
	thread *io_thread = nullptr;
	utf8str io_thread_name;

	io_thread = thread_alloc(io_thread_main);
	if (io_thread == nullptr) {
		printstr("thread_alloc() に失敗しました。\n");
		panic();
	}

	io_thread_name = "io/";
	io_thread_name.append_uint64(id, 0);
	io_thread->name(io_thread_name);

	processor = processor_alloc(*io_thread);
	if (processor == nullptr) {
		printstr("processor_alloc() に失敗しました。\n");
		panic();
	}

	processor->id(id);
	processor->apic_address(0x00000000fee00000ul);

	if (id == processor_id()) {
		processor->boot_processor(true);
	}

	processors->insert(*processor);

	processor->threads().insert(*io_thread);

	return 0;
}

extern "C" void timer_interrupt_handler(uint8_t gsi);

void
timer_interrupt_handler_fn(uint8_t gsi)
{
/*
	utf8str x;
	x += "TMIH 0x";
	x.append_hex64(processor_id(), 2);
	x += " 0x";
	x.append_hex64(gsi, 2);
	x += "\n";
	printstr(x);
*/
}

struct interrupt_handler timer_ih = {
	.gsi	= 0x20,
	.ih	= timer_interrupt_handler_fn,
};

void
processor_init(struct loader_info *li)
{
	assert_sizeof_entry_classes();

	thread_lock = new spinlock;

	interrupt_handlers_lock = new spinlock;
	interrupt_handlers_lock->acquire();
	for (int i = 0; i < 256; ++i) {
		interrupt_handlers[i] = new linked_list<struct interrupt_handler>;
	}
	interrupt_handlers_lock->release();
	interrupt_handler_register(timer_ih);

	processors = new sorted_list<processor_base>;

	if (processors == nullptr) {
		printstr("プロセッサーのリストの初期化に失敗しました。\n");
		panic();
	}

	subsequent_processor_boot_code = memory_alloc_page_lo(memory_page_size::page_size_4k);
	if ((((uint64_t)subsequent_processor_boot_code) >> 12) > 0xff) {
		printstr("subsequent_processor_boot_code のベクタがオーバーフローします。\n");
		panic();
	}
	extern uint64_t mptramp_start;
	extern uint64_t mptramp_end;
	uint8_t *src = (uint8_t *)&mptramp_start;
	uint8_t *dst = (uint8_t *)subsequent_processor_boot_code;
	while (src != (uint8_t *)&mptramp_end) {
		*dst = *src;
		++src;
		++dst;
	}

	gdt = new intel64_gdt_entry[3];
	gdt[1].l(true);
	gdt[1].base(0x00000000);
	gdt[1].g(true);
	gdt[1].limit(0xfffff);
	gdt[1].p(true);
	gdt[1].s(true);
	gdt[1].type(0xb);
	gdt[2].base(0x00000000);
	gdt[2].db(true);
	gdt[2].g(true);
	gdt[2].limit(0xfffff);
	gdt[2].p(true);
	gdt[2].s(true);
	gdt[2].type(0x3);

	gdtrp = new intel64_gdtr();
	gdtrp->base((uint64_t)&gdt[0]);
	gdtrp->limit(0x0017);
	gdtrp->code_segment_selector(0x8);
	gdtrp->data_segment_selector(0x10);

	idt = new intel64_idt_entry[256];
	interrupt_handler_init(idt, gdtrp->code_segment_selector());

	idtrp = new intel64_idtr();
	idtrp->base((uint64_t)&idt[0]);
	idtrp->limit(0x0fff);

	global_pd_tables = new intel64_pd_table[64];
	for (uint64_t i = 0; i < 64; ++i) {
		for (uint64_t j = 0; j < 512; ++j) {
			uint64_t page_frame_beg, page_frame_end;
			page_frame_beg = (i << 30) + (j << 21);
			page_frame_end = page_frame_beg + 0x0000000000200000ul;
			global_pd_tables[i][j].page_frame_address(page_frame_beg);
			global_pd_tables[i][j].present(true);
			global_pd_tables[i][j].read_write(true);
			global_pd_tables[i][j].page_size(true);
			for (int k = 0; k < li->mm_num_of_mds; ++k) {
				if (li->mm_mds[k].md_type == 11) {
					uint64_t mmio_beg, mmio_end;
					mmio_beg = li->mm_mds[k].md_phys_start;
					mmio_end = mmio_beg + (li->mm_mds[k].md_num_of_pages * 512);
					if (((mmio_beg <= page_frame_beg) && (mmio_end <= page_frame_beg))
					 || ((mmio_beg >= page_frame_end) && (mmio_end >= page_frame_end))) {
						// このページフレームは MMIO に触れない。
					} else {
						// このページフレームは MMIO に触れる。
						global_pd_tables[i][j].page_level_cache_disable(true);
					}
				}
			}
		}
	}

	acpi_foreach_processor_apic(processor_init_one);
}

processor_base *
processor_alloc(thread &io_thread)
{
	return new intel64_processor(io_thread);
}

void
processor_free(processor_base *ptr)
{
	delete ptr;
}

extern "C" void boot_processor_start();

void
boot_processor_start()
{
	uint64_t thread_arg;

	gdtrp->load();
	idtrp->load();

	local_apic_init();

	thread_arg = (uint64_t)&(processor_current()->io_thread());

	sti();

	asm volatile ("pop %rbp");
	asm volatile ("movq %0, %%rdi" : : "r"(thread_arg) :);
	asm volatile ("jmp io_thread_main");
}

extern "C" void subsequent_processor_start();

void
subsequent_processor_start()
{
	uint64_t thread_arg;

	gdtrp->load();
	idtrp->load();

	local_apic_init();

	thread_arg = (uint64_t)&(processor_current()->io_thread());

	sti();

	subsequent_processor_status = 1;

	asm volatile ("pop %rbp");
	asm volatile ("movq %0, %%rdi" : : "r"(thread_arg) :);
	asm volatile ("jmp io_thread_main");
}

void
processor_start()
{
	bidir_node<processor_base> *bn;
	for (bn = processors->head(); bn != nullptr; bn = bn->next()) {
		processor_base &processor = bn->v();
		thread &io_thread = processor.io_thread();
		processor.running_thread(&io_thread);
		void *psa = io_thread.processor_state()->processor_state_address();
		processor_state_storage[processor.id()] = (intel64_processor_state_storage *)psa;
		if (processor.boot_processor()) {
			boot_processor_pml4_table_address = io_thread.page_table();
			boot_processor_stack_pointer = io_thread.stack_pointer();
			continue;
		}
		subsequent_processor_pml4_table_address = io_thread.page_table();
		subsequent_processor_stack_pointer = io_thread.stack_pointer();
		subsequent_processor_status = 0;
		boot_subsequent_processor(processor.id());

		uint64_t count = 0;
		while (subsequent_processor_status == 0) {
			sleep(1000);
			++count;
			if (count > 1000) {
				printstr("subsequent_processor_start に失敗しました。\n");
				panic();
			}
		}
		for (int i = 0; i < 1000; ++i) {
			sleep(1000);
		}
	}
	asm volatile ("movq %0, %%cr3" : : "r"(boot_processor_pml4_table_address) :);
	asm volatile ("movq %0, %%rsp" : : "r"(boot_processor_stack_pointer) :);
	asm volatile ("jmp boot_processor_start");
}

void
enable_interrupt()
{
	sti();
}

void
disable_interrupt()
{
	cli();
}

void
backup_interrupt(uint64_t &interrupt)
{
	interrupt = rflags() & 0x0000000000000200ul;
	if (interrupt) {
		cli();
	}
}

void
restore_interrupt(uint64_t &interrupt)
{
	if (interrupt) {
		sti();
	}
}

void
idle()
{
	//processor_current()->running_thread()->state(thread_state::idle);
	thread &t = *processor_current()->running_thread();
/*
	utf8str str(t.name());
	str += ": ";
	thread_state_append(t.state(), str);
	str += " => idle\n";
	printstr(str);
*/
	t.state(thread_state::idle);
	hlt();
}

void
reschedule()
{
	//processor_current()->running_thread()->state(thread_state::idle);
	thread &t = *processor_current()->running_thread();
/*
	utf8str str(t.name());
	str += ": ";
	thread_state_append(t.state(), str);
	str += " => idle\n";
	printstr(str);
*/
	t.state(thread_state::idle);
	int_0x20();
}

processor_state_base *
processor_state_alloc()
{
	return new intel64_processor_state;
}

void
processor_state_free(processor_state_base *ptr)
{
	delete ptr;
}

intel64_pml4_table *
pml4_table_alloc()
{
	intel64_pml4_table *pml4t = nullptr;
	intel64_pdpt_table *pdptt = nullptr;

	pdptt = new intel64_pdpt_table;
	for (int i = 0; i < 64; ++i) {
		pdptt->pd_table_at(i, &global_pd_tables[i]);
		(*pdptt)[i].pd_table_address((uint64_t)global_pd_tables[i].get_page_table());
		(*pdptt)[i].present(true);
		(*pdptt)[i].read_write(true);
	}

	pml4t = new intel64_pml4_table;
	pml4t->pdpt_table_at(0, pdptt);
	(*pml4t)[0].pdpt_table_address((uint64_t)pdptt->get_page_table());
	(*pml4t)[0].present(true);
	(*pml4t)[0].read_write(true);

	return pml4t;
}

void
pml4_table_free(intel64_pml4_table *pml4t)
{
	if (pml4t == nullptr) {
		return;
	}

	delete pml4t->pdpt_table_at(0);
	delete pml4t;
}

uint64_t
processor_id()
{
	uint64_t processor_id;
	processor_id = *((uint32_t *)0x00000000fee00020ul);
	processor_id = (processor_id >> 24);
	return processor_id;
}

processor_base *
processor_current()
{
	uint64_t pid = processor_id();
	bidir_node<processor_base> *bn;
	for (bn = processors->head(); bn != nullptr; bn = bn->next()) {
		if (bn->v().id() == pid)
			return &bn->v();
	}
	return nullptr;
}

int
processor_add_thread(thread &thread)
{
	bidir_node<processor_base> *bn;
	for (bn = processors->head(); bn != nullptr; bn = bn->next()) {
		bn->v().threads().insert(thread);
	}
	return 0;
}

void
processor_dump()
{
	bidir_node<processor_base> *bn;
	for (bn = processors->head(); bn != nullptr; bn = bn->next()) {
		bn->v().dump();
	}
}

static void
assert_sizeof_entry_classes()
{
	utf8str s;
	int errors = 0;

	if (sizeof(intel64_gdt_entry) != 8) {
		s += "sizeof(intel64_gdt_entry) = ";
		s.append_uint64(sizeof(intel64_gdt_entry), 0);
		s += "\n";
		++errors;
	}
		
	if (sizeof(intel64_idt_entry) != 16) {
		s += "sizeof(intel64_idt_entry) = ";
		s.append_uint64(sizeof(intel64_idt_entry), 0);
		s += "\n";
		++errors;
	}

	if (sizeof(intel64_page_entry_base) != 8) {
		s += "sizeof(intel64_page_entry_base) = ";
		s.append_uint64(sizeof(intel64_page_entry_base), 0);
		s += "\n";
		++errors;
	}

	if (sizeof(intel64_pd_entry) != 8) {
		s += "sizeof(intel64_pd_entry) = ";
		s.append_uint64(sizeof(intel64_pd_entry), 0);
		s += "\n";
		++errors;
	}

	if (sizeof(intel64_pdpt_entry) != 8) {
		s += "sizeof(intel64_pdpt_entry) = ";
		s.append_uint64(sizeof(intel64_pdpt_entry), 0);
		s += "\n";
		++errors;
	}

	if (sizeof(intel64_pml4_entry) != 8) {
		s += "sizeof(intel64_pml4_entry) = ";
		s.append_uint64(sizeof(intel64_pml4_entry), 0);
		s += "\n";
		++errors;
	}

	if (errors > 0) {
		printstr(s.ptr());
		panic();
	}

	return;
}

