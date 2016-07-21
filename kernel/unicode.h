/**
 * @file	unicode.h
 * @brief	UNICODE と UTF-8 に関連する関数定義。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

int unicode_to_utf8(const uint32_t *unicode, char *utf8);
int utf8_to_unicode(const char *utf8, uint32_t *unicode);

