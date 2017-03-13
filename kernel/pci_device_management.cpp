/**
 * @file	pci_device_management.cpp
 * @brief	PCI デバイス関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"
#include "sorted_list.h"

#include "unknown_pci_device.h"
#include "virtio_net_pci_device.h"

#include "pci_device_management.h"

static sorted_list<struct pci_device_entry> *pci_device_entries = nullptr;

bool
register_pci_device_entry(struct pci_device_entry &entry)
{
	bidir_node<struct pci_device_entry> *bn;
	for (bn = pci_device_entries->head(); bn != nullptr; bn = bn->next()) {
		if (bn->v() == entry) {
			print("register_pci_device_entry: already registered.\n");
			return false;
		}
	}
	return (pci_device_entries->insert(entry) == 0);
}

void
pci_device_init()
{
	pci_device_entries = new sorted_list<struct pci_device_entry>;

	unknown_pci_device_init();
	virtio_net_pci_device_init();

	pci_check_all_buses();
}

