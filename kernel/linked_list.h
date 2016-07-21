/**
 * @file	linked_list.h
 * @brief	リンクリストのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "bidir_node.h"

template<class V>
class linked_list {

public:
	/*
	 *
	 */
	linked_list();

	/*
	 *
	 */
	virtual ~linked_list();

	/*
	 *
	 */
	int insert_head(V &v);

	/*
	 *
	 */
	int insert_tail(V &v);

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
	linked_list(const linked_list<V> &src);

	/*
	 *
	 */
	void operator=(const linked_list<V> &src);

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

#include "linked_list.cpp"

