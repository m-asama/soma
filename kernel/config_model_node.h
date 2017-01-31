/**
 * @file	config_model_node.h
 * @brief	設定モデルノードのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"
#include "sorted_list.h"
#include "memory_pool.h"
#include "console_base.h"
#include "config_model_argument.h"
#include "config_model_range.h"
#include "config_model_pattern.h"
#include "config_model_length.h"

class config_data_node;

typedef bool (*validate_fn)(config_data_node *);
typedef bool (*commit_fn)(config_data_node *, config_data_node *);

/**
 *
 */
enum class config_model_node_statement {
	statement_container,
	statement_leaf,
	statement_leaf_list,
	statement_list,
};

/**
 *
 */
enum class config_model_node_type {
	type_binary,
	type_bits,
	type_boolean,
	type_decimal64,
	type_empty,
	type_enumeration,
	type_identityref,
	type_instance_identifier,
	type_int8,
	type_int16,
	type_int32,
	type_int64,
	type_leafref,
	type_string,
	type_uint8,
	type_uint16,
	type_uint32,
	type_uint64,
	type_union,
};

/**
 *
 */
enum class config_model_node_ordered_by {
	ordered_by_system,
	ordered_by_user,
};

/**
 *
 */
class config_model_node {

public:
	/**
	 * コンストラクタ。
	 */
	config_model_node();

