/**
 * @file	memory_management.h
 * @brief	メモリ管理に関連する関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "loader_info.h"

#include "utf8str.h"

/**
 * ページサイズを表すための enum class。
 */
enum class memory_page_size {
	page_size_4k,
	page_size_2m,
};

/**
 * メモリ割り当て関数。
 * @param size 割り当てたいサイズ。
 * @return 割り当てられたアドレスを指すポインタ。
 */
void *memory_alloc(size_t size);

/**
 * 割り当てられたメモリを解放する関数。
 * @param ptr 解放したいアドレスを指すポインタ。
 */
void memory_free(void *ptr);

/**
 * できるだけ低位のアドレスからページを割り当てる関数。
 * @param page_size 割り当てたいページサイズ。
 * @param page_count 割り当てたいページの枚数。
 * @return 割り当てられたアドレスを指すポインタ。
 */
void *memory_alloc_page_lo(memory_page_size page_size, uint64_t page_count);

/*
 * できるだけ高位のアドレスからページを割り当てる関数。
 * @param page_size 割り当てたいページサイズ。
 * @param page_count 割り当てたいページの枚数。
 * @return 割り当てられたアドレスを指すポインタ。
 */
//void *memory_alloc_page_hi(memory_page_size page_size, uint64_t page_count);

/**
 * メモリ管理の初期化を行う関数。
 * @param li ブートローダから渡される構造体へのポインタ。
 */
void memory_init(struct loader_info *li);

/**
 * 割当済みメモリ容量を返す関数。
 * @return 割当済みメモリ容量。
 */
uint64_t memory_alloc_size();

/**
 * 空きメモリ容量を返す関数。
 * @return 空きメモリ容量。
 */
uint64_t memory_free_size();

/**
 * メモリブロックの割り当て数を返す関数。
 * @return メモリブロックの割り当て数。
 */
uint64_t memory_block_count();

/**
 * メモリブロックの bidir_node の割り当て数を返す関数。
 * @return メモリブロックの bidir_node の割り当て数。
 */
uint64_t memory_block_bidir_node_count();

/**
 * メモリ割り当てで管理している情報を表示する関数。
 */
utf8str memory_dump();
void memory_free_dump();
void memory_stats();

/**
 *
 */
utf8str memory_debug_memory_map();

