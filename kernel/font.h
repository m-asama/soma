/**
 * @file	font.h
 * @brief	フォント関連の関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "font_data.h"

struct font_data * font_find(uint64_t unicode);
void font_init();

