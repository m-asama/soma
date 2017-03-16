/**
 * @file	pci_device_base.cpp
 * @brief	PCI デバイス基底クラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "pci_device_management.h"

#include "pci_device_base.h"

pci_device_base::pci_device_base()
	: m_bus(-1), m_slot(-1)
{
}

pci_device_base::~pci_device_base()
{
}

bool
pci_device_base::operator==(const pci_device_base &rhs)
{
	if ((m_bus == rhs.m_bus)
	 && (m_slot == rhs.m_slot)) {
		return true;
	}
	return false;
}

bool
pci_device_base::operator>(const pci_device_base &rhs)
{
	if ((m_bus > rhs.m_bus)
	 || ((m_bus == rhs.m_bus)
	  && (m_slot > rhs.m_slot))) {
		return true;
	}
	return false;
}

void
pci_device_base::bus(sint16_t bus)
{
	m_bus = bus;
}

sint16_t
pci_device_base::bus()
{
	return m_bus;
}

void
pci_device_base::slot(sint16_t slot)
{
	m_slot = slot;
}

sint16_t
pci_device_base::slot()
{
	return m_slot;
}

uint32_t
pci_device_base::address(uint8_t function, uint8_t offset)
{
	return pci_address(m_bus, m_slot, function, offset);
}

uint8_t
pci_device_base::config_read_uint8(uint8_t function, uint8_t offset)
{
	return pci_config_read_uint8(m_bus, m_slot, function, offset);
}

void
pci_device_base::config_write_uint8(uint8_t function, uint8_t offset, uint8_t val)
{
	pci_config_write_uint8(m_bus, m_slot, function, offset, val);
}

uint16_t
pci_device_base::config_read_uint16(uint8_t function, uint8_t offset)
{
	return pci_config_read_uint16(m_bus, m_slot, function, offset);
}

void
pci_device_base::config_write_uint16(uint8_t function, uint8_t offset, uint16_t val)
{
	pci_config_write_uint16(m_bus, m_slot, function, offset, val);
}

uint32_t
pci_device_base::config_read_uint32(uint8_t function, uint8_t offset)
{
	return pci_config_read_uint32(m_bus, m_slot, function, offset);
}

void
pci_device_base::config_write_uint32(uint8_t function, uint8_t offset, uint32_t val)
{
	pci_config_write_uint32(m_bus, m_slot, function, offset, val);
}

uint16_t
pci_device_base::vendor_id()
{
	return config_read_uint16(0, 0x00);
}

uint16_t
pci_device_base::device_id()
{
	return config_read_uint16(0, 0x02);
}

void
pci_device_base::command(uint16_t command)
{
	config_write_uint16(0, 0x04, command);
}

uint16_t
pci_device_base::command()
{
	return config_read_uint16(0, 0x04);
}

void
pci_device_base::status(uint16_t status)
{
	config_write_uint16(0, 0x06, status);
}

uint16_t
pci_device_base::status()
{
	return config_read_uint16(0, 0x06);
}

uint8_t
pci_device_base::revision_id()
{
	return config_read_uint8(0, 0x08);
}

uint32_t
pci_device_base::class_code()
{
	return config_read_uint32(0, 0x08) >> 8;
}

void
pci_device_base::cacheline_size(uint8_t cacheline_size)
{
	config_write_uint8(0, 0x0c, cacheline_size);
}

uint8_t
pci_device_base::cacheline_size()
{
	return config_read_uint8(0, 0x0c);
}

void
pci_device_base::latency_timer(uint8_t latency_timer)
{
	config_write_uint8(0, 0x0d, latency_timer);
}

uint8_t
pci_device_base::latency_timer()
{
	return config_read_uint8(0, 0x0d);
}

uint8_t
pci_device_base::header_type()
{
	return config_read_uint8(0, 0x0e);
}

void
pci_device_base::bist(uint8_t bist)
{
	config_write_uint8(0, 0x0f, bist);
}

uint8_t
pci_device_base::bist()
{
	return config_read_uint8(0, 0x0f);
}

void
pci_device_base::base_address_register_0(uint32_t base_address_register_0)
{
	config_write_uint32(0, 0x10, base_address_register_0);
}

uint32_t
pci_device_base::base_address_register_0()
{
	return config_read_uint32(0, 0x10);
}

void
pci_device_base::base_address_register_1(uint32_t base_address_register_1)
{
	config_write_uint32(0, 0x14, base_address_register_1);
}

uint32_t
pci_device_base::base_address_register_1()
{
	return config_read_uint32(0, 0x14);
}

void
pci_device_base::base_address_register_2(uint32_t base_address_register_2)
{
	config_write_uint32(0, 0x18, base_address_register_2);
}

uint32_t
pci_device_base::base_address_register_2()
{
	return config_read_uint32(0, 0x18);
}

void
pci_device_base::base_address_register_3(uint32_t base_address_register_3)
{
	config_write_uint32(0, 0x1c, base_address_register_3);
}

uint32_t
pci_device_base::base_address_register_3()
{
	return config_read_uint32(0, 0x1c);
}

void
pci_device_base::base_address_register_4(uint32_t base_address_register_4)
{
	config_write_uint32(0, 0x20, base_address_register_4);
}

uint32_t
pci_device_base::base_address_register_4()
{
	return config_read_uint32(0, 0x20);
}

void
pci_device_base::base_address_register_5(uint32_t base_address_register_5)
{
	config_write_uint32(0, 0x24, base_address_register_5);
}

uint32_t
pci_device_base::base_address_register_5()
{
	return config_read_uint32(0, 0x24);
}

void
pci_device_base::cardbus_cis_pointer(uint32_t cardbus_cis_pointer)
{
	config_write_uint32(0, 0x28, cardbus_cis_pointer);
}

uint32_t
pci_device_base::cardbus_cis_pointer()
{
	return config_read_uint32(0, 0x28);
}

uint16_t
pci_device_base::subsystem_vendor_id()
{
	return config_read_uint16(0, 0x2c);
}

uint16_t
pci_device_base::subsystem_id()
{
	return config_read_uint16(0, 0x2e);
}

void
pci_device_base::expansion_rom_base_address(uint32_t expansion_rom_base_address)
{
	config_write_uint32(0, 0x30, expansion_rom_base_address);
}

uint32_t
pci_device_base::expansion_rom_base_address()
{
	return config_read_uint32(0, 0x30);
}

uint8_t
pci_device_base::capabilities_pointer()
{
	return config_read_uint8(0, 0x34);
}

void
pci_device_base::interrupt_line(uint8_t interrupt_line)
{
	config_write_uint8(0, 0x3c, interrupt_line);
}

uint8_t
pci_device_base::interrupt_line()
{
	return config_read_uint8(0, 0x3c);
}

uint8_t
pci_device_base::interrupt_pin()
{
	return config_read_uint8(0, 0x3d);
}

uint8_t
pci_device_base::min_gnt()
{
	return config_read_uint8(0, 0x3e);
}

uint8_t
pci_device_base::max_lat()
{
	return config_read_uint8(0, 0x3f);
}

utf8str
pci_device_base::pci_dump()
{
	utf8str s;
	s += "Bus: ";
	s.append_hex64(m_bus, 2);
	s += " Slot: ";
	s.append_hex64(m_slot, 2);
	s += "\n";
	s += "    Vendor ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x00), 4);
	s += " Device ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x02), 4);
	s += "\n";
	s += "    Command: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x04), 4);
	s += " Status: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x06), 4);
	s += "\n";
	s += "    Revision ID: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x08), 2);
	s += " Class Code: ";
	s.append_hex64((pci_config_read_uint32(m_bus, m_slot, 0, 0x08) >> 8), 6);
	s += "\n";
	s += "    Cacheline Size: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0c), 2);
	s += " Latency Timer: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0d), 2);
	s += " Header Type: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0e), 2);
	s += " BIST: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x0f), 2);
	s += "\n";
	if (pci_config_read_uint8(m_bus, m_slot, 0, 0x0e) != 0x00) {
		return s;
	}
	s += "    Base Address Register 1: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x10), 8);
	s += "\n";
	s += "    Base Address Register 2: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x14), 8);
	s += "\n";
	s += "    Base Address Register 3: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x18), 8);
	s += "\n";
	s += "    Base Address Register 4: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x1c), 8);
	s += "\n";
	s += "    Base Address Register 5: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x20), 8);
	s += "\n";
	s += "    Base Address Register 6: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x24), 8);
	s += "\n";
	s += "    Cardbus CIS Pointer: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x28), 8);
	s += "\n";
	s += "    Subsystem Vendor ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x2c), 4);
	s += " Subsystem ID: ";
	s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, 0x2e), 4);
	s += "\n";
	s += "    Expansion ROM Base Address: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x30), 8);
	s += "\n";
	s += "    Capabilities Pointer: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x34), 2);
	s += " Reserved: ";
	s.append_hex64((pci_config_read_uint32(m_bus, m_slot, 0, 0x34) >> 8), 6);
	s += "\n";
	s += "    Reserved: ";
	s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, 0x38), 8);
	s += "\n";
	s += "    Interrupt Line: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3c), 2);
	s += " Interrupt Pin: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3d), 2);
	s += " Min_Gnt: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3e), 2);
	s += " Max_Lat: ";
	s.append_hex64(pci_config_read_uint8(m_bus, m_slot, 0, 0x3f), 2);
	s += "\n";

	s += "    Capabilities List:\n";
	uint8_t capp = pci_config_read_uint8(m_bus, m_slot, 0, 0x34) & 0xfc;
	while (capp != 0x00) {
		uint8_t capid = pci_config_read_uint8(m_bus, m_slot, 0, capp);
		s += "        Capability ID: ";
		s.append_hex64(capid, 2);
		switch (capid) {
		case 0x01: s += " (PCI Power Management Interface)\n"; break;
		case 0x02: s += " (AGP)\n"; break;
		case 0x03: s += " (VPD)\n"; break;
		case 0x04: s += " (Slot Identification)\n"; break;
		case 0x05: s += " (Message Signaled Interrupts)\n"; break;
		case 0x06: s += " (CompactPCI Hot Swap)\n"; break;
		case 0x07: s += " (PCI-X)\n"; break;
		case 0x08: s += " (HyperTransport)\n"; break;
		case 0x09: s += " (Vendor Specific)\n"; break;
		case 0x0a: s += " (Debug port)\n"; break;
		case 0x0b: s += " (CompactPCI central resource control)\n"; break;
		case 0x0c: s += " (PCI Hot-Plug)\n"; break;
		case 0x0d: s += " (PCI Bridge Subsystem Vendor ID)\n"; break;
		case 0x0e: s += " (AGP 8x)\n"; break;
		case 0x0f: s += " (Secure Device)\n"; break;
		case 0x10: s += " (PCI Express)\n"; break;
		case 0x11:
			s += " (MSI-X)\n";
			s += "            Message Control: ";
			s.append_hex64(pci_config_read_uint16(m_bus, m_slot, 0, capp + 2), 4);
			s += "\n            Table Offset: ";
			s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, capp + 4), 8);
			s += "\n            PBA Offset: ";
			s.append_hex64(pci_config_read_uint32(m_bus, m_slot, 0, capp + 8), 8);
			s += "\n";
			break;
		default:
			s += " (Unknown Capability)\n";
		}
		capp = pci_config_read_uint8(m_bus, m_slot, 0, capp + 1) & 0xfc;
	}

	return s;
}

