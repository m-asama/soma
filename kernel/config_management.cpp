/**
 * @file	config_management.cpp
 * @brief	設定管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "unicode.h"
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
	s += n->identifier();
	s += "\n";
	print(s);
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

int
config_model_node_nearest(utf8str path, config_model_node *&node, utf8str &remaining, bool exclude_leaf)
{
	return 0;
}

int
config_data_node_find(config_data_node *root, utf8str path, config_data_node *&node)
{
	int i = 0;
	int len = path.unicode_length();
	while ((i < len) && (path[i] == ' ')) {
		++i;
	}
	utf8str token;
	while ((i < len) && (path[i] != '\0')) {
		token = "";
		while ((i < len) && (path[i] != ' ') && (path[i] != '\0')) {
			token += path[i];
			++i;
		}
		sorted_list<config_data_node> &children = root->children();
		bidir_node<config_data_node> *bn;
		bool found = false;
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			if (bn->v().label() == token) {
				root = &bn->v();
				found = true;
				break;
			}
		}
		if (found == false) {
			node = nullptr;
			return 0;
		}
		while ((i < len) && (path[i] == ' ')) {
			++i;
		}
	}
	node = root;
	return 0;
}

void
config_init()
{
	config_data_node_running = new config_data_node;
	config_data_node_running->type(config_data_node_type::type_root);
	config_data_node_candidate = new config_data_node;
	config_data_node_candidate->type(config_data_node_type::type_root);
	config_model_build();
}

