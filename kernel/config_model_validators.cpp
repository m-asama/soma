/**
 * @file	config_model_validators.cpp
 * @brief	設定モデルノードの値チェック関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_validators.h"

bool
config_model_node_valid_binary(utf8str value)
{
	return true;
}

bool
config_model_node_valid_bits(utf8str value)
{
	return true;
}

bool
config_model_node_valid_boolean(utf8str value)
{
	return false;
}

bool
config_model_node_valid_decimal64(utf8str value)
{
	return true;
}

bool
config_model_node_valid_empty(utf8str value)
{
	return false;
}

bool
config_model_node_valid_enumeration(utf8str value)
{
	return true;
}

bool
config_model_node_valid_identityref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_instance_identifier(utf8str value)
{
	return true;
}

bool
config_model_node_valid_int8(utf8str value)
{
	return true;
}

bool
config_model_node_valid_int16(utf8str value)
{
	return true;
}

bool
config_model_node_valid_int32(utf8str value)
{
	return true;
}

bool
config_model_node_valid_int64(utf8str value)
{
	return true;
}

bool
config_model_node_valid_leafref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_string(utf8str value)
{
	return true;
}

bool
config_model_node_valid_uint8(utf8str value)
{
	return true;
}

bool
config_model_node_valid_uint16(utf8str value)
{
	return true;
}

bool
config_model_node_valid_uint32(utf8str value)
{
	return true;
}

bool
config_model_node_valid_uint64(utf8str value)
{
	return true;
}

bool
config_model_node_valid_union(utf8str value)
{
	return true;
}

bool
config_model_node_valid(config_model_node_type type, utf8str value)
{
	switch (type) {
	case config_model_node_type::type_binary:
		return config_model_node_valid_binary(value);
		break;
	case config_model_node_type::type_bits:
		return config_model_node_valid_bits(value);
		break;
	case config_model_node_type::type_boolean:
		return config_model_node_valid_boolean(value);
		break;
	case config_model_node_type::type_decimal64:
		return config_model_node_valid_decimal64(value);
		break;
	case config_model_node_type::type_empty:
		return config_model_node_valid_empty(value);
		break;
	case config_model_node_type::type_enumeration:
		return config_model_node_valid_enumeration(value);
		break;
	case config_model_node_type::type_identityref:
		return config_model_node_valid_identityref(value);
		break;
	case config_model_node_type::type_instance_identifier:
		return config_model_node_valid_instance_identifier(value);
		break;
	case config_model_node_type::type_int8:
		return config_model_node_valid_int8(value);
		break;
	case config_model_node_type::type_int16:
		return config_model_node_valid_int16(value);
		break;
	case config_model_node_type::type_int32:
		return config_model_node_valid_int32(value);
		break;
	case config_model_node_type::type_int64:
		return config_model_node_valid_int64(value);
		break;
	case config_model_node_type::type_leafref:
		return config_model_node_valid_leafref(value);
		break;
	case config_model_node_type::type_string:
		return config_model_node_valid_string(value);
		break;
	case config_model_node_type::type_uint8:
		return config_model_node_valid_uint8(value);
		break;
	case config_model_node_type::type_uint16:
		return config_model_node_valid_uint16(value);
		break;
	case config_model_node_type::type_uint32:
		return config_model_node_valid_uint32(value);
		break;
	case config_model_node_type::type_uint64:
		return config_model_node_valid_uint64(value);
		break;
	case config_model_node_type::type_union:
		return config_model_node_valid_union(value);
		break;
	}
}

