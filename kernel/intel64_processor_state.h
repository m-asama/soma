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
	virtual int init();

	/**
	 *
	 */
	virtual void backup();

	/**
	 *
	 */
	virtual void restore();

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

private:
	/**
	 *
	 */
	intel64_pml4_table *m_pml4_table;

	/**
	 *
	 */
	uint64_t m_stack_pointer;

};

