/**
 * @file	config_management.h
 * @brief	設定管理関連の宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "config_model_node.h"
#include "config_data_node.h"

extern config_model_node *config_model_node_root;

int config_model_node_nearest(utf8str path, config_model_node *&node, utf8str &remaining, uint64_t &arg_parsed, bool exclude_leaf);

int config_data_node_find(config_data_node *root, utf8str path, config_data_node *&node);

void config_init();

