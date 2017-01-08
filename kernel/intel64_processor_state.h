/**
 * @file	intel64_processor_state.h
 * @brief	Intel64 CPU の状態を格納するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "intel64_processor.h"
#include "processor_state_base.h"

/**
 * Intel64 プロセッサーのレジスタを保持するための構造体。
 */
struct intel64_processor_state_storage {
	uint64_t gsi;		// 0x00
	uint64_t stacked_size;	// 0x08
	uint64_t cr3;		// 0x10
	uint64_t ss;		// 0x18
	uint64_t rsp;		// 0x20
	uint64_t rflags;	// 0x28
	uint64_t cs;		// 0x30
	uint64_t rip;		// 0x38
	uint64_t error_code;	// 0x40
	uint64_t rax;		// 0x48
	uint64_t rbx;		// 0x50
	uint64_t rcx;		// 0x58
	uint64_t rdx;		// 0x60
	uint64_t rdi;		// 0x68
	uint64_t rsi;		// 0x70
	uint64_t rbp;		// 0x78
	uint64_t r8;		// 0x80
	uint64_t r9;		// 0x88
	uint64_t r10;		// 0x90
	uint64_t r11;		// 0x98
	uint64_t r12;		// 0xa0
	uint64_t r13;		// 0xa8
	uint64_t r14;		// 0xb0
	uint64_t r15;		// 0xb8
};

/**
 * Intel64 プロセッサーの状態を保持するためのクラス。
 */
class intel64_processor_state : public processor_state_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_processor_state();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_processor_state();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_processor_state(const intel64_processor_state &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_processor_state(const intel64_processor_state &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_processor_state &operator=(const intel64_processor_state &&src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_processor_state &operator=(const intel64_processor_state &src) = delete;

	/**
	 *
	 */
	virtual int init(uint64_t thread_main, uint64_t thread_arg);

	/**
	 *
	 */
	//virtual void backup(uint64_t *processor_state);

	/**
	 *
	 */
	//virtual void restore(uint64_t *processor_state);

	/**
	 *
	 */
	virtual void dump();

	/**
	 *
	 */
	intel64_pml4_table *pml4_table();

	/**
	 *
	 */
	virtual uint64_t page_table();

	/**
	 *
	 */
	virtual uint64_t stack_pointer();

	/**
	 *
	 */
	virtual void *processor_state_address();

private:
	/**
	 *
	 */
	intel64_pml4_table *m_pml4_table;

	/**
	 *
	 */
	uint64_t m_stack_pointer;

	/**
	 * Intel64 プロセッサのレジスタ情報。
	 */
	intel64_processor_state_storage m_processor_state;

};

