/**
 * @file	command_node.h
 * @brief	コマンドノードのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"
#include "sorted_list.h"
#include "memory_pool.h"
#include "console_base.h"
#include "config_model_type.h"

class config_model_node;

typedef bool (*execute_fn)(console_base &, utf8str);

/**
 *
 */
enum class command_node_type {
	type_keyword,
	type_variable,
	type_config_model,		// config = true のノード
	type_config_model_woleafs,	// config = true で leaf と leaf_list 以外のノード
	type_root,
};

/**
 *
 */
class command_node {

public:
	/**
	 * コンストラクタ。
	 */
	command_node();

	/**
	 * デストラクタ。
	 */
	virtual ~command_node();

	/**
	 *
	 */
	command_node(const command_node &src) = delete;

	/**
	 *
	 */
	command_node(const command_node &&src) = delete;

	/**
	 *
	 */
	command_node &operator=(const command_node &src) = delete;

	/**
	 *
	 */
	command_node &operator=(const command_node &&src) = delete;

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
	bool operator==(const command_node &rhs);

	/**
	 *
	 */
	bool operator>(const command_node &rhs);

	/**
	 *
	 */
	void node_type(command_node_type node_type);

	/**
	 *
	 */
	command_node_type node_type();

	/**
	 *
	 */
	void keyword_label(utf8str keyword_label);

	/**
	 *
	 */
	utf8str keyword_label();

	/**
	 *
	 */
	void model_type(config_model_type *model_type);

	/**
	 *
	 */
	config_model_type *model_type();

	/**
	 *
	 */
	void parent(command_node *parent);

	/**
	 *
	 */
	command_node *parent();

	/**
	 *
	 */
	void add_child(command_node &child);

	/**
	 *
	 */
	void delete_child(command_node &child);

	/**
	 *
	 */
	sorted_list<command_node> &children();

	/**
	 *
	 */
	void execute(execute_fn execute);

	/**
	 *
	 */
	execute_fn execute();

	/**
	 *
	 */
	void description(msg *description);

	/**
	 *
	 */
	msg *description();

private:
	/**
	 *
	 */
	static memory_pool<command_node> s_mem_pool;

	/**
	 * コマンドノードのタイプ。
	 */
	command_node_type m_node_type;

	/**
	 * コマンドノードを表す文字列(タイプがキーワードの場合)。
	 */
	utf8str m_keyword_label;

	/**
	 * コマンドノードの表すデータ型(タイプが変数の場合)。
	 */
	config_model_type *m_model_type;

	/**
	 * 親。
	 */
	command_node *m_parent;

	/**
	 * 子。
	 */
	sorted_list<command_node> m_children;

	/**
	 * コマンド実行関数へのポインタ。
	 */
	execute_fn m_execute;

	/**
	 * コマンドの説明。
	 */
	msg *m_description;

};

