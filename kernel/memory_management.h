/**
 * @file	memory_management.h
 * @brief	メモリ管理に関連する関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "loader_info.h"

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
 * @return 割り当てられたアドレスを指すポインタ。
 */
void *memory_alloc_page_lo(memory_page_size page_size);

/*
 * できるだけ高位のアドレスからページを割り当てる関数。
 * @param page_size 割り当てたいページサイズ。
 * @return 割り当てられたアドレスを指すポインタ。
 */
//void *memory_alloc_page_hi(memory_page_size page_size);

/**
 * メモリ管理の初期化を行う関数。
 * @param li ブートローダから渡される構造体へのポインタ。
 */
void memory_init(struct loader_info *li);

/**
 * メモリ割り当てで管理している情報を表示する関数。
 */
void memory_dump();

