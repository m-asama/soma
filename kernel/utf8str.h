/**
 * @file	utf8str.h
 * @brief	文字列のクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * 文字列のクラス。
 */
class utf8str {

	/**
	 * テスト関数は friend に設定する必要がある。
	 */
	friend void utf8str_test_one(utf8str &s, char const *teststr, char const *title);

public:
	/**
	 * コンストラクタ。
	 */
	utf8str();

	/**
	 * デストラクタ。
	 */
	virtual ~utf8str();

	/**
	 * コピーコンストラクタ。
	 * @param src 初期化する文字列。
	 */
	utf8str(const utf8str &src);

	/**
	 * ムーブコンストラクタ。ムーブは禁止(仮)。
	 */
	utf8str(const utf8str &&src) = delete;

	/**
	 * コンストラクタ。
	 * @param s 初期化する文字列。
	 */
	utf8str(const char *s);

	/**
	 * コピー代入演算子。
	 * @param src 代入する文字列。
	 */
	utf8str &operator=(const utf8str &src);

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止(仮)。
	 */
	utf8str &operator=(const utf8str &&src) = delete;

	/**
	 * 代入演算子。
	 * @param s 代入する文字列。
	 */
	utf8str &operator=(const char *s);

	/**
	 * 文字列の末尾に文字列を追加する演算子。
	 * @param s 追加する文字列。
	 * @return 追加後の文字列。
	 */
	utf8str &operator+=(const utf8str &s);

	/**
	 * 文字列の末尾に文字列を追加する演算子。
	 * @param s 追加する文字列。
	 * @return 追加後の文字列。
	 */
	utf8str &operator+=(const char *s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数と一致した場合に true を返す。
	 */
	bool operator==(const utf8str &s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数と一致した場合に true を返す。
	 */
	bool operator==(const char *s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数と一致しなかった場合に true を返す。
	 */
	bool operator!=(const utf8str &s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数と一致しなかった場合に true を返す。
	 */
	bool operator!=(const char *s);

	/**
	 * 文字列を初期化する関数。
	 * @param s 初期化したい文字列。
	 */
	void init_utf8str(const char *s);

	/**
	 * 文字列を代入する関数。
	 * @param s 代入したい文字列。
	 * @return 代入した後の文字列。
	 */
	utf8str &assign_utf8str(const char *s);

	/**
	 * 文字列の末尾に文字列を追加する関数。
	 * @param s 追加したい文字列。
	 * @param width 追加したい幅数。
	 * @return 追加後の文字列。
	 */
	utf8str &append_utf8str(const char *s, size_t width);

	/**
	 * 文字列の末尾に符合付き整数を追加する関数。
	 * @param val 追加したい符合付き整数。
	 * @param width 追加したい幅数。
	 * @return 追加後の文字列。
	 */
	utf8str &append_sint64(sint64_t val, size_t width);

	/**
	 * 文字列の末尾に符合なし整数を追加する関数。
	 * @param val 追加したい符合なし整数。
	 * @param width 追加したい幅数。
	 * @return 追加後の文字列。
	 */
	utf8str &append_uint64(uint64_t val, size_t width);

	/**
	 * 文字列の末尾に１６進整数を追加する関数。
	 * @param val 追加したい整数。
	 * @param width 追加したい幅数。
	 * @return 追加後の文字列。
	 */
	utf8str &append_hex64(uint64_t val, size_t width);

	/**
	 * 文字列を比較する関数。
	 * @param s 比較対象の文字列。
	 * @return 文字列が等しい時に true を返す。
	 */
	bool is_equal(const char *s);

	/**
	 * 文字列へのポインタを返す関数。
	 * @return 文字列へのポインタ。
	 */
	const char *ptr() const;

	/**
	 * 文字列の長さを返す関数。
	 * @return 文字列の長さ。
	 */
	size_t length() const;

	/**
	 * 文字列の幅を返す関数。
	 * @return 文字列の幅。
	 */
	size_t width() const;

private:
	/**
	 * バッファへのポインタ。
	 */
	char *m_buffer;

	/**
	 * バッファの大きさ。
	 */
	size_t m_buffer_size;

};

