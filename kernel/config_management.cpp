/**
 * @file	config_management.cpp
 * @brief	設定管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "unicode.h"
#include "config_model_build.h"
#include "config_model_node.h"
#include "config_model_validators.h"
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
config_model_node_nearest(utf8str path, config_model_node *&node,
	utf8str &remaining, uint64_t &arg_parsed, bool exclude_leaf)
{
	node = config_model_node_root;
	arg_parsed = 0;
	int i = 0;
	int len = path.unicode_length();
	while ((i < len) && (path[i] == ' ')) {
		++i;
	}
	utf8str token1, token2;
	while ((i < len) && (path[i] != '\0')) {
		token1 = "";
		while ((i < len)
		    && (path[i] != ' ') && (path[i] != '\0')) {
			token1 += path[i];
			++i;
		}
		sorted_list<config_model_node> &children = node->children();
		bidir_node<config_model_node> *bn;
		bool found = false;
		arg_parsed = 0;
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			if (bn->v().identifier() != token1) {
				continue;
			}
			config_model_node_type type;
			switch (bn->v().statement()) {
			case config_model_node_statement::statement_container:
				node = &bn->v();
				found = true;
				arg_parsed = 0;
				goto exit_loop;
				break;
			case config_model_node_statement::statement_leaf:
			case config_model_node_statement::statement_leaf_list:
				node = &bn->v();
				found = true;
				arg_parsed = 0;
				while ((i < len) && (path[i] == ' ')) {
					++i;
				}
				token2 = "";
				while ((i < len)
				    && (path[i] != ' ') && (path[i] != '\0')) {
					token2 += path[i];
					++i;
				}
				type = bn->v().type();
				if ((token2 != "")
				 && config_model_node_valid(type, token2)) {
					arg_parsed = 1;
				}
				goto exit_loop;
				break;
			case config_model_node_statement::statement_list:
				node = &bn->v();
				found = true;
				arg_parsed = 0;
				bidir_node<config_model_node> *bn2;
				for (bn2 = node->key().head(); bn2 != nullptr; bn2 = bn2->next()) {
					while ((i < len) && (path[i] == ' ')) {
						++i;
					}
					token2 = "";
					while ((i < len)
					    && (path[i] != ' ') && (path[i] != '\0')) {
						token2 += path[i];
						++i;
					}
					type = bn2->v().type();
					if ((token2 != "")
					 && config_model_node_valid(type, token2)) {
						++arg_parsed;
					}
				}
				goto exit_loop;
				break;
			}
		}
		exit_loop:
		if (found == false) {
			remaining = token1;
			for (int j = i; j < len; ++j) {
				remaining += path[j];
			}
			return 0;
		}
		while ((i < len) && (path[i] == ' ')) {
			++i;
		}
	}
	remaining = "";
	return 0;
}

int
config_data_node_find(config_data_node *root, utf8str path,
	config_data_node *&node)
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

