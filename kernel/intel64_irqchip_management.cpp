/**
 * @file	intel64_irqchip_management.cpp
 * @brief	Intel64 I/O APIC の初期化等を行う関数群実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"

#include "print.h"
#include "intel64_ioapic.h"
#include "acpi_management.h"
#include "util.h"
#include "intel64_assembly.h"
#include "sorted_list.h"
#include "irqchip_management.h"

static sorted_list<irqchip_base> *irqchips = nullptr;

static void
pic_init()
{
/*
	const uint16_t IO_PIC1_CMD = 0x20;
	const uint16_t IO_PIC1_IMR = 0x21;
	const uint16_t IO_PIC2_CMD = 0xa0;
	const uint16_t IO_PIC2_IMR = 0xa1;

	outb(IO_PIC1_IMR, 0xff); sleep(100);
	outb(IO_PIC2_IMR, 0xff); sleep(100);

	outb(IO_PIC1_CMD, 0x11); sleep(100);
	outb(IO_PIC1_IMR, 0x20); sleep(100);
	outb(IO_PIC1_IMR, 0x04); sleep(100);
	outb(IO_PIC1_IMR, 0x01); sleep(100);

	outb(IO_PIC2_CMD, 0x11); sleep(100);
	outb(IO_PIC2_IMR, 0x28); sleep(100);
	outb(IO_PIC2_IMR, 0x02); sleep(100);
	outb(IO_PIC2_IMR, 0x01); sleep(100);

//	outb(IO_PIC1_CMD, 0x68); sleep(100);
//	outb(IO_PIC1_CMD, 0x0a); sleep(100);
//	outb(IO_PIC2_CMD, 0x68); sleep(100);
//	outb(IO_PIC2_CMD, 0x0a); sleep(100);

	sleep(100);

//	outb(IO_PIC1_IMR, 0x00); sleep(100);
//	outb(IO_PIC2_IMR, 0x00); sleep(100);
//	outb(IO_PIC1_IMR, 0xe1); sleep(100);
//	outb(IO_PIC2_IMR, 0xff); sleep(100);
//	outb(IO_PIC1_IMR, 0xff); sleep(100);
//	outb(IO_PIC2_IMR, 0xff); sleep(100);
*/

	outb(0x20, 0x10 | 0x01);
	outb(0x21, 32);
	outb(0x21, (1 << (2)));
	outb(0x21, 0x01);
	outb(0x21, 0xff);
	outb(0x20, 0x08 | 0x02);

	outb(0xa0, 0x10 | 0x01);
	outb(0xa1, 32 + 8);
	outb(0xa1, 2);
	outb(0xa1, 0x01);
	outb(0xa1, 0xff);
	outb(0xa0, 0x08 | 0x02);

}

static void
ioapic_init()
{
	uint32_t *ioapic = (uint32_t *)0x00000000fec00000ul;

//	ioapic[0] = 0x00000001; sleep(100);
//	print("IOAPICVS: "); printhex32(ioapic[4]); print("\n");

//	sleep(100);

	for (uint32_t i = 0; i <= 0x17; ++i) {
		ioapic[0] = 0x10 + 2 * i;
		sleep(100);
		ioapic[4] = 0x00010000 + 0x20 + i;
		sleep(100);
		ioapic[0] = 0x11 + 2 * i;
		sleep(100);
		ioapic[4] = 0x00000000;
		sleep(100);
	}

	// KBD
	ioapic[0] = 0x00000012; sleep(100);
	ioapic[4] = 0x00000021; sleep(100);
	ioapic[0] = 0x00000013; sleep(100);
	ioapic[4] = 0x00000000; sleep(100);

	// COM1
	ioapic[0] = 0x00000018; sleep(100);
	ioapic[4] = 0x00000024; sleep(100);
	ioapic[0] = 0x00000019; sleep(100);
	ioapic[4] = 0x00000000; sleep(100);

	// COM2
	ioapic[0] = 0x00000016; sleep(100);
	ioapic[4] = 0x00000023; sleep(100);
	ioapic[0] = 0x00000017; sleep(100);
	ioapic[4] = 0x00000000; sleep(100);

	// EOI
	ioapic[16] = 0x00000021; sleep(100);
	ioapic[16] = 0x00000024; sleep(100);
	ioapic[16] = 0x00000023; sleep(100);

//	outb(0x22, 0x70); 		// Select IMCR
//	outb(0x23, inb(0x23) | 1);	// Mask external interrupts.

}

static int
irqchip_init_one(uint64_t id, uint64_t apic_address, uint64_t gsi_base)
{
	irqchip_base *irqchip = nullptr;

	irqchip = irqchip_alloc();

	if (irqchip == nullptr) {
		print("irqchip_alloc() に失敗しました。\n");
		panic();
	}

	irqchip->id(id);
	irqchip->apic_address(apic_address);
	irqchip->gsi_base(gsi_base);

	irqchips->insert(*irqchip);

	return 0;
}

void irqchip_init()
{
	irqchips = new sorted_list<irqchip_base>;

	if (irqchips == nullptr) {
		print("IRQ チップのリストの初期化に失敗しました。\n");
		panic();
	}

	acpi_foreach_irqchip_apic(irqchip_init_one);

	pic_init();
	ioapic_init();
}

irqchip_base *
irqchip_alloc()
{
	return new intel64_ioapic;
}

void
irqchip_free(irqchip_base *ptr)
{
	delete ptr;
}

void
irqchip_dump()
{
	bidir_node<irqchip_base> *bn;
	for (bn = irqchips->head(); bn != nullptr; bn = bn->next()) {
		bn->v().dump();
	}
}

