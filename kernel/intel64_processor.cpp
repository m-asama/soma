/**
 * @file	intel64_processor.cpp
 * @brief	Intel64 CPU の初期化等を行う関数群実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "intel64_assembly.h"
#include "memory_management.h"
#include "utf8str.h"
#include "print.h"
#include "util.h"
#include "processor_state_base.h"
#include "intel64_processor_state.h"

#include "intel64_processor.h"

intel64_gdt_entry::intel64_gdt_entry()
{
	m_intel64_gdt_entry = 0;
}

/*
intel64_gdt_entry::~intel64_gdt_entry()
{
	m_intel64_gdt_entry = 0;
}
*/

void
intel64_gdt_entry::l(bool l)
{
	if (l) {
		m_intel64_gdt_entry |= 0x0020000000000000ul;
	} else {
		m_intel64_gdt_entry &= ~0x0020000000000000ul;
	}
}

bool
intel64_gdt_entry::l()
{
	return ((m_intel64_gdt_entry & 0x0020000000000000ul) != 0);
}

void
intel64_gdt_entry::avl(bool avl)
{
	if (avl) {
		m_intel64_gdt_entry |= 0x0010000000000000ul;
	} else {
		m_intel64_gdt_entry &= ~0x0010000000000000ul;
	}
}

bool
intel64_gdt_entry::avl()
{
	return ((m_intel64_gdt_entry & 0x0010000000000000ul) != 0);
}

void
intel64_gdt_entry::base(uint64_t base)
{
	m_intel64_gdt_entry = m_intel64_gdt_entry & ~0xff0000ffffff0000ul;
	m_intel64_gdt_entry |= (base & 0x000000000000fffful) << 16;
	m_intel64_gdt_entry |= (base & 0x0000000000ff0000ul) << 16;
	m_intel64_gdt_entry |= (base & 0x00000000ff000000ul) << 32;
}

uint64_t
intel64_gdt_entry::base()
{
	uint64_t base = 0;
	base |= (m_intel64_gdt_entry & 0x00000000ffff0000ul) >> 16;
	base |= (m_intel64_gdt_entry & 0x000000ff00000000ul) >> 16;
	base |= (m_intel64_gdt_entry & 0xff00000000000000ul) >> 32;
	return base;
}

void
intel64_gdt_entry::db(bool db)
{
	if (db) {
		m_intel64_gdt_entry |= 0x0040000000000000ul;
	} else {
		m_intel64_gdt_entry &= ~0x0040000000000000ul;
	}
}

bool
intel64_gdt_entry::db()
{
	return ((m_intel64_gdt_entry & 0x0040000000000000ul) != 0);
}

void
intel64_gdt_entry::dpl(uint8_t dpl)
{
	m_intel64_gdt_entry = m_intel64_gdt_entry & ~0x0000600000000000ul;
	m_intel64_gdt_entry |= ((uint64_t)(dpl & 0x03)) << 45;
}

uint8_t
intel64_gdt_entry::dpl()
{
	uint8_t dpl = 0;
	dpl |= (uint8_t)((m_intel64_gdt_entry & 0x0000600000000000ul) >> 45);
	return dpl;
}

void
intel64_gdt_entry::g(bool g)
{
	if (g) {
		m_intel64_gdt_entry |= 0x0080000000000000ul;
	} else {
		m_intel64_gdt_entry &= ~0x0080000000000000ul;
	}
}

bool
intel64_gdt_entry::g()
{
	return ((m_intel64_gdt_entry & 0x0080000000000000ul) != 0);
}

void
intel64_gdt_entry::limit(uint64_t limit)
{
	m_intel64_gdt_entry = m_intel64_gdt_entry & ~0x000f00000000fffful;
	m_intel64_gdt_entry |= (limit & 0x000000000000fffful) << 0;
	m_intel64_gdt_entry |= (limit & 0x0000000000ff0000ul) << 32;
}

