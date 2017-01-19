/**
 * @file	intel64_display_console.cpp
 * @brief	ディスプレイ・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "memory_management.h"
#include "intel64_assembly.h"
#include "font_data.h"
#include "font.h"

#include "print.h"

#include "display_console.h"

static struct keymap keymaps[] = {
	{
		.name	= "jp",
		.table	= {
		/* 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f */
	 /* 0 */   0,0x1b, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '^',0x7f,'\t',
	 /* 1 */ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '@', '[',0x0d,   0, 'a', 's',
	 /* 2 */ 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', ':',   0,   0, ']', 'z', 'x', 'c', 'v',
	 /* 3 */ 'b', 'n', 'm', ',', '.', '/',   0, '*',   0,0x20,   0,   0,   0,   0,   0,   0,
	 /* 4 */   0,   0,   0,   0,   0,   0,   0, '7', '8', '9', '-', '4', '5', '6', '+', '1',
	 /* 5 */ '2', '3', '0', '.',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* 6 */   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* 7 */   0,   0,   0, '_',   0,   0,   0,   0,   0,   0,   0,   0,   0,'\\',   0,   0,
	 /* 8 */   0,0x1b, '!', '"', '#', '$', '%', '&','\'', '(', ')', '0', '=', '~',0x7f,'\t',
	 /* 9 */ 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '`', '{',0x0d,   0, 'A', 'S',
	 /* a */ 'D', 'F', 'G', 'H', 'J', 'K', 'L', '+', '*',   0,   0, '}', 'Z', 'X', 'C', 'V',
	 /* b */ 'B', 'N', 'M', '<', '>', '?',   0, '*',   0,0x20,   0,   0,   0,   0,   0,   0,
	 /* c */   0,   0,   0,   0,   0,   0,   0, '7', '8', '9', '-', '4', '5', '6', '+', '1',
	 /* d */ '2', '3', '0', '.',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* e */   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* f */   0,   0,   0, '_',   0,   0,   0,   0,   0,   0,   0,   0,   0, '|',   0,   0,
		},
	},
	{
		.name	= "us",
		.table	= {
		/* 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f */
	 /* 0 */   0,0x1b, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',0x7f,'\t',
	 /* 1 */ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',0x0d,   0, 'a', 's',
	 /* 2 */ 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', '`',   0,'\\', 'z', 'x', 'c', 'v',
	 /* 3 */ 'b', 'n', 'm', ',', '.', '/',   0, '*',   0,0x20,   0,   0,   0,   0,   0   ,0,
	 /* 4 */   0,   0,   0,   0,   0,   0,   0, '7', '8', '9', '-', '4', '5', '6', '+', '1',
	 /* 5 */ '2', '3', '0', '.',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* 6 */   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* 7 */   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* 8 */   0,0x1b, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+',0x7f,'\t',
	 /* 9 */ 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}',0x0d,   0, 'A', 'S',
	 /* a */ 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '"', '~',   0, '|', 'Z', 'X', 'C', 'V',
	 /* b */ 'B', 'N', 'M', '<', '>', '?',   0, '*',   0,0x20,   0,   0,   0,   0,   0,   0,
	 /* c */   0,   0,   0,   0,   0,   0,   0, '7', '8', '9', '-', '4', '5', '6', '+', '1',
	 /* d */ '2', '3', '0', '.',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* e */   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	 /* f */   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
		},
	},
};

static struct keymap *default_keymap = &keymaps[0];

display_console::display_console()
	: m_keymap(default_keymap), m_ibuf(256), m_obuf(256)
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
	m_shift_pressed = false;
	m_ctrl_pressed = false;
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
	m_shift_pressed = false;
	m_ctrl_pressed = false;
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

uint64_t
display_console::read_from_keyboard()
{
	uint64_t readed = 0;
	uint8_t c;
	while ((inb(0x64) & 0x01) && (m_ibuf.writeable() > 0)) {
		c = inb(0x60);
		m_ibuf.write(c);
		++readed;
	}
	return readed;
}

void
display_console::reset()
{
	uint32_t *base = (uint32_t *)m_uefifb_addr;

	cols(m_uefifb_width / 8);
	rows(m_uefifb_height / 16);

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

	outb(0x64, 0xad);
	outb(0x64, 0xa7);

	inb(0x60);

	sint8_t c;
	outb(0x64, 0x20);
	c = inb(0x60);
	c |= 0x45;
//	c |= 0x01;
	c &= ~0x22;
	outb(0x64, 0x60);
	outb(0x60, c);

	outb(0x64, 0xae);
//	outb(0x64, 0xa8);

	console_base::reset();
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
			plotchar(x * 8, y * 16, c);
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

void
display_console::handler()
{
	while (m_ibuf.readable() > 0) {
		uint8_t c = 0;

		if (m_ibuf[0] == 0xe0) {
			if (m_ibuf.readable() < 2) {
				return;
			}
			switch (m_ibuf[1]) {
			case 0x1d:
			case 0x38:
				m_ibuf.read(c);
				break;
			case 0x48: // 上矢印
				handle_arrow(console_arrow::arrow_up);
				m_ibuf.read(c); m_ibuf.read(c);
				continue;
			case 0x50: // 下矢印
				handle_arrow(console_arrow::arrow_down);
				m_ibuf.read(c); m_ibuf.read(c);
				continue;
			case 0x4d: // 右矢印
				handle_arrow(console_arrow::arrow_right);
				m_ibuf.read(c); m_ibuf.read(c);
				continue;
			case 0x4b: // 左矢印
				handle_arrow(console_arrow::arrow_left);
				m_ibuf.read(c); m_ibuf.read(c);
				continue;
			default:
				m_ibuf.read(c); m_ibuf.read(c);
				continue;
			}
		}

		if (m_ibuf[0] == 0xe1) {
			if (m_ibuf.readable() < 3) {
				return;
			}
			m_ibuf.read(c); m_ibuf.read(c); m_ibuf.read(c);
			continue;
		}

		if ((m_ibuf[0] == 0x08) && (m_ibuf.readable() >= 3)
		 && (m_ibuf[1] == 0x00) && (m_ibuf[2] == 0x00)) {
			m_ibuf.read(c); m_ibuf.read(c); m_ibuf.read(c);
			continue;
		}

		m_ibuf.read(c);

		if ((c == 0x2a) || (c == 0x36)) {
			m_shift_pressed = true;
			continue;
		}

		if ((c == 0xaa) || (c == 0xb6)) {
			m_shift_pressed = false;
			continue;
		}

		if (c == 0x1d) {
			m_ctrl_pressed = true;
			continue;
		}

		if (c == 0x9d) {
			m_ctrl_pressed = false;
			continue;
		}

		if (c & 0x80) {
			continue;
		}

		if (m_shift_pressed)
			c |= 0x80;

		c = m_keymap->table[c];

		if (c > 0)
			getchar(c);

	}
}

void
display_console::putchar(uint32_t c)
{
	uint32_t x, y;
	struct font_data *font;
	bool wchar;

	if ((c == 0x08) || (c == 0x7f)) {
		if (cursor_x() > 0) {
			cursor_x(cursor_x() - 1);
			plotchar(cursor_x() * 8, cursor_y() * 16, ' ');
		}
		if ((cursor_x() > 0) && (buffer()[cols() * cursor_y() + cursor_x()] == 0xff)) {
			cursor_x(cursor_x() - 1);
			plotchar(cursor_x() * 8, cursor_y() * 16, ' ');
		}
		return;
	}

	font = font_find(c);
	if (font == nullptr)
		font = font_find(0x00);
	if (font == nullptr)
		return;

	if ((c == '\r') || (c == '\n')) {
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
	plotchar(x * 8, y * 16, c);
	buffer()[cols() * y + x] = c;
	if (wchar) {
		buffer()[cols() * y + (x + 1)] = 0xff;
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
display_console::plotchar(uint32_t x, uint32_t y, uint32_t c)
{
	uint32_t *base = (uint32_t *)m_uefifb_addr;
	struct font_data *font;

	font = font_find(c);
	if (font == nullptr)
		font = font_find(0x00);
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

