/**
 * @file	command_debug_config.cpp
 * @brief	設定デバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "command_debug.h"

#include "command_debug_config.h"

command_node *cn_show_debug_config;
command_node *cn_show_debug_config_running_config;
command_node *cn_show_debug_config_candidate_config;
command_node *cn_show_debug_config_model;

static void
dump_config_data_node_recursive(console_base &cb, config_data_node *cdn, int level)
{
	if (cdn == nullptr) {
		cb.print("dump_config_data_node_recursive: cdn == nullptr\n");
		return;
	}
	utf8str indent;
	for (int i = 0; i < level; ++i) {
		indent += "    ";
	}
	utf8str line;
	line += indent;
	switch (cdn->type()) {
	case config_data_node_type::type_root:
		line += "[R] ";
		break;
	case config_data_node_type::type_keyword:
		line += "[K] ";
		break;
	case config_data_node_type::type_variable:
		line += "[V] ";
		break;
	}
	if (cdn->config_model_node_() == nullptr) {
		line += "(NULL) ";
	} else {
		switch (cdn->config_model_node_()->statement()) {
		case config_model_node_statement::statement_container:
			line += "(CT:";
			break;
		case config_model_node_statement::statement_leaf:
			line += "(LF:";
			break;
		case config_model_node_statement::statement_leaf_list:
			line += "(LL:";
			break;
		case config_model_node_statement::statement_list:
			line += "(LT:";
			break;
		}
		line += cdn->config_model_node_()->identifier();
		line += ") ";
	}
	line += cdn->label();
	line += "\n";
	cb.print(line);
	sorted_list<config_data_node> &children = cdn->children();
	bidir_node<config_data_node> *bn;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		config_data_node &child = bn->v();
		dump_config_data_node_recursive(cb, &child, level + 1);
	}
}

static void
dump_config_model_node_recursive(console_base &cb, config_model_node *cmn, int level)
{
	if (cmn == nullptr) {
		cb.print("dump_config_model_node_recursive: cmn == nullptr\n");
		return;
	}
	utf8str indent;
	for (int i = 0; i < level; ++i) {
		indent += "    ";
	}
	utf8str line;
	line += indent;
	switch (cmn->statement()) {
	case config_model_node_statement::statement_container:
		line += "(CT) ";
		break;
	case config_model_node_statement::statement_leaf:
		line += "(LF) ";
		break;
	case config_model_node_statement::statement_leaf_list:
		line += "(LL) ";
		break;
	case config_model_node_statement::statement_list:
		line += "(LT) ";
		break;
	}
	line += cmn->identifier();
	line += "\n";
	line += indent;
	line += "\"";
	line += cmn->description()[0].msg;
	line += "\"\n";
	line += indent;
	line += "\"";
	line += cmn->description()[1].msg;
	line += "\"\n";
	cb.print(line);
	sorted_list<config_model_node> &children = cmn->children();
	bidir_node<config_model_node> *bn;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		config_model_node &child = bn->v();
		dump_config_model_node_recursive(cb, &child, level + 1);
	}
}

bool
cn_show_debug_config_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_show_debug_config_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "設定関連のデバッグ。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Configuration debug.",
	},
};

bool
cn_show_debug_config_running_config_execute(console_base &cb, utf8str command)
{
	dump_config_data_node_recursive(cb, config_data_node_running, 0);
	return true;
}

msg cn_show_debug_config_running_config_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "実行中の設定のツリーを表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump running config tree.",
	},
};

bool
cn_show_debug_config_candidate_config_execute(console_base &cb, utf8str command)
{
	dump_config_data_node_recursive(cb, config_data_node_candidate, 0);
	return true;
}

msg cn_show_debug_config_candidate_config_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "設定中の設定のツリーを表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump candidate config tree.",
	},
};

bool
cn_show_debug_config_model_execute(console_base &cb, utf8str command)
{
	dump_config_model_node_recursive(cb, config_model_node_root, 0);
	return true;
}

msg cn_show_debug_config_model_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "設定モデルのツリーを表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump configuration model tree.",
	},
};

void
command_debug_config_init()
{
	command_node *t;

	cn_show_debug_config = new command_node;
	t = cn_show_debug_config;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("config");
	t->execute(cn_show_debug_config_execute);
	t->description(cn_show_debug_config_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_config);

	cn_show_debug_config_running_config = new command_node;
	t = cn_show_debug_config_running_config;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("running-config");
	t->execute(cn_show_debug_config_running_config_execute);
	t->description(cn_show_debug_config_running_config_msg);
	t->parent(cn_show_debug_config);
	cn_show_debug_config->add_child(*cn_show_debug_config_running_config);

	cn_show_debug_config_candidate_config = new command_node;
	t = cn_show_debug_config_candidate_config;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("candidate-config");
	t->execute(cn_show_debug_config_candidate_config_execute);
	t->description(cn_show_debug_config_candidate_config_msg);
	t->parent(cn_show_debug_config);
	cn_show_debug_config->add_child(*cn_show_debug_config_candidate_config);

	cn_show_debug_config_model = new command_node;
	t = cn_show_debug_config_model;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("model");
	t->execute(cn_show_debug_config_model_execute);
	t->description(cn_show_debug_config_model_msg);
	t->parent(cn_show_debug_config);
	cn_show_debug_config->add_child(*cn_show_debug_config_model);
}

