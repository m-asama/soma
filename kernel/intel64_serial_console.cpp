/**
 * @file	intel64_serial_console.cpp
 * @brief	シリアル・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "intel64_assembly.h"
#include "unicode.h"
#include "print.h"
#include "util.h"

#include "serial_console.h"

serial_console::serial_console()
	: m_ibuf(256), m_obuf(256)
{
	m_io_port_base = 0x3f8;	// COM1
	m_irq = 0x4;		// IRQ4
	m_baud_rate = 12;	// 9600
	m_data_bits = 0x3;	// 8bits
	m_stop_bits = 0x0;	// 1
	m_parity = 0x0;		// NONE
}

serial_console::~serial_console()
{
}

void
serial_console::io_port_base(uint16_t io_port_base)
{
	m_io_port_base = io_port_base;
}

uint16_t
serial_console::io_port_base()
{
	return m_io_port_base;
}

void
serial_console::irq(uint8_t irq)
{
	m_irq = irq;
}

uint8_t
serial_console::irq()
{
	return m_irq;
}

void
serial_console::baud_rate(uint16_t baud_rate)
{
	m_baud_rate = baud_rate;
}

uint16_t
serial_console::baud_rate()
{
	return m_baud_rate;
}

void
serial_console::data_bits(uint8_t data_bits)
{
	m_data_bits = data_bits;
}

uint8_t
serial_console::data_bits()
{
	return m_data_bits;
}

void
serial_console::stop_bits(uint8_t stop_bits)
{
	m_stop_bits = stop_bits;
}

uint8_t
serial_console::stop_bits()
{
	return m_stop_bits;
}

void
serial_console::parity(uint8_t parity)
{
	m_parity = parity;
}

uint8_t
serial_console::parity()
{
	return m_parity;
}

uint64_t
serial_console::read_from_serial()
{
	uint64_t readed = 0;
	uint8_t c;
	while (((inb(m_io_port_base+5)&1) != 0) && (m_ibuf.writeable() > 0)) {
		c = inb(m_io_port_base);
		m_ibuf.write(c);
		++readed;
		/* XXX: 後で見直す。 */
		volatile int i = 100000;
		while (--i > 0);
	}
	return readed;
}

void
serial_console::reset()
{
	uint8_t t = 0;
	t |= (m_data_bits & 0x3);
	t |= (m_stop_bits & 0x1) << 2;
	t |= (m_parity & 0x7) << 3;
	outb(m_io_port_base+1, 0x00);
	outb(m_io_port_base+3, 0x80);
	outb(m_io_port_base+0, (m_baud_rate & 0xff));
	outb(m_io_port_base+1, (m_baud_rate >> 8));
	outb(m_io_port_base+3, t);
	//outb(m_io_port_base+2, 0xc7);
	//outb(m_io_port_base+4, 0x0b);
	outb(m_io_port_base+1, 0x01);

	/* コンソールの大きさを取得。 */
	char buf[16] = "\x1b[18t";
	// \033[18t
	for (int i = 0; buf[i] != '\0'; ++i) {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, buf[i]);
	}
	// \033[8;55;100t
	for (int i = 0; i < 16; ++i) {
		buf[i] = '\0';
	}
	for (int i = 0; i < 15; ++i) {
		while ((inb(m_io_port_base+5) & 0x01) == 0);
		buf[i] = inb(m_io_port_base);
		if (buf[i] == 't') {
			break;
		}
	}
	uint64_t colst = 0;
	uint64_t rowst = 0;
	char *ptr;
	int index = 2;
	ptr = nullptr;
	for (int i = index; i < 15; ++i) {
		if (buf[i] == ';') {
			ptr = &buf[i + 1];
			index = i + 1;
			break;
		}
	}
	if (ptr != nullptr)
		rowst = parse_uint64(ptr);
	ptr = nullptr;
	for (int i = index; i < 15; ++i) {
		if (buf[i] == ';') {
			ptr = &buf[i + 1];
			break;
		}
	}
	if (ptr != nullptr)
		colst = parse_uint64(ptr);
	cols(colst);
	rows(rowst);

	/* コンソールのクリア。 */
	char buf2[16] = "\x1b[2J";
	for (int i = 0; buf2[i] != '\0'; ++i) {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, buf2[i]);
	}

	/* カーソルを [1:1] へ移動。 */
	char buf3[16] = "\x1b[1;1H";
	for (int i = 0; buf3[i] != '\0'; ++i) {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, buf3[i]);
	}

	console_base::reset();
}

void
serial_console::refresh()
{
}

void
serial_console::handle_osc(char const *buf, const char c)
{
	switch (c) {
	case 'A':
		handle_arrow(console_arrow::arrow_up);
		break;
	case 'B':
		handle_arrow(console_arrow::arrow_down);
		break;
	case 'C':
		handle_arrow(console_arrow::arrow_right);
		break;
	case 'D':
		handle_arrow(console_arrow::arrow_left);
		break;
	}
}

void
serial_console::handler()
{
	while (m_ibuf.readable() > 0) {
		char buf[16];

		for (int i = 0; i < 6; ++i) {
			buf[i] = m_ibuf[i];
		}

		if ((m_ibuf.readable() > 2)
		 && (m_ibuf[0] == 0x1b)
		 && (m_ibuf[1] == 0x5b)) {
			for (int i = 2; i < m_ibuf.readable(); ++i) {
				if ((m_ibuf[i] >= 0x40) && (m_ibuf[i] <= 0x7e)) {
					for (int j = 0; j <= i; ++j) {
						buf[j] = m_ibuf[j];
					}
					for (int j = 0; j <= i; ++j) {
						uint8_t dummy;
						m_ibuf.read(dummy);
					}
					handle_osc(buf, buf[i]);
					continue;
				}
			}
		}

		for (int i = 0; i < 6; ++i) {
			buf[i] = m_ibuf[i];
		}

		uint32_t c = 0;
		int utf8len = utf8_to_unicode(buf, &c);
		if (utf8len <= m_ibuf.readable()) {
			for (int i = 0; i < utf8len; ++i) {
				uint8_t dummy;
				m_ibuf.read(dummy);
			}
		}
		getchar(c);
	}
}

void
serial_console::putchar(uint32_t c)
{
	char cc[8];
	int b, i;

	if (c == 0x7f) {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, 0x08);
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, ' ');
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, 0x08);
		return;
	}

	if (c == '\n') {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, '\r');
	}
	b = unicode_to_utf8(&c, cc);
	for (i = 0; i < b; ++i) {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, cc[i]);
	}
	if (c == '\r') {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, '\n');
	}
}

void
serial_console::plotchar(uint32_t x, uint32_t y, uint32_t c)
{
}

