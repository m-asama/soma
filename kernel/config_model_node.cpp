/**
 * @file	config_model_node.cpp
 * @brief	設定モデルノードのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "utf8str.h"

#include "print.h"

#include "memory_block.h"
#include "intel64_assembly.h"

#include "config_model_node.h"

config_model_node::config_model_node()
	: m_parent(nullptr), m_presence(false), m_mandatory(false), m_min_elements(-1), m_max_elements(-1),
	  m_validate(nullptr), m_commit(nullptr), m_description(msg_null)
{
}

config_model_node::~config_model_node()
{
}

void *
config_model_node::operator new(size_t size)
{
	return s_mem_pool.alloc();
}

void
config_model_node::operator delete(void *ptr)
{
	s_mem_pool.free((config_model_node *)ptr);
}

bool
config_model_node::operator==(const config_model_node &rhs)
{
	return (m_identifier == rhs.identifier());
}

bool
config_model_node::operator>(const config_model_node &rhs)
{
	return (m_identifier > rhs.identifier());
}

void
config_model_node::statement(config_model_node_statement statement)
{
	m_statement = statement;
}

config_model_node_statement
config_model_node::statement()
{
	return m_statement;
}

void
config_model_node::identifier(utf8str identifier)
{
	m_identifier = identifier;
}

void
config_model_node::identifier(char const *identifier)
{
	utf8str s(identifier);
	m_identifier = s;
}

utf8str
config_model_node::identifier() const
{
	return m_identifier;
}

void
config_model_node::parent(config_model_node *parent)
{
	m_parent = parent;
}

config_model_node *
config_model_node::parent()
{
	return m_parent;
}

void
config_model_node::add_child(config_model_node &child)
{
	m_children.insert(child);
}

void
config_model_node::delete_child(config_model_node &child)
{
	m_children.remove(child);
}

sorted_list<config_model_node> &
config_model_node::children()
{
	return m_children;
}

void
config_model_node::presence(bool presence)
{
	m_presence = presence;
}

bool
config_model_node::presence()
{
	return m_presence;
}

void
config_model_node::default_(utf8str default_)
{
	m_default = default_;
}

void
config_model_node::default_(char const *default_)
{
	utf8str s(default_);
	m_default = s;
}

utf8str
config_model_node::default_()
{
	return m_default;
}

void
config_model_node::mandatory(bool mandatory)
{
	m_mandatory = mandatory;
}

bool
config_model_node::mandatory()
{
	return m_mandatory;
}

void
config_model_node::min_elements(sint64_t min_elements)
{
	m_min_elements = min_elements;
}

sint64_t
config_model_node::min_elements()
{
	return m_min_elements;
}

void
config_model_node::max_elements(sint64_t max_elements)
{
	m_max_elements = max_elements;
}

sint64_t
config_model_node::max_elements()
{
	return m_max_elements;
}

void
config_model_node::ordered_by(config_model_node_ordered_by ordered_by)
{
	m_ordered_by = ordered_by;
}

config_model_node_ordered_by
config_model_node::ordered_by()
{
	return m_ordered_by;
}

void
config_model_node::add_key(config_model_node &key)
{
	m_key.insert_tail(key);
}

void
config_model_node::delete_key(config_model_node &key)
{
	m_key.remove(key);
}

linked_list<config_model_node> &
config_model_node::key()
{
	return m_key;
}

void
config_model_node::add_unique(config_model_node &unique)
{
	m_unique.insert_tail(unique);
}

void
config_model_node::delete_unique(config_model_node &unique)
{
	m_unique.remove(unique);
}

linked_list<config_model_node> &
config_model_node::unique()
{
	return m_unique;
}

void
config_model_node::config(bool config)
{
	m_config = config;
}

bool
config_model_node::config()
{
	return m_config;
}

void
config_model_node::add_type(config_model_type &type)
{
	m_types.insert_tail(type);
}

void
config_model_node::delete_type(config_model_type &type)
{
	m_types.remove(type);
}

linked_list<config_model_type> &
config_model_node::types()
{
	return m_types;
}

void
config_model_node::validate(validate_fn validate)
{
	m_validate = validate;
}

validate_fn
config_model_node::validate()
{
	return m_validate;
}

void
config_model_node::commit(commit_fn commit)
{
	m_commit = commit;
}

commit_fn
config_model_node::commit()
{
	return m_commit;
}

void
config_model_node::description(msg *description)
{
	m_description = description;
}

msg *
config_model_node::description()
{
	return m_description;
}

bool
config_model_node::is_key()
{
	bidir_node<config_model_node> *bn;

	if (m_parent == nullptr) {
		return false;
	}

	for (bn = m_parent->m_key.head(); bn != nullptr; bn = bn->next()) {
		if (bn->v() == *this) {
			return true;
		}
	}

	return false;
}

memory_pool<config_model_node> config_model_node::s_mem_pool;

