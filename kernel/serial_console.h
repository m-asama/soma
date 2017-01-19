/**
 * @file	serial_console.h
 * @brief	シリアル・コンソールのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "ring_buffer.h"

#include "console_base.h"

/**
 * シリアル・コンソールのクラス。
 */
class serial_console : public console_base {

public:
	/**
	 * コンストラクタ。
	 */
	serial_console();

	/**
	 * デストラクタ。
	 */
	virtual ~serial_console();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	serial_console(const serial_console &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	serial_console(const serial_console &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const serial_console &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const serial_console &&src) = delete;

	/**
	 * コンソールをリセットするための関数。
	 */
	virtual void reset();

	/**
	 * コンソールを再描画するための関数。
	 */
	virtual void refresh();

	/**
	 * 入力ハンドラ。
	 */
	virtual void handler();

	/**
	 * コンソールへ一文字出力するための関数。
	 * @param c UNICODE で表現された一文字。
	 */
	virtual void putchar(uint32_t c);

	/**
	 * コンソールへ一文字出力するための関数。
	 * @param c UNICODE で表現された一文字。
	 */
	virtual void plotchar(uint32_t x, uint32_t y, uint32_t c);

	/**
	 * I/O ポート番号のベースを設定する関数。
	 * @param io_port_base I/O ポート番号のベース。
	 */
	void io_port_base(uint16_t io_port_base);

	/**
	 * I/O ポート番号のベースを返す関数。
	 * @return I/O ポート番号のベース。
	 */
	uint16_t io_port_base();

	/**
	 * IRQ 番号を設定する関数。
	 * @param irq IRQ 番号。
	 */
	void irq(uint8_t irq);

	/**
	 * IRQ 番号を返す関数。
	 * @return IRQ 番号。
	 */
	uint8_t irq();

	/**
	 * 通信速度を設定する関数。
	 * @param baud_rate 通信速度。
	 */
	void baud_rate(uint16_t baud_rate);

	/**
	 * 通信速度を返す関数。
	 * @return 通信速度。
	 */
	uint16_t baud_rate();

	/**
	 * データビットを設定する関数。
 	 * @param data_bits データビット。
	 */
	void data_bits(uint8_t data_bits);

	/**
	 * データビットを返す関数。
	 * @return データビット。
	 */
	uint8_t data_bits();

	/**
	 * ストップビットを設定する関数。
	 * @param stop_bits ストップビット。
	 */
	void stop_bits(uint8_t stop_bits);

	/**
	 * ストップビットを返す関数。
	 * @return ストップビット。
	 */
	uint8_t stop_bits();

	/**
	 * パリティを設定する関数。
	 * @param parity パリティ。
	 */
	void parity(uint8_t parity);

	/**
	 * パリティを返す関数。
	 * @return パリティ。
	 */
	uint8_t parity();

	/**
	 * シリアルからデータを読み込みバッファ(ibuf)に格納。
	 * @return 読み込んだバイト数。
	 */
	uint64_t read_from_serial();

	/**
	 * Control Sequence Introducer を処理。
	 */
	void handle_osc(char const *buf, const char c);

private:
	/**
	 * I/O ポートのベース。
	 */
	uint16_t m_io_port_base;

	/**
	 * IRQ 番号。
	 */
	uint8_t m_irq;

	/**
	 * 通信速度。
	 */
	uint16_t m_baud_rate;

	/**
	 * データビット。
	 */
	uint8_t m_data_bits;

	/**
	 * ストップビット。
	 */
	uint8_t m_stop_bits;

	/**
	 * パリティ。
	 */
	uint8_t m_parity;

	/**
	 * シリアルコンソールからの入力用バッファ。
	 */
	ring_buffer<uint8_t> m_ibuf;

	/**
	 * シリアルコンソールへの出力用バッファ。
	 */
	ring_buffer<uint8_t> m_obuf;

};

