/**
 * @file	hash_table.h
 * @brief	ハッシュテーブルのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "bidir_node.h"

#include "loader_info.h"

const int hash_table_init_size = 0x100;

template<class V>
class hash_table {

	friend void memory_init(struct loader_info *li);

public:
	/*
	 *
	 */
	hash_table(uint64_t (*hash_fn)(const V &v), bool (*equal_fn)(const V &vl, const V &vr));

	/*
	 *
	 */
	virtual ~hash_table();

	/*
	 *
	 */
	int insert(V &v);

	/*
	 *
	 */
	int remove(const V &v);

	/*
	 *
	 */
	V *find(const V &v);

	/*
	 *
	 */
	uint64_t table_size();

	/*
	 *
	 */
	bidir_node<V> **table();

	/*
	 *
	 */
	uint64_t nodes();

private:
	/*
	 *
	 */
	hash_table();

	/*
	 *
	 */
	hash_table(const hash_table<V> &src);

	/*
	 *
	 */
	void operator=(const hash_table<V> &src);

	/*
	 *
	 */
	void expand();

	/*
	 *
	 */
	uint64_t (*m_hash_fn)(const V &v);

	/*
	 *
	 */
	bool (*m_equal_fn)(const V &vl, const V &vr);

	/*
	 *
	 */
	uint64_t m_table_size;

	/*
	 *
	 */
	bidir_node<V> **m_table;

	/*
	 *
	 */
	uint64_t m_nodes;

};

#include "hash_table.cpp"

