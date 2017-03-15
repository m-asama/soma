/**
 * @file	virtio_net_pci_device.cpp
 * @brief	VirtIO-Net PCI デバイスクラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "pci_device_management.h"

#include "virtio_net_pci_device.h"

virtio_net_pci_device::virtio_net_pci_device()
{
}

virtio_net_pci_device::~virtio_net_pci_device()
{
}

utf8str
virtio_net_pci_device::pci_dump()
{
	utf8str s(pci_device_base::pci_dump());
	return s;
}

pci_device_base *
virtio_net_pci_device_alloc()
{
	return new virtio_net_pci_device;
}

static struct pci_device_entry virtio_net_pci_device_entries[] = {
	{
		.name		= "VirtIO-Net PCI device(0x1000)",
		.vendor_id	= 0x1af4,
		.device_id	= 0x1000,
		.alloc		= virtio_net_pci_device_alloc,
	},
	{
		.name		= "VirtIO-Net PCI device(0x1041)",
		.vendor_id	= 0x1af4,
		.device_id	= 0x1041,
		.alloc		= virtio_net_pci_device_alloc,
	},
};

bool
virtio_net_pci_device_init()
{
	for (int i = 0; i < (sizeof(virtio_net_pci_device_entries) / sizeof(struct pci_device_entry)); ++i) {
		if (register_pci_device_entry(virtio_net_pci_device_entries[i]) == false) {
			print("Register ");
			print(virtio_net_pci_device_entries[i].name);
			print(" failed.\n");
		}
	}
	return true;
}

