/**
 * @file	config_management.cpp
 * @brief	設定管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "config_model_build.h"
#include "config_model_node.h"
#include "config_data_node.h"

#include "config_management.h"

config_model_node *config_model_node_root;

config_data_node *config_data_node_running;
config_data_node *config_data_node_candidate;

void
config_model_dump_recursive(config_model_node *n, int indent)
{
	utf8str s;
	for (int i = indent; i > 0; --i) {
		s += "    ";
	}
	if (n->identifier().ptr() != nullptr) {
		s += n->identifier().ptr();
	}
	s += "\n";
	printstr(s);
	bidir_node<config_model_node> *bn;
	for (bn = n->children().head(); bn != nullptr; bn = bn->next()) {
		if (bn->v().config() == true)
			config_model_dump_recursive(&bn->v(), indent + 1);
	}
}

void
config_model_dump()
{
	config_model_dump_recursive(config_model_node_root, 0);
}

void
config_init()
{
	config_data_node_running = new config_data_node;
	config_data_node_running->type(config_data_node_type::type_keyword);
	config_data_node_running->label("");
	config_data_node_candidate = new config_data_node;
	config_data_node_candidate->type(config_data_node_type::type_keyword);
	config_data_node_candidate->label("");
	config_model_build();
}

