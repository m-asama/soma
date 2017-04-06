/**
 * @file	virtqueue.cpp
 * @brief	VirtIO Virtqueue 関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "util.h"
#include "memory_management.h"

#include "virtqueue.h"

virtqueue::virtqueue(uint16_t queue_size)
	: m_base(nullptr), m_ring_descriptor(nullptr), m_ring_available(nullptr), m_ring_used(nullptr),
	  m_free_descriptor_bits(nullptr), m_allocated_descriptor_count(0)
{
	uint64_t alloc_size, descriptor_size, first_block_size;

	descriptor_size = 16 * queue_size;
	alloc_size = descriptor_size + 2 * (2 + queue_size);
	round_up_64(alloc_size, 0x1000);
	first_block_size = alloc_size;
	alloc_size += 8 * queue_size;
	round_up_64(alloc_size, 0x1000);

	m_queue_size = queue_size;
	m_base = (uint8_t *)memory_alloc_page_lo(memory_page_size::page_size_4k, (alloc_size >> 12));
	uint64_t *p = (uint64_t *)m_base;
	for (int i = 0; i < (alloc_size >> 6); ++i) {
		p[i] = 0x0000000000000000ull;
	}
	m_ring_descriptor = m_base;
	m_ring_available = m_base + descriptor_size;
	m_ring_used = m_base + first_block_size;

	uint64_t bit_count = queue_size;
	round_up_64(bit_count, 64);
	m_free_descriptor_bits = (uint64_t *)memory_alloc(sizeof(uint64_t) * (bit_count >> 6));
	m_free_descriptor_bits_size = bit_count >> 6;
	for (int i = 0; i < m_free_descriptor_bits_size; ++i) {
		m_free_descriptor_bits[i] = 0xffffffffffffffffull;
	}

}

virtqueue::~virtqueue()
{
}

uint16_t
virtqueue::queue_size()
{
	return m_queue_size;
}

uint8_t *
virtqueue::base()
{
	return m_base;
}

uint8_t *
virtqueue::ring_descriptor()
{
	return m_ring_descriptor;
}

uint8_t *
virtqueue::ring_available()
{
	return m_ring_available;
}

uint8_t *
virtqueue::ring_used()
{
	return m_ring_used;
}

sint32_t
virtqueue::ring_descriptor_alloc()
{
	sint32_t index = -1;

	if (m_allocated_descriptor_count == m_queue_size) {
		return index;
	}

	for (int i = 0; i < m_free_descriptor_bits_size; ++i) {
		if (count_population_64(m_free_descriptor_bits[i]) > 0) {
			int j = count_training_zero_64(m_free_descriptor_bits[i]);
			index = i * 64 + j;
			m_free_descriptor_bits[i] &= ~(1ul << j);
			++m_allocated_descriptor_count;
			break;
		}
	}

	return index;
}

void
virtqueue::ring_descriptor_free(uint16_t index)
{
	int i, j;

	i = index >> 6;
	j = index & 0x3ful;

	if ((m_free_descriptor_bits[i] & (1ul << j)) == 0) {
		--m_allocated_descriptor_count;
	}

	m_free_descriptor_bits[i] |= (1ul << j);
}

uint16_t
virtqueue::allocated_descriptor_count()
{
	return m_allocated_descriptor_count;
}

void
virtqueue::descriptor_address(uint16_t index, uint64_t address)
{
	uint64_t *p = (uint64_t *)m_ring_descriptor + 16 * index;
	*p = address;
}

uint64_t
virtqueue::descriptor_address(uint16_t index)
{
	uint64_t *p = (uint64_t *)m_ring_descriptor + 16 * index;
	return *p;
}

void
virtqueue::descriptor_length(uint16_t index, uint32_t length)
{
	uint32_t *p = (uint32_t *)m_ring_descriptor + 16 * index + 8;
	*p = length;
}

uint32_t
virtqueue::descriptor_length(uint16_t index)
{
	uint32_t *p = (uint32_t *)m_ring_descriptor + 16 * index + 8;
	return *p;
}

void
virtqueue::descriptor_flag_next(uint16_t index, bool next)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 12;
	*p = *p & 0xfffe;
	if (next) {
		*p = *p | 0x0001;
	}
}

bool
virtqueue::descriptor_flag_next(uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 12;
	bool next = false;
	if ((*p & 0x0001) == 0x0001) {
		next = true;
	}
	return next;
}

void
virtqueue::descriptor_flag_write(uint16_t index, bool write)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 12;
	*p = *p & 0xfffd;
	if (write) {
		*p = *p | 0x0002;
	}
}

bool
virtqueue::descriptor_flag_write(uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 12;
	bool write = false;
	if ((*p & 0x0002) == 0x0002) {
		write = true;
	}
	return write;
}

void
virtqueue::descriptor_flag_indirect(uint16_t index, bool indirect)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 12;
	*p = *p & 0xfffb;
	if (indirect) {
		*p = *p | 0x0004;
	}
}

bool
virtqueue::descriptor_flag_indirect(uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 12;
	bool indirect = false;
	if ((*p & 0x0004) == 0x0004) {
		indirect = true;
	}
	return indirect;
}

void
virtqueue::descriptor_next(uint16_t index, uint16_t next)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 14;
	*p = next;
}

uint16_t
virtqueue::descriptor_next(uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_descriptor + 16 * index + 14;
	return *p;
}

void
virtqueue::available_flag_no_interrupt(bool no_interrupt)
{
	uint16_t *p = (uint16_t *)m_ring_available;
	*p = *p & 0xfffe;
	if (no_interrupt) {
		*p = *p | 0x0001;
	}
}

bool
virtqueue::available_flag_no_interrupt()
{
	uint16_t *p = (uint16_t *)m_ring_available;
	bool no_interrupt = false;
	if ((*p & 0x0001) == 0x0001) {
		no_interrupt = true;
	}
	return no_interrupt;
}

void
virtqueue::available_index(uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_available + 2;
	*p = index;
}

uint16_t
virtqueue::available_index()
{
	uint16_t *p = (uint16_t *)m_ring_available + 2;
	return *p;
}

void
virtqueue::available_ring(uint16_t at, uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_available + 4 + 2 * at;
	*p = index;
}

uint16_t
virtqueue::available_ring(uint16_t at)
{
	uint16_t *p = (uint16_t *)m_ring_available + 4 + 2 * at;
	return *p;
}

void
virtqueue::available_used_event(uint16_t used_event)
{
	uint16_t *p = (uint16_t *)m_ring_available + 4 + 2 * m_queue_size;
	*p = used_event;
}

uint16_t
virtqueue::available_used_event()
{
	uint16_t *p = (uint16_t *)m_ring_available + 4 + 2 * m_queue_size;
	return *p;
}

void
virtqueue::used_flag_no_notify(bool no_notify)
{
	uint16_t *p = (uint16_t *)m_ring_used;
	*p = *p & 0xfffe;
	if (no_notify) {
		*p = *p | 0x0001;
	}
}

bool
virtqueue::used_flag_no_notify()
{
	uint16_t *p = (uint16_t *)m_ring_used;
	bool no_notify = false;
	if ((*p & 0x0001) == 0x0001) {
		no_notify = true;
	}
	return no_notify;
}

void
virtqueue::used_index(uint16_t index)
{
	uint16_t *p = (uint16_t *)m_ring_used + 2;
	*p = index;
}

uint16_t
virtqueue::used_index()
{
	uint16_t *p = (uint16_t *)m_ring_used + 2;
	return *p;
}

void
virtqueue::used_ring_index(uint16_t at, uint32_t index)
{
	uint32_t *p = (uint32_t *)m_ring_used + 4 + 8 * at;
	*p = index;
}

uint32_t
virtqueue::used_ring_index(uint16_t at)
{
	uint32_t *p = (uint32_t *)m_ring_used + 4 + 8 * at;
	return *p;
}

void
virtqueue::used_ring_length(uint16_t at, uint32_t length)
{
	uint32_t *p = (uint32_t *)m_ring_used + 4 + 8 * at + 4;
	*p = length;
}

uint32_t
virtqueue::used_ring_length(uint16_t at)
{
	uint32_t *p = (uint32_t *)m_ring_used + 4 + 8 * at + 4;
	return *p;
}

void
virtqueue::used_ring_available_event(uint16_t available_event)
{
	uint16_t *p = (uint16_t *)m_ring_used + 4 + 8 * m_queue_size;
	*p = available_event;
}

uint16_t
virtqueue::used_ring_available_event()
{
	uint16_t *p = (uint16_t *)m_ring_used + 4 + 8 * m_queue_size;
	return *p;
}

