/**
 * @file	processor_management.h
 * @brief	CPU の初期化等を行う関数群宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "processor_base.h"
#include "processor_state_base.h"

void interrupt_handler(uint64_t gsi, uint64_t sp);

void processor_init(struct loader_info *li);

processor_base *processor_alloc(thread &io_thread);
void processor_free(processor_base *ptr);

extern "C" void boot_processor_start();
extern "C" void subsequent_processor_start();

void processor_start();

void enable_interrupt();
void disable_interrupt();

void backup_interrupt(uint64_t &interrupt);
void restore_interrupt(uint64_t &interrupt);

void idle();

processor_state_base *processor_state_alloc();
void processor_state_free(processor_state_base *ptr);

uint64_t processor_id();

processor_base *processor_current();

int processor_add_thread(thread &thread);

void processor_dump();

