/**
 * @file	config_management.h
 * @brief	設定管理関連の宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "config_model_node.h"

extern config_model_node *config_model_node_root;

void config_init();

