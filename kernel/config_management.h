/**
 * @file	config_management.h
 * @brief	設定管理関連の宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "config_model_node.h"
#include "config_data_node.h"

extern config_model_node *config_model_node_root;

extern config_data_node *config_data_node_running;
extern config_data_node *config_data_node_candidate;

bool config_model_node_completed(config_model_node *&cmn, uint64_t pos);

int config_model_node_nearest(utf8str path, config_model_node *&node, utf8str &remaining, uint64_t &pos, bool exclude_leaf);

int config_data_node_find(config_data_node *root, utf8str path, config_data_node *&node);
bool config_data_node_nearest(utf8str path, config_data_node *&node, utf8str &remaining);

bool config_data_node_set(config_data_node *node, utf8str path);

bool config_data_node_get(utf8str path, utf8str &result);

bool config_data_node_delete(config_data_node *node, utf8str path);

void config_init();

