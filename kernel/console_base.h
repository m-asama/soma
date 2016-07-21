/**
 * @file	console_base.h
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * コンソールの基底クラス。
 * すべてのコンソールに共通する変数や関数を定義。
 */
class console_base {

public:
	/**
	 * コンストラクタ。
	 */
	console_base();

	/**
	 * デストラクタ。
	 */
	virtual ~console_base();

	/**
	 * コンソール同士を比較するための等価演算子。
	 * @param rhs 比較対象のオブジェクト。
	 * @return メモリ上のアドレスが等しい時に true を返す。
	 */
	bool operator==(const console_base &rhs);
	
	/**
	 * コンソールの列数を設定する。
	 * @param cols 新しいコンソールの列数。
	 * @return 何も返さない。
	 */
	void cols(uint32_t cols);

	/**
	 * コンソールの列数を返す。
	 * @return 現在の列数を返す。
	 */
	uint32_t cols();

	/**
	 * コンソールの行数を設定する。
	 * @param rows 新しいコンソールの行数。
	 * @return 何も返さない。
	 */
	void rows(uint32_t rows);
	
	/**
	 * コンソールの行数を返す。
	 * @return 現在の行数を返す。
	 */
	uint32_t rows();
	
	/**
	 * コンソールバッファを設定する。
	 * @param buffer 新しいコンソールバッファへのポインタ。
	 */
	void buffer(uint32_t *buffer);
	
	/*
	 *
	 */
	uint32_t *buffer();
	
	/*
	 *
	 */
	void cursor_x(uint32_t cursor_x);
	
	/*
	 *
	 */
	uint32_t cursor_x();
	
	/*
	 *
	 */
	void cursor_y(uint32_t cursor_y);
	
	/*
	 *
	 */
	uint32_t cursor_y();

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
	virtual uint32_t getchar() = 0;

	/*
	 *
	 */
	virtual void putchar(uint32_t c) = 0;

	/*
	 *
	 */
	void line_shift();

private:
	/*
	 *
	 */
	uint32_t m_cols;

	/*
	 *
	 */
	uint32_t m_rows;

	/*
	 *
	 */
	uint32_t *m_buffer;

	/*
	 *
	 */
	uint32_t m_cursor_x;

	/*
	 *
	 */
	uint32_t m_cursor_y;

};

