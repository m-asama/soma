/**
 * @file	bidir_node.cpp
 * @brief	双方向リンクリストのノード。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"

template<class V>
bidir_node<V>::bidir_node(V &v)
	: m_v(v)
{
	//printstr("bidir_node<V>::bidir_node(V &v)\n");
	m_next = nullptr;
	m_prev = nullptr;
}

template<class V>
bidir_node<V>::~bidir_node()
{
	//printstr("bidir_node<V>::~bidir_node()\n");
	m_next = nullptr;
	m_prev = nullptr;
}

template<class V>
void *
bidir_node<V>::operator new(size_t size)
{
	//printstr("bidir_node<V>::operator new\n");
	return s_mem_pool.alloc();
}

template<class V>
void
bidir_node<V>::operator delete(void *ptr)
{
	s_mem_pool.free((bidir_node<V> *)ptr);
}

template<class V>
V &
bidir_node<V>::v()
{
	return m_v;
}

template<class V>
void
bidir_node<V>::next(bidir_node<V> *next)
{
	m_next = next;
}

template<class V>
bidir_node<V> *
bidir_node<V>::next()
{
	return m_next;
}

template<class V>
void
bidir_node<V>::prev(bidir_node<V> *prev)
{
	m_prev = prev;
}

template<class V>
bidir_node<V> *
bidir_node<V>::prev()
{
	return m_prev;
}

template<class V>
uint64_t
bidir_node<V>::count()
{
	return s_mem_pool.count();
}

template<class V>
memory_pool<bidir_node<V>> bidir_node<V>::s_mem_pool;

