/**
 * @file	memory_pool.h
 * @brief	ある型のメモリ領域をまとめて管理するプールを表すクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

const int memory_pool_free_bits_size = 8;

template<class T>
class memory_pool {

	friend void memory_init(struct loader_info *li);

public:
	/*
	 *
	 */
	memory_pool();

	/*
	 *
	 */
	virtual ~memory_pool();

	/*
	 *
	 */
	T *alloc();

	/*
	 *
	 */
	void free(T *ptr);

	/*
	 *
	 */
	uint64_t count();

private:
	/*
	 *
	 */
	memory_pool(const memory_pool<T> &src);

	/*
	 *
	 */
	void operator=(const memory_pool<T> &src);

	/*
	 *
	 */
	uint64_t m_free_bits[memory_pool_free_bits_size];

	/*
	 *
	 */
	T *m_table;

	/*
	 *
	 */
	memory_pool<T> *m_next;

};

#include "memory_pool.cpp"

