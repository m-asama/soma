/**
 * @file	memory_pool.cpp
 * @brief	ある型のメモリ領域をまとめて管理するプールを表すクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"

#include "util.h"
#include "memory_management.h"

template<class T>
memory_pool<T>::memory_pool()
	: m_table(nullptr), m_next(nullptr)
{
	//printstr("memory_pool<T>::memory_pool()\n");
}

template<class T>
memory_pool<T>::~memory_pool()
{
	int i;

	//printstr("memory_pool<T>::~memory_pool()\n");

	if (m_next != nullptr) {
		delete m_next;
		m_next = nullptr;
	}

	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		m_free_bits[i] = 0x0000000000000000ul;
	}
	memory_free(m_table);
	m_table = nullptr;
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
		//printstr("sizeof(T) * 64 * memory_pool_free_bits_size = ");
		//printhex64((uint64_t)(sizeof(T) * 64 * memory_pool_free_bits_size));
		//printstr("\n");
	}
/*
	printstr("before free_bits = \n");
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		printhex64(m_free_bits[i]);
		printstr("\n");
	}
*/
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
		if (m_next == nullptr)
			m_next = new memory_pool<T>();
		return m_next->alloc();
	}
/*
	printstr("after free_bits = \n");
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		printhex64(m_free_bits[i]);
		printstr("\n");
	}

	printstr("alloc index = 0x");
	printhex8(index);
	printstr(" alloc address = 0x");
	printhex64((uint64_t)&m_table[index]);
	printstr("\n");
*/
	return &m_table[index];
}

template<class T>
void
memory_pool<T>::free(T *ptr)
{
	int i, j, index;
	char *cp;

	//printstr("memory_pool<T>::free(T *ptr)\n");
/*
	printstr("before free_bits = \n");
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		printhex64(m_free_bits[i]);
		printstr("\n");
	}

	printstr("ptr = ");
	printhex64((uint64_t)ptr);
	printstr(" m_table = ");
	printhex64((uint64_t)m_table);
	printstr(" sizeof(t) = ");
	printhex8(sizeof(T));
	printstr("\n");
*/
	//index = (((uint64_t)ptr) - ((uint64_t)m_table)) / sizeof(T);
	index = (int)(ptr - m_table);
	i = index >> 6;
	j = index & 0x3ful;

	if (index < 0 || index >= (64 * memory_pool_free_bits_size)) {
		printstr("index out of range index = ");
		printhex8(index);
		printstr("\n");
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
/*
	printstr("free index = ");
	printhex8(index);
	printstr(" free address = ");
	printhex64((uint64_t)&m_table[index]);
	printstr("\n");

	printstr("after free_bits = \n");
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		printhex64(m_free_bits[i]);
		printstr("\n");
	}
*/
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

