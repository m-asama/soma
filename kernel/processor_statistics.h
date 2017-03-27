/**
 * @file	processor_statistics.h
 * @brief	CPU 統計情報のクラス定義。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * CPU 統計情報のクラス定義。
 */
class processor_statistics {

public:
	/**
	 * コンストラクタ。
	 */
	processor_statistics();

	/**
	 * デストラクタ。
	 */
	virtual ~processor_statistics();

	/**
	 *
	 */
	uint64_t &interrupt_counter(uint8_t index);

private:
	/**
	 *
	 */
	uint64_t m_interrupt_counters[256];

};

