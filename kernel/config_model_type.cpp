/**
 * @file	config_model_type.cpp
 * @brief	設定モデルノードの型クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_type.h"

config_model_type::config_model_type(config_model_node_type type)
	: m_type(type), m_description(msg_null), m_format(msg_null)
{
}

config_model_type::~config_model_type()
{
}

void *
config_model_type::operator new(size_t size)
{
	return s_mem_pool.alloc();
}

void
config_model_type::operator delete(void *ptr)
{
	s_mem_pool.free((config_model_type *)ptr);
}

bool
config_model_type::operator==(const config_model_type &rhs)
{
	return (this == &rhs);
}

config_model_node_type
config_model_type::type()
{
	return m_type;
}

void
config_model_type::add_argument(config_model_argument &argument)
{
	m_arguments.insert_tail(argument);
}

void
config_model_type::delete_argument(config_model_argument &argument)
{
	m_arguments.remove(argument);
}

linked_list<config_model_argument> &
config_model_type::arguments()
{
	return m_arguments;
}

void
config_model_type::add_range(config_model_range &range)
{
	m_ranges.insert_tail(range);
}

void
config_model_type::delete_range(config_model_range &range)
{
	m_ranges.remove(range);
}

linked_list<config_model_range> &
config_model_type::ranges()
{
	return m_ranges;
}

void
config_model_type::add_pattern(config_model_pattern &pattern)
{
	m_patterns.insert_tail(pattern);
}

void
config_model_type::delete_pattern(config_model_pattern &pattern)
{
	m_patterns.remove(pattern);
}

linked_list<config_model_pattern> &
config_model_type::patterns()
{
	return m_patterns;
}

void
config_model_type::add_length(config_model_length &length)
{
	m_lengthes.insert_tail(length);
}

void
config_model_type::delete_length(config_model_length &length)
{
	m_lengthes.remove(length);
}

linked_list<config_model_length> &
config_model_type::lengthes()
{
	return m_lengthes;
}

void
config_model_type::description(msg *description)
{
	m_description = description;
}

msg *
config_model_type::description()
{
	return m_description;
}

void
config_model_type::format(msg *format)
{
	m_format = format;
}

msg *
config_model_type::format()
{
	return m_format;
}

bool
config_model_type::valid(utf8str value)
{
	bidir_node<config_model_argument> *bna;
	switch (m_type) {
	case config_model_node_type::type_bits:
	case config_model_node_type::type_boolean:
	case config_model_node_type::type_enumeration:
	case config_model_node_type::type_identityref:
		for (bna = m_arguments.head(); bna != nullptr; bna = bna->next()) {
			config_model_argument &argument = bna->v();
			if (value == argument.label()) {
				return true;
			}
		}
		return false;
		break;
	case config_model_node_type::type_leafref:
		break;
	case config_model_node_type::type_string:
		break;
	case config_model_node_type::type_int8:
	case config_model_node_type::type_int16:
	case config_model_node_type::type_int32:
	case config_model_node_type::type_int64:
	case config_model_node_type::type_uint8:
	case config_model_node_type::type_uint16:
	case config_model_node_type::type_uint32:
	case config_model_node_type::type_uint64:
		break;
	case config_model_node_type::type_decimal64:
		break;
	case config_model_node_type::type_binary:
	case config_model_node_type::type_empty:
	case config_model_node_type::type_instance_identifier:
	case config_model_node_type::type_union:
		break;
	}
	return true;
}

memory_pool<config_model_type> config_model_type::s_mem_pool;

