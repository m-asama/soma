/**
 * @file	memory_pool.cpp
 * @brief	ある型のメモリ領域をまとめて管理するプールを表すクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "debug.h"

#include "util.h"
#include "memory_management.h"

template<class T>
memory_pool<T>::memory_pool()
	: m_table(nullptr), m_next(nullptr), m_prev(nullptr), m_allocating(false)
{
	//printstr("memory_pool<T>::memory_pool()\n");

	for (int i = 0; i < memory_pool_free_bits_size; ++i) {
		m_free_bits[i] = 0xfffffffffffffffful;
	}
}

template<class T>
memory_pool<T>::~memory_pool()
{
	//printstr("memory_pool<T>::~memory_pool()\n");

	if (m_next != nullptr) {
		delete m_next;
		m_next = nullptr;
		m_prev = nullptr;
	}

	for (int i = 0; i < memory_pool_free_bits_size; ++i) {
		m_free_bits[i] = 0xfffffffffffffffful;
	}

	if (m_table != nullptr) {
		memory_free(m_table);
		m_table = nullptr;
	}
}

template<class T>
T *
memory_pool<T>::alloc()
{
	int i, j, index;

	//printstr("memory_pool<T>::alloc()\n");

	if (m_table == nullptr) {
		for (i = 0; i < memory_pool_free_bits_size; ++i) {
			m_free_bits[i] = 0xfffffffffffffffful;
		}
		//m_table = new T[64 * memory_pool_free_bits_size];
		m_table = (T *)memory_alloc(sizeof(T) * 64 * memory_pool_free_bits_size);
	}

	index = -1;
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		if (count_population_64(m_free_bits[i]) > 0) {
			j = count_training_zero_64(m_free_bits[i]);
			index = i * 64 + j;
			m_free_bits[i] &= ~(1ul << j);
			break;
		}
	}

	if (index < 0) {
		if (m_next == nullptr) {
			m_next = new memory_pool<T>();
			m_next->m_prev = this;
		}
		return m_next->alloc();
	}

	return &m_table[index];
}

template<class T>
void
memory_pool<T>::free(T *ptr)
{
	int i, j, index;
	char *cp;

	//printstr("memory_pool<T>::free(T *ptr)\n");

	//index = (((uint64_t)ptr) - ((uint64_t)m_table)) / sizeof(T);
	index = (int)(ptr - m_table);
	i = index >> 6;
	j = index & 0x3ful;

	if (index < 0 || index >= (64 * memory_pool_free_bits_size)) {
		if (m_next != nullptr)
			m_next->free(ptr);
		return;
	}

	if (m_free_bits[i] & (1ul << j)) {
		printstr("not allocated? index = ");
		printhex8(index);
		printstr("\n");
		return;
	}

	if (ptr != &m_table[index]) {
		printstr("index not match index = ");
		printhex8(index);
		printstr("\n");
		return;
	}

	m_free_bits[i] |= (1ul << j);

	// XXX:
	cp = (char *)ptr;
	for (i = 0; i < sizeof(T); ++i) {
		cp[i] = 0;
	}

	uint64_t count = 0;
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		count += count_population_64(~m_free_bits[i]);
	}
	if (count == 0 && m_table != nullptr) {
		memory_free(m_table);
		m_table = nullptr;
	}
	if (count == 0 && m_prev != nullptr) {
		m_prev->m_next = m_next;
		if (m_next != nullptr) {
			m_next->m_prev = m_prev;
		}
		m_next = nullptr;
		m_prev = nullptr;
		delete this;
	}
}

template<class T>
uint64_t
memory_pool<T>::count()
{
	int i;
	uint64_t count = 0;

	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		count += count_population_64(~m_free_bits[i]);
	}

	if (m_next != nullptr)
		count += m_next->count();

	return count;
}

template<class T>
uint64_t
memory_pool<T>::vacancy()
{
	int i;
	uint64_t vacancy = 0;

	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		vacancy += 64 - count_population_64(~m_free_bits[i]);
	}

	if (m_next != nullptr)
		vacancy += m_next->vacancy();

	return vacancy;
}

