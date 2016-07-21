/**
 * @file	spinlock.cpp
 * @brief	スピンロッククラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "processor_management.h"
#include "util.h"

#include "spinlock.h"

spinlock::spinlock()
	: m_locked(0), m_processor_id(0)
{
	for (int i = 0; i < 256; ++i) {
		m_interrupts[i] = 0;
	}
}

spinlock::~spinlock()
{
}

void
spinlock::acquire()
{
	backup_interrupt(m_interrupts[processor_id()]);
	while (xchg(&m_locked, 1) != 0);
	m_processor_id = processor_id();

}

void
spinlock::release()
{
	m_processor_id = 0;
	xchg(&m_locked, 0);
	restore_interrupt(m_interrupts[processor_id()]);
}

