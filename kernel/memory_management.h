/**
 * @file	memory_management.h
 * @brief	メモリ管理に関連する関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "loader_info.h"

enum class memory_page_size {
	page_size_4k,
	page_size_2m,
};

void *memory_alloc(size_t size);
void memory_free(void *ptr);
void *memory_alloc_page_lo(memory_page_size page_size);
//void *memory_alloc_page_hi(memory_page_size page_size);

void memory_init(struct loader_info *li);

void memory_dump();

