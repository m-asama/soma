/**
 * @file	config_model_validators_test.cpp
 * @brief	設定モデル値チェック関数のテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "config_model_validators.h"

void
config_model_validators_test()
{
	test_result res;

	memory_leak_test_begin();

	{
		utf8str s("192.168.0.1");
		if (config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192.168.1.1");
		if (config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192.168.1.1.1");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192.168.1");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192.168.1.1.");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s(".192.168.1.1");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192..1.1");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192.256.1.1");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}
	{
		utf8str s("192.16x.1.1");
		if (!config_model_node_valid_ipv4_address(s)) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result(s.ptr(), res);
	}

	memory_leak_test_end("設定モデル値チェック関数");
}

