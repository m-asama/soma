/**
 * @file	memory_block.cpp
 * @brief	メモリ内の位置と大きさを表すブロックを表現するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"

#include "memory_block.h"

memory_block::memory_block(uint64_t base, uint64_t size)
	: m_base(base), m_size(size)
{
/*
	printstr("XXX: base = 0x");
	printhex64(m_base);
	printstr(" size = 0x");
	printhex64(m_size);
	printstr("\n");
*/
}

memory_block::~memory_block()
{
}

void *
memory_block::operator new(size_t size)
{
	//printstr("memory_block::operator new\n");
	return s_mem_pool.alloc();
}

void
memory_block::operator delete(void *ptr)
{
	s_mem_pool.free((memory_block *)ptr);
}

bool
memory_block::operator==(const memory_block &rhs)
{
	return ((m_base == rhs.m_base)
	     && (m_size == rhs.m_size));
}

bool
memory_block::operator>(const memory_block &rhs)
{
	return (m_base > rhs.m_base);
}

void
memory_block::base(uint64_t base)
{
	m_base = base;
}

uint64_t
memory_block::base() const
{
	return m_base;
}

void
memory_block::size(uint64_t size)
{
	m_size = size;
}

uint64_t
memory_block::size() const
{
	return m_size;
}

uint64_t
memory_block::count()
{
	return s_mem_pool.count();
}

memory_pool<memory_block> memory_block::s_mem_pool;

uint64_t memory_block_hash(const memory_block &mb)
{
	uint64_t hash;
	hash = mb.base() >> 0x3;
	//hash ^= (hash >> 40);
	//hash ^= (hash >> 20);
	//hash ^= (hash >> 10);
	//hash ^= (hash >> 5);
	return hash;
}

bool memory_block_equal(const memory_block &mbl, const memory_block &mbr)
{
	return (mbl.base() == mbr.base());
}

