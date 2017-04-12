/**
 * @file	intel64_virtio_pci_device_base.cpp
 * @brief	Virtio PCI デバイス基底クラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "pci_device_management.h"
#include "intel64_assembly.h"

#include "intel64_virtio_pci_device_base.h"

intel64_virtio_pci_device_base::intel64_virtio_pci_device_base()
	: m_io_base(-1)
{
}

intel64_virtio_pci_device_base::~intel64_virtio_pci_device_base()
{
}

utf8str
intel64_virtio_pci_device_base::pci_dump()
{
        utf8str s(pci_device_base::pci_dump());
        s += "    Device Features Bits: ";
        s.append_hex64(device_features_bits(), 8);
        s += "\n";
        s += "    Driver Features Bits: ";
        s.append_hex64(driver_features_bits(), 8);
        s += "\n";
        s += "    Queue Address: ";
        s.append_hex64(queue_address(), 8);
        s += "\n";
        s += "    Queue Size: ";
        s.append_hex64(queue_size(), 4);
        s += "\n";
        s += "    Queue Select: ";
        s.append_hex64(queue_select(), 4);
        s += "\n";
        s += "    Queue Notify: ";
        s.append_hex64(queue_notify(), 4);
        s += "\n";
        s += "    Device Status: ";
        s.append_hex64(device_status(), 2);
        s += "\n";
        s += "    ISR Status: ";
        s.append_hex64(isr_status(), 2);
        s += "\n";
	s += "    Virtqueues:\n";
	for (int i = 0; i < 8; ++i) {
		queue_select(i);
		if (queue_size() == 0) {
			break;
		}
		s += "        ";
		s.append_hex64(i, 2);
		s += " Queue Address: ";
		s.append_hex64(queue_address(), 8);
		s += " Queue Size: ";
		s.append_hex64(queue_size(), 4);
		s += "\n";
	}
	s += "    VirtIO Supported Features:\n";
	if (device_features_bits() & (1 << 24)) { s += "        VIRTIO_F_NOTIFY_ON_EMPTY\n"; }
	if (device_features_bits() & (1 << 28)) { s += "        VIRTIO_F_RING_INDIRECT_DESC\n"; }
	if (device_features_bits() & (1 << 29)) { s += "        VIRTIO_F_RING_EVENT_IDX\n"; }
        return s;
}

void
intel64_virtio_pci_device_base::pci_init()
{
	m_io_base = base_address_register_0() & 0xfffffff0;
}

uint32_t
intel64_virtio_pci_device_base::device_features_bits()
{
	return inl(m_io_base + 0x00);
}

void
intel64_virtio_pci_device_base::driver_features_bits(uint32_t driver_features_bits)
{
	outl(m_io_base + 0x04, driver_features_bits);
}

uint32_t
intel64_virtio_pci_device_base::driver_features_bits()
{
	return inl(m_io_base + 0x04);
}

void
intel64_virtio_pci_device_base::queue_address(uint32_t queue_address)
{
	outl(m_io_base + 0x08, queue_address);
}

uint32_t
intel64_virtio_pci_device_base::queue_address()
{
	return inl(m_io_base + 0x08);
}

uint16_t
intel64_virtio_pci_device_base::queue_size()
{
	return inw(m_io_base + 0x0c);
}

void
intel64_virtio_pci_device_base::queue_select(uint16_t queue_select)
{
	outw(m_io_base + 0x0e, queue_select);
}

uint16_t
intel64_virtio_pci_device_base::queue_select()
{
	return inw(m_io_base + 0x0e);
}

void
intel64_virtio_pci_device_base::queue_notify(uint16_t queue_notify)
{
	outw(m_io_base + 0x10, queue_notify);
}

uint16_t
intel64_virtio_pci_device_base::queue_notify()
{
	return inw(m_io_base + 0x10);
}

void
intel64_virtio_pci_device_base::device_status(uint8_t device_status)
{
	outb(m_io_base + 0x12, device_status);
}

uint8_t
intel64_virtio_pci_device_base::device_status()
{
	return inb(m_io_base + 0x12);
}

uint8_t
intel64_virtio_pci_device_base::isr_status()
{
	return inb(m_io_base + 0x13);
}

uint16_t
intel64_virtio_pci_device_base::device_specific_header_offset()
{
	uint16_t device_specific_header_offset = 0x14;
	if (msix_enable()) {
		device_specific_header_offset += 0x04;
	}
	return device_specific_header_offset;
}

