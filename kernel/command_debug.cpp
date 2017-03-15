/**
 * @file	command_debug.cpp
 * @brief	デバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "command_debug_memory.h"
#include "command_debug_pci.h"
#include "command_debug_command.h"
#include "command_debug_config.h"

#include "command_debug.h"

command_node *cn_show_debug;

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

	command_debug_memory_init();
	command_debug_pci_init();
	command_debug_command_init();
	command_debug_config_init();
}

