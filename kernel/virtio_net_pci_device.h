/**
 * @file	virtio_net_pci_device.h
 * @brief	VirtIO-Net PCI デバイスクラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "virtio_device_base.h"
#include "net_device_base.h"
#include "pci_device_base.h"

/**
 * VirtIO-Net PCI デバイスクラス。
 */
class virtio_net_pci_device : public virtio_device_base, public net_device_base, public pci_device_base {

public:
	/**
	 *
	 */
	virtio_net_pci_device();

	/**
	 *
	 */
	virtual ~virtio_net_pci_device();

	/**
	 *
	 */
	virtio_net_pci_device(const virtio_net_pci_device &src) = delete;

	/**
	 *
	 */
	virtio_net_pci_device(virtio_net_pci_device &&src) = delete;

	/**
	 *
	 */
	virtio_net_pci_device &operator=(const virtio_net_pci_device &src) = delete;

	/**
	 *
	 */
	virtio_net_pci_device &operator=(virtio_net_pci_device &&src) = delete;

	/**
	 *
	 */
	virtual utf8str pci_dump();

private:

};

bool virtio_net_pci_device_init();

