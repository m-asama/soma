/**
 * @file	processor_base.h
 * @brief	CPU の基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "sorted_list.h"
#include "thread.h"
#include "processor_statistics.h"

/**
 * CPU の基底クラス。
 */
class processor_base {

public:
	/**
	 * コンストラクタ。
	 * @param io_thread
	 */
	processor_base(thread &io_thread);

	/**
	 * デストラクタ。
	 */
	virtual ~processor_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	processor_base(const processor_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	processor_base(processor_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	processor_base &operator=(const processor_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	processor_base &operator=(processor_base &&src) = delete;

	/**
	 *
	 */
	bool operator==(const processor_base &rhs);

	/**
	 *
	 */
	bool operator>(const processor_base &rhs);

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
	void apic_address(uint64_t apic_address);

	/**
	 *
	 */
	uint64_t apic_address() const;

	/**
	 *
	 */
	void boot_processor(bool boot_processor);

	/**
	 *
	 */
	bool boot_processor();

	/**
	 *
	 */
	sorted_list<thread> &threads();

	/**
	 *
	 */
	thread &io_thread();

	/**
	 *
	 */
	void running_thread(thread *running_thread);

	/**
	 *
	 */
	thread *running_thread();

	/**
	 *
	 */
	processor_statistics &statistics();

	/**
	 *
	 */
	virtual void dump();

protected:
	/**
	 *
	 */
	uint64_t m_id;

	/**
	 *
	 */
	uint64_t m_apic_address;

	/**
	 *
	 */
	bool m_boot_processor;

	/**
	 *
	 */
	sorted_list<thread> m_threads;

	/**
	 *
	 */
	thread &m_io_thread;

	/**
	 *
	 */
	thread *m_running_thread;

	/**
	 *
	 */
	processor_statistics m_statistics;

};

