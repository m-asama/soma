/**
 * @file	virtqueue.h
 * @brief	VirtIO Virtqueue 関連の宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 *
 */
class virtqueue {

public:
	/**
	 *
	 */
	virtqueue() = delete;

	/**
	 *
	 */
	virtqueue(uint16_t queue_size);

	/**
	 *
	 */
	virtual ~virtqueue();

	/**
	 *
	 */
	virtqueue(const virtqueue &src) = delete;

	/**
	 *
	 */
	virtqueue(virtqueue &&src) = delete;

	/**
	 *
	 */
	virtqueue &operator=(const virtqueue &src) = delete;

	/**
	 *
	 */
	virtqueue &operator=(virtqueue &&src) = delete;

	/**
	 *
	 */
	uint16_t queue_size();

	/**
	 *
	 */
	uint8_t *base();

	/**
	 *
	 */
	uint8_t *ring_descriptor();

	/**
	 *
	 */
	uint8_t *ring_available();

	/**
	 *
	 */
	uint8_t *ring_used();

	/**
	 *
	 */
	sint32_t ring_descriptor_alloc();

	/**
	 *
	 */
	void ring_descriptor_free(uint16_t index);

	/**
	 *
	 */
	uint16_t allocated_descriptor_count();

	/**
	 *
	 */
	void descriptor_address(uint16_t index, uint64_t address);

	/**
	 *
	 */
	uint64_t descriptor_address(uint16_t index);

	/**
	 *
	 */
	void descriptor_length(uint16_t index, uint32_t length);

	/**
	 *
	 */
	uint32_t descriptor_length(uint16_t index);

	/**
	 *
	 */
	void descriptor_flag_next(uint16_t index, bool next);

	/**
	 *
	 */
	bool descriptor_flag_next(uint16_t index);

	/**
	 *
	 */
	void descriptor_flag_write(uint16_t index, bool write);

	/**
	 *
	 */
	bool descriptor_flag_write(uint16_t index);

	/**
	 *
	 */
	void descriptor_flag_indirect(uint16_t index, bool indirect);

	/**
	 *
	 */
	bool descriptor_flag_indirect(uint16_t index);

	/**
	 *
	 */
	void descriptor_next(uint16_t index, uint16_t next);

	/**
	 *
	 */
	uint16_t descriptor_next(uint16_t index);

	/**
	 *
	 */
	void available_flag_no_interrupt(bool no_interrupt);

	/**
	 *
	 */
	bool available_flag_no_interrupt();

	/**
	 *
	 */
	void available_index(uint16_t index);

	/**
	 *
	 */
	uint16_t available_index();

	/**
	 *
	 */
	void available_ring(uint16_t at, uint16_t index);

	/**
	 *
	 */
	uint16_t available_ring(uint16_t at);

	/**
	 *
	 */
	void available_used_event(uint16_t used_event);

	/**
	 *
	 */
	uint16_t available_used_event();

	/**
	 *
	 */
	void used_flag_no_notify(bool no_notify);

	/**
	 *
	 */
	bool used_flag_no_notify();

	/**
	 *
	 */
	void used_index(uint16_t index);

	/**
	 *
	 */
	uint16_t used_index();

	/**
	 *
	 */
	void used_ring_index(uint16_t at, uint32_t index);

	/**
	 *
	 */
	uint32_t used_ring_index(uint16_t at);

	/**
	 *
	 */
	void used_ring_length(uint16_t at, uint32_t length);

	/**
	 *
	 */
	uint32_t used_ring_length(uint16_t at);

	/**
	 *
	 */
	void used_ring_available_event(uint16_t available_event);

	/**
	 *
	 */
	uint16_t used_ring_available_event();

private:
	/**
	 *
	 */
	uint16_t m_queue_size;

	/**
	 *
	 */
	uint8_t *m_base;

	/**
	 *
	 */
	uint8_t *m_ring_descriptor;

	/**
	 *
	 */
	uint8_t *m_ring_available;

	/**
	 *
	 */
	uint8_t *m_ring_used;

	/**
	 *
	 */
	uint64_t *m_free_descriptor_bits;

	/**
	 *
	 */
	uint64_t m_free_descriptor_bits_size;

	/**
	 *
	 */
	uint16_t m_allocated_descriptor_count;

};

