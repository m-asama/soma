/**
 * @file	command_management.h
 * @brief	コマンド管理関連の宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "command_node.h"

extern command_node *command_node_root;
extern command_node *cn_set;
extern command_node *cn_get;
extern command_node *cn_delete;
extern command_node *cn_edit;
extern command_node *cn_top;
extern command_node *cn_show;
extern command_node *cn_reset;
extern command_node *cn_clear;

void command_node_nearest(utf8str command, command_node *&node, utf8str &remaining);

void command_init();

