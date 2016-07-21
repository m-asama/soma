/**
 * @file	pci_management.cpp
 * @brief	PCI 関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "intel64_assembly.h"
#include "print.h"

static uint32_t
pci_address(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	return (uint32_t)((bus << 16)
		| (slot << 11)
		| (function << 8)
		| (offset & 0xfc)
		| ((uint32_t)0x80000000));
}

static uint16_t
pci_config_read_word(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	uint32_t address;
	uint32_t tmp = 0;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	tmp = (uint16_t)((inl(0xcfc) >> ((offset & 2) * 8)) & 0xffff);
	return tmp;
}

static void
pci_config_write_word(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint16_t val)
{
	uint32_t address;
	uint32_t orig;
	address = pci_address(bus, slot, function, offset);
	outl(0xcf8, address);
	orig = inl(0xcfc);
	outl(0xcf8, address);
	if (offset & 2) {
		orig &= 0x0000ffff;
		orig |= (val << 16);
	} else {
		orig &= 0xffff0000;
		orig |= val;
	}
	outl(0xcfc, orig);
}

static uint16_t __attribute__ ((unused))
pci_config_read_long(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	uint32_t address;
	uint32_t tmp = 0;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	tmp = inl(0xcfc);
	return tmp;
}

static uint16_t
pci_check_vendor(uint8_t bus, uint8_t slot)
{
	uint16_t vendor;
	vendor = pci_config_read_word(bus, slot, 0, 0);
	return vendor;
}

static uint16_t
pci_check_device(uint8_t bus, uint8_t slot)
{
	uint16_t device;
	device = pci_config_read_word(bus, slot, 0, 2);
	return device;
}

static void
pci_check_all_buses()
{
	uint16_t bus;
	uint16_t slot;
	uint16_t vendor, device;
	for (bus = 0; bus < 256; ++bus) {
		for (slot = 0; slot < 32; ++slot) {
			vendor = pci_check_vendor(bus, slot);
			device = pci_check_device(bus, slot);
			if (vendor != 0xffff) {
				printstr(" ");
				printhex8(bus);
				printstr(" ");
				printhex8(slot);
				printstr(" ");
				printhex64(vendor);
				printstr(" ");
				printhex64(device);
				printstr("\n");
			}
			if (vendor == 0x8086 && ((device == 0x0c46)
					      || (device == 0x0c47)
					      || (device == 0x0c48)
					      || (device == 0x0c49))) {
				uint16_t w;
				w = pci_config_read_word(bus, slot, 0, 0x92);
				pci_config_write_word(bus, slot, 0, 0x92, (w|1));
				w = pci_config_read_word(bus, slot, 0, 0x92);
				printstr("    ");
				printhex64(w);
				printstr("\n");
			}
		}
	}
}

void
pci_init()
{
	pci_check_all_buses();
/*
	uint16_t xbcs;
	xbcs = pci_config_read_word(0, 1, 0, 0x4e);
	xbcs |= 0x0100;
	pci_config_write_word(0, 1, 0, 0x4e, xbcs);

	uint32_t *ioapic = (uint32_t *)0x00000000fec00000ul;
	ioapic[0] = 0x12;
	ioapic[4] = 0x00000030;
	ioapic[0] = 0x13;
	ioapic[4] = 0x00000000;
*/


	int8_t c;
	outb(0x64, 0x20);
	c = inb(0x60);
	c |= 0x45;
//	c |= 0x01;
	outb(0x64, 0x60);
	outb(0x60, c);

	outb(0x64, 0xae);

/*
	uint8_t a1 = inb(0x21);
	uint8_t a2 = inb(0xa1);
	outb(0x20, 0x11);
	outb(0xa0, 0x11);
	outb(0x21, 0x40);
	outb(0xa1, 0x48);
	outb(0x21, 0x04);
	outb(0xa1, 0x02);
	outb(0x21, 0x01);
	outb(0xa1, 0x01);
	outb(0x21, a1);
	outb(0xa1, a2);
*/

/*
	x = pci_config_read_word(0, 1, 0, 0x4e);
	x |= 0x0100;
	pci_config_write_word(0, 1, 0, 0x4e, x);
	printhex64(pci_config_read_word(0, 1, 0, 0x4e));
	printstr("\n");
	printhex64(x);
	printstr("\n");
*/
}

