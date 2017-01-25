/**
 * @file	config_model_validators.h
 * @brief	設定モデルノードの値チェック関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"
#include "config_model_node.h"

bool config_model_node_valid_binary(utf8str value);
bool config_model_node_valid_bits(utf8str value);
bool config_model_node_valid_boolean(utf8str value);
bool config_model_node_valid_decimal64(utf8str value);
bool config_model_node_valid_empty(utf8str value);
bool config_model_node_valid_enumeration(utf8str value);
bool config_model_node_valid_identityref(utf8str value);
bool config_model_node_valid_instance_identifier(utf8str value);
bool config_model_node_valid_int8(utf8str value);
bool config_model_node_valid_int16(utf8str value);
bool config_model_node_valid_int32(utf8str value);
bool config_model_node_valid_int64(utf8str value);
bool config_model_node_valid_leafref(utf8str value);
bool config_model_node_valid_string(utf8str value);
bool config_model_node_valid_uint8(utf8str value);
bool config_model_node_valid_uint16(utf8str value);
bool config_model_node_valid_uint32(utf8str value);
bool config_model_node_valid_uint64(utf8str value);
bool config_model_node_valid_union(utf8str value);
bool config_model_node_valid_counter32(utf8str value);
bool config_model_node_valid_zero_based_counter32(utf8str value);
bool config_model_node_valid_counter64(utf8str value);
bool config_model_node_valid_zero_based_counter64(utf8str value);
bool config_model_node_valid_gauge32(utf8str value);
bool config_model_node_valid_gauge64(utf8str value);
bool config_model_node_valid_object_identifier(utf8str value);
bool config_model_node_valid_object_identifier_128(utf8str value);
bool config_model_node_valid_yang_identifier(utf8str value);
bool config_model_node_valid_date_and_time(utf8str value);
bool config_model_node_valid_timeticks(utf8str value);
bool config_model_node_valid_timestamp(utf8str value);
bool config_model_node_valid_phys_address(utf8str value);
bool config_model_node_valid_mac_address(utf8str value);
bool config_model_node_valid_xpath1_0(utf8str value);
bool config_model_node_valid_hex_string(utf8str value);
bool config_model_node_valid_uuid(utf8str value);
bool config_model_node_valid_dotted_quad(utf8str value);
bool config_model_node_valid_interface_ref(utf8str value);
bool config_model_node_valid_interface_state_ref(utf8str value);
bool config_model_node_valid_ip_version(utf8str value);
bool config_model_node_valid_dscp(utf8str value);
bool config_model_node_valid_ipv6_flow_label(utf8str value);
bool config_model_node_valid_port_number(utf8str value);
bool config_model_node_valid_as_number(utf8str value);
bool config_model_node_valid_ip_address(utf8str value);
bool config_model_node_valid_ipv4_address(utf8str value);
bool config_model_node_valid_ipv6_address(utf8str value);
bool config_model_node_valid_ip_address_no_zone(utf8str value);
bool config_model_node_valid_ipv4_address_no_zone(utf8str value);
bool config_model_node_valid_ipv6_address_no_zone(utf8str value);
bool config_model_node_valid_ip_prefix(utf8str value);
bool config_model_node_valid_ipv4_prefix(utf8str value);
bool config_model_node_valid_ipv6_prefix(utf8str value);
bool config_model_node_valid_domain_name(utf8str value);
bool config_model_node_valid_host(utf8str value);
bool config_model_node_valid_uri(utf8str value);
bool config_model_node_valid_ip_address_origin(utf8str value);
bool config_model_node_valid_neighbor_origin(utf8str value);
bool config_model_node_valid_routing_instance_ref(utf8str value);
bool config_model_node_valid_routing_instance_state_ref(utf8str value);
bool config_model_node_valid_rib_ref(utf8str value);
bool config_model_node_valid_rib_state_ref(utf8str value);
bool config_model_node_valid_next_hop_list_ref(utf8str value);
bool config_model_node_valid_route_filter_ref(utf8str value);
bool config_model_node_valid_route_filter_state_ref(utf8str value);
bool config_model_node_valid_route_preference(utf8str value);

bool config_model_node_valid(config_model_node_type type, utf8str value);