uint64_t
intel64_gdt_entry::limit()
{
	uint64_t limit = 0;
	limit |= (m_intel64_gdt_entry & 0x000000000000fffful) >> 0;
	limit |= (m_intel64_gdt_entry & 0x000f000000000000ul) >> 32;
	return limit;
}

void
intel64_gdt_entry::p(bool p)
{
	if (p) {
		m_intel64_gdt_entry |= 0x0000800000000000ul;
	} else {
		m_intel64_gdt_entry &= ~0x0000800000000000ul;
	}
}

bool
intel64_gdt_entry::p()
{
	return ((m_intel64_gdt_entry & 0x0000800000000000ul) != 0);
}

void
intel64_gdt_entry::s(bool s)
{
	if (s) {
		m_intel64_gdt_entry |= 0x0000100000000000ul;
	} else {
		m_intel64_gdt_entry &= ~0x0000100000000000ul;
	}
}

bool
intel64_gdt_entry::s()
{
	return ((m_intel64_gdt_entry & 0x0000100000000000ul) != 0);
}

void
intel64_gdt_entry::type(uint8_t type)
{
	m_intel64_gdt_entry = m_intel64_gdt_entry & ~0x00000f0000000000ul;
	m_intel64_gdt_entry |= ((uint64_t)(type & 0x0f)) << 40;
}

uint8_t
intel64_gdt_entry::type()
{
	uint8_t type = 0;
	type |= (uint8_t)((m_intel64_gdt_entry & 0x00000f0000000000ul) >> 40);
	return type;
}

void
intel64_gdt_entry::set_intel64_gdt_entry(uint64_t intel64_gdt_entry)
{
	m_intel64_gdt_entry = intel64_gdt_entry;
}

uint64_t
intel64_gdt_entry::get_intel64_gdt_entry()
{
	return m_intel64_gdt_entry;
}

intel64_gdtr::intel64_gdtr()
{
	m_intel64_gdtr[0] = 0;
	m_intel64_gdtr[1] = 0;
}

intel64_gdtr::~intel64_gdtr()
{
	m_intel64_gdtr[0] = 0;
	m_intel64_gdtr[1] = 0;
}

void
intel64_gdtr::base(uint64_t base)
{
	m_intel64_gdtr[1] = base;
}

uint64_t
intel64_gdtr::base()
{
	return m_intel64_gdtr[1];
}

void
intel64_gdtr::limit(uint16_t limit)
{
	uint16_t *ptr = (uint16_t *)&m_intel64_gdtr[0];
	ptr += 3;
	*ptr = limit;
}

uint16_t
intel64_gdtr::limit()
{
	return (uint16_t)m_intel64_gdtr[0];
}

void
intel64_gdtr::code_segment_selector(uint16_t code_segment_selector)
{
	m_code_segment_selector = code_segment_selector;
}

uint16_t
intel64_gdtr::code_segment_selector()
{
	return m_code_segment_selector;
}

void
intel64_gdtr::data_segment_selector(uint16_t data_segment_selector)
{
	m_data_segment_selector = data_segment_selector;
}

uint16_t
intel64_gdtr::data_segment_selector()
{
	return m_data_segment_selector;
}

int
intel64_gdtr::load()
{
	uint16_t *intel64_gdtr;
	intel64_gdtr = (uint16_t *)&m_intel64_gdtr[0];
	intel64_gdtr += 3;
	lgdt(intel64_gdtr, m_code_segment_selector, m_data_segment_selector);
	return 0;
}

int
intel64_gdtr::store()
{
	uint16_t *intel64_gdtr;
	intel64_gdtr = (uint16_t *)&m_intel64_gdtr[0];
	intel64_gdtr += 3;
	sgdt(intel64_gdtr);
	return 0;
}

void
intel64_gdtr::set_intel64_gdtr0(uint64_t intel64_gdtr0)
{

	m_intel64_gdtr[0] = intel64_gdtr0;
}

uint64_t
intel64_gdtr::get_intel64_gdtr0()
{
	return m_intel64_gdtr[0];
}

