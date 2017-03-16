/**
 * @file	intel64_virtio_block_pci_device.cpp
 * @brief	VirtIO-Block PCI デバイスクラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "pci_device_management.h"

#include "intel64_virtio_block_pci_device.h"

intel64_virtio_block_pci_device::intel64_virtio_block_pci_device()
{
}

intel64_virtio_block_pci_device::~intel64_virtio_block_pci_device()
{
}

void
intel64_virtio_block_pci_device::pci_init()
{
	intel64_virtio_pci_device_base::pci_init();
}

utf8str
intel64_virtio_block_pci_device::pci_dump()
{
	utf8str s(intel64_virtio_pci_device_base::pci_dump());
	return s;
}

pci_device_base *
intel64_virtio_block_pci_device_alloc()
{
	return new intel64_virtio_block_pci_device;
}

static struct pci_device_entry intel64_virtio_block_pci_device_entries[] = {
	{
		.name		= "VirtIO-Block PCI device(0x1001)",
		.vendor_id	= 0x1af4,
		.device_id	= 0x1001,
		.alloc		= intel64_virtio_block_pci_device_alloc,
	},
/*
	{
		.name		= "VirtIO-Block PCI device(0x1042)",
		.vendor_id	= 0x1af4,
		.device_id	= 0x1042,
		.alloc		= intel64_virtio_block_pci_device_alloc,
	},
*/
};

bool
intel64_virtio_block_pci_device_init()
{
	for (int i = 0; i < (sizeof(intel64_virtio_block_pci_device_entries) / sizeof(struct pci_device_entry)); ++i) {
		if (register_pci_device_entry(intel64_virtio_block_pci_device_entries[i]) == false) {
			print("Register ");
			print(intel64_virtio_block_pci_device_entries[i].name);
			print(" failed.\n");
		}
	}
	return true;
}

