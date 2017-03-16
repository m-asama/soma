/**
 * @file	virtio_device_base.h
 * @brief	VirtIO デバイス基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * VirtIO デバイス基底クラス。
 */
class virtio_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	virtio_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~virtio_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	virtio_device_base(const virtio_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	virtio_device_base(virtio_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	virtio_device_base &operator=(const virtio_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	virtio_device_base &operator=(virtio_device_base &&src) = delete;

	/**
	 *
	 */
	virtual uint32_t device_features_bits() = 0;

	/**
	 *
	 */
	virtual void driver_features_bits(uint32_t driver_features_bits) = 0;

	/**
	 *
	 */
	virtual uint32_t driver_features_bits() = 0;

	/**
	 *
	 */
	virtual void queue_address(uint32_t queue_address) = 0;

	/**
	 *
	 */
	virtual uint32_t queue_address() = 0;

	/**
	 *
	 */
	virtual uint16_t queue_size() = 0;

	/**
	 *
	 */
	virtual void queue_select(uint16_t queue_select) = 0;

	/**
	 *
	 */
	virtual uint16_t queue_select() = 0;

	/**
	 *
	 */
	virtual void queue_notify(uint16_t queue_notify) = 0;

	/**
	 *
	 */
	virtual uint16_t queue_notify() = 0;

	/**
	 *
	 */
	virtual void device_status(uint8_t device_status) = 0;

	/**
	 *
	 */
	virtual uint8_t device_status() = 0;

	/**
	 *
	 */
	virtual uint8_t isr_status() = 0;

private:

};

