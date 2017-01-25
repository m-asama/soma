/**
 * @file	config_data_node.h
 * @brief	設定データノードのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"
#include "config_model_node.h"

/**
 *
 */
enum class config_data_node_type {
	type_keyword,
	type_variable,
	type_root,
};

/**
 *
 */
class config_data_node {

public:
	/**
	 * コンストラクタ。
	 */
	config_data_node();

	/**
	 * デストラクタ。
	 */
	virtual ~config_data_node();

	/**
	 *
	 */
	config_data_node(const config_data_node &src);

	/**
	 *
	 */
	config_data_node(const config_data_node &&src) = delete;

	/**
	 *
	 */
	config_data_node &operator=(const config_data_node &src);

	/**
	 *
	 */
	config_data_node &operator=(const config_data_node &&src) = delete;

	/**
	 *
	 */
	static void *operator new(size_t size);

	/**
	 *
	 */
	static void operator delete(void *ptr);

	/**
	 *
	 */
	bool operator==(const config_data_node &rhs);

	/**
	 *
	 */
	bool operator>(const config_data_node &rhs);

	/**
	 *
	 */
	void type(config_data_node_type type);

	/**
	 *
	 */
	config_data_node_type type();

	/**
	 *
	 */
	void label(utf8str label);

	/**
	 *
	 */
	void label(char const *label);

	/**
	 *
	 */
	utf8str label();

	/**
	 *
	 */
	void config_model_node_(config_model_node *config_model_node_);

	/**
	 *
	 */
	config_model_node *config_model_node_();

	/**
	 *
	 */
	void parent(config_data_node *parent);

	/**
	 *
	 */
	config_data_node *parent();

	/**
	 *
	 */
	void add_child(config_data_node &child);

	/**
	 *
	 */
	void delete_child(config_data_node &child);

	/**
	 *
	 */
	sorted_list<config_data_node> &children();

	/**
	 *
	 */
	static uint64_t count();

private:
	/**
	 *
	 */
	static memory_pool<config_data_node> s_mem_pool;

	/**
	 *
	 */
	config_data_node_type m_type;

	/**
	 *
	 */
	utf8str m_label;

	/**
	 *
	 */
	config_model_node *m_config_model_node;

	/**
	 *
	 */
	config_data_node *m_parent;

	/**
	 *
	 */
	sorted_list<config_data_node> m_children;

};

