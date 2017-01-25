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
	if (m_table == nullptr) {
		m_table = (T *)memory_alloc(sizeof(T) * 64 * memory_pool_free_bits_size);
	}
	for (int i = 0; i < memory_pool_free_bits_size; ++i) {
		m_free_bits[i] = 0xfffffffffffffffful;
	}
}

template<class T>
memory_pool<T>::~memory_pool()
{
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

	memory_pool<T> *head = this->head();
	memory_pool<T> *tail = this->tail();

	if (m_table == nullptr) {
		for (i = 0; i < memory_pool_free_bits_size; ++i) {
			m_free_bits[i] = 0xfffffffffffffffful;
		}
		m_table = (T *)memory_alloc(sizeof(T) * 64 * memory_pool_free_bits_size);
	}

	if ((head->m_allocating == false)
	 && (head->vacancy() < memory_pool_vacancy_threshold1)) {
		head->m_allocating = true;
		if (tail->m_next == nullptr) {
			tail->m_next = new memory_pool<T>();
			tail->m_next->m_prev = tail;
		}
		head->m_allocating = false;
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

	memory_pool<T> *head = this->head();
	//memory_pool<T> *tail = this->tail();

	index = (int)(ptr - m_table);
	i = index >> 6;
	j = index & 0x3ful;

	if (index < 0 || index >= (64 * memory_pool_free_bits_size)) {
		if (m_next != nullptr)
			m_next->free(ptr);
		return;
	}

	if (m_free_bits[i] & (1ul << j)) {
		print("not allocated? index = ");
		printhex8(index);
		print("\n");
		return;
	}

	if (ptr != &m_table[index]) {
		print("index not match index = ");
		printhex8(index);
		print("\n");
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
/*
	if (count == 0 && m_table != nullptr) {
		memory_free(m_table);
		m_table = nullptr;
	}
*/
	if ((count == 0 && m_prev != nullptr)
	 && (head->vacancy() > memory_pool_vacancy_threshold2)) {
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
memory_pool<T> *
memory_pool<T>::head()
{
	memory_pool<T> *head = this;
	while (head->m_prev != nullptr) {
		head = head->m_prev;
	}
	return head;
}

template<class T>
memory_pool<T> *
memory_pool<T>::tail()
{
	memory_pool<T> *tail = this;
	while (tail->m_next != nullptr) {
		tail = tail->m_next;
	}
	return tail;
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

