/**
 * @file	virtio_block_device_base.h
 * @brief	Virtio-Block ブロックデバイス基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "virtio_device_base.h"
#include "block_device_base.h"

/**
 * Virtio-Block ブロックデバイス基底クラス。
 */
class virtio_block_device_base : public virtual virtio_device_base, public block_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	virtio_block_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~virtio_block_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	virtio_block_device_base(const virtio_block_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	virtio_block_device_base(virtio_block_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	virtio_block_device_base &operator=(const virtio_block_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	virtio_block_device_base &operator=(virtio_block_device_base &&src) = delete;

protected:

};

