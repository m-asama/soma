/**
 * @file	sorted_list.cpp
 * @brief	整列されたリストのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"

#include "bidir_node.h"

template<class V>
sorted_list<V>::sorted_list()
	: m_head(nullptr), m_tail(nullptr), m_nodes(0)
{
	//printstr("sorted_list<V>::sorted_list()\n");
}

template<class V>
sorted_list<V>::~sorted_list()
{
	//printstr("sorted_list<V>::~sorted_list()\n");
	while (m_head != nullptr) {
		remove(m_head->v());
	}
	m_head = nullptr;
	m_tail = nullptr;
	m_nodes = 0;
}

template<class V>
int
sorted_list<V>::insert(V &v)
{
	bidir_node<V> *itr, *tmp;
	bidir_node<V> *n = new bidir_node<V>(v);

	if (m_head == nullptr && m_tail == nullptr) {
		m_head = n;
		m_tail = n;
		++m_nodes;
		return 0;
	}

	for (itr = m_head; itr != nullptr; itr = itr->next()) {
		if (itr->v() > v)
			break;
	}

	if (itr == nullptr) {
		tmp = m_tail;
		n->prev(tmp);
		tmp->next(n);
		m_tail = n;
	} else if (itr->prev() == nullptr) {
		tmp = m_head;
		n->next(tmp);
		tmp->prev(n);
		m_head = n;
	} else {
		tmp = itr->prev();
		tmp->next(n);
		n->next(itr);
		itr->prev(n);
		n->prev(tmp);
	}

	++m_nodes;

	return 0;
}

template<class V>
int
sorted_list<V>::remove(V &v)
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
const V *
sorted_list<V>::find(const V &v)
{
	bidir_node<V> *tmp;

	for (tmp = m_head; tmp != nullptr; tmp = tmp->next()) {
		if (tmp->v() == v)
			return &tmp->v();
	}

	return nullptr;
}

template<class V>
int
sorted_list<V>::resort()
{
	bidir_node<V> *head, *tail, *min, *tmp;

	head = nullptr;
	tail = nullptr;
	while (m_head != nullptr) {
		min = nullptr;
		for (tmp = m_head; tmp != nullptr; tmp = tmp->next()) {
			if (min == nullptr || tmp->v() < min->v())
				min = tmp;
		}
		if (min->next() != nullptr && min->prev() != nullptr) {
			min->prev()->next(min->next());
			min->next()->prev(min->prev());
		} else if (min->next() != nullptr) {
			min->next()->prev(nullptr);
			m_head = min->next();
		} else if (min->prev() != nullptr) {
			min->prev()->next(nullptr);
			m_tail = min->prev();
		} else {
			m_head = nullptr;
			m_tail = nullptr;
		}
		min->next(nullptr);
		min->prev(nullptr);
		if (head != nullptr && tail != nullptr) {
			tmp = tail;
			min->prev(tmp);
			tmp->next(min);
			tail = min;
		} else if (head == nullptr && tail == nullptr) {
			head = min;
			tail = min;
		} else {
			// BUG?
		}
	}
	m_head = head;
	m_tail = tail;
	return 0;
}

template<class V>
bidir_node<V> *
sorted_list<V>::head() const
{
	return m_head;
}

template<class V>
bidir_node<V> *
sorted_list<V>::tail() const
{
	return m_tail;
}

template<class V>
int
sorted_list<V>::nodes()
{
	return m_nodes;
}

