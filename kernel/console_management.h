/**
 * @file	console_management.h
 * @brief	コンソール関連の処理をする関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "loader_info.h"

/**
 * コンソールに 1 文字出力するための関数。
 * @param c UNICODE 文字。
 * @return 何も返さない。
 */
void console_putchar(uint32_t c);

/**
 *
 */
uint32_t console_getchar();

/**
 * コンソールの初期化を行う関数。
 * @param li ブートローダから渡された loader_info 構造体へのポインタ。
 * @return 何も返さない。
 */
void console_init1(struct loader_info *li);

/**
 *
 */
void console_init2();