	/**
	 * デストラクタ。
	 */
	virtual ~config_model_node();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	config_model_node(const config_model_node &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	config_model_node(const config_model_node &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	config_model_node &operator=(const config_model_node &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	config_model_node &operator=(const config_model_node &&src) = delete;

	/**
	 * メモリ割当演算子。 memory_pool から割り当てる。
	 * @param size メモリを割り当てる大きさ。
	 * @return 確保されたメモリ領域へのポインタ。
	 */
	static void *operator new(size_t size);

	/**
	 * メモリ削除演算子。メモリプールに返す。
	 * @param ptr 解放するメモリへのポインタ。
	 */
	static void operator delete(void *ptr);

	/**
	 * 
	 */
	bool operator==(const config_model_node &rhs);

	/**
	 *
	 */
	bool operator>(const config_model_node &rhs);

	/**
	 *
	 */
	void statement(config_model_node_statement statement);

	/**
	 *
	 */
	config_model_node_statement statement();

	/**
	 *
	 */
	void identifier(utf8str identifier);

	/**
	 *
	 */
	void identifier(char const *identifier);

	/**
	 *
	 */
	utf8str identifier() const;

	/**
	 *
	 */
	void parent(config_model_node *parent);

	/**
	 *
	 */
	config_model_node *parent();

	/**
	 *
 	 */
	void add_child(config_model_node &child);

	/**
	 *
	 */
	void delete_child(config_model_node &child);

	/**
	 *
	 */
	sorted_list<config_model_node> &children();

	/**
	 *
	 */
	void type(config_model_node_type type);

	/**
	 *
	 */
	config_model_node_type type();

	/**
	 *
	 */
	void presence(bool presence);

	/**
	 *
	 */
	bool presence();

	/**
	 *
	 */
	void default_(utf8str default_);

	/**
	 *
	 */
	void default_(char const *default_);

	/**
	 *
	 */
	utf8str default_();

	/**
	 *
	 */
	void mandatory(bool mandatory);

	/**
	 *
	 */
	bool mandatory();

	/**
	 *
	 */
	void min_elements(sint64_t min_elements);

	/**
	 *
	 */
	sint64_t min_elements();

	/**
	 *
	 */
	void max_elements(sint64_t max_elements);

	/**
	 *
	 */
	sint64_t max_elements();

	/**
	 *
	 */
	void ordered_by(config_model_node_ordered_by ordered_by);

	/**
	 *
 	 */
	config_model_node_ordered_by ordered_by();

	/**
	 *
	 */
	void add_key(config_model_node &key);

	/**
	 *
	 */
	void delete_key(config_model_node &key);

	/**
	 *
	 */
	linked_list<config_model_node> &key();

	/**
	 *
	 */
	void add_unique(config_model_node &unique);

	/**
	 *
	 */
	void delete_unique(config_model_node &unique);

	/**
	 *
	 */
	linked_list<config_model_node> &unique();

	/**
	 *
	 */
	void config(bool config);

	/**
	 *
	 */
	bool config();

	/**
	 *
	 */
	void add_argument(config_model_argument &argument);

	/**
	 *
	 */
	void delete_argument(config_model_argument &argument);

	/**
	 *
	 */
	linked_list<config_model_argument> &arguments();

	/**
	 *
	 */
	void add_range(config_model_range &range);

	/**
	 *
	 */
	void delete_range(config_model_range &range);

	/**
	 *
	 */
	linked_list<config_model_range> &ranges();

	/**
	 *
	 */
	void add_pattern(config_model_pattern &pattern);

	/**
	 *
	 */
	void delete_pattern(config_model_pattern &pattern);

	/**
	 *
	 */
	linked_list<config_model_pattern> &patterns();

	/**
	 *
	 */
	void add_length(config_model_length &length);

	/**
	 *
	 */
	void delete_length(config_model_length &length);

	/**
	 *
	 */
	linked_list<config_model_length> &lengthes();

	/**
	 *
	 */
	void validate(validate_fn validate);

	/**
	 *
	 */
	validate_fn validate();

	/**
	 *
	 */
	void commit(commit_fn commit);

	/**
	 *
	 */
	commit_fn commit();

	/**
	 *
	 */
	void description(msg *description);

	/**
	 *
	 */
	msg *description();

	/**
	 *
	 */
	void format(msg *format);

	/**
	 *
	 */
	msg *format();

private:
	/**
	 *
	 */
	static memory_pool<config_model_node> s_mem_pool;

	/**
	 * ステートメント。
	 */
	config_model_node_statement m_statement;

	/**
	 * 識別子。
	 */
	utf8str m_identifier;

	/**
	 * 親のノード。
	 */
	config_model_node *m_parent;

	/**
	 * 子ノードのリスト。
	 */
	sorted_list<config_model_node> m_children;

	/**
	 * ノードの型。
	 * leaf, leaf_list
	 */
	config_model_node_type m_type;

	/**
	 * 存在フラグ。
	 * container
	 */
	bool m_presence;

	/**
	 * デフォルト値。
	 * leaf
	 */
	utf8str m_default;

	/**
	 * 必須フラグ。
	 * leaf
	 */
	bool m_mandatory;

	/**
	 * 最小数。
	 * leaf_list, list
	 */
	sint64_t m_min_elements;

	/**
	 * 最大数。
	 * leaf_list, list
	 */
	sint64_t m_max_elements;

	/**
	 * 表示順。
	 * leaf_list, list
	 */
	config_model_node_ordered_by m_ordered_by;

	/**
	 * キー。
	 * list
	 */
	linked_list<config_model_node> m_key;

	/**
	 * ユニーク。
	 * list
	 */
	linked_list<config_model_node> m_unique;

	/**
	 * 設定フラグ。
	 * container, leaf, leaf_list, list
	 */
	bool m_config;

	/**
	 * 引数。
	 * leaf_list か list で、
	 * 型が bits, enumeration, identityref の時のみ使用。
	 */
	linked_list<config_model_argument> m_arguments;

	/**
	 * 範囲。
	 * leaf_list か list で、
	 * 型が数値型の時のみ使用。
	 */
	linked_list<config_model_range> m_ranges;

	/**
	 * パターン。
	 * leaf_list か list で、
	 * 型が文字列型の時のみ使用。
	 */
	linked_list<config_model_pattern> m_patterns;

	/**
	 * 長さ。
	 * leaf_list か list で、
	 * 型が文字列型の時のみ使用。
	 */
	linked_list<config_model_length> m_lengthes;

	/**
	 * 設定の検証をする関数へのポインタ。
	 */
	validate_fn m_validate;

	/**
	 * 設定を反映する関数へのポインタ。
	 */
	commit_fn m_commit;

	/**
	 * 説明。
	 */
	msg *m_description;

	/**
	 * フォーマット。
	 */
	msg *m_format;

};

