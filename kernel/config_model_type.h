/**
 * @file	config_model_type.h
 * @brief	設定モデルノードの型クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"
#include "linked_list.h"
#include "console_management.h"
#include "config_model_argument.h"
#include "config_model_length.h"
#include "config_model_pattern.h"
#include "config_model_range.h"

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
class config_model_type {

public:
	/**
	 *
 	 */
	config_model_type() = delete;

	/**
	 *
 	 */
	config_model_type(config_model_node_type type);

	/**
	 *
	 */
	virtual ~config_model_type();

	/**
	 *
	 */
	config_model_type(const config_model_type &src) = delete;

	/**
	 *
	 */
	config_model_type(config_model_type &&src) = delete;

	/**
	 *
	 */
	config_model_type &operator=(const config_model_type &src) = delete;

	/**
	 *
	 */
	config_model_type &operator=(config_model_type &&src) = delete;

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
	bool operator==(const config_model_type &rhs);

	/**
	 *
	 */
	config_model_node_type type();

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

	/**
	 *
	 */
	bool valid(utf8str value);

private:
	/**
	 *
	 */
	static memory_pool<config_model_type> s_mem_pool;

	/**
	 * 型。
	 * leaf, leaf_list
	 */
	config_model_node_type m_type;

	/**
	 * 引数。
	 * leaf_list か leaf で、
	 * 型が bits, enumeration, identityref の時のみ使用。
	 */
	linked_list<config_model_argument> m_arguments;

	/**
	 * 範囲。
	 * leaf_list か leaf で、
	 * 型が数値型の時のみ使用。
	 */
	linked_list<config_model_range> m_ranges;

	/**
	 * パターン。
	 * leaf_list か leaf で、
	 * 型が文字列型の時のみ使用。
	 */
	linked_list<config_model_pattern> m_patterns;

	/**
	 * 長さ。
	 * leaf_list か leaf で、
	 * 型が文字列型の時のみ使用。
	 */
	linked_list<config_model_length> m_lengthes;

	/**
	 * 説明。
	 */
	msg *m_description;

	/**
	 * フォーマット。
	 */
	msg *m_format;

};

