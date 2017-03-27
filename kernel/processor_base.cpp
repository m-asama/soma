/**
 * @file	processor_base.cpp
 * @brief	CPU の基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"

#include "processor_base.h"

processor_base::processor_base(thread &io_thread)
	: m_boot_processor(false), m_io_thread(io_thread)
{
}

processor_base::~processor_base()
{
}

bool
processor_base::operator==(const processor_base &rhs)
{
	return (this->id() == rhs.id());
}

bool
processor_base::operator>(const processor_base &rhs)
{
	return (this->id() > rhs.id());
}

void
processor_base::id(uint64_t id)
{
	m_id = id;
}

uint64_t
processor_base::id() const
{
	return m_id;
}

void
processor_base::apic_address(uint64_t apic_address)
{
	m_apic_address = apic_address;
}

uint64_t
processor_base::apic_address() const
{
	return m_apic_address;
}

void
processor_base::boot_processor(bool boot_processor)
{
	m_boot_processor = boot_processor;
}

bool
processor_base::boot_processor()
{
	return m_boot_processor;
}

sorted_list<thread> &
processor_base::threads()
{
	return m_threads;
}

thread &
processor_base::io_thread()
{
	return m_io_thread;
}

void
processor_base::running_thread(thread *running_thread)
{
	m_running_thread = running_thread;
}

thread *
processor_base::running_thread()
{
	return m_running_thread;
}

processor_statistics &
processor_base::statistics()
{
	return m_statistics;
}

void
processor_base::dump()
{
	utf8str s;
	s += "processor";
	s.append_uint64(m_id, 0);
	s += ": MMIO BASE = 0x";
	s.append_hex64(m_apic_address, 16);
	s += "\n";
	print(s);
	bidir_node<thread> *bn;
	for (bn = m_threads.head(); bn != nullptr; bn = bn->next()) {
		bn->v().dump();
	}
}

