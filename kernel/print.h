/**
 * @file	print.h
 * @brief	表示関連の処理をする関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "console_msg.h"

int putchar(const uint32_t c);
int printhex8(const uint8_t uc);
int printhex16(const uint16_t us);
int printhex32(const uint32_t ui);
int printhex64(const uint64_t ul);
int print(const utf8str str);
int print(const char *str);
int print(msg *str);

