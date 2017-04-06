/**
 * @file	packet_buffer.cpp
 * @brief	パケットバッファを表すクラスの実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "packet_buffer.h"

packet_buffer::packet_buffer()
	: m_head(m_buffer + packet_buffer_initial_head_offset), m_size(0)
{
}

packet_buffer::~packet_buffer()
{
}

packet_buffer::packet_buffer(const packet_buffer &src)
{
	packet_buffer_copy(src, *this);
}

packet_buffer::packet_buffer(packet_buffer &&src)
{
	packet_buffer_copy(src, *this);
}

packet_buffer &
packet_buffer::operator=(const packet_buffer &src)
{
	packet_buffer_copy(src, *this);
	return *this;
}

packet_buffer &
packet_buffer::operator=(packet_buffer &&src)
{
	packet_buffer_copy(src, *this);
	return *this;
}

void *
packet_buffer::operator new(size_t size)
{
	return s_mem_pool.alloc();
}

void
packet_buffer::operator delete(void *ptr)
{
	s_mem_pool.free((packet_buffer *)ptr);
}

uint64_t
packet_buffer::initial_head_address()
{
	return (uint64_t)m_buffer + packet_buffer_initial_head_offset;
}

uint8_t *
packet_buffer::head()
{
	return m_head;
}

uint8_t *
packet_buffer::tail()
{
	return m_head + m_size;
}

uint64_t
packet_buffer::size()
{
	return m_size;
}

bool
packet_buffer::prepend(const uint8_t *data, uint64_t length)
{
	if (length > headroom()) {
		return false;
	}

	m_head -= length;
	m_size += length;
	for (int i = 0; i < length; ++i) {
		m_head[i] = data[i];
	}

	return true;
}

bool
packet_buffer::append(const uint8_t *data, uint64_t length)
{
	if (length > tailroom()) {
		return false;
	}

	uint8_t *tailp = tail();
	m_size += length;
	for (int i = 0; i < length; ++i) {
		tailp[i] = data[i];
	}

	return true;
}

uint64_t
packet_buffer::headroom()
{
	return m_head - m_buffer;
}

uint64_t
packet_buffer::tailroom()
{
	return (m_buffer + packet_buffer_buffer_size) - (m_head + m_size);
}

bool
packet_buffer::head_move(sint64_t offset)
{
	if (((head() + offset) < m_buffer)
	 || ((head() + offset) > (m_buffer + packet_buffer_buffer_size))
	 || ((head() + offset) > tail())) {
		return false;
	}

	m_head += offset;
	m_size -= offset;
	return true;
}

bool
packet_buffer::tail_move(sint64_t offset)
{
	if (((tail() + offset) < m_buffer)
	 || ((tail() + offset) > (m_buffer + packet_buffer_buffer_size))
	 || ((tail() + offset) < head())) {
		return false;
	}

	m_size += offset;
	return true;
}

memory_pool<packet_buffer> packet_buffer::s_mem_pool;

void
packet_buffer_copy(const packet_buffer &src, packet_buffer &dst)
{
	uint64_t offset = (uint64_t)(src.m_head - src.m_buffer);
	for (int i = 0; i < src.m_size; ++i) {
		dst.m_buffer[offset + i] = src.m_buffer[offset + i];
	}
	dst.m_head = src.m_head;
	dst.m_size = src.m_size;
}

packet_buffer *
packet_buffer_from_initial_head_address(uint64_t address)
{
	packet_buffer tmp;
	uint64_t offset = tmp.initial_head_address() - (uint64_t)&tmp;
	return (packet_buffer *)(address - offset);
}

