/**
 * @file	processor_management.h
 * @brief	CPU の初期化等を行う関数群宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "processor_base.h"
#include "processor_state_base.h"

extern "C" void interrupt_handler_dispatcher();

struct interrupt_handler {
	uint8_t gsi;
	char const *name;
	void (*ih)(uint8_t);
};

inline bool operator==(const struct interrupt_handler &lhs, const struct interrupt_handler &rhs)
{
	if ((lhs.gsi == rhs.gsi)
	 && (lhs.ih == rhs.ih)) {
		return true;
	} else {
		return false;
	}
}

void interrupt_handler_register(interrupt_handler &ih);

void interrupt_handler_unregister(interrupt_handler &ih);

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
void reschedule();

processor_state_base *processor_state_alloc();
void processor_state_free(processor_state_base *ptr);

uint64_t processor_id();

processor_base *processor_current();

int processor_add_thread(thread &thread);

void processor_dump();

utf8str processor_debug_interrupt_counters();

