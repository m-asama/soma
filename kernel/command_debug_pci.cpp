/**
 * @file	command_debug_pci.cpp
 * @brief	PCI デバッグコマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "command_debug.h"
#include "pci_device_management.h"

#include "command_debug_pci.h"

command_node *cn_show_debug_pci;
command_node *cn_show_debug_pci_devices;

bool
cn_show_debug_pci_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_show_debug_pci_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "PCI 関連のデバッグ。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "PCI debug.",
	},
};

bool
cn_show_debug_pci_devices_execute(console_base &cb, utf8str command)
{
	pci_device_dump(cb);
	return true;
}

msg cn_show_debug_pci_devices_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "PCI 関連の情報をダンプ。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "PCI information dump.",
	},
};

void
command_debug_pci_init()
{
	command_node *t;

	cn_show_debug_pci = new command_node;
	t = cn_show_debug_pci;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("pci");
	t->execute(cn_show_debug_pci_execute);
	t->description(cn_show_debug_pci_msg);
	t->parent(cn_show_debug);
	cn_show_debug->add_child(*cn_show_debug_pci);

	cn_show_debug_pci_devices = new command_node;
	t = cn_show_debug_pci_devices;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label("devices");
	t->execute(cn_show_debug_pci_devices_execute);
	t->description(cn_show_debug_pci_devices_msg);
	t->parent(cn_show_debug_pci);
	cn_show_debug_pci->add_child(*cn_show_debug_pci_devices);
}

