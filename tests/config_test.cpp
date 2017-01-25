/**
 * @file	config_test.cpp
 * @brief	設定のテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"
#include "utf8str.h"
#include "config_model_build.h"
#include "config_model_node.h"
#include "config_data_node.h"

config_model_node *config_model_node_root;

void
print_rec(config_data_node *n, int indent)
{
	test_result res = test_result::pass;
	utf8str si;
	si += "0x";
	si.append_hex64((uint64_t)n, 16);
	si += " ";
	si.append_hex64((uint64_t)n->parent(), 16);
	si += " ";
	for (int i = 0; i < indent; ++i) {
		si += "    ";
	}
	si += n->label();
	print_test_result(si, res);
	sorted_list<config_data_node> &children = n->children();
	bidir_node<config_data_node> *bn;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		print_rec(&bn->v(), indent + 1);
	}
}

void
config_test()
{
	test_result res = test_result::pass;

	config_model_build();

/*
	print_test_result("aaa", res);
	utf8str x;
	x.append_hex64((uint64_t)config_model_node_root->identifier(), 16);
	print_test_result(x, res);
	print_test_result(config_model_node_root->identifier(), res);

*/
	sorted_list<config_model_node> &children = config_model_node_root->children();
	bidir_node<config_model_node> *bn;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		print_test_result("bbb", res);
		print_test_result(bn->v().identifier(), res);
	}

	if (config_data_node::count() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("config_data_node 割当数", res);

	config_data_node *r1, *r2, *r3;
	config_data_node *p1, *p2;
	config_data_node *c1, *c2;

	c1 = new config_data_node;
	c1->type(config_data_node_type::type_variable);
	c1->label("child1");
	
	c2 = new config_data_node;
	c2->type(config_data_node_type::type_variable);
	c2->label("child2");
	
	p1 = new config_data_node;
	p1->type(config_data_node_type::type_keyword);
	p1->label("parent1");
	
	p2 = new config_data_node;
	p2->type(config_data_node_type::type_keyword);
	p2->label("parent2");
	
	r1 = new config_data_node;
	r1->type(config_data_node_type::type_keyword);
	r1->label("root");

	c1->parent(p1);
	p1->add_child(*c1);

	c2->parent(p2);
	p2->add_child(*c2);

	p1->parent(r1);
	p2->parent(r1);
	r1->add_child(*p1);
	r1->add_child(*p2);

	r2 = new config_data_node;
	*r2 = *r1;

	r3 = new config_data_node(*r1);

	print_rec(r1, 0);
	print_rec(r2, 0);
	print_rec(r3, 0);

	delete r1;
	delete r2;
	delete r3;

	if (config_data_node::count() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("config_data_node 割当数", res);
	
}

