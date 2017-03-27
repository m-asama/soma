/**
 * @file	processor_statistics.cpp
 * @brief	CPU 統計情報のクラス実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"

#include "processor_statistics.h"

processor_statistics::processor_statistics()
{
	for (int i = 0; i < 256; ++i) {
		m_interrupt_counters[i] = 0;
	}
}

processor_statistics::~processor_statistics()
{
}

uint64_t &
processor_statistics::interrupt_counter(uint8_t index)
{
	return m_interrupt_counters[index];
}

