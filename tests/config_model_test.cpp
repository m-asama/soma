/**
 * @file	config_model_test.cpp
 * @brief	設定モデルのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"
#include "utf8str.h"
#include "config_model_build.h"
#include "config_model_node.h"

config_model_node *config_model_node_root;

void
config_model_test()
{
	test_result res = test_result::pass;

	config_model_build();

	print_test_result("aaa", res);
	utf8str x;
	x.append_hex64((uint64_t)config_model_node_root->identifier().ptr(), 16);
	print_test_result(x.ptr(), res);
	print_test_result(config_model_node_root->identifier().ptr(), res);

	sorted_list<config_model_node> &children = config_model_node_root->children();
	bidir_node<config_model_node> *bn;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		print_test_result("bbb", res);
		print_test_result(bn->v().identifier().ptr(), res);
	}
}

