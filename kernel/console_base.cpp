/**
 * @file	console_base.cpp
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "unicode.h"

#include "console_base.h"

console_base::console_base()
{
	m_cols = 0;
	m_rows = 0;
	m_buffer = nullptr;
	m_cursor_x = 0;
	m_cursor_y = 0;
	m_console_thread = nullptr;
	m_current_role = console_role::role_operator;
	m_current_mode = console_mode::mode_prompt;
}

console_base::~console_base()
{
	bidir_node<utf8str> *bn;
	m_cols = 0;
	m_rows = 0;
	if (m_buffer != nullptr)
		delete[] m_buffer;
	m_cursor_x = 0;
	m_cursor_y = 0;
	if (m_console_thread != nullptr)
		delete m_console_thread;
	while ((bn = m_command_history.head()) != nullptr) {
		m_command_history.remove(bn->v());
		delete &bn->v();
	}
}

bool
console_base::operator==(const console_base &rhs)
{
	return (this == &rhs);
}

void
console_base::name(utf8str name)
{
	m_name = name;
}

utf8str
console_base::name()
{
	return m_name;
}

void
console_base::cols(uint32_t cols)
{
	m_cols = cols;
}

uint32_t
console_base::cols()
{
	return m_cols;
}

void
console_base::rows(uint32_t rows)
{
	m_rows = rows;
}

uint32_t
console_base::rows()
{
	return m_rows;
}

void
console_base::buffer(uint32_t *buffer)
{
	m_buffer = buffer;
}

uint32_t *
console_base::buffer()
{
	return m_buffer;
}

void
console_base::cursor_x(uint32_t cursor_x)
{
	m_cursor_x = cursor_x;
}

uint32_t
console_base::cursor_x()
{
	return m_cursor_x;
}

void
console_base::cursor_y(uint32_t cursor_y)
{
	m_cursor_y = cursor_y;
}

uint32_t
console_base::cursor_y()
{
	return m_cursor_y;
}

void
console_base::console_thread(thread *console_thread)
{
	m_console_thread = console_thread;
}

thread *
console_base::console_thread()
{
	return m_console_thread;
}

void
console_base::current_role(console_role current_role)
{
	m_current_role = current_role;
}

console_role
console_base::current_role()
{
	return m_current_role;
}

void
console_base::current_mode(console_mode current_mode)
{
	m_current_mode = current_mode;
}

console_mode
console_base::current_mode()
{
	return m_current_mode;
}

void
console_base::print_prompt()
{
	utf8str prompt;
	prompt += "[edit";
	if (m_edit_path.length() > 0) {
		prompt += " ";
	}
	prompt += m_edit_path;
	prompt += "]\n";
	switch (m_current_role) {
	case console_role::role_administrator:
		prompt += "# ";
		break;
	case console_role::role_operator:
		prompt += "$ ";
		break;
	default:
		prompt += "? ";
	}
	print(prompt.ptr());
}

void
console_base::reset()
{
	int x, y;

	if (m_buffer != nullptr)
		delete[] m_buffer;

	if (m_cols > 0 && m_rows > 0) {
		m_buffer = new uint32_t[m_cols * m_rows];
		for (y = 0; y < m_rows; ++y) {
			for (x = 0; x < m_cols; ++x) {
				m_buffer[m_cols * y + x] = ' ';
			}
		}
	}

	m_cursor_x = 0;
	m_cursor_y = 0;
}

void
console_base::refresh()
{
}

/*
uint32_t
console_base::getchar()
{
	return 0;
}
*/

/*
void
console_base::putchar(uint32_t c)
{
	if (m_buffer == nullptr)
		return;
}
*/

int
console_base::print(const char *str)
{
	int b = 0;
	uint32_t c;

	if (str == nullptr)
		return 0;

	while (*str != '\0') {
		b = utf8_to_unicode(str, &c);
		putchar(c);
		str += b;
	}

	return b;
}

int
console_base::print(utf8str &str)
{
	return print(str.ptr());
}

void
console_base::line_shift()
{
	int x, y;

	if (m_buffer == nullptr)
		return;

	for (y = 0; y < (m_rows - 1); ++y) {
		for (x = 0; x < m_cols; ++x) {
			m_buffer[m_cols * y + x] = m_buffer[m_cols * (y + 1) + x];
		}
	}
	for (x = 0; x < m_cols; ++x) {
		m_buffer[m_cols * (m_rows - 1) + x] = ' ';
	}

	refresh();
}

void
console_base::handle_arrow(console_arrow arrow)
{
	switch (arrow) {
	case console_arrow::arrow_up:
		break;
	case console_arrow::arrow_down:
		break;
	case console_arrow::arrow_right:
		break;
	case console_arrow::arrow_left:
		break;
	}
}

