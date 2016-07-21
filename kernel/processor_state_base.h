/**
 * @file	processor_state_base.h
 * @brief	CPU 状態の基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 *
 */
class processor_state_base {

public:
	/**
	 *
	 */
	processor_state_base();

	/**
	 *
	 */
	virtual ~processor_state_base();

	/**
	 *
	 */
	processor_state_base(const processor_state_base &src) = delete;

	/**
	 *
	 */
	processor_state_base(const processor_state_base &&src) = delete;

	/**
	 *
	 */
	processor_state_base &operator=(const processor_state_base &src) = delete;

	/**
	 *
	 */
	processor_state_base &operator=(const processor_state_base &&src) = delete;

	/**
	 *
	 */
	virtual int init() = 0;

	/**
	 *
	 */
	virtual void backup() = 0;

	/**
	 *
	 */
	virtual void restore() = 0;

	/**
	 *
	 */
	virtual uint64_t page_table() = 0;

	/**
	 *
	 */
	virtual uint64_t stack_pointer() = 0;

	/**
	 *
	 */
	virtual void dump() = 0;

};