void
intel64_gdtr::set_intel64_gdtr1(uint64_t intel64_gdtr1)
{
	m_intel64_gdtr[1] = intel64_gdtr1;
}

uint64_t
intel64_gdtr::get_intel64_gdtr1()
{
	return m_intel64_gdtr[1];
}

intel64_idt_entry::intel64_idt_entry()
{
	m_intel64_idt_entry[0] = 0;
	m_intel64_idt_entry[1] = 0;
}

/*
intel64_idt_entry::~intel64_idt_entry()
{
	m_intel64_idt_entry[0] = 0;
	m_intel64_idt_entry[1] = 0;
}
*/

void
intel64_idt_entry::dpl(uint8_t dpl)
{
	m_intel64_idt_entry[0] = m_intel64_idt_entry[0] & ~0x0000600000000000ul;
	m_intel64_idt_entry[0] |= ((uint64_t)(dpl & 0x03)) << 45;
}

uint8_t
intel64_idt_entry::dpl()
{
	uint8_t dpl = 0;
	dpl |= (uint8_t)((m_intel64_idt_entry[0] & 0x0000600000000000ul) >> 45);
	return dpl;
}

void
intel64_idt_entry::offset(uint64_t offset)
{
	m_intel64_idt_entry[0] = m_intel64_idt_entry[0] & ~0xffff00000000fffful;
	m_intel64_idt_entry[0] |= (offset & 0x000000000000fffful) << 0;
	m_intel64_idt_entry[0] |= (offset & 0x00000000ffff0000ul) << 32;
	m_intel64_idt_entry[1] = m_intel64_idt_entry[1] & ~0x00000000fffffffful;
	m_intel64_idt_entry[1] |= (offset & 0xffffffff00000000ul) >> 32;
}

uint64_t
intel64_idt_entry::offset()
{
	uint64_t offset = 0;
	offset |= (m_intel64_idt_entry[0] & 0x000000000000fffful) >> 0;
	offset |= (m_intel64_idt_entry[0] & 0xffff000000000000ul) >> 32;
	offset |= (m_intel64_idt_entry[1] & 0x00000000fffffffful) << 32;
	return offset;
}

void
intel64_idt_entry::p(bool p)
{
	if (p) {
		m_intel64_idt_entry[0] |= 0x0000800000000000ul;
	} else {
		m_intel64_idt_entry[0] &= ~0x0000800000000000ul;
	}
}

bool
intel64_idt_entry::p()
{
	return ((m_intel64_idt_entry[0] & 0x0000800000000000ul) != 0);
}

void
intel64_idt_entry::segment_selector(uint16_t segment_selector)
{
	m_intel64_idt_entry[0] = m_intel64_idt_entry[0] & ~0x00000000ffff0000ul;
	m_intel64_idt_entry[0] |= ((uint64_t)(segment_selector & 0xffff)) << 16;
}

uint16_t
intel64_idt_entry::segment_selector()
{
	uint16_t segment_selector = 0;
	segment_selector |= (uint16_t)((m_intel64_idt_entry[0] & 0x00000000ffff0000ul) >> 16);
	return segment_selector;
}

void
intel64_idt_entry::ist(uint8_t ist)
{
	m_intel64_idt_entry[0] = m_intel64_idt_entry[0] & ~0x0000000300000000ul;
	m_intel64_idt_entry[0] |= ((uint64_t)(ist & 0x03)) << 32;
}

uint8_t
intel64_idt_entry::ist()
{
	uint8_t ist = 0;
	ist |= (uint8_t)((m_intel64_idt_entry[0] & 0x0000000300000000ul) >> 32);
	return ist;
}

void
intel64_idt_entry::type(uint8_t type)
{
	m_intel64_idt_entry[0] = m_intel64_idt_entry[0] & ~0x00000f0000000000ul;
	m_intel64_idt_entry[0] |= ((uint64_t)(type & 0x0f)) << 40;
}

