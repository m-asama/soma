/**
 * @file	command_node.cpp
 * @brief	コマンドノードのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "command_node.h"

command_node::command_node()
	: m_model_type(nullptr), m_parent(nullptr), m_execute(nullptr), m_description(msg_null)
{
}

command_node::~command_node()
{
}

void *
command_node::operator new(size_t size)
{
	return s_mem_pool.alloc();
}

void
command_node::operator delete(void *ptr)
{
	s_mem_pool.free((command_node *)ptr);
}

bool
command_node::operator==(const command_node &rhs)
{
	if (m_node_type == rhs.m_node_type) {
		switch (m_node_type) {
		case command_node_type::type_keyword:
			return (m_keyword_label == rhs.m_keyword_label);
		case command_node_type::type_variable:
			return (m_model_type == rhs.m_model_type);
		case command_node_type::type_config_model:
			return true;
		case command_node_type::type_config_model_woleafs:
			return true;
		case command_node_type::type_root:
			return true;
		}
	} else {
		return false;
	}
}

bool
command_node::operator>(const command_node &rhs)
{
	if (m_node_type == rhs.m_node_type) {
		switch (m_node_type) {
		case command_node_type::type_keyword:
			return (m_keyword_label > rhs.m_keyword_label);
		case command_node_type::type_variable:
			return (m_model_type > rhs.m_model_type);
		case command_node_type::type_config_model:
			return false;
		case command_node_type::type_config_model_woleafs:
			return false;
		case command_node_type::type_root:
			return false;
		}
	} else {
		return (m_node_type > rhs.m_node_type);
	}
}

void
command_node::node_type(command_node_type node_type)
{
	m_node_type = node_type;
}

command_node_type
command_node::node_type()
{
	return m_node_type;
}

void
command_node::keyword_label(utf8str keyword_label)
{
	m_keyword_label = keyword_label;
}

utf8str
command_node::keyword_label()
{
	return m_keyword_label;
}

void
command_node::model_type(config_model_type *model_type)
{
	m_model_type = model_type;
}

config_model_type *
command_node::model_type()
{
	return m_model_type;
}

void
command_node::parent(command_node *parent)
{
	m_parent = parent;
}

command_node *
command_node::parent()
{
	return m_parent;
}

void
command_node::add_child(command_node &child)
{
	m_children.insert(child);
}

void
command_node::delete_child(command_node &child)
{
	m_children.remove(child);
}

sorted_list<command_node> &
command_node::children()
{
	return m_children;
}

void
command_node::execute(execute_fn execute)
{
	m_execute = execute;
}

execute_fn
command_node::execute()
{
	return m_execute;
}

void
command_node::description(msg *description)
{
	m_description = description;
}

msg *
command_node::description()
{
	return m_description;
}

memory_pool<command_node> command_node::s_mem_pool;

