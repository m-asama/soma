/**
 * @file	thread_management.h
 * @brief	スレッド管理の関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "thread.h"

/**
 *
 */
extern "C" void io_thread_main();

/**
 *
 */
void thread_init();

/**
 *
 */
thread *thread_alloc(void (*main)());

/**
 *
 */
void thread_free(thread *ptr);

/**
 *
 */
void thread_dump();

