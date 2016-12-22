/**
 * @file	intel64_display_console.cpp
 * @brief	ディスプレイ・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "memory_management.h"
#include "font_data.h"
#include "font.h"

#include "print.h"

#include "display_console.h"

display_console::display_console()
{
	m_uefifb_addr = 0;
	m_uefifb_size = 0;
	m_uefifb_width = 0;
	m_uefifb_height = 0;
	m_uefifb_stride = 0;
	m_uefifb_mask_red = 0;
	m_uefifb_mask_green = 0;
	m_uefifb_mask_blue = 0;
	m_uefifb_mask_reserved = 0;
	m_uefifb_cache = nullptr;
}

display_console::~display_console()
{
	m_uefifb_addr = 0;
	m_uefifb_size = 0;
	m_uefifb_width = 0;
	m_uefifb_height = 0;
	m_uefifb_stride = 0;
	m_uefifb_mask_red = 0;
	m_uefifb_mask_green = 0;
	m_uefifb_mask_blue = 0;
	m_uefifb_mask_reserved = 0;
	if (m_uefifb_cache != nullptr)
		memory_free(m_uefifb_cache);
}

void
display_console::uefifb_addr(uint64_t uefifb_addr)
{
	m_uefifb_addr = uefifb_addr;
}

uint64_t
display_console::uefifb_addr()
{
	return m_uefifb_addr;
}

void
display_console::uefifb_size(uint64_t uefifb_size)
{
	m_uefifb_size = uefifb_size;
}

uint64_t
display_console::uefifb_size()
{
	return m_uefifb_size;
}

void
display_console::uefifb_width(int uefifb_width)
{
	m_uefifb_width = uefifb_width;
}

int
display_console::uefifb_width()
{
	return m_uefifb_width;
}

void
display_console::uefifb_height(int uefifb_height)
{
	m_uefifb_height = uefifb_height;
}

int
display_console::uefifb_height()
{
	return m_uefifb_height;
}

void
display_console::uefifb_stride(int uefifb_stride)
{
	m_uefifb_stride = uefifb_stride;
}

int
display_console::uefifb_stride()
{
	return m_uefifb_stride;
}

void
display_console::uefifb_mask_red(uint32_t uefifb_mask_red)
{
	m_uefifb_mask_red = uefifb_mask_red;
}

uint32_t
display_console::uefifb_mask_red()
{
	return m_uefifb_mask_red;
}

void
display_console::uefifb_mask_green(uint32_t uefifb_mask_green)
{
	m_uefifb_mask_green = uefifb_mask_green;
}

uint32_t
display_console::uefifb_mask_green()
{
	return m_uefifb_mask_green;
}

void
display_console::uefifb_mask_blue(uint32_t uefifb_mask_blue)
{
	m_uefifb_mask_blue = uefifb_mask_blue;
}

uint32_t
display_console::uefifb_mask_blue()
{
	return m_uefifb_mask_blue;
}

void
display_console::uefifb_mask_reserved(uint32_t uefifb_mask_reserved)
{
	m_uefifb_mask_reserved = uefifb_mask_reserved;
}

uint32_t
display_console::uefifb_mask_reserved()
{
	return m_uefifb_mask_reserved;
}

void
display_console::reset()
{
	uint32_t *base = (uint32_t *)m_uefifb_addr;

	cols(m_uefifb_width / 8);
	rows(m_uefifb_height / 16);
	console_base::reset();

	/* XXX: なぜか実機ではこれをするとハングアップ？する。 */
	/*
	for (i = 0; i < m_uefifb_size; ++i)
		base[i] = 0x00000000;
	*/

	for (int y = 0; y < m_uefifb_height; ++y) {
		for (int x = 0; x < m_uefifb_width; ++x) {
			base[m_uefifb_width * y + x] = 0x00000000;
		}
	}

	if (m_uefifb_cache != nullptr)
		memory_free(m_uefifb_cache);
	m_uefifb_cache = (uint32_t *)memory_alloc(m_uefifb_size);
	for (int i = 0; i < m_uefifb_size; ++i) {
		m_uefifb_cache[i] = 0x00000000;
	}
}

void
display_console::refresh()
{
	uint32_t *base = (uint32_t *)m_uefifb_addr;

	/* XXX: 遅いのでこの方法はやめる。 */
	/*
	for (y = 0; y < rows(); ++y) {
		for (x = 0; x < cols(); ++x) {
			c = buffer()[cols() * y + x];
			font = font_find(c);
			if (font == nullptr)
				font = font_find(0x00);
			if (font == nullptr)
				return;
			plot_char(x * 8, y * 16, font);
			if (font->width == 16) {
				++x;
			}
		}
	}
	*/

	for (int y = 0; y < (rows() - 1) * 16; ++y) {
		for (int x = 0; x < cols() * 8; ++x) {
			int src = m_uefifb_width * (y + 16) + x;
			int dst = m_uefifb_width * y + x;
			if (m_uefifb_cache[dst] != m_uefifb_cache[src])
				base[dst] = m_uefifb_cache[src];
			m_uefifb_cache[dst] = m_uefifb_cache[src];
		}
	}
	for (int y = (rows() - 1) * 16; y < rows() * 16; ++y) {
		for (int x = 0; x < cols() * 8; ++x) {
			int dst = m_uefifb_width * y + x;
			if (m_uefifb_cache[dst] != 0x00000000)
				base[dst] = 0x00000000;
			m_uefifb_cache[dst] = 0x00000000;
		}
	}
}

uint32_t
display_console::getchar()
{
	return 0;
}

void
display_console::putchar(uint32_t c)
{
	uint32_t x, y;
	struct font_data *font;
	bool wchar;

	font = font_find(c);
	if (font == nullptr)
		font = font_find(0x00);
	if (font == nullptr)
		return;

	if (c == '\n') {
		cursor_x(0);
		cursor_y(cursor_y() + 1);
		if (cursor_y() == rows()) {
			line_shift();
			cursor_y(cursor_y() - 1);
		}
		return;
	}

	wchar = (font->width == 16) ? true : false;
	if (wchar && (cursor_x() == (cols() - 1))) {
		cursor_x(0);
		cursor_y(cursor_y() + 1);
	}
	if (cursor_y() == rows()) {
		line_shift();
		cursor_y(cursor_y() - 1);
	}

	x = cursor_x();
	y = cursor_y();
	plot_char(x * 8, y * 16, font);
	buffer()[cols() * y + x] = c;
	if (wchar) {
		buffer()[cols() * y + (x + 1)] = ' ';
	}

	cursor_x(cursor_x() + (wchar ? 2 : 1));
	if (cursor_x() == cols()) {
		cursor_x(0);
		cursor_y(cursor_y() + 1);
	}
	if (cursor_y() == rows()) {
		line_shift();
		cursor_y(cursor_y() - 1);
	}
}

void
display_console::plot_char(uint32_t x, uint32_t y, struct font_data *font)
{
	uint32_t *base = (uint32_t *)m_uefifb_addr;

	if (font == nullptr)
		return;

	for (uint32_t xx = 0; xx < font->width; ++xx) {
		for (uint32_t yy = 0; yy < font->height; ++yy) {
			uint32_t dot = 0x00000000;
			if (font->data[yy] & (1 << (15-xx)))
				dot = 0xffffffff & ~m_uefifb_mask_reserved;
			int dst = (y + yy) * m_uefifb_width + (x + xx);
			if (m_uefifb_cache[dst] != dot)
				base[dst] = dot;
			m_uefifb_cache[dst] = dot;
		}
	}
}

