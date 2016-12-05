/**
 * @file	intel64_processor_interrupt_handler.h
 * @brief	Intel64 CPU の割り込みハンドラ関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "intel64_processor.h"

void interrupt_handler_init(intel64_idt_entry *idt, uint16_t code_segment_selector);

