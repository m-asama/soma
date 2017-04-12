/**
 * @file	virtio_net_device_base.cpp
 * @brief	Virtio-Net ネットワークデバイス基底クラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "virtio_net_device_base.h"

virtio_net_device_base::virtio_net_device_base()
	: m_transmit_queue(nullptr), m_receive_queue(nullptr), m_control_queue(nullptr)
{
}

virtio_net_device_base::~virtio_net_device_base()
{
}

