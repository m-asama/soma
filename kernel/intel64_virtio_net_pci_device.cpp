/**
 * @file	intel64_virtio_net_pci_device.cpp
 * @brief	VirtIO-Net PCI デバイスクラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "pci_device_management.h"
#include "intel64_assembly.h"
#include "virtqueue.h"

#include "intel64_virtio_net_pci_device.h"

intel64_virtio_net_pci_device::intel64_virtio_net_pci_device()
{
}

intel64_virtio_net_pci_device::~intel64_virtio_net_pci_device()
{
}

void
intel64_virtio_net_pci_device::pci_init()
{
	intel64_virtio_pci_device_base::pci_init();

	if(msix_capable()) {
		msix_enable(true);
	}

	queue_select(virtio_net_receive_queue_index);
	m_receive_queue = new virtqueue(queue_size());

	queue_select(virtio_net_transmit_queue_index);
	m_transmit_queue = new virtqueue(queue_size());

	queue_select(virtio_net_control_queue_index);
	m_control_queue = new virtqueue(queue_size());
}

utf8str
intel64_virtio_net_pci_device::pci_dump()
{
	utf8str s(intel64_virtio_pci_device_base::pci_dump());
	s += "    MAC Address: ";
	s += mac_utf8str();
	s += "\n";
	s += "    Status: ";
	s.append_hex64(status(), 2);
	s += "\n";
	s += "    Max Virtqueue Pairs: ";
	s.append_hex64(max_virtqueue_pairs(), 2);
	s += "\n";
	s += "    VirtIO Net Supported Features:\n";
	if (device_features_bits() & (1 <<  0)) { s += "        VIRTIO_NET_F_CSUM\n"; }
	if (device_features_bits() & (1 <<  1)) { s += "        VIRTIO_NET_F_GUEST_CSUM\n"; }
	if (device_features_bits() & (1 <<  5)) { s += "        VIRTIO_NET_F_MAC\n"; }
	if (device_features_bits() & (1 <<  6)) { s += "        VIRTIO_NET_F_GSO\n"; }
	if (device_features_bits() & (1 <<  7)) { s += "        VIRTIO_NET_F_GUEST_TSO4\n"; }
	if (device_features_bits() & (1 <<  8)) { s += "        VIRTIO_NET_F_GUEST_TSO6\n"; }
	if (device_features_bits() & (1 <<  9)) { s += "        VIRTIO_NET_F_GUEST_ECN\n"; }
	if (device_features_bits() & (1 << 10)) { s += "        VIRTIO_NET_F_GUEST_UFO\n"; }
	if (device_features_bits() & (1 << 11)) { s += "        VIRTIO_NET_F_HOST_TSO4\n"; }
	if (device_features_bits() & (1 << 12)) { s += "        VIRTIO_NET_F_HOST_TSO6\n"; }
	if (device_features_bits() & (1 << 13)) { s += "        VIRTIO_NET_F_HOST_ECN\n"; }
	if (device_features_bits() & (1 << 14)) { s += "        VIRTIO_NET_F_HOST_UFO\n"; }
	if (device_features_bits() & (1 << 15)) { s += "        VIRTIO_NET_F_MRG_RXBUF\n"; }
	if (device_features_bits() & (1 << 16)) { s += "        VIRTIO_NET_F_STATUS\n"; }
	if (device_features_bits() & (1 << 17)) { s += "        VIRTIO_NET_F_CTRL_VQ\n"; }
	if (device_features_bits() & (1 << 18)) { s += "        VIRTIO_NET_F_CTRL_RX\n"; }
	if (device_features_bits() & (1 << 19)) { s += "        VIRTIO_NET_F_CTRL_VLAN\n"; }
	if (device_features_bits() & (1 << 21)) { s += "        VIRTIO_NET_F_GUEST_ANNOUNCE\n"; }
	return s;
}

void
intel64_virtio_net_pci_device::set_mac(uint8_t *mac)
{
	uint16_t offset = device_specific_header_offset();
	outb(m_io_base + offset + 0x00, mac[0]);
	outb(m_io_base + offset + 0x01, mac[1]);
	outb(m_io_base + offset + 0x02, mac[2]);
	outb(m_io_base + offset + 0x03, mac[3]);
	outb(m_io_base + offset + 0x04, mac[4]);
	outb(m_io_base + offset + 0x05, mac[5]);
}

void
intel64_virtio_net_pci_device::get_mac(uint8_t *mac)
{
	uint16_t offset = device_specific_header_offset();
	mac[0] = inb(m_io_base + offset + 0x00);
	mac[1] = inb(m_io_base + offset + 0x01);
	mac[2] = inb(m_io_base + offset + 0x02);
	mac[3] = inb(m_io_base + offset + 0x03);
	mac[4] = inb(m_io_base + offset + 0x04);
	mac[5] = inb(m_io_base + offset + 0x05);
}

utf8str
intel64_virtio_net_pci_device::mac_utf8str()
{
	uint16_t offset = device_specific_header_offset();
	utf8str mac_utf8str;
	mac_utf8str.append_hex64(inb(m_io_base + offset + 0x00), 2);
	mac_utf8str += ":";
	mac_utf8str.append_hex64(inb(m_io_base + offset + 0x01), 2);
	mac_utf8str += ":";
	mac_utf8str.append_hex64(inb(m_io_base + offset + 0x02), 2);
	mac_utf8str += ":";
	mac_utf8str.append_hex64(inb(m_io_base + offset + 0x03), 2);
	mac_utf8str += ":";
	mac_utf8str.append_hex64(inb(m_io_base + offset + 0x04), 2);
	mac_utf8str += ":";
	mac_utf8str.append_hex64(inb(m_io_base + offset + 0x05), 2);
	return mac_utf8str;
}

void
intel64_virtio_net_pci_device::status(uint16_t status)
{
	uint16_t offset = device_specific_header_offset();
	outw(m_io_base + offset + 0x06, status);
}

uint16_t
intel64_virtio_net_pci_device::status()
{
	uint16_t offset = device_specific_header_offset();
	return inw(m_io_base + offset + 0x06);
}

void
intel64_virtio_net_pci_device::max_virtqueue_pairs(uint16_t max_virtqueue_pairs)
{
	uint16_t offset = device_specific_header_offset();
	outw(m_io_base + offset + 0x08, max_virtqueue_pairs);
}

uint16_t
intel64_virtio_net_pci_device::max_virtqueue_pairs()
{
	uint16_t offset = device_specific_header_offset();
	return inw(m_io_base + offset + 0x08);
}

pci_device_base *
intel64_virtio_net_pci_device_alloc()
{
	return new intel64_virtio_net_pci_device;
}

static struct pci_device_entry intel64_virtio_net_pci_device_entries[] = {
	{
		.name		= "VirtIO-Net PCI device(0x1000)",
		.vendor_id	= 0x1af4,
		.device_id	= 0x1000,
		.alloc		= intel64_virtio_net_pci_device_alloc,
	},
/*
	{
		.name		= "VirtIO-Net PCI device(0x1041)",
		.vendor_id	= 0x1af4,
		.device_id	= 0x1041,
		.alloc		= intel64_virtio_net_pci_device_alloc,
	},
*/
};

bool
intel64_virtio_net_pci_device_init()
{
	for (int i = 0; i < (sizeof(intel64_virtio_net_pci_device_entries) / sizeof(struct pci_device_entry)); ++i) {
		if (register_pci_device_entry(intel64_virtio_net_pci_device_entries[i]) == false) {
			print("Register ");
			print(intel64_virtio_net_pci_device_entries[i].name);
			print(" failed.\n");
		}
	}
	return true;
}

