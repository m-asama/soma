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

static sorted_list<pci_device_base> *pci_devices = nullptr;

pci_device_base *
pci_device_alloc(uint16_t vendor_id, uint16_t device_id)
{
	bidir_node<struct pci_device_entry> *bn;
	for (bn = pci_device_entries->head(); bn != nullptr; bn = bn->next()) {
		if ((bn->v().vendor_id == vendor_id)
		 && (bn->v().device_id == device_id)) {
			return bn->v().alloc();
		}
	}
	return unknown_pci_device_alloc();
}

int
register_pci_device(pci_device_base &device)
{
	return pci_devices->insert(device);
}

void
pci_device_dump(console_base &cb)
{
	bidir_node<pci_device_base> *bn;
	for (bn = pci_devices->head(); bn != nullptr; bn = bn->next()) {
		cb.print(bn->v().pci_dump());
	}
}

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
	pci_devices = new sorted_list<pci_device_base>;
	pci_device_entries = new sorted_list<struct pci_device_entry>;

	unknown_pci_device_init();
	virtio_net_pci_device_init();

	pci_check_all_buses();
}

