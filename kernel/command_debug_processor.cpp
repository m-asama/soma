/**
 * @file	command_debug_processor.cpp
 * @brief	CPU デバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "command_debug.h"
#include "processor_management.h"

#include "command_debug_processor.h"

command_node *cn_show_debug_processor;
command_node *cn_show_debug_processor_interrupt_counters;

bool
cn_show_debug_processor_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_show_debug_processor_msg[] = {
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
cn_show_debug_processor_interrupt_counters_execute(console_base &cb, utf8str command)
{
	cb.print(processor_debug_interrupt_counters());
	return true;
}

msg cn_show_debug_processor_interrupt_counters_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "メモリマップを表示。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "Dump MemoryMap.",
	},
};

void
command_debug_processor_init()
{
	command_node *t;

	cn_show_debug_processor = new command_node;
	t = cn_show_debug_processor;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("processor");
	t->execute(cn_show_debug_processor_execute);
	t->description(cn_show_debug_processor_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_processor);

	cn_show_debug_processor_interrupt_counters = new command_node;
	t = cn_show_debug_processor_interrupt_counters;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("interrupt-counters");
	t->execute(cn_show_debug_processor_interrupt_counters_execute);
	t->description(cn_show_debug_processor_interrupt_counters_msg);
	t->parent(cn_show_debug_processor);
	cn_show_debug_processor->add_child(*cn_show_debug_processor_interrupt_counters);
}

