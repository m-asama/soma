/**
 * @file	console_base.cpp
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_base.h"

console_base::console_base()
{
	m_cols = 0;
	m_rows = 0;
	m_buffer = nullptr;
	m_cursor_x = 0;
	m_cursor_y = 0;
}

console_base::~console_base()
{
	m_cols = 0;
	m_rows = 0;
	if (m_buffer != nullptr)
		delete[] m_buffer;
	m_cursor_x = 0;
	m_cursor_y = 0;
}

bool
console_base::operator==(const console_base &rhs)
{
	return (this == &rhs);
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

