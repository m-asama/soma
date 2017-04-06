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
class intel64_virtio_pci_device_base : public virtual virtio_device_base, public virtual pci_device_base {

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
	uint32_t device_features_bits();

	/**
	 *
	 */
	void driver_features_bits(uint32_t driver_features_bits);

	/**
	 *
	 */
	uint32_t driver_features_bits();

	/**
	 *
	 */
	void queue_address(uint32_t queue_address);

	/**
	 *
	 */
	uint32_t queue_address();

	/**
	 *
	 */
	uint16_t queue_size();

	/**
	 *
	 */
	void queue_select(uint16_t queue_select);

	/**
	 *
	 */
	uint16_t queue_select();

	/**
	 *
	 */
	void queue_notify(uint16_t queue_notify);

	/**
	 *
	 */
	uint16_t queue_notify();

	/**
	 *
	 */
	void device_status(uint8_t device_status);

	/**
	 *
	 */
	uint8_t device_status();

	/**
	 *
	 */
	uint8_t isr_status();

	/**
	 *
	 */
	uint16_t device_specific_header_offset();

protected:
	/**
	 *
	 */
	sint32_t m_io_base;

};

