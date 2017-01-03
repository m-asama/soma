/**
 * @file	thread.cpp
 * @brief	スレッドを表現するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "processor_management.h"

#include "thread.h"

thread::thread(main_fn main)
	: m_main(main), m_processor_state(nullptr), m_state(thread_state::idle)
{
}

thread::~thread()
{
	if (m_processor_state != nullptr) {
		processor_state_free(m_processor_state);
		m_processor_state = nullptr;
	}
}

bool
thread::operator==(const thread &rhs)
{
	return (this->id() == rhs.id());
}

bool
thread::operator>(const thread &rhs)
{
	return (this->id() > rhs.id());
}

int
thread::init(uint64_t id, const utf8str &name)
{
	m_processor_state = processor_state_alloc();
	if (m_processor_state == nullptr) {
		return -1;
	}
	m_processor_state->init((uint64_t)m_main);
	m_id = id;
	m_name = name;
	return 0;
}

void
thread::id(uint64_t id)
{
	m_id = id;
}

uint64_t
thread::id() const
{
	return m_id;
}

void
thread::name(const utf8str &name)
{
	m_name = name;
}

const utf8str &
thread::name()
{
	return m_name;
}

void
thread::state(thread_state state)
{
	m_state = state;
}

thread_state
thread::state()
{
	return m_state;
}

processor_state_base *
thread::processor_state()
{
	return m_processor_state;
}

uint64_t
thread::page_table()
{
	uint64_t page_table = 0;
	if (m_processor_state != nullptr) {
		page_table = m_processor_state->page_table();
	}
	return page_table;
}

uint64_t
thread::stack_pointer()
{
	uint64_t stack_pointer = 0;
	if (m_processor_state != nullptr) {
		stack_pointer = m_processor_state->stack_pointer();
	}
	return stack_pointer;
}

main_fn
thread::main()
{
	return m_main;
}

void
thread::dump()
{
	utf8str s;
	s += "thread";
	s.append_uint64(m_id, 0);
	s += ": NAME = ";
	s += m_name;
	s += "\n";
	printstr(s);
/*
	if (m_processor_state != nullptr) {
		m_processor_state->dump();
	}
*/
}

