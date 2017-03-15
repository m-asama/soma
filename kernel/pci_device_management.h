/**
 * @file	pci_device_management.h
 * @brief	PCI デバイス関連の関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "pci_device_base.h"
#include "console_base.h"

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
uint32_t pci_address(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset);

/**
 *
 */
uint8_t pci_config_read_uint8(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset);

/**
 *
 */
void pci_config_write_uint8(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint8_t val);

/**
 *
 */
uint16_t pci_config_read_uint16(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset);

/**
 *
 */
void pci_config_write_uint16(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint16_t val);

/**
 *
 */
uint32_t pci_config_read_uint32(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset);

/**
 *
 */
void pci_config_write_uint32(uint8_t bus, uint8_t slot, uint8_t function, uint8_t offset, uint32_t val);

/**
 *
 */
uint16_t pci_check_vendor(uint8_t bus, uint8_t slot);

/**
 *
 */
uint16_t pci_check_device(uint8_t bus, uint8_t slot);

/**
 *
 */
void pci_check_all_buses();

/**
 *
 */
pci_device_base *pci_device_alloc(uint16_t vendor_id, uint16_t device_id);

/**
 *
 */
int register_pci_device(pci_device_base &device);

/**
 *
 */
void pci_device_dump(console_base &cb);

/**
 *
 */
bool register_pci_device_entry(struct pci_device_entry &entry);

/**
 *
 */
void pci_device_init();

