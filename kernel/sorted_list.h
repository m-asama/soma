/**
 * @file	sorted_list.h
 * @brief	整列されたリストのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "bidir_node.h"

template<class V>
class sorted_list {

	friend void memory_init(struct loader_info *li);

public:
	/*
	 *
	 */
	sorted_list();

	/*
	 *
	 */
	virtual ~sorted_list();

	/*
	 *
	 */
	int
	insert(V &v);

	/*
	 *
	 */
	int
	remove(V &v);

	/*
	 *
	 */
	const V *
	find(const V &v);

	/*
	 *
	 */
	int
	resort();

	/*
	 *
	 */
	bidir_node<V> *head();

	/*
	 *
	 */
	bidir_node<V> *tail();

	/*
	 *
	 */
	int nodes();

private:
	/*
	 *
	 */
	sorted_list(const sorted_list<V> &src);

	/*
	 *
	 */
	void operator=(const sorted_list<V> &src);

	/*
	 *
	 */
	bidir_node<V> *m_head;

	/*
	 *
	 */
	bidir_node<V> *m_tail;

	/*
	 *
	 */
	int m_nodes;

};

#include "sorted_list.cpp"

