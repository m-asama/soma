/**
 * @file	virtio_device_base.h
 * @brief	VirtIO デバイス基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

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

private:

};

