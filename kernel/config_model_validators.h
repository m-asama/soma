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

bool config_model_node_valid(config_model_node_type type, utf8str value);

