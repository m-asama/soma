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

	return c;
}

void
display_console_keyboard_interrupt_handler_fn(uint8_t gsi)
{
	/*
	utf8str x;
	x += "DCIH 0x";
	x.append_hex64(processor_id(), 2);
	x += " 0x";
	x.append_hex64(gsi, 2);
	x += "\n";
	printstr(x);
	*/
	bidir_node<display_console> *bn;
	for (bn = display_consoles->head(); bn != nullptr; bn = bn->next()) {
		display_console &dc = bn->v();
		thread *ct = dc.console_thread();
		uint64_t readed = dc.read_from_keyboard();
		if ((readed > 0) && (ct != nullptr)) {
/*
			utf8str str(ct->name());
			str += ": ";
			thread_state_append(ct->state(), str);
			str += " => pending\n";
			printstr(str);
*/
			ct->state(thread_state::pending);
		}
	}
}

void
display_console_mouse_interrupt_handler_fn(uint8_t gsi)
{
}

struct interrupt_handler display_console_keyboard_ih = {
	.gsi	= 0x21,
	.ih	= display_console_keyboard_interrupt_handler_fn,
};

struct interrupt_handler display_console_mouse_ih = {
	.gsi	= 0x2c,
	.ih	= display_console_mouse_interrupt_handler_fn,
};

void
serial_console_interrupt_handler_fn(uint8_t gsi)
{
	/*
	utf8str x;
	x += "SCIH 0x";
	x.append_hex64(processor_id(), 2);
	x += " 0x";
	x.append_hex64(gsi, 2);
	x += "\n";
	printstr(x);
	*/
	bidir_node<serial_console> *bn;
	for (bn = serial_consoles->head(); bn != nullptr; bn = bn->next()) {
		serial_console &sc = bn->v();
		thread *ct = sc.console_thread();
		if (sc.irq() == (gsi - 0x20)) {
			uint64_t readed = sc.read_from_serial();
			if ((readed > 0) && (ct != nullptr)) {
/*
				utf8str str(ct->name());
				str += ": ";
				thread_state_append(ct->state(), str);
				str += " => pending\n";
				printstr(str);
*/
				ct->state(thread_state::pending);
			}
		}
	}
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
console_thread_main(thread *t)
{
	console_base &cb = *(console_base *)t->private_data();

	while (true) {
/*
		utf8str x("C I: 0x");
		x.append_hex64(processor_id(), 2);
		x += " ";
		x.append_hex64((uint64_t)t, 16);
		x += " CR3:0x";
		x.append_hex64((uint64_t)cr3(), 16);
		x += " RSP:0x";
		x.append_hex64((uint64_t)rsp(), 16);
		x += "\n";
		printstr(x);
*/
		uint32_t c;
		while((c = cb.getchar()) > 0) {
/*
			utf8str x;
			x.append_hex64(c, 2);
			x += " ";
			printstr(x);
*/
			cb.putchar(c);
		}

		reschedule();
	}
}

void
console_init1(struct loader_info *li)
{
	display_console *dcon;
	serial_console *scon;
	utf8str name;

	consoles_lock = new spinlock;

	consoles_lock->acquire();

	consoles = new linked_list<console_base>;
	display_consoles = new linked_list<display_console>;
	serial_consoles = new linked_list<serial_console>;

	dcon = new display_console;
	name = "console/display";
	dcon->name(name);
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
	name = "console/com1";
	scon->name(name);
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
	name = "console/com2";
	scon->name(name);
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
	name = "console/com3";
	scon->name(name);
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
	name = "console/com4";
	scon->name(name);
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
console_init2()
{
	bidir_node<console_base> *bn;
	consoles_lock->acquire();
	for (bn = consoles->head(); bn != nullptr; bn = bn->next()) {
		console_base &cb = bn->v();
		thread *ct = thread_alloc(console_thread_main);
		if (ct == nullptr) {
			printstr("console_thread のメモリ割当に失敗しました。\n");
			panic();
		}
		ct->name(cb.name());
		ct->private_data((void *)&cb);
		processor_add_thread(*ct);
		cb.console_thread(ct);
	}
	consoles_lock->release();

	interrupt_handler_register(display_console_keyboard_ih);
	interrupt_handler_register(display_console_mouse_ih);
	interrupt_handler_register(serial_console_ih1);
	interrupt_handler_register(serial_console_ih2);

}

