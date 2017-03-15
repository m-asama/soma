/**
 * @file	command_debug_command.cpp
 * @brief	コマンド関連デバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "command_debug.h"

#include "command_debug_command.h"

command_node *cn_show_debug_command;
command_node *cn_show_debug_command_model;

static void
dump_command_node_recursive(console_base &cb, command_node *cn, int level)
{
	if (cn == nullptr) {
		cb.print("dump_command_node_recursive: cn == nullptr\n");
		return;
	}
	utf8str indent;
	for (int i = 0; i < level; ++i) {
		indent += "    ";
	}
	utf8str line;
	line += indent;
	switch (cn->node_type()) {
	case command_node_type::type_keyword:
		line += "[K] ";
		break;
	case command_node_type::type_variable:
		line += "[V] ";
		break;
	case command_node_type::type_config_model:
		line += "[M] ";
		break;
	case command_node_type::type_config_model_woleafs:
		line += "[N] ";
		break;
	case command_node_type::type_root:
		line += "[R] ";
		break;
	}
	line += cn->keyword_label();
	line += "\n";
	/*
	for (int i = 0; i < sizeof(console_lang); ++i) {
		for (int j = 0; j < sizeof(console_lang); ++j) {
			if (cn->description()[j].lang == (console_lang)i) {
				line += cn->description()[j].msg;
				line += "\n";
			}
		}
	}
	*/
	line += indent;
	line += "\"";
	line += cn->description()[0].msg;
	line += "\"\n";
	line += indent;
	line += "\"";
	line += cn->description()[1].msg;
	line += "\"\n";
	cb.print(line);
	sorted_list<command_node> &children = cn->children();
	bidir_node<command_node> *bn;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		command_node &child = bn->v();
		dump_command_node_recursive(cb, &child, level + 1);
	}
}

bool
cn_show_debug_command_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_show_debug_command_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "コマンド関連のデバッグ。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Command debug.",
	},
};

bool
cn_show_debug_command_model_execute(console_base &cb, utf8str command)
{
	dump_command_node_recursive(cb, command_node_root, 0);
	return true;
}

msg cn_show_debug_command_model_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "コマンドモデルのツリーを表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump command model tree.",
	},
};

void
command_debug_command_init()
{
	command_node *t;

	cn_show_debug_command = new command_node;
	t = cn_show_debug_command;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("command");
	t->execute(cn_show_debug_command_execute);
	t->description(cn_show_debug_command_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_command);

	cn_show_debug_command_model = new command_node;
	t = cn_show_debug_command_model;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("model");
	t->execute(cn_show_debug_command_model_execute);
	t->description(cn_show_debug_command_model_msg);
	t->parent(cn_show_debug_command);
	cn_show_debug_command->add_child(*cn_show_debug_command_model);
}

