/**
 * @file	command_debug.cpp
 * @brief	デバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"

#include "command_debug.h"

command_node *cn_show_debug;
command_node *cn_show_debug_running_config;
command_node *cn_show_debug_candidate_config;

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

bool
cn_show_debug_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_show_debug_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "デバッグ情報を表示する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Print debug messages.",
	},
};

bool
cn_show_debug_running_config_execute(console_base &cb, utf8str command)
{
	dump_config_data_node_recursive(cb, config_data_node_running, 0);
	return true;
}

msg cn_show_debug_running_config_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "実行中の設定ツリーを表示する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Print running config tree.",
	},
};

bool
cn_show_debug_candidate_config_execute(console_base &cb, utf8str command)
{
	dump_config_data_node_recursive(cb, config_data_node_candidate, 0);
	return true;
}

msg cn_show_debug_candidate_config_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "編集中の設定ツリーを表示する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Print candidate config tree.",
	},
};

void
command_debug_init()
{
	command_node *t;

	cn_show_debug = new command_node;
	t = cn_show_debug;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("debug");
	t->execute(cn_show_debug_execute);
	t->description(cn_show_debug_msg);
	t->parent(cn_show);
	cn_show->add_child(*cn_show_debug);

	cn_show_debug_running_config = new command_node;
	t = cn_show_debug_running_config;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("running-config");
	t->execute(cn_show_debug_running_config_execute);
	t->description(cn_show_debug_running_config_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_running_config);

	cn_show_debug_candidate_config = new command_node;
	t = cn_show_debug_candidate_config;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("candidate-config");
	t->execute(cn_show_debug_candidate_config_execute);
	t->description(cn_show_debug_candidate_config_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_candidate_config);

}

