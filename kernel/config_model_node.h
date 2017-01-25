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
	// YANG 組込型
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
	// ietf-yang-types
	type_counter32,
	type_zero_based_counter32,
	type_counter64,
	type_zero_based_counter64,
	type_gauge32,
	type_gauge64,
	type_object_identifier,
	type_object_identifier_128,
	type_yang_identifier,
	type_date_and_time,
	type_timeticks,
	type_timestamp,
	type_phys_address,
	type_mac_address,
	type_xpath1_0,
	type_hex_string,
	type_uuid,
	type_dotted_quad,
	// ietf-interfaces
	type_interface_ref,
	type_interface_state_ref,
	// ietf-inet-types
	type_ip_version,
	type_dscp,
	type_ipv6_flow_label,
	type_port_number,
	type_as_number,
	type_ip_address,
	type_ipv4_address,
	type_ipv6_address,
	type_ip_address_no_zone,
	type_ipv4_address_no_zone,
	type_ipv6_address_no_zone,
	type_ip_prefix,
	type_ipv4_prefix,
	type_ipv6_prefix,
	type_domain_name,
	type_host,
	type_uri,
	// ietf-ip
	type_ip_address_origin,
	type_neighbor_origin,
	// ietf-routing
	type_routing_instance_ref,
	type_routing_instance_state_ref,
	type_rib_ref,
	type_rib_state_ref,
	type_next_hop_list_ref,
	type_route_filter_ref,
	type_route_filter_state_ref,
	type_route_preference,
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
	void min_elements(uint64_t min_elements);

	/**
	 *
	 */
	uint64_t min_elements();

	/**
	 *
	 */
	void max_elements(uint64_t max_elements);

	/**
	 *
	 */
	uint64_t max_elements();

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
	void key(utf8str key);

	/**
	 *
	 */
	void key(char const *key);

	/**
	 *
	 */
	utf8str key();

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
	uint64_t m_min_elements;

	/**
	 * 最大数。
	 * leaf_list, list
	 */
	uint64_t m_max_elements;

	/**
	 * 表示順。
	 * leaf_list, list
	 */
	config_model_node_ordered_by m_ordered_by;

	/**
	 * 主キー。
	 * list
	 */
	utf8str m_key;

	/**
	 * 設定フラグ。
	 * container, leaf, leaf_list, list
	 */
	bool m_config;

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

};

