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
	: m_parent(nullptr), m_validate(nullptr), m_commit(nullptr)
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
config_model_node::type(config_model_node_type type)
{
	m_type = type;
}

config_model_node_type
config_model_node::type()
{
	return m_type;
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
config_model_node::min_elements(uint64_t min_elements)
{
	m_min_elements = min_elements;
}

uint64_t
config_model_node::min_elements()
{
	return m_min_elements;
}

void
config_model_node::max_elements(uint64_t max_elements)
{
	m_max_elements = max_elements;
}

uint64_t
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
config_model_node::key(utf8str key)
{
	m_key = key;
}

void
config_model_node::key(char const *key)
{
	utf8str s(key);
	m_key = s;
}

utf8str
config_model_node::key()
{
	return m_key;
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
config_model_node::description_ja(char const *description_ja)
{
	m_description_ja = description_ja;
}

char const *
config_model_node::description_ja()
{
	return m_description_ja;
}

void
config_model_node::description_en(char const *description_en)
{
	m_description_en = description_en;
}

char const *
config_model_node::description_en()
{
	return m_description_en;
}

memory_pool<config_model_node> config_model_node::s_mem_pool;

