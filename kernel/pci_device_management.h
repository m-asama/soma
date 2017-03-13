/**
 * @file	pci_device_management.h
 * @brief	PCI デバイス関連の関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "pci_device_base.h"

/**
 *
 */
struct pci_device_entry {
	char const *name;
	uint16_t vendor_id;
	uint16_t device_id;
	pci_device_base *(*alloc)();
	bool operator==(const struct pci_device_entry &rhs) {
		if ((vendor_id == rhs.vendor_id)
		 && (device_id == rhs.device_id)) {
			return true;
		}
		return false;
	}
	bool operator>(const struct pci_device_entry &rhs) {
		if ((vendor_id > rhs.vendor_id)
		 || ((vendor_id == rhs.vendor_id)
		  && (device_id > rhs.device_id))) {
			return true;
		}
		return false;
	}
};

/**
 *
 */
void pci_check_all_buses();

/**
 *
 */
bool register_pci_device_entry(struct pci_device_entry &entry);

/**
 *
 */
void pci_device_init();