uint8_t
intel64_idt_entry::type()
{
	uint8_t type = 0;
	type |= (uint8_t)((m_intel64_idt_entry[0] & 0x00000f0000000000ul) >> 40);
	return type;
}

void
intel64_idt_entry::set_intel64_idt_entry0(uint64_t intel64_idt_entry0)
{
	m_intel64_idt_entry[0] = intel64_idt_entry0;
}

uint64_t
intel64_idt_entry::get_intel64_idt_entry0()
{
	return m_intel64_idt_entry[0];
}

void
intel64_idt_entry::set_intel64_idt_entry1(uint64_t intel64_idt_entry1)
{
	m_intel64_idt_entry[1] = intel64_idt_entry1;
}
        
uint64_t
intel64_idt_entry::get_intel64_idt_entry1()
{
	return m_intel64_idt_entry[1];
}

intel64_idtr::intel64_idtr()
{
	m_intel64_idtr[0] = 0;
	m_intel64_idtr[1] = 0;
}

intel64_idtr::~intel64_idtr()
{
	m_intel64_idtr[0] = 0;
	m_intel64_idtr[1] = 0;
}

void
intel64_idtr::base(uint64_t base)
{
	m_intel64_idtr[1] = base;
}

uint64_t
intel64_idtr::base()
{
	return m_intel64_idtr[1];
}

void
intel64_idtr::limit(uint16_t limit)
{
	uint16_t *ptr = (uint16_t *)&m_intel64_idtr[0];
	ptr += 3;
	*ptr = limit;
}

uint16_t
intel64_idtr::limit()
{
	return (uint16_t)m_intel64_idtr[0];
}

int
intel64_idtr::load()
{
	uint16_t *intel64_idtr;
	intel64_idtr = (uint16_t *)&m_intel64_idtr[0];
	intel64_idtr += 3;
	asm volatile ("lidt 0(%0)" : : "r"(intel64_idtr) :);
	return 0;
}

int
intel64_idtr::store()
{
	uint16_t *intel64_idtr;
	intel64_idtr = (uint16_t *)&m_intel64_idtr[0];
	intel64_idtr += 3;
	asm volatile ("sidt 0(%0)" : : "r"(intel64_idtr) :);
	return 0;
}

void
intel64_idtr::set_intel64_idtr0(uint64_t intel64_idtr0)
{
	m_intel64_idtr[0] = intel64_idtr0;
}

uint64_t
intel64_idtr::get_intel64_idtr0()
{
	return m_intel64_idtr[0];
}

void
intel64_idtr::set_intel64_idtr1(uint64_t intel64_idtr1)
{
	m_intel64_idtr[1] = intel64_idtr1;
}

uint64_t
intel64_idtr::get_intel64_idtr1()
{
	return m_intel64_idtr[1];
}

intel64_page_entry_base::intel64_page_entry_base()
{
	m_page_table_entry = 0;
}

/*
intel64_page_entry_base::~intel64_page_entry_base()
{
	m_page_table_entry = 0;
}
*/

void
intel64_page_entry_base::init()
{
	m_page_table_entry = 0;
}

void
intel64_page_entry_base::present(bool present)
{
	if (present) {
		m_page_table_entry |= 0x0000000000000001ul;
	} else {
		m_page_table_entry &= ~0x0000000000000001ul;
	}
}

bool
intel64_page_entry_base::present()
{
	return ((m_page_table_entry & 0x0000000000000001ul) != 0ul);
}

void
intel64_page_entry_base::read_write(bool read_write)
{
	if (read_write) {
		m_page_table_entry |= 0x0000000000000002ul;
	} else {
		m_page_table_entry &= ~0x0000000000000002ul;
	}
}

bool
intel64_page_entry_base::read_write()
{
	return ((m_page_table_entry & 0x0000000000000002ul) != 0ul);
}

