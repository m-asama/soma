/**
 * @file	intel64_virtio_pci_device_base.h
 * @brief	Virtio PCI デバイスの基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "virtio_device_base.h"

/**
 * Virtio PCI デバイスの基底クラス宣言。
 */
class intel64_virtio_pci_device_base : public virtio_device_base, public pci_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_virtio_pci_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_virtio_pci_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_virtio_pci_device_base(const intel64_virtio_pci_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_virtio_pci_device_base(intel64_virtio_pci_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_virtio_pci_device_base &operator=(const intel64_virtio_pci_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_virtio_pci_device_base &operator=(intel64_virtio_pci_device_base &&src) = delete;

	/**
	 *
	 */
	virtual utf8str pci_dump();

	/**
	 *
	 */
	virtual void pci_init();

	/**
	 *
	 */
	virtual uint32_t device_features_bits();

	/**
	 *
	 */
	virtual void driver_features_bits(uint32_t driver_features_bits);

	/**
	 *
	 */
	virtual uint32_t driver_features_bits();

	/**
	 *
	 */
	virtual void queue_address(uint32_t queue_address);

	/**
	 *
	 */
	virtual uint32_t queue_address();

	/**
	 *
	 */
	virtual uint16_t queue_size();

	/**
	 *
	 */
	virtual void queue_select(uint16_t queue_select);

	/**
	 *
	 */
	virtual uint16_t queue_select();

	/**
	 *
	 */
	virtual void queue_notify(uint16_t queue_notify);

	/**
	 *
	 */
	virtual uint16_t queue_notify();

	/**
	 *
	 */
	virtual void device_status(uint8_t device_status);

	/**
	 *
	 */
	virtual uint8_t device_status();

	/**
	 *
	 */
	virtual uint8_t isr_status();

protected:
	/**
	 *
	 */
	sint32_t m_io_base;

};

