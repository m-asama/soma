/**
 * @file	unknown_pci_device.cpp
 * @brief	未知の PCI デバイスクラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "pci_device_management.h"

#include "unknown_pci_device.h"

unknown_pci_device::unknown_pci_device()
{
}

unknown_pci_device::~unknown_pci_device()
{
}

pci_device_base *
unknown_pci_device_alloc()
{
	return new unknown_pci_device;
}

static struct pci_device_entry unknown_pci_device_entries[] = {
	{
		.name		= "Unknown PCI device",
		.vendor_id	= 0xffff,
		.device_id	= 0xffff,
		.alloc		= unknown_pci_device_alloc,
	},
};

bool
unknown_pci_device_init()
{
	for (int i = 0; i < (sizeof(unknown_pci_device_entries) / sizeof(struct pci_device_entry)); ++i) {
		if (register_pci_device_entry(unknown_pci_device_entries[i]) == false) {
			print("Register ");
			print(unknown_pci_device_entries[i].name);
			print(" failed.\n");
		}
	}
	return true;
}