void
intel64_page_entry_base::user_supervisor(bool user_supervisor)
{
	if (user_supervisor) {
		m_page_table_entry |= 0x0000000000000004ul;
	} else {
		m_page_table_entry &= ~0x0000000000000004ul;
	}
}

bool
intel64_page_entry_base::user_supervisor()
{
	return ((m_page_table_entry & 0x0000000000000004ul) != 0ul);
}

void
intel64_page_entry_base::page_level_write_through(bool page_level_write_through)
{
	if (page_level_write_through) {
		m_page_table_entry |= 0x0000000000000008ul;
	} else {
		m_page_table_entry &= ~0x0000000000000008ul;
	}
}

bool
intel64_page_entry_base::page_level_write_through()
{
	return ((m_page_table_entry & 0x0000000000000008ul) != 0ul);
}

void
intel64_page_entry_base::page_level_cache_disable(bool page_level_cache_disable)
{
	if (page_level_cache_disable) {
		m_page_table_entry |= 0x0000000000000010ul;
	} else {
		m_page_table_entry &= ~0x0000000000000010ul;
	}
}

bool
intel64_page_entry_base::page_level_cache_disable()
{
	return ((m_page_table_entry & 0x0000000000000010ul) != 0ul);
}

void
intel64_page_entry_base::accessed(bool accessed)
{
	if (accessed) {
		m_page_table_entry |= 0x0000000000000020ul;
	} else {
		m_page_table_entry &= ~0x0000000000000020ul;
	}
}

bool
intel64_page_entry_base::accessed()
{
	return ((m_page_table_entry & 0x0000000000000020ul) != 0ul);
}

uint64_t
intel64_page_entry_base::get_page_table_entry()
{
	return m_page_table_entry;
}

intel64_page_table_base::intel64_page_table_base()
{
	m_page_table = (intel64_page_entry_base *)memory_alloc_page_lo(memory_page_size::page_size_4k);
	for (int i = 0; i < 512; ++i) {
		m_page_table[i].init();
	}
}

intel64_page_table_base::~intel64_page_table_base()
{
	for (int i = 0; i < 512; ++i) {
		m_page_table[i].init();
	}
	memory_free(m_page_table);
}

uint64_t *
intel64_page_table_base::get_page_table()
{
	return (uint64_t *)m_page_table;
}

intel64_pd_entry::intel64_pd_entry()
{
}

/*
intel64_pd_entry::~intel64_pd_entry()
{
}
*/

void
intel64_pd_entry::dirty(bool dirty)
{
	if (dirty) {
		m_page_table_entry |= 0x0000000000000040ul;
	} else {
		m_page_table_entry &= ~0x0000000000000040ul;
	}
}

bool
intel64_pd_entry::dirty()
{
	return ((m_page_table_entry & 0x0000000000000040ul) != 0ul);
}

void
intel64_pd_entry::page_size(bool page_size)
{
	if (page_size) {
		m_page_table_entry |= 0x0000000000000080ul;
	} else {
		m_page_table_entry &= ~0x0000000000000080ul;
	}
}

bool
intel64_pd_entry::page_size()
{
	return ((m_page_table_entry & 0x0000000000000080ul) != 0ul);
}

void
intel64_pd_entry::global(bool global)
{
	if (global) {
		m_page_table_entry |= 0x0000000000000100ul;
	} else {
		m_page_table_entry &= ~0x0000000000000100ul;
	}
}

bool
intel64_pd_entry::global()
{
	return ((m_page_table_entry & 0x0000000000000100ul) != 0ul);
}

void
intel64_pd_entry::pat(bool pat)
{
	if (pat) {
		m_page_table_entry |= 0x0000000000001000ul;
	} else {
		m_page_table_entry &= ~0x0000000000001000ul;
	}
}

bool
intel64_pd_entry::pat()
{
	return ((m_page_table_entry & 0x0000000000001000ul) != 0ul);
}

void
intel64_pd_entry::page_frame_address(uint64_t page_frame_address)
{
	m_page_table_entry = m_page_table_entry & ~0x0000ffffffe00000ul;
	m_page_table_entry |= page_frame_address & 0x0000ffffffe00000ul;
}

