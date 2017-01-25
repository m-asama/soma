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
config_model_node_valid_counter32(utf8str value)
{
	return config_model_node_valid_uint32(value);
}

bool
config_model_node_valid_zero_based_counter32(utf8str value)
{
	return config_model_node_valid_uint32(value);
}

bool
config_model_node_valid_counter64(utf8str value)
{
	return config_model_node_valid_uint64(value);
}

bool
config_model_node_valid_zero_based_counter64(utf8str value)
{
	return config_model_node_valid_uint64(value);
}

bool
config_model_node_valid_gauge32(utf8str value)
{
	return config_model_node_valid_uint32(value);
}

bool
config_model_node_valid_gauge64(utf8str value)
{
	return config_model_node_valid_uint64(value);
}

bool
config_model_node_valid_object_identifier(utf8str value)
{
	return true;
}

bool
config_model_node_valid_object_identifier_128(utf8str value)
{
	return true;
}

bool
config_model_node_valid_yang_identifier(utf8str value)
{
	return true;
}

bool
config_model_node_valid_date_and_time(utf8str value)
{
	return true;
}

bool
config_model_node_valid_timeticks(utf8str value)
{
	return true;
}

bool
config_model_node_valid_timestamp(utf8str value)
{
	return true;
}

bool
config_model_node_valid_phys_address(utf8str value)
{
	return config_model_node_valid_hex_string(value);
}

bool
config_model_node_valid_mac_address(utf8str value)
{
	if (value.byte_length() != 17) {
		return false;
	}
	return config_model_node_valid_hex_string(value);
}

bool
config_model_node_valid_xpath1_0(utf8str value)
{
	return true;
}

bool
config_model_node_valid_hex_string(utf8str value)
{
	if (value == "") {
		return true;
	}
	int i = 0;
	if (((value.byte_at(i) >= '0' && value.byte_at(i) <= '9')
	  || (value.byte_at(i) >= 'A' && value.byte_at(i) <= 'F')
	  || (value.byte_at(i) >= 'a' && value.byte_at(i) <= 'f'))
	 && ((value.byte_at(i + 1) >= '0' && value.byte_at(i + 1) <= '9')
	  || (value.byte_at(i + 1) >= 'A' && value.byte_at(i + 1) <= 'F')
	  || (value.byte_at(i + 1) >= 'a' && value.byte_at(i + 1) <= 'f'))) {
	} else {
		return false;
	}
	i += 2;
	while ((value.byte_at(i) != '\0')
	    && (value.byte_at(i + 1) != '\0')
	    && (value.byte_at(i + 2) != '\0')) {
		if ((value.byte_at(i) == ':')
		 && ((value.byte_at(i + 1) >= '0' && value.byte_at(i + 1) <= '9')
		  || (value.byte_at(i + 1) >= 'A' && value.byte_at(i + 1) <= 'F')
		  || (value.byte_at(i + 1) >= 'a' && value.byte_at(i + 1) <= 'f'))
		 && ((value.byte_at(i + 2) >= '0' && value.byte_at(i + 2) <= '9')
		  || (value.byte_at(i + 2) >= 'A' && value.byte_at(i + 2) <= 'F')
		  || (value.byte_at(i + 2) >= 'a' && value.byte_at(i + 2) <= 'f'))) {
		} else {
			return false;
		}
		i += 3;
	}
	return true;
}

bool
config_model_node_valid_uuid(utf8str value)
{
	return true;
}

bool
config_model_node_valid_dotted_quad(utf8str value)
{
	return true;
}

bool
config_model_node_valid_interface_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_interface_state_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ip_version(utf8str value)
{
	return true;
}

