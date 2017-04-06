/**
 * @file	command_debug_memory.cpp
 * @brief	メモリデバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "command_debug.h"
#include "memory_management.h"

#include "command_debug_memory.h"

command_node *cn_show_debug_memory;
command_node *cn_show_debug_memory_memory_map;
command_node *cn_show_debug_memory_dump;

bool
cn_show_debug_memory_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_show_debug_memory_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "メモリ関連のデバッグ。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Memory debug.",
	},
};

bool
cn_show_debug_memory_memory_map_execute(console_base &cb, utf8str command)
{
	cb.print(memory_debug_memory_map());
	return true;
}

msg cn_show_debug_memory_memory_map_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "メモリマップを表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump MemoryMap.",
	},
};

bool
cn_show_debug_memory_dump_execute(console_base &cb, utf8str command)
{
	cb.print(memory_dump());
	return true;
}

msg cn_show_debug_memory_dump_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "メモリ管理情報を表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump Memory Usage.",
	},
};

void
command_debug_memory_init()
{
	command_node *t;

	cn_show_debug_memory = new command_node;
	t = cn_show_debug_memory;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("memory");
	t->execute(cn_show_debug_memory_execute);
	t->description(cn_show_debug_memory_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_memory);

	cn_show_debug_memory_memory_map = new command_node;
	t = cn_show_debug_memory_memory_map;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("memory-map");
	t->execute(cn_show_debug_memory_memory_map_execute);
	t->description(cn_show_debug_memory_memory_map_msg);
	t->parent(cn_show_debug_memory);
	cn_show_debug_memory->add_child(*cn_show_debug_memory_memory_map);

	cn_show_debug_memory_dump = new command_node;
	t = cn_show_debug_memory_dump;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("dump");
	t->execute(cn_show_debug_memory_dump_execute);
	t->description(cn_show_debug_memory_dump_msg);
	t->parent(cn_show_debug_memory);
	cn_show_debug_memory->add_child(*cn_show_debug_memory_dump);
}

