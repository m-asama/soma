/**
 * @file	virtio_net_device_base.h
 * @brief	Virtio-Net ネットワークデバイス基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "virtio_device_base.h"
#include "net_device_base.h"
#include "virtqueue.h"

/**
 *
 */
const uint16_t virtio_net_receive_queue_index = 0;

/**
 *
 */
const uint16_t virtio_net_transmit_queue_index = 1;

/**
 *
 */
const uint16_t virtio_net_control_queue_index = 2;

/**
 * Virtio-Net ネットワークデバイス基底クラス。
 */
class virtio_net_device_base : public virtual virtio_device_base, public net_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	virtio_net_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~virtio_net_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	virtio_net_device_base(const virtio_net_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	virtio_net_device_base(virtio_net_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	virtio_net_device_base &operator=(const virtio_net_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	virtio_net_device_base &operator=(virtio_net_device_base &&src) = delete;

protected:
	/**
	 *
	 */
	virtqueue *m_transmit_queue;

	/**
	 *
	 */
	virtqueue *m_receive_queue;

	/**
	 *
	 */
	virtqueue *m_control_queue;

};

