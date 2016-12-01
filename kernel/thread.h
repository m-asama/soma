/**
 * @file	thread.h
 * @brief	スレッドを表現するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "processor_state_base.h"

/**
 *
 */
enum class thread_state {
	idle,
	running,
};

typedef void (*main_fn)();

/**
 *
 */
class thread {

public:
	/**
	 *
	 */
	thread(main_fn main);

	/**
	 *
	 */
	virtual ~thread();

	/**
	 *
	 */
	thread() = delete;

	/**
	 *
	 */
	thread(const thread &src) = delete;

	/**
	 *
	 */
	thread(const thread &&src) = delete;

	/**
	 *
	 */
	thread &operator=(const thread &src) = delete;

	/**
	 *
	 */
	thread &operator=(const thread &&src) = delete;

	/**
	 *
	 */
	bool operator==(const thread &rhs);

	/**
	 *
	 */
	bool operator>(const thread &rhs);

	/**
	 *
	 */
	int init(uint64_t id, const utf8str &name);

	/**
	 *
	 */
	void id(uint64_t id);

	/**
	 *
	 */
	uint64_t id() const;

	/**
	 *
	 */
	void name(const utf8str &name);

	/**
	 *
	 */
	const utf8str &name();

	/**
	 *
	 */
	void state(thread_state state);

	/**
	 *
	 */
	thread_state state();

	/**
	 *
	 */
	uint64_t page_table();

	/**
	 *
	 */
	uint64_t stack_pointer();

	/**
	 *
	 */
	main_fn main();

	/**
	 *
	 */
	void dump();

private:
	/**
	 *
	 */
	uint64_t m_id;

	/**
	 *
	 */
	utf8str m_name;

	/**
	 *
	 */
	main_fn m_main;

	/**
	 *
	 */
	processor_state_base *m_processor_state;

	/**
	 *
	 */
	thread_state m_state;

};

