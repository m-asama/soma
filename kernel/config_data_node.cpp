/**
 * @file	config_data_node.cpp
 * @brief	設定データノードのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "linked_list.h"

#include "config_data_node.h"

config_data_node::config_data_node()
	: m_config_model_node(nullptr), m_parent(nullptr)
{
}

config_data_node::~config_data_node()
{
	linked_list<config_data_node> dellist;
	bidir_node<config_data_node> *bn;
	for (bn = m_children.head(); bn != nullptr; bn = bn->next()) {
		dellist.insert_tail(bn->v());
	}
	for (bn = dellist.head(); bn != nullptr; bn = bn->next()) {
		m_children.remove(bn->v());
		delete &bn->v();
	}
}

config_data_node::config_data_node(const config_data_node &src)
{
	m_type = src.m_type;
	m_label = src.m_label;
	m_config_model_node = src.m_config_model_node;
	m_parent = src.m_parent;
	bidir_node<config_data_node> *bn;
	for (bn = src.m_children.head(); bn != nullptr; bn = bn->next()) {
		config_data_node *child = new config_data_node(bn->v());
		child->parent(this);
		m_children.insert(*child);
	}
}

config_data_node &
config_data_node::operator=(const config_data_node &src)
{
	linked_list<config_data_node> dellist;
	bidir_node<config_data_node> *bn;
	for (bn = m_children.head(); bn != nullptr; bn = bn->next()) {
		dellist.insert_tail(bn->v());
	}
	for (bn = dellist.head(); bn != nullptr; bn = bn->next()) {
		m_children.remove(bn->v());
		delete &bn->v();
	}
	m_type = src.m_type;
	m_label = src.m_label;
	m_config_model_node = src.m_config_model_node;
	m_parent = src.m_parent;
	for (bn = src.m_children.head(); bn != nullptr; bn = bn->next()) {
		config_data_node *child = new config_data_node(bn->v());
		child->parent(this);
		m_children.insert(*child);
	}
	return *this;
}

void *
config_data_node::operator new(size_t size)
{
	return s_mem_pool.alloc();
}

void
config_data_node::operator delete(void *ptr)
{
	s_mem_pool.free((config_data_node *)ptr);
}

bool
config_data_node::operator==(const config_data_node &rhs)
{
	return (m_label == rhs.m_label);
}

bool
config_data_node::operator>(const config_data_node &rhs)
{
	return (m_label > rhs.m_label);
}

void
config_data_node::type(config_data_node_type type)
{
	m_type = type;
}

config_data_node_type
config_data_node::type()
{
	return m_type;
}

void
config_data_node::label(utf8str label)
{
	m_label = label;
}

void
config_data_node::label(char const *label)
{
	utf8str s(label);
	m_label = s;
}

utf8str
config_data_node::label()
{
	return m_label;
}

void
config_data_node::config_model_node_(config_model_node *config_model_node_)
{
	m_config_model_node = config_model_node_;
}

config_model_node *
config_data_node::config_model_node_()
{
	return m_config_model_node;
}

void
config_data_node::parent(config_data_node *parent)
{
	m_parent = parent;
}

config_data_node *
config_data_node::parent()
{
	return m_parent;
}

void
config_data_node::add_child(config_data_node &child)
{
	m_children.insert(child);
}

void
config_data_node::delete_child(config_data_node &child)
{
	m_children.remove(child);
}

sorted_list<config_data_node> &
config_data_node::children()
{
	return m_children;
}

uint64_t
config_data_node::count()
{
	return s_mem_pool.count();
}

memory_pool<config_data_node> config_data_node::s_mem_pool;

