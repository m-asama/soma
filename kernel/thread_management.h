/**
 * @file	thread_management.h
 * @brief	スレッド管理の関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "thread.h"

/**
 *
 */
void thread_init();

/**
 *
 */
thread *thread_alloc(void (*main)(thread *));

/**
 *
 */
void thread_free(thread *ptr);

/**
 *
 */
void thread_state_append(thread_state state, utf8str &str);

/**
 *
 */
void thread_dump();

