/**
 * @file	intel64_serial_console.cpp
 * @brief	シリアル・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "intel64_assembly.h"
#include "unicode.h"

#include "serial_console.h"

serial_console::serial_console()
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
}

void
serial_console::refresh()
{
}

uint32_t
serial_console::getchar()
{
	if ((inb(m_io_port_base+5)&1) == 0) {
		return 0;
	}
	return inb(m_io_port_base);
}

void
serial_console::putchar(uint32_t c)
{
	char cc[6];
	int b, i;
	if (c == '\n') {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, '\r');
	}
	b = unicode_to_utf8(&c, cc);
	for (i = 0; i < b; ++i) {
		while ((inb(m_io_port_base+5) & 0x20) == 0);
		outb(m_io_port_base, cc[i]);
	}
}

