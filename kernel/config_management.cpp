/**
 * @file	config_management.cpp
 * @brief	設定管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "debug.h"
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

bool
config_model_node_completed(config_model_node *&cmn, uint64_t pos)
{
	bool completed = false;
	switch (cmn->statement()) {
	case config_model_node_statement::statement_container:
		if (pos == 0) {
			completed = true;
		}
		break;
	case config_model_node_statement::statement_leaf:
	case config_model_node_statement::statement_leaf_list:
		if (pos == 1) {
			completed = true;
		} else {
			linked_list<config_model_type> &types = cmn->types();
			bidir_node<config_model_type> *bn;
			for (bn = types.head(); bn != nullptr; bn = bn->next()) {
				if (bn->v().type() == config_model_node_type::type_empty) {
					completed = true;
				}
			}
		}
		break;
	case config_model_node_statement::statement_list:
		if (pos == cmn->key().nodes()) {
			completed = true;
		}
		break;
	}
	return completed;
}

void
config_model_node_nearest(utf8str path, config_model_node *&node,
	utf8str &remaining, uint64_t &pos, bool exclude_leaf)
{
	node = config_model_node_root;
	pos = 0;
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
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			if (bn->v().identifier() != token1) {
				continue;
			}
			switch (bn->v().statement()) {
			case config_model_node_statement::statement_container:
				node = &bn->v();
				found = true;
				pos = 0;
				goto exit_loop;
				break;
			case config_model_node_statement::statement_leaf:
			case config_model_node_statement::statement_leaf_list:
				node = &bn->v();
				found = true;
				pos = 0;
				while ((i < len) && (path[i] == ' ')) {
					++i;
				}
				token2 = "";
				while ((i < len)
				    && (path[i] != ' ') && (path[i] != '\0')) {
					token2 += path[i];
					++i;
				}
				bidir_node<config_model_type> *bnt;
				for (bnt = node->types().head(); bnt != nullptr; bnt = bnt->next()) {
					config_model_type &type = bnt->v();
					if ((token2 != "")
					 && type.valid(token2)) {
						pos = 1;
					}
				}
				if (pos == 0) {
					remaining = token2;
					for (int j = i; j < len; ++j) {
						remaining += path[j];
					}
					return;
				}
				goto exit_loop;
				break;
			case config_model_node_statement::statement_list:
				node = &bn->v();
				found = true;
				pos = 0;
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
					bidir_node<config_model_type> *bnt;
					int posbak = pos;
					for (bnt = bn2->v().types().head(); bnt != nullptr; bnt = bnt->next()) {
						config_model_type &type = bnt->v();
						if ((token2 != "")
						 && type.valid(token2)) {
							++pos;
						}
					}
					if (pos == posbak) {
						remaining = token2;
						for (int j = i; j < len; ++j) {
							remaining += path[j];
						}
						return;
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
			return;
		}
		while ((i < len) && (path[i] == ' ')) {
			++i;
		}
	}
	remaining = "";
	return;
}

void
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
			return;
		}
		while ((i < len) && (path[i] == ' ')) {
			++i;
		}
	}
	node = root;
	return;
}

bool
config_data_node_nearest(utf8str path, config_data_node *&node, utf8str &remaining)
{
	if (node == nullptr) {
		return false;
	}
	int i = 0;
	int len = path.unicode_length();
	while ((i < len) && (path[i] == ' ')) {
		++i;
	}
	utf8str token;
	while ((i < len) && (path[i] != '\0')) {
		token = "";
		while ((i < len)
		     && (path[i] != ' ') && (path[i] != '\0')) {
			token += path[i];
			++i;
		}
		sorted_list<config_data_node> &children = node->children();
		bidir_node<config_data_node> *bn;
		bool found = false;
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			config_data_node &cdn = bn->v();
			if (cdn.label() == token) {
				node = &cdn;
				found = true;
				break;
			}
		}
		if (found == false) {
			remaining = token;
			for (int j = i; j < len; ++j) {
				remaining += path[j];
			}
			return false;
		}
		while ((i < len) && (path[i] == ' ')) {
			++i;
		}
	}
	remaining = "";
	return true;
}

bool
config_data_node_set(config_data_node *node, utf8str path)
{
	if (node == nullptr) {
		return false;
	}
	utf8str remaining;
	if (config_data_node_nearest(path, node, remaining) == true) {
		return true;
	}
	int i = 0;
	int len = remaining.unicode_length();
	while ((i < len) && (remaining[i] == ' ')) {
		++i;
	}

	utf8str token;
	while ((i < len) && (remaining[i] != '\0')) {
		token = "";
		while ((i < len)
		     && (remaining[i] != ' ') && (remaining[i] != '\0')) {
			token += remaining[i];
			++i;
		}
		int key_index = 0;
		config_data_node *kwnode = node;
		while (kwnode->type() == config_data_node_type::type_variable) {
			kwnode = kwnode->parent();
			++key_index;
		}
		config_model_node *kwn_model = kwnode->config_model_node_();
		sorted_list<config_model_node> &children = kwn_model->children();
		bidir_node<config_model_node> *bn;
		bool found = false;
		config_model_node *cmn = nullptr;
		config_data_node *newn = nullptr;
		int key_count;
		switch (kwn_model->statement()) {
		case config_model_node_statement::statement_container:
			for (bn = children.head(); bn != nullptr; bn = bn->next()) {
				if (bn->v().identifier() == token) {
					cmn = &bn->v();
					found = true;
					break;
				}
			}
			if (found == false) {
				dp("NOT FOUND");
				return false;
			}
			newn = new config_data_node;
			newn->type(config_data_node_type::type_keyword);
			newn->label(token);
			newn->config_model_node_(cmn);
			newn->parent(node);
			node->add_child(*newn);
			node = newn;
			break;
		case config_model_node_statement::statement_list:
			key_count = kwn_model->key().nodes();
			if (key_index == key_count) {
				// すでに list は完成している。
				for (bn = children.head(); bn != nullptr; bn = bn->next()) {
					if (bn->v().identifier() == token) {
						cmn = &bn->v();
						found = true;
						break;
					}
				}
				if (found == false) {
					return false;
				}
				newn = new config_data_node;
				newn->type(config_data_node_type::type_keyword);
				newn->label(token);
				newn->config_model_node_(cmn);
				newn->parent(node);
				node->add_child(*newn);
				node = newn;
			} else {
				// まだ指定されていない list の key が残っている。
				newn = new config_data_node;
				newn->label(token);
				newn->type(config_data_node_type::type_variable);
				newn->config_model_node_(kwn_model);
				newn->parent(node);
				node->add_child(*newn);
				node = newn;
			}
			break;
		case config_model_node_statement::statement_leaf:
		case config_model_node_statement::statement_leaf_list:
			newn = new config_data_node;
			newn->label(token);
			newn->type(config_data_node_type::type_variable);
			newn->config_model_node_(kwn_model);
			newn->parent(node);
			if ((kwn_model->statement() == config_model_node_statement::statement_leaf)
			 && (node->children().nodes() > 0)) {
				while (node->children().nodes() > 0) {
					config_data_node &t = node->children().head()->v();
					node->delete_child(t);
					delete &t;
				}
			}
			node->add_child(*newn);
			node = newn;
			break;
		}
		while ((i < len) && (remaining[i] == ' ')) {
			++i;
		}
	}
	return true;
}

static int
variable_count(config_data_node &node)
{
	int variable_count = 0;
	config_data_node *t = &node;
	while (t->type() == config_data_node_type::type_variable) {
		t = t->parent();
		++variable_count;
	}
	return variable_count;
}

static void
config_data_node_get_begin(utf8str &result, utf8str head, utf8str indent, config_data_node &node)
{
	switch (node.config_model_node_()->statement()) {
	case config_model_node_statement::statement_container:
		result += head;
		result += indent;
		result += node.label();
		result += " {\n";
		break;
	case config_model_node_statement::statement_leaf:
	case config_model_node_statement::statement_leaf_list:
		if (variable_count(node) == 1) {
			result += head;
			result += indent;
			result += node.parent()->label();
			result += " ";
			result += node.label();
			result += "\n";
		} else {
			linked_list<config_model_type> &types = node.config_model_node_()->types();
			bidir_node<config_model_type> *bn;
			for (bn = types.head(); bn != nullptr; bn = bn->next()) {
				if (bn->v().type() == config_model_node_type::type_empty) {
					result += head;
					result += indent;
					result += node.label();
					result += "\n";
				}
			}
		}
		break;
	case config_model_node_statement::statement_list:
		if (variable_count(node) == node.config_model_node_()->key().nodes()) {
			linked_list<utf8str> strlist;
			config_data_node *t = &node;
			for (int i = 0; i <= variable_count(node); ++i) {
				utf8str *strtmp = new utf8str(t->label());
				strlist.insert_head(*strtmp);
				t = t->parent();
			}
			result += head;
			result += indent;
			bidir_node<utf8str> *bn;
			for (bn = strlist.head(); bn != nullptr; bn = bn->next()) {
				result += bn->v();
				result += " ";
			}
			while (strlist.head() != nullptr) {
				utf8str *strtmp = &strlist.head()->v();
				strlist.remove(*strtmp);
				delete strtmp;
			}
			result += "{\n";
		}
		break;
	}
}

static void
config_data_node_get_end(utf8str &result, utf8str head, utf8str indent, config_data_node &node)
{
	switch (node.config_model_node_()->statement()) {
	case config_model_node_statement::statement_container:
		result += head;
		result += indent;
		result += "}\n";
		break;
	case config_model_node_statement::statement_list:
		if (variable_count(node) == node.config_model_node_()->key().nodes()) {
			result += head;
			result += indent;
			result += "}\n";
		}
		break;
	case config_model_node_statement::statement_leaf:
	case config_model_node_statement::statement_leaf_list:
		break;
	}
}

static int
next_level(int level, config_data_node &node)
{
	int next_level = level;
	switch (node.config_model_node_()->statement()) {
	case config_model_node_statement::statement_container:
		++next_level;
		break;
	case config_model_node_statement::statement_list:
		if (variable_count(node) == node.config_model_node_()->key().nodes()) {
			++next_level;
		}
		break;
	case config_model_node_statement::statement_leaf:
	case config_model_node_statement::statement_leaf_list:
		break;
	}
	return next_level;
}

static void
config_data_node_get_recursive(config_data_node *running, config_data_node *candidate, utf8str &result, int level)
{
	utf8str indent;
	for (int i = 0; i < level; ++i) {
		indent += "    ";
	}

	bidir_node<config_data_node> *bn_running = nullptr;
	if (running != nullptr) {
		bn_running = running->children().head();
	}

	bidir_node<config_data_node> *bn_candidate = nullptr;
	if (candidate != nullptr) {
		bn_candidate = candidate->children().head();
	}

	while ((bn_running != nullptr) || (bn_candidate != nullptr)) {
		if ((bn_running != nullptr)
		 && (bn_candidate != nullptr)
		 && (bn_running->v() == bn_candidate->v())) {
			config_data_node_get_begin(result, "  ", indent, bn_running->v());
			config_data_node_get_recursive(&bn_running->v(),
				&bn_candidate->v(), result, next_level(level, bn_running->v()));
			config_data_node_get_end(result, "  ", indent, bn_running->v());
			bn_running = bn_running->next();
			bn_candidate = bn_candidate->next();
		} else if ((bn_candidate == nullptr)
		 || ((bn_running != nullptr)
		  && (bn_candidate != nullptr)
		  && (bn_running->v() < bn_candidate->v()))) {
			config_data_node_get_begin(result, "- ", indent, bn_running->v());
			config_data_node_get_recursive(&bn_running->v(),
				nullptr, result, next_level(level, bn_running->v()));
			config_data_node_get_end(result, "- ", indent, bn_running->v());
			bn_running = bn_running->next();
		} else if ((bn_running == nullptr)
		 || ((bn_running != nullptr)
		  && (bn_candidate != nullptr)
		  && (bn_running->v() > bn_candidate->v()))) {
			config_data_node_get_begin(result, "+ ", indent, bn_candidate->v());
			config_data_node_get_recursive(nullptr,
				&bn_candidate->v(), result, next_level(level, bn_candidate->v()));
			config_data_node_get_end(result, "+ ", indent, bn_candidate->v());
			bn_candidate = bn_candidate->next();
		}
	}
}

bool
config_data_node_get(utf8str path, utf8str &result)
{
	config_data_node *running = nullptr;
	config_data_node *candidate = nullptr;
	config_data_node_find(config_data_node_running, path, running);
	config_data_node_find(config_data_node_candidate, path, candidate);
	config_data_node_get_recursive(running, candidate, result, 0);
	return true;
}

bool
config_data_node_delete(config_data_node *node, utf8str path)
{
	if (node == nullptr) {
		return false;
	}
	config_data_node *target = nullptr;
	config_data_node_find(node, path, target);
	if (target == nullptr) {
		return false;
	}
	config_data_node *parent = target->parent();
	parent->delete_child(*target);
	delete target;
//	while (parent->children().nodes() == 0) {
//	}
	return true;
}

void
config_init()
{
	config_model_build();
	config_data_node_running = new config_data_node;
	config_data_node_running->type(config_data_node_type::type_root);
	config_data_node_running->config_model_node_(config_model_node_root);
	config_data_node_candidate = new config_data_node;
	config_data_node_candidate->type(config_data_node_type::type_root);
	config_data_node_candidate->config_model_node_(config_model_node_root);
}

