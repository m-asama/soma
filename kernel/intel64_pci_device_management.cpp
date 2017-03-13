/**
 * @file	intel64_pci_device_management.cpp
 * @brief	PCI デバイス関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "intel64_assembly.h"
#include "print.h"

#include "pci_device_management.h"

static uint32_t
pci_address(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	return (uint32_t)((bus << 16)
		| (slot << 11)
		| (function << 8)
		| (offset & 0xfc)
		| ((uint32_t)0x80000000));
}

static uint8_t __attribute__ ((unused))
pci_config_read_uint8(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	uint32_t address;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	return ((inl(0xcfc) >> ((offset & 0x03) * 8)) & 0xff);
}

static void __attribute__ ((unused))
pci_config_write_uint8(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint8_t val)
{
	uint32_t address;
	uint32_t tmp;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	tmp = inl(0xcfc);

	outl(0xcf8, address);
	tmp &= ~(0x000000fful << ((offset & 0x03) * 8));
	tmp |= val << ((offset & 0x03) * 8);
	outl(0xcfc, tmp);
}

static uint16_t __attribute__ ((unused))
pci_config_read_uint16(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	uint32_t address;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	return ((inl(0xcfc) >> ((offset & 0x02) * 8)) & 0xffff);
}

static void __attribute__ ((unused))
pci_config_write_uint16(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint16_t val)
{
	uint32_t address;
	uint32_t tmp;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	tmp = inl(0xcfc);

	outl(0xcf8, address);
	tmp &= ~(0x0000fffful << ((offset & 0x02) * 8));
	tmp |= val << ((offset & 0x02) * 8);
	outl(0xcfc, tmp);
}

static uint32_t __attribute__ ((unused))
pci_config_read_uint32(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset)
{
	uint32_t address;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	return (inl(0xcfc));
}

static void __attribute__ ((unused))
pci_config_write_uint32(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint32_t val)
{
	uint32_t address;

	address = pci_address(bus, slot, function, offset);

	outl(0xcf8, address);
	outl(0xcfc, val);
}

static uint16_t
pci_check_vendor(uint8_t bus, uint8_t slot)
{
	uint16_t vendor;
	vendor = pci_config_read_uint16(bus, slot, 0, 0);
	return vendor;
}

static uint16_t
pci_check_device(uint8_t bus, uint8_t slot)
{
	uint16_t device;
	device = pci_config_read_uint16(bus, slot, 0, 2);
	return device;
}

void
pci_check_all_buses()
{
	uint16_t bus;
	uint16_t slot;
	uint16_t vendor, device;
	for (bus = 0; bus < 256; ++bus) {
		for (slot = 0; slot < 32; ++slot) {
			vendor = pci_check_vendor(bus, slot);
			device = pci_check_device(bus, slot);
			if (vendor == 0xffff) {
				continue;
			}
		}
	}
}

