/**
 * @file	hash_table.cpp
 * @brief	ハッシュテーブルのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"

#include "bidir_node.h"

template<class V>
hash_table<V>::hash_table(uint64_t (*hash_fn)(const V &v), bool (*equal_fn)(const V &vl, const V &vr))
	: m_hash_fn(hash_fn), m_equal_fn(equal_fn), m_table_size(0), m_table(nullptr), m_nodes(0)
{
	//printstr("hash_table<V>::hash_table()\n");
}

template<class V>
hash_table<V>::~hash_table()
{
	uint64_t i;
	//printstr("hash_table<V>::~hash_table()\n");
	if (m_table != nullptr) {
		for (i = 0; i < m_table_size; ++i) {
			while (m_table[i] != nullptr) {
				remove(m_table[i]->v());
			}
		}
		delete[] m_table;
	}
	m_table_size = 0;
	m_table = nullptr;
	m_nodes = 0;
}

template<class V>
int
hash_table<V>::insert(V &v)
{
	uint64_t hash, i;
	bidir_node<V> *tmp;
	bidir_node<V> *n = new bidir_node<V>(v);

	if (m_table == nullptr) {
		m_table_size = hash_table_init_size;
		m_table = new bidir_node<V>*[m_table_size];
		for (i = 0; i < m_table_size; ++i) {
			m_table[i] = nullptr;
		}
	} else if (m_nodes >= m_table_size * 2) {
		expand();
	}

	hash = m_hash_fn(v) & (m_table_size - 1);
	if (m_table[hash] != nullptr) {
		tmp = m_table[hash];
		n->next(tmp);
		tmp->prev(n);
	}
	m_table[hash] = n;

	++m_nodes;

	return 0;
}

template<class V>
int
hash_table<V>::remove(const V &v)
{
	uint64_t hash;
	bidir_node<V> *tmp = nullptr;

	if (m_table == nullptr)
		return -1;

	hash = m_hash_fn(v) & (m_table_size - 1);
	for (tmp = m_table[hash]; tmp != nullptr; tmp = tmp->next()) {
		if (tmp->v() == v)
			break;
	}

	if (tmp == nullptr)
		return -1;

	if (tmp->next() != nullptr && tmp->prev() != nullptr) {
		tmp->prev()->next(tmp->next());
		tmp->next()->prev(tmp->prev());
	} else if (tmp->next() != nullptr) {
		tmp->next()->prev(nullptr);
		m_table[hash] = tmp->next();
	} else if (tmp->prev() != nullptr) {
		tmp->prev()->next(nullptr);
	} else {
		m_table[hash] = nullptr;
	}
	tmp->next(nullptr);
	tmp->prev(nullptr);

	delete tmp;

	--m_nodes;

	return 0;
}

template<class V>
V *
hash_table<V>::find(const V &v)
{
	uint64_t hash;
	bidir_node<V> *tmp;

	if (m_table == nullptr)
		return nullptr;

	hash = m_hash_fn(v) & (m_table_size - 1);
	for (tmp = m_table[hash]; tmp != nullptr; tmp = tmp->next()) {
		if (m_equal_fn(tmp->v(), v))
			return &tmp->v();
	}

	return nullptr;
}

template<class V>
uint64_t
hash_table<V>::table_size()
{
	return m_table_size;
}

template<class V>
bidir_node<V> **
hash_table<V>::table()
{
	return m_table;
}

template<class V>
uint64_t
hash_table<V>::nodes()
{
	return m_nodes;
}

template<class V>
void
hash_table<V>::expand()
{
	uint64_t hash, i;
	bidir_node<V> *tmp;
	uint64_t table_size;
	bidir_node<V> **table;

	if (m_table == nullptr)
		return;

	table_size = m_table_size << 2;
	table = new bidir_node<V>*[table_size];
	for (i = 0; i < table_size; ++i) {
		table[i] = nullptr;
	}

	for (i = 0; i < m_table_size; ++i) {
		while (m_table[i] != nullptr) {
			tmp = m_table[i];
			if (tmp->next() != nullptr)
				tmp->next()->prev(nullptr);
			m_table[i] = tmp->next();
			tmp->next(nullptr);
			tmp->prev(nullptr);
			hash = m_hash_fn(tmp->v()) & (table_size - 1);
			tmp->next(table[hash]);
			if (tmp->next() != nullptr)
				tmp->next()->prev(tmp);
			table[hash] = tmp;
		}
	}

	delete[] m_table;

	m_table = table;
	m_table_size = table_size;
}