bool
config_model_node_valid_dscp(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ipv6_flow_label(utf8str value)
{
	return true;
}

bool
config_model_node_valid_port_number(utf8str value)
{
	return true;
}

bool
config_model_node_valid_as_number(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ip_address(utf8str value)
{
	if (config_model_node_valid_ipv4_address(value)
	 || config_model_node_valid_ipv6_address(value)) {
		return true;
	}
	return false;
}

bool
config_model_node_valid_ipv4_address(utf8str value)
{
	char *p = nullptr;
	char buf[256];

	for (int i = 0; i < 256; ++i) {
		buf[i] = '\0';
	}
	int t = value.byte_length();
	if (t >= 255) {
		t = 255;
	}
	for (int i = 0; i < t; ++i) {
		buf[i] = value.byte_at(i);
	}

	/* インターフェース部分のチェック */
	int pcount = 0;
	p = buf;
	while (*p != '\0') {
		if (*p == '%') {
			*p = '\0';
			++pcount;
		}
		++p;
	}
	if (pcount > 1) {
		return false;
	}


	/* アドレス部分のチェック */
	char *optr[4];
	p = buf;
	int index = 0;
	optr[index] = p;
	++index;
	while (*p != '\0') {
		if (*p == '.') {
			if (index == 4) {
				return false;
			}
			*p = '\0';
			optr[index] = p + 1;
			++index;
		}
		++p;
	}
	if (index != 4) {
		return false;
	}
	for (int i = 0; i < 4; ++i) {
		p = optr[i];
		if (*p == '\0') {
			return false;
		}
		if (parse_uint64(p) > 255) {
			return false;
		}
		while (*p != '\0') {
			if ((*p < '0') || (*p > '9')) {
				return false;
			}
			++p;
		}
	}

	return true;
}

bool
config_model_node_valid_ipv6_address(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ip_address_no_zone(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ipv4_address_no_zone(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ipv6_address_no_zone(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ip_prefix(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ipv4_prefix(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ipv6_prefix(utf8str value)
{
	return true;
}

bool
config_model_node_valid_domain_name(utf8str value)
{
	return true;
}

bool
config_model_node_valid_host(utf8str value)
{
	return true;
}

bool
config_model_node_valid_uri(utf8str value)
{
	return true;
}

bool
config_model_node_valid_ip_address_origin(utf8str value)
{
	return true;
}

bool
config_model_node_valid_neighbor_origin(utf8str value)
{
	return true;
}

bool
config_model_node_valid_routing_instance_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_routing_instance_state_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_rib_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_rib_state_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_next_hop_list_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_route_filter_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_route_filter_state_ref(utf8str value)
{
	return true;
}

bool
config_model_node_valid_route_preference(utf8str value)
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
	case config_model_node_type::type_counter32:
		return config_model_node_valid_counter32(value);
		break;
	case config_model_node_type::type_zero_based_counter32:
		return config_model_node_valid_zero_based_counter32(value);
		break;
	case config_model_node_type::type_counter64:
		return config_model_node_valid_counter64(value);
		break;
	case config_model_node_type::type_zero_based_counter64:
		return config_model_node_valid_zero_based_counter64(value);
		break;
	case config_model_node_type::type_gauge32:
		return config_model_node_valid_gauge32(value);
		break;
	case config_model_node_type::type_gauge64:
		return config_model_node_valid_gauge64(value);
		break;
	case config_model_node_type::type_object_identifier:
		return config_model_node_valid_object_identifier(value);
		break;
	case config_model_node_type::type_object_identifier_128:
		return config_model_node_valid_object_identifier_128(value);
		break;
	case config_model_node_type::type_yang_identifier:
		return config_model_node_valid_yang_identifier(value);
		break;
	case config_model_node_type::type_date_and_time:
		return config_model_node_valid_date_and_time(value);
		break;
	case config_model_node_type::type_timeticks:
		return config_model_node_valid_timeticks(value);
		break;
	case config_model_node_type::type_timestamp:
		return config_model_node_valid_timestamp(value);
		break;
	case config_model_node_type::type_phys_address:
		return config_model_node_valid_phys_address(value);
		break;
	case config_model_node_type::type_mac_address:
		return config_model_node_valid_mac_address(value);
		break;
	case config_model_node_type::type_xpath1_0:
		return config_model_node_valid_xpath1_0(value);
		break;
	case config_model_node_type::type_hex_string:
		return config_model_node_valid_hex_string(value);
		break;
	case config_model_node_type::type_uuid:
		return config_model_node_valid_uuid(value);
		break;
	case config_model_node_type::type_dotted_quad:
		return config_model_node_valid_dotted_quad(value);
		break;
	case config_model_node_type::type_interface_ref:
		return config_model_node_valid_interface_ref(value);
		break;
	case config_model_node_type::type_interface_state_ref:
		return config_model_node_valid_interface_state_ref(value);
		break;
	case config_model_node_type::type_ip_version:
		return config_model_node_valid_ip_version(value);
		break;
	case config_model_node_type::type_dscp:
		return config_model_node_valid_dscp(value);
		break;
	case config_model_node_type::type_ipv6_flow_label:
		return config_model_node_valid_ipv6_flow_label(value);
		break;
	case config_model_node_type::type_port_number:
		return config_model_node_valid_port_number(value);
		break;
	case config_model_node_type::type_as_number:
		return config_model_node_valid_as_number(value);
		break;
	case config_model_node_type::type_ip_address:
		return config_model_node_valid_ip_address(value);
		break;
	case config_model_node_type::type_ipv4_address:
		return config_model_node_valid_ipv4_address(value);
		break;
	case config_model_node_type::type_ipv6_address:
		return config_model_node_valid_ipv6_address(value);
		break;
	case config_model_node_type::type_ip_address_no_zone:
		return config_model_node_valid_ip_address_no_zone(value);
		break;
	case config_model_node_type::type_ipv4_address_no_zone:
		return config_model_node_valid_ipv4_address_no_zone(value);
		break;
	case config_model_node_type::type_ipv6_address_no_zone:
		return config_model_node_valid_ipv6_address_no_zone(value);
		break;
	case config_model_node_type::type_ip_prefix:
		return config_model_node_valid_ip_prefix(value);
		break;
	case config_model_node_type::type_ipv4_prefix:
		return config_model_node_valid_ipv4_prefix(value);
		break;
	case config_model_node_type::type_ipv6_prefix:
		return config_model_node_valid_ipv6_prefix(value);
		break;
	case config_model_node_type::type_domain_name:
		return config_model_node_valid_domain_name(value);
		break;
	case config_model_node_type::type_host:
		return config_model_node_valid_host(value);
		break;
	case config_model_node_type::type_uri:
		return config_model_node_valid_uri(value);
		break;
	case config_model_node_type::type_ip_address_origin:
		return config_model_node_valid_ip_address_origin(value);
		break;
	case config_model_node_type::type_neighbor_origin:
		return config_model_node_valid_neighbor_origin(value);
		break;
	case config_model_node_type::type_routing_instance_ref:
		return config_model_node_valid_routing_instance_ref(value);
		break;
	case config_model_node_type::type_routing_instance_state_ref:
		return config_model_node_valid_routing_instance_state_ref(value);
		break;
	case config_model_node_type::type_rib_ref:
		return config_model_node_valid_rib_ref(value);
		break;
	case config_model_node_type::type_rib_state_ref:
		return config_model_node_valid_rib_state_ref(value);
		break;
	case config_model_node_type::type_next_hop_list_ref:
		return config_model_node_valid_next_hop_list_ref(value);
		break;
	case config_model_node_type::type_route_filter_ref:
		return config_model_node_valid_route_filter_ref(value);
		break;
	case config_model_node_type::type_route_filter_state_ref:
		return config_model_node_valid_route_filter_state_ref(value);
		break;
	case config_model_node_type::type_route_preference:
		return config_model_node_valid_route_preference(value);
		break;
	}
}

