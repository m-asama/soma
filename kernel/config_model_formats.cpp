/**
 * @file	config_model_formats.cpp
 * @brief	設定モデルフォーマット実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_formats.h"

msg fmt_binary_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "BINARY",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "BINARY",
	},
};

msg fmt_binary_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "バイナリー書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Binary format.",
	},
};

msg fmt_bits_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "BITS",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "BITS",
	},
};

msg fmt_bits_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "ビット列書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Bits format.",
	},
};

msg fmt_boolean_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "(true|false)",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "(true|false)",
	},
};

msg fmt_boolean_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "真偽値書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Boolean format.",
	},
};

msg fmt_decimal64_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "123.456",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "123.456",
	},
};

msg fmt_decimal64_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "10進数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Decimal format.",
	},
};

msg fmt_empty_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_empty",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_empty",
	},
};

msg fmt_empty_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_empty",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_empty",
	},
};

msg fmt_enumeration_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_enumeration",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_enumeration",
	},
};

msg fmt_enumeration_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_enumeration",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_enumeration",
	},
};

msg fmt_identityref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_identityref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_identityref",
	},
};

msg fmt_identityref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_identityref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_identityref",
	},
};

msg fmt_instance_identifier_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_instance_identifier",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_instance_identifier",
	},
};

msg fmt_instance_identifier_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_instance_identifier",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_instance_identifier",
	},
};

msg fmt_int8_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "-128..127",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "-128..127",
	},
};

msg fmt_int8_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号付き8ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Signed 8bits integer format.",
	},
};

msg fmt_int16_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "-32768..32767",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "-32768..32767",
	},
};

msg fmt_int16_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号付き16ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Signed 16bits integer format.",
	},
};

msg fmt_int32_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "-2147483648..2147483647",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "-2147483648..2147483647",
	},
};

msg fmt_int32_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号付き32ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Signed 32bits integer format.",
	},
};

msg fmt_int64_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "-9223372036854775808..9223372036854775807",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "-9223372036854775808..9223372036854775807",
	},
};

msg fmt_int64_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号付き32ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Signed 32bits integer format.",
	},
};

msg fmt_leafref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_leafref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_leafref",
	},
};

msg fmt_leafref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_leafref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_leafref",
	},
};

msg fmt_string_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "STRING",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "STRING",
	},
};

msg fmt_string_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "文字列書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "String format.",
	},
};

msg fmt_uint8_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "0..255",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "0..255",
	},
};

msg fmt_uint8_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号無し8ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Unsigned 8bits integer format.",
	},
};

msg fmt_uint16_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "0..65535",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "0..65535",
	},
};

msg fmt_uint16_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号無し16ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Unsigned 16bits integer format.",
	},
};

msg fmt_uint32_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "0..4294967295",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "0..4294967295",
	},
};

msg fmt_uint32_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号無し32ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Unsigned 32bits integer format.",
	},
};

msg fmt_uint64_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "0..18446744073709551615",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "0..18446744073709551615",
	},
};

msg fmt_uint64_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "符号無し32ビット整数書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Unsigned 32bits integer format.",
	},
};

msg fmt_union_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_union",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_union",
	},
};

msg fmt_union_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_union",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_union",
	},
};

msg fmt_counter32_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_counter32",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_counter32",
	},
};

msg fmt_counter32_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_counter32",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_counter32",
	},
};

msg fmt_zero_based_counter32_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_zero_based_counter32",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_zero_based_counter32",
	},
};

msg fmt_zero_based_counter32_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_zero_based_counter32",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_zero_based_counter32",
	},
};

msg fmt_counter64_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_counter64",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_counter64",
	},
};

msg fmt_counter64_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_counter64",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_counter64",
	},
};

msg fmt_zero_based_counter64_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_zero_based_counter64",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_zero_based_counter64",
	},
};

msg fmt_zero_based_counter64_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_zero_based_counter64",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_zero_based_counter64",
	},
};

msg fmt_gauge32_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_gauge32",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_gauge32",
	},
};

msg fmt_gauge32_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_gauge32",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_gauge32",
	},
};

msg fmt_gauge64_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_gauge64",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_gauge64",
	},
};

msg fmt_gauge64_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_gauge64",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_gauge64",
	},
};

msg fmt_object_identifier_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_object_identifier",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_object_identifier",
	},
};

msg fmt_object_identifier_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_object_identifier",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_object_identifier",
	},
};

msg fmt_object_identifier_128_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_object_identifier_128",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_object_identifier_128",
	},
};

msg fmt_object_identifier_128_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_object_identifier_128",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_object_identifier_128",
	},
};

msg fmt_yang_identifier_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_yang_identifier",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_yang_identifier",
	},
};

msg fmt_yang_identifier_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_yang_identifier",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_yang_identifier",
	},
};

msg fmt_date_and_time_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_date_and_time",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_date_and_time",
	},
};

msg fmt_date_and_time_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_date_and_time",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_date_and_time",
	},
};

msg fmt_timeticks_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_timeticks",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_timeticks",
	},
};

msg fmt_timeticks_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_timeticks",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_timeticks",
	},
};

msg fmt_timestamp_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_timestamp",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_timestamp",
	},
};

msg fmt_timestamp_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_timestamp",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_timestamp",
	},
};

msg fmt_phys_address_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "([0-9a-fA-F]{2}(:[0-9a-fA-F]{2})*)?",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "([0-9a-fA-F]{2}(:[0-9a-fA-F]{2})*)?",
	},
};

msg fmt_phys_address_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "物理アドレス書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Physical address format.",
	},
};

msg fmt_mac_address_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "XX:XX:XX:XX:XX:XX",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "XX:XX:XX:XX:XX:XX",
	},
};

msg fmt_mac_address_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "MACアドレス書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "MAC address format.",
	},
};

msg fmt_xpath1_0_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_xpath1_0",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_xpath1_0",
	},
};

msg fmt_xpath1_0_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_xpath1_0",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_xpath1_0",
	},
};

msg fmt_hex_string_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_hex_string",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_hex_string",
	},
};

msg fmt_hex_string_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_hex_string",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_hex_string",
	},
};

msg fmt_uuid_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_uuid",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_uuid",
	},
};

msg fmt_uuid_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_uuid",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_uuid",
	},
};

msg fmt_dotted_quad_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_dotted_quad",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_dotted_quad",
	},
};

msg fmt_dotted_quad_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_dotted_quad",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_dotted_quad",
	},
};

msg fmt_interface_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_interface_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_interface_ref",
	},
};

msg fmt_interface_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_interface_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_interface_ref",
	},
};

msg fmt_interface_state_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_interface_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_interface_state_ref",
	},
};

msg fmt_interface_state_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_interface_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_interface_state_ref",
	},
};

msg fmt_ip_version_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_version",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_version",
	},
};

msg fmt_ip_version_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_version",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_version",
	},
};

msg fmt_dscp_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_dscp",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_dscp",
	},
};

msg fmt_dscp_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_dscp",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_dscp",
	},
};

msg fmt_ipv6_flow_label_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ipv6_flow_label",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ipv6_flow_label",
	},
};

msg fmt_ipv6_flow_label_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ipv6_flow_label",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ipv6_flow_label",
	},
};

msg fmt_port_number_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "0..65535",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "0..65535",
	},
};

msg fmt_port_number_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "ポート番号書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Port number format.",
	},
};

msg fmt_as_number_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_as_number",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_as_number",
	},
};

msg fmt_as_number_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_as_number",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_as_number",
	},
};

msg fmt_ip_address_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_address",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_address",
	},
};

msg fmt_ip_address_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_address",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_address",
	},
};

msg fmt_ipv4_address_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "XXX.XXX.XXX.XXX(%XXX)?",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "XXX.XXX.XXX.XXX(%XXX)?",
	},
};

msg fmt_ipv4_address_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "IPv4アドレス書式(ゾーン情報付加可)。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "IPv4 address format(with zone index).",
	},
};

msg fmt_ipv6_address_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "X:X:X:X::X(%XXX)?",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "X:X:X:X::X(%XXX)?",
	},
};

msg fmt_ipv6_address_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "IPv6アドレス書式(ゾーン情報付加可)。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "IPv6 address format(with zone index).",
	},
};

msg fmt_ip_address_no_zone_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_address_no_zone",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_address_no_zone",
	},
};

msg fmt_ip_address_no_zone_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_address_no_zone",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_address_no_zone",
	},
};

msg fmt_ipv4_address_no_zone_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "XXX.XXX.XXX.XXX",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "XXX.XXX.XXX.XXX",
	},
};

msg fmt_ipv4_address_no_zone_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "IPv4アドレス書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "IPv4 address format.",
	},
};

msg fmt_ipv6_address_no_zone_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "X:X:X:X::X",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "X:X:X:X::X",
	},
};

msg fmt_ipv6_address_no_zone_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "IPv6アドレス書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "IPv6 address format.",
	},
};

msg fmt_ip_prefix_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_prefix",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_prefix",
	},
};

msg fmt_ip_prefix_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_prefix",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_prefix",
	},
};

msg fmt_ipv4_prefix_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "XXX.XXX.XXX.XXX/XX",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "XXX.XXX.XXX.XXX/XX",
	},
};

msg fmt_ipv4_prefix_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "IPv4プレフィクス書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "IPv4 prefix format.",
	},
};

msg fmt_ipv6_prefix_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "X:X:X:X::X/XX",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "X:X:X:X::X/XX",
	},
};

msg fmt_ipv6_prefix_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "IPv6プレフィクス書式。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "IPv6 prefix format.",
	},
};

msg fmt_domain_name_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_domain_name",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_domain_name",
	},
};

msg fmt_domain_name_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_domain_name",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_domain_name",
	},
};

msg fmt_host_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_host",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_host",
	},
};

msg fmt_host_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_host",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_host",
	},
};

msg fmt_uri_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_uri",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_uri",
	},
};

msg fmt_uri_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_uri",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_uri",
	},
};

msg fmt_ip_address_origin_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_address_origin",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_address_origin",
	},
};

msg fmt_ip_address_origin_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_ip_address_origin",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_ip_address_origin",
	},
};

msg fmt_neighbor_origin_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_neighbor_origin",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_neighbor_origin",
	},
};

msg fmt_neighbor_origin_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_neighbor_origin",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_neighbor_origin",
	},
};

msg fmt_routing_instance_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_routing_instance_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_routing_instance_ref",
	},
};

msg fmt_routing_instance_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_routing_instance_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_routing_instance_ref",
	},
};

msg fmt_routing_instance_state_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_routing_instance_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_routing_instance_state_ref",
	},
};

msg fmt_routing_instance_state_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_routing_instance_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_routing_instance_state_ref",
	},
};

msg fmt_rib_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_rib_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_rib_ref",
	},
};

msg fmt_rib_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_rib_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_rib_ref",
	},
};

msg fmt_rib_state_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_rib_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_rib_state_ref",
	},
};

msg fmt_rib_state_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_rib_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_rib_state_ref",
	},
};

msg fmt_next_hop_list_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_next_hop_list_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_next_hop_list_ref",
	},
};

msg fmt_next_hop_list_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_next_hop_list_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_next_hop_list_ref",
	},
};

msg fmt_route_filter_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_route_filter_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_route_filter_ref",
	},
};

msg fmt_route_filter_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_route_filter_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_route_filter_ref",
	},
};

msg fmt_route_filter_state_ref_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_route_filter_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_route_filter_state_ref",
	},
};

msg fmt_route_filter_state_ref_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_route_filter_state_ref",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_route_filter_state_ref",
	},
};

msg fmt_route_preference_frmt[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_route_preference",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_route_preference",
	},
};

msg fmt_route_preference_dscr[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "fmt_route_preference",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "fmt_route_preference",
	},
};

