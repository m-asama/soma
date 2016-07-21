/**
 * @file	serial_console.h
 * @brief	シリアル・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "console_base.h"

class serial_console : public console_base {

public:
	/*
	 *
	 */
	serial_console();

	/*
	 *
	 */
	virtual ~serial_console();

	/*
	 *
	 */
	virtual void reset();

	/*
	 *
	 */
	virtual void refresh();

	/*
	 *
	 */
	virtual uint32_t getchar();

	/*
	 *
	 */
	virtual void putchar(uint32_t c);

	/*
	 *
	 */
	void io_port_base(uint16_t io_port_base);

	/*
	 *
	 */
	uint16_t io_port_base();

	/*
	 *
	 */
	void irq(uint8_t irq);

	/*
	 *
	 */
	uint8_t irq();

	/*
	 *
	 */
	void baud_rate(uint16_t baud_rate);

	/*
	 *
	 */
	uint16_t baud_rate();

	/*
	 *
	 */
	void data_bits(uint8_t data_bits);

	/*
	 *
	 */
	uint8_t data_bits();

	/*
	 *
	 */
	void stop_bits(uint8_t stop_bits);

	/*
	 *
	 */
	uint8_t stop_bits();

	/*
	 *
	 */
	void parity(uint8_t parity);

	/*
	 *
	 */
	uint8_t parity();

private:
	/*
	 *
	 */
	uint16_t m_io_port_base;
	/*
	 *
	 */
	uint8_t m_irq;

	/*
	 *
	 */
	uint16_t m_baud_rate;

	/*
	 *
	 */
	uint8_t m_data_bits;

	/*
	 *
	 */
	uint8_t m_stop_bits;

	/*
	 *
	 */
	uint8_t m_parity;

};

