/**
 * @file	packet_buffer.h
 * @brief	パケットバッファを表すクラスの宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "memory_pool.h"

/**
 *
 */
const uint64_t packet_buffer_buffer_size = 10000;

/**
 *
 */
const uint64_t packet_buffer_initial_head_offset = 200;

/**
 *
 */
class packet_buffer {

	friend void packet_buffer_copy(const packet_buffer &src, packet_buffer &dst);

public:
	/**
	 *
	 */
	packet_buffer();

	/**
	 *
	 */
	virtual ~packet_buffer();

	/**
	 *
	 */
	packet_buffer(const packet_buffer &src);

	/**
	 *
	 */
	packet_buffer(packet_buffer &&src);

	/**
	 *
	 */
	packet_buffer &operator=(const packet_buffer &src);

	/**
	 *
	 */
	packet_buffer &operator=(packet_buffer &&src);

	/**
	 *
	 */
	static void *operator new(size_t size);

	/**
	 *
	 */
	static void operator delete(void *ptr);

	/**
	 *
	 */
	uint64_t initial_head_address();

	/**
	 *
	 */
	uint8_t *head();

	/**
	 *
	 */
	uint8_t *tail();

	/**
	 *
	 */
	uint64_t size();

	/**
	 *
	 */
	bool prepend(const uint8_t *data, uint64_t length);

	/**
	 *
	 */
	bool append(const uint8_t *data, uint64_t length);

	/**
	 *
	 */
	uint64_t headroom();

	/**
	 *
	 */
	uint64_t tailroom();

	/**
	 *
	 */
	bool head_move(sint64_t offset);

	/**
	 *
	 */
	bool tail_move(sint64_t offset);

	/**
	 *
	 */
	static packet_buffer *container_of(uint64_t address);

private:
	/**
	 *
	 */
	static memory_pool<packet_buffer> s_mem_pool;

	/**
	 *
	 */
	uint8_t m_buffer[packet_buffer_buffer_size];

	/**
	 *
	 */
	uint8_t *m_head;

	/**
	 *
	 */
	uint64_t m_size;

};

/**
 *
 */
void packet_buffer_copy(const packet_buffer &src, packet_buffer &dst);

/**
 *
 */
packet_buffer *packet_buffer_from_initial_head_address(uint64_t address);

