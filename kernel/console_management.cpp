/**
 * @file	console_management.cpp
 * @brief	コンソール関連の処理をする関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "linked_list.h"
#include "console_base.h"
#include "display_console.h"
#include "serial_console.h"
#include "thread_management.h"
#include "processor_management.h"
#include "spinlock.h"

#include "loader_info.h"

static linked_list<console_base> *consoles = nullptr;
static linked_list<display_console> *display_consoles = nullptr;
static linked_list<serial_console> *serial_consoles = nullptr;

static spinlock *consoles_lock = nullptr;

static thread *console_thread = nullptr;

void
console_putchar(uint32_t c)
{
	bidir_node<console_base> *bn;

	if (consoles == nullptr)
		return;

	consoles_lock->acquire();
	for (bn = consoles->head(); bn != nullptr; bn = bn->next()) {
		bn->v().putchar(c);
	}
	consoles_lock->release();
}

uint32_t
console_getchar()
{
	uint32_t c;
	bidir_node<console_base> *bn;

	consoles_lock->acquire();
	for (bn = consoles->head(); bn != nullptr; bn = bn->next()) {
		c = bn->v().getchar();
		if (c > 0) {
			break;
		}
	}
	consoles_lock->release();

	if (bn != nullptr) {
		if (console_thread != nullptr) {
			console_thread->state(thread_state::pending);
		}
/*
		utf8str x("0x");
		x.append_hex64((uint64_t)bn, 16);
		x += " 0x";
		x.append_hex64(c, 2);
		x += "\n";
		printstr(x);
*/
	}

	return c;
}

void
display_console_interrupt_handler_fn(uint8_t gsi)
{
	console_getchar();
	utf8str x;
	x += "DCIH 0x";
	x.append_hex64(processor_id(), 2);
	x += " 0x";
	x.append_hex64(gsi, 2);
	x += "\n";
	printstr(x);
}

struct interrupt_handler display_console_ih = {
	.gsi	= 0x21,
	.ih	= display_console_interrupt_handler_fn,
};

void
serial_console_interrupt_handler_fn(uint8_t gsi)
{
	console_getchar();
	utf8str x;
	x += "SCIH 0x";
	x.append_hex64(processor_id(), 2);
	x += " 0x";
	x.append_hex64(gsi, 2);
	x += "\n";
	printstr(x);
}

struct interrupt_handler serial_console_ih1 = {
	.gsi	= 0x23,
	.ih	= serial_console_interrupt_handler_fn,
};

struct interrupt_handler serial_console_ih2 = {
	.gsi	= 0x24,
	.ih	= serial_console_interrupt_handler_fn,
};

void
console_init1(struct loader_info *li)
{
	display_console *dcon;
	serial_console *scon;

	consoles_lock = new spinlock;

	consoles_lock->acquire();

	consoles = new linked_list<console_base>;
	display_consoles = new linked_list<display_console>;
	serial_consoles = new linked_list<serial_console>;

	dcon = new display_console;
	dcon->uefifb_addr(li->fb_addr);
	dcon->uefifb_size(li->fb_size);
	dcon->uefifb_width(li->fb_width);
	dcon->uefifb_height(li->fb_height);
	dcon->uefifb_stride(li->fb_stride);
	dcon->uefifb_mask_red(li->fb_mask_red);
	dcon->uefifb_mask_green(li->fb_mask_green);
	dcon->uefifb_mask_blue(li->fb_mask_blue);
	dcon->uefifb_mask_reserved(li->fb_mask_reserved);
	dcon->reset();
	consoles->insert_head(*dcon);
	display_consoles->insert_head(*dcon);

	// COM1
	scon = new serial_console;
	scon->io_port_base(0x3f8);
	scon->irq(0x4);
	scon->baud_rate(2);
	scon->data_bits(0x3);
	scon->stop_bits(0x0);
	scon->parity(0x0);
	scon->reset();
	consoles->insert_head(*scon);
	serial_consoles->insert_head(*scon);

/*
	// COM2
	scon = new serial_console;
	scon->io_port_base(0x2f8);
	scon->irq(0x3);
	scon->baud_rate(2);
	scon->data_bits(0x3);
	scon->stop_bits(0x0);
	scon->parity(0x0);
	scon->reset();
	consoles->insert_head(*scon);
	serial_consoles->insert_head(*scon);

	// COM3
	scon = new serial_console;
	scon->io_port_base(0x3e8);
	scon->irq(0x4);
	scon->baud_rate(2);
	scon->data_bits(0x3);
	scon->stop_bits(0x0);
	scon->parity(0x0);
	scon->reset();
	consoles->insert_head(*scon);
	serial_consoles->insert_head(*scon);

	// COM4
	scon = new serial_console;
	scon->io_port_base(0x2e8);
	scon->irq(0x3);
	scon->baud_rate(2);
	scon->data_bits(0x3);
	scon->stop_bits(0x0);
	scon->parity(0x0);
	scon->reset();
	consoles->insert_head(*scon);
	serial_consoles->insert_head(*scon);
*/

	consoles_lock->release();
}

void
console_thread_main()
{
	while (true) {

		utf8str x("C I: 0x");
		x.append_hex64(processor_id(), 2);
		x += "\n";
		printstr(x);

		reschedule();
	}
}

void
console_init2()
{
	console_thread = thread_alloc(console_thread_main);
	if (console_thread == nullptr) {
		printstr("console_thread のメモリ割当に失敗しました。\n");
		panic();
	}
	console_thread->name("console");
	processor_add_thread(*console_thread);

	interrupt_handler_register(display_console_ih);
	interrupt_handler_register(serial_console_ih1);
	interrupt_handler_register(serial_console_ih2);

}

