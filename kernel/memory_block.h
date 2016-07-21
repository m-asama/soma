/**
 * @file	memory_block.h
 * @brief	メモリ内の位置と大きさを表すブロックを表現するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "memory_pool.h"

class memory_block {

	friend void memory_init(struct loader_info *li);

public:
	/*
	 *
	 */
	memory_block(uint64_t base, uint64_t size);

	/*
	 *
	 */
	virtual ~memory_block();

	/*
	 *
	 */
	static void *operator new(size_t size);

	/*
	 *
	 */
	static void operator delete(void *ptr);

	/*
	 *
	 */
	bool operator==(const memory_block &rhs);

	/*
	 *
	 */
	bool operator>(const memory_block &rhs);

	/*
	 *
	 */
	void base(uint64_t base);

	/*
	 *
	 */
	uint64_t base() const;

	/*
	 *
	 */
	void size(uint64_t size);

	/*
	 *
	 */
	uint64_t size() const;

	/*
	 *
	 */
	static uint64_t count();

private:
	/*
	 *
	 */
	memory_block();

	/*
	 *
	 */
	memory_block(const memory_block &src);

	/*
	 *
	 */
	void operator=(const memory_block &src);

	/*
	 *
	 */
	static memory_pool<memory_block> s_mem_pool;

	/*
	 *
	 */
	uint64_t m_base;

	/*
	 *
	 */
	uint64_t m_size;

};

uint64_t memory_block_hash(const memory_block &mb);
bool memory_block_equal(const memory_block &mbl, const memory_block &mbr);

