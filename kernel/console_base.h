/**
 * @file	console_base.h
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "thread.h"

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
	 * コピーコンストラクタ。コピーは禁止。
	 */
	console_base(const console_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	console_base(const console_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const console_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const console_base &&src) = delete;

	/**
	 * コンソール同士を比較するための等価演算子。
	 * @param rhs 比較対象のオブジェクト。
	 * @return メモリ上のアドレスが等しい時に true を返す。
	 */
	bool operator==(const console_base &rhs);

	/**
	 * コンソール名を設定する。
	 * @param name コンソール名。
	 */
	void name(utf8str name);

	/**
	 * コンソール名を返す。
	 * @return コンソール名。
	 */
	utf8str name();

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
	
	/**
	 * コンソールバッファへのポインタを返す。
	 * @return コンソールバッファへのポインタ。
	 */
	uint32_t *buffer();
	
	/**
	 * カーソルの横方向の位置を設定する。
	 * @param cursor_x カーソルの横方向の位置。
	 */
	void cursor_x(uint32_t cursor_x);
	
	/**
	 * カーソルの横方向の位置を返す。
	 * @return カーソルの横方向の位置。
	 */
	uint32_t cursor_x();
	
	/**
	 * カーソルの縦方向の位置を設定する。
	 * @param cursor_y カーソルの縦方向の位置。
	 */
	void cursor_y(uint32_t cursor_y);
	
	/**
	 * カーソルの縦方向の位置を返す。
	 * @return カーソルの縦方向の位置。
	 */
	uint32_t cursor_y();

	/**
	 * コンソールスレッドへのポインタを設定。
	 * @param console_thread コンソールスレッドへのポインタ。
	 */
	void console_thread(thread *console_thread);

	/**
	 * コンソールスレッドへのポインタを返す。
	 * @return コンソールスレッドへのポインタ。
	 */
	thread *console_thread();

	/**
	 * コンソールをリセットする。
	 */
	virtual void reset();

	/**
	 * コンソールを再描画する。
	 */
	virtual void refresh();

	/**
	 * コンソールから一文字取得する。
	 */
	virtual uint32_t getchar() = 0;

	/**
	 * コンソールへ一文字表示する。
	 */
	virtual void putchar(uint32_t c) = 0;

	/**
	 * 文字列を表示する。
	 */
	int print(const char *str);

	/**
	 * 文字列を表示する。
	 */
	int print(utf8str &str);

	/**
	 * コンソールを一行送る。
	 */
	void line_shift();

private:
	/**
	 * コンソール名。
	 */
	utf8str m_name;

	/**
	 * コンソールの列数。
	 */
	uint32_t m_cols;

	/**
	 * コンソールの行数。
	 */
	uint32_t m_rows;

	/**
	 * コンソールバッファ。
	 */
	uint32_t *m_buffer;

	/**
	 * カーソルの横方向の位置。
	 */
	uint32_t m_cursor_x;

	/**
	 * カーソルの縦方向の位置。
	 */
	uint32_t m_cursor_y;

	/**
	 * コンソールスレッド。
	 */
	thread *m_console_thread;

};

