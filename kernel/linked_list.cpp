/**
 * @file	linked_list.cpp
 * @brief	リンクリストのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"

#include "bidir_node.h"

template<class V>
linked_list<V>::linked_list()
	: m_head(nullptr), m_tail(nullptr), m_nodes(0)
{
	//printstr("linked_list<V>::linked_list()\n");
}

template<class V>
linked_list<V>::~linked_list()
{
	//printstr("linked_list<V>::~linked_list()\n");
	while (m_head != nullptr) {
		remove(m_head->v());
	}
	m_head = nullptr;
	m_tail = nullptr;
	m_nodes = 0;
}

template<class V>
int
linked_list<V>::insert_head(V &v)
{
	bidir_node<V> *tmp = nullptr;
	bidir_node<V> *n = new bidir_node<V>(v);

	if (m_head != nullptr && m_tail != nullptr) {
		tmp = m_head;
		n->next(tmp);
		tmp->prev(n);
		m_head = n;
	} else if (m_head == nullptr && m_tail == nullptr) {
		m_head = n;
		m_tail = n;
	} else {
		return -1;
	}

	++m_nodes;

	return 0;
}

template<class V>
int
linked_list<V>::insert_tail(V &v)
{
	bidir_node<V> *tmp = nullptr;
	bidir_node<V> *n = new bidir_node<V>(v);

	if (m_head != nullptr && m_tail != nullptr) {
		tmp = m_tail;
		n->prev(tmp);
		tmp->next(n);
		m_tail = n;
	} else if (m_head == nullptr && m_tail == nullptr) {
		m_head = n;
		m_tail = n;
	} else {
		return -1;
	}

	++m_nodes;

	return 0;
}

template<class V>
int
linked_list<V>::remove(const V &v)
{
	bidir_node<V> *tmp = nullptr;

	if (m_head == nullptr && m_tail == nullptr)
		return -1;

	for (tmp = m_head; tmp != nullptr; tmp = tmp->next()) {
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
		m_head = tmp->next();
	} else if (tmp->prev() != nullptr) {
		tmp->prev()->next(nullptr);
		m_tail = tmp->prev();
	} else {
		m_head = nullptr;
		m_tail = nullptr;
	}
	tmp->next(nullptr);
	tmp->prev(nullptr);

	delete tmp;

	--m_nodes;

	return 0;
}

template<class V>
V *
linked_list<V>::find(const V &v)
{
	bidir_node<V> *tmp;

	for (tmp = m_head; tmp != nullptr; tmp = tmp->next()) {
		if (tmp->v() == v)
			return &tmp->v();
	}

	return nullptr;
}

template<class V>
bidir_node<V> *
linked_list<V>::head()
{
	return m_head;
}

template<class V>
bidir_node<V> *
linked_list<V>::tail()
{
	return m_tail;
}

template<class V>
int
linked_list<V>::nodes()
{
	return m_nodes;
}

template<class V>
linked_list<V>::linked_list(const linked_list<V> &src)
{
}

template<class V>
void
linked_list<V>::operator=(const linked_list<V> &src)
{
}

