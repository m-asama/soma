/**
 * @file	intel64_processor_state.h
 * @brief	Intel64 CPU の状態を格納するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "intel64_processor.h"
#include "processor_state_base.h"

class intel64_processor_state : public processor_state_base {

public:
	/**
	 *
	 */
	intel64_processor_state();

	/**
	 *
	 */
	virtual ~intel64_processor_state();

	/**
	 *
	 */
	intel64_processor_state(const intel64_processor_state &src) = delete;

	/**
	 *
	 */
	intel64_processor_state(const intel64_processor_state &&src) = delete;

	/**
	 *
	 */
	intel64_processor_state &operator=(const intel64_processor_state &&src) = delete;

	/**
	 *
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

