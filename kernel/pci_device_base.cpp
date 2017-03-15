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