uint64_t
intel64_pd_entry::page_frame_address()
{
	return m_page_table_entry & 0x0000ffffffe00000ul;
}

intel64_pd_table::intel64_pd_table()
{
}

intel64_pd_table::~intel64_pd_table()
{
}

intel64_pd_entry &
intel64_pd_table::operator[](size_t index)
{
	return (intel64_pd_entry &)m_page_table[index];
}

intel64_pdpt_entry::intel64_pdpt_entry()
{
}

/*
intel64_pdpt_entry::~intel64_pdpt_entry()
{
}
*/

void
intel64_pdpt_entry::page_size(bool page_size)
{
	if (page_size) {
		m_page_table_entry |= 0x0000000000000080ul;
	} else {
		m_page_table_entry &= ~0x0000000000000080ul;
	}
}

bool
intel64_pdpt_entry::page_size()
{
	return ((m_page_table_entry & 0x0000000000000080ul) != 0ul);
}

void
intel64_pdpt_entry::pd_table_address(uint64_t pd_table_address)
{
	m_page_table_entry = m_page_table_entry & ~0x0000fffffffff000ul;
	m_page_table_entry |= pd_table_address & 0x0000fffffffff000ul;
}

uint64_t
intel64_pdpt_entry::pd_table_address()
{
	return m_page_table_entry & 0x0000fffffffff000ul;
}

intel64_pdpt_table::intel64_pdpt_table()
{
	int i;
	for (i = 0; i < 512; ++i) {
		m_intel64_pd_tables[i] = nullptr;
	}
}

intel64_pdpt_table::~intel64_pdpt_table()
{
}

intel64_pdpt_entry &
intel64_pdpt_table::operator[](size_t index)
{
	return (intel64_pdpt_entry &)m_page_table[index];
}

void
intel64_pdpt_table::pd_table_at(int index, intel64_pd_table *pd_table)
{
	if ((index < 0) || (index >= 512)) {
		return;
	}

	m_intel64_pd_tables[index] = pd_table;
}

intel64_pd_table *
intel64_pdpt_table::pd_table_at(int index)
{
	if ((index < 0) || (index >= 512)) {
		return nullptr;
	}
	return m_intel64_pd_tables[index];
}

intel64_pml4_entry::intel64_pml4_entry()
{
}

/*
intel64_pml4_entry::~intel64_pml4_entry()
{
}
*/

void
intel64_pml4_entry::pdpt_table_address(uint64_t pdpt_table_address)
{
	m_page_table_entry = m_page_table_entry & ~0x0000fffffffff000ul;
	m_page_table_entry |= pdpt_table_address & 0x0000fffffffff000ul;
}

uint64_t
intel64_pml4_entry::pdpt_table_address()
{
	return m_page_table_entry & 0x0000fffffffff000ul;
}

intel64_pml4_table::intel64_pml4_table()
{
	int i;
	for (i = 0; i < 512; ++i) {
		m_intel64_pdpt_tables[i] = nullptr;
	}
}

intel64_pml4_table::~intel64_pml4_table()
{
}

intel64_pml4_entry &
intel64_pml4_table::operator[](size_t index)
{
	return (intel64_pml4_entry &)m_page_table[index];
}

void
intel64_pml4_table::pdpt_table_at(int index, intel64_pdpt_table *pdpt_table)
{
	if ((index < 0) || (index >= 512)) {
		return;
	}

	m_intel64_pdpt_tables[index] = pdpt_table;
}

intel64_pdpt_table *
intel64_pml4_table::pdpt_table_at(int index)
{
	if ((index < 0) || (index >= 512)) {
		return nullptr;
	}

	return m_intel64_pdpt_tables[index];
}

intel64_processor::intel64_processor(thread &io_thread)
	: processor_base(io_thread)
{
}

intel64_processor::~intel64_processor()
{
}

