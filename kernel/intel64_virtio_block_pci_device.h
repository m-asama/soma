/**
 * @file	intel64_virtio_block_pci_device.h
 * @brief	VirtIO-Block PCI デバイスクラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "intel64_virtio_pci_device_base.h"
#include "block_device_base.h"

/**
 * VirtIO-Block PCI デバイスクラス。
 */
class intel64_virtio_block_pci_device : public intel64_virtio_pci_device_base, public block_device_base {

public:
	/**
	 *
	 */
	intel64_virtio_block_pci_device();

	/**
	 *
	 */
	virtual ~intel64_virtio_block_pci_device();

	/**
	 *
	 */
	intel64_virtio_block_pci_device(const intel64_virtio_block_pci_device &src) = delete;

	/**
	 *
	 */
	intel64_virtio_block_pci_device(intel64_virtio_block_pci_device &&src) = delete;

	/**
	 *
	 */
	intel64_virtio_block_pci_device &operator=(const intel64_virtio_block_pci_device &src) = delete;

	/**
	 *
	 */
	intel64_virtio_block_pci_device &operator=(intel64_virtio_block_pci_device &&src) = delete;

	/**
	 *
	 */
	virtual void pci_init();

	/**
	 *
	 */
	virtual utf8str pci_dump();

private:

};

bool intel64_virtio_block_pci_device_init();

