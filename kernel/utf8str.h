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
	friend void utf8str_test_one(utf8str &s, char const *teststr, utf8str title);

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
	 * ムーブコンストラクタ。
	 */
	utf8str(utf8str &&src);

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
	 * ムーブ代入演算子。
	 */
	utf8str &operator=(utf8str &&src);

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
	 * 文字列の末尾に文字を追加する演算子。
	 * @param c 追加する文字。
	 * @return 追加後の文字列。
	 */
	utf8str &operator+=(const uint32_t c);

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
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数より大きい時に true を返す。
	 */
	bool operator>(const utf8str &s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数より大きい時に true を返す。
	 */
	bool operator>(const char *s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数より小さい時に true を返す。
	 */
	bool operator<(const utf8str &s);

	/**
	 * 文字列を比較する演算子。
	 * @param s 比較対象の文字列。
	 * @return 文字列が引数より小さい時に true を返す。
	 */
	bool operator<(const char *s);

	/**
	 * インデックスを指定して UNICODE 文字を返す。
	 * @param i インデックス。
	 * @return 指定された位置の UNICODE 文字。
	 */
	uint32_t operator[](sint64_t i) const;

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
	 * 文字列の末尾から削除する関数。
	 * @param count 削除したい文字数。
	 * @return 削除後の文字列。
	 */
	utf8str &truncate(uint64_t count);

	/**
	 * 文字列を比較する関数。
	 * @param s 比較対象の文字列。
	 * @return 文字列が等しい時に true を返す。
	 */
	bool is_equal(const char *s);

	/**
	 * 文字列を比較する関数。
	 * @param s 比較対象の文字列。
	 * @return 文字列が大きい時に true を返す。
	 */
	bool is_large(const char *s);

	/**
	 * 文字列を比較する関数。
	 * @param s 比較対象の文字列。
	 * @return 文字列が小さい時に true を返す。
	 */
	bool is_small(const char *s);

	/**
	 * 文字列が指定する文字列で始まるかチェックする関数。
	 * @param s チェックしたい文字列。
	 * @return 指定した文字列で始まる場合に true を返す。
	 */
	bool beginning(utf8str s);

	/**
	 * 文字列が指定する文字列で始まるかチェックする関数。
	 * @param s チェックしたい文字列。
	 * @return 指定した文字列で始まる場合に true を返す。
	 */
	bool beginning(char const *s);

	/**
	 * 文字列が指定する文字列で終わるかチェックする関数。
	 * @param s チェックしたい文字列。
	 * @return 指定した文字列で終わる場合に true を返す。
	 */
	bool ending(utf8str s);

	/**
	 * 文字列が指定する文字列で終わるかチェックする関数。
	 * @param s チェックしたい文字列。
	 * @return 指定した文字列で終わる場合に true を返す。
	 */
	bool ending(char const *s);

	/**
	 * 文字列へのポインタを返す関数。
	 * @return 文字列へのポインタ。
	 */
	//const char *ptr() const;

	/**
	 * インデックスで指定したバイトの値を返す関数。
	 * @param i インデックス。
	 * @return 指定したインデックスのバイトの値。
	 */
	char byte_at(sint64_t i) const;

	/**
	 * インデックスで指定した UNICODE 文字を返す関数。
	 * @param i インデックス。
	 * @return 指定したインデックスの UNICODE の値。
	 */
	uint32_t unicode_at(sint64_t i) const;

	/**
	 * 部分文字列を返す関数。
	 * @param begin 先頭文字のインデックス。
	 * @param end 末尾文字のインデックス。
	 * @return 指定された部分文字列。
	 */
	utf8str byte_substring(sint64_t begin, sint64_t end) const;

	/**
	 * 部分文字列を返す関数。
	 * @param begin 先頭文字のインデックス。
	 * @param end 末尾文字のインデックス。
	 * @return 指定された部分文字列。
	 */
	utf8str unicode_substring(sint64_t begin, sint64_t end) const;

	/**
	 * 文字列の長さ(バイト数)を返す関数。
	 * @return 文字列の長さ(バイト数)。
	 */
	size_t byte_length() const;

	/**
	 * 文字列の UNICODE 文字数を返す関数。
	 * @return 文字列の UNICODE 文字数。
	 */
	size_t unicode_length() const;

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

