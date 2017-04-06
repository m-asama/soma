/**
 * @file	intel64_virtio_net_pci_device.h
 * @brief	VirtIO-Net PCI デバイスクラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "intel64_virtio_pci_device_base.h"
#include "virtio_net_device_base.h"

/**
 * VirtIO-Net PCI デバイスクラス。
 */
class intel64_virtio_net_pci_device : public intel64_virtio_pci_device_base, public virtio_net_device_base {

public:
	/**
	 *
	 */
	intel64_virtio_net_pci_device();

	/**
	 *
	 */
	virtual ~intel64_virtio_net_pci_device();

	/**
	 *
	 */
	intel64_virtio_net_pci_device(const intel64_virtio_net_pci_device &src) = delete;

	/**
	 *
	 */
	intel64_virtio_net_pci_device(intel64_virtio_net_pci_device &&src) = delete;

	/**
	 *
	 */
	intel64_virtio_net_pci_device &operator=(const intel64_virtio_net_pci_device &src) = delete;

	/**
	 *
	 */
	intel64_virtio_net_pci_device &operator=(intel64_virtio_net_pci_device &&src) = delete;

	/**
	 *
	 */
	virtual void pci_init();

	/**
	 *
	 */
	virtual utf8str pci_dump();

	/**
	 *
	 */
	void set_mac(uint8_t *mac);

	/**
	 *
	 */
	void get_mac(uint8_t *mac);

	/**
	 *
	 */
	utf8str mac_utf8str();

	/**
	 *
	 */
	void status(uint16_t status);

	/**
	 *
	 */
	uint16_t status();

	/**
	 *
	 */
	void max_virtqueue_pairs(uint16_t max_virtqueue_pairs);

	/**
	 *
	 */
	uint16_t max_virtqueue_pairs();

private:

};

bool intel64_virtio_net_pci_device_init();

