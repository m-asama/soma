/**
 * @file	ring_buffer.h
 * @brief	リングバッファのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * リングバッファのクラス。
 */
template<class V>
class ring_buffer {

	/**
	 * テスト関数は friend に設定する必要がある。
	 */
	friend void ring_buffer_test();

public:
	/**
	 * コンストラクタ。
	 * @param size リングバッファのサイズ。 2 の冪乗数以外が指定された時は繰り上げる。
	 */
	ring_buffer(uint64_t size);

	/**
	 * デフォルトコンストラクタ。引数なしのコンストラクタは禁止。
	 */
	ring_buffer() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~ring_buffer();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	ring_buffer(const ring_buffer<V> &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	ring_buffer(ring_buffer<V> &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const ring_buffer<V> &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(ring_buffer<V> &&src) = delete;

	/**
	 * インデックスを指定して値を読む。
	 * @return 指定されたインデックスの値。
	 * @param i インデックス。
	 */
	V operator[](uint64_t i);

	/**
	 * 一つ読み込み。
	 * @return 読めた場合に真。
	 * @param d 読むデータへの参照。
	 */
	bool read(V &d);

	/**
	 * 一つ書き込み。
	 * @return 書けた場合に真。
	 * @param d 書くデータへの参照。
	 */
	bool write(V &d);

	/**
	 * 読み込み可能かを確認。
	 * @return 読める場合に真。
	 */
	uint64_t readable();

	/**
	 * 書き込み可能かを確認。
	 * @return 書ける場合に真。
	 */
	uint64_t writeable();

private:
	/**
	 * リングバッファ領域。
	 */
	V *m_buffer;

	/**
	 * リングバッファの大きさ。 2 の冪乗数。
	 */
	uint64_t m_size;

	/**
	 * 次に読む位置。
	 */
	uint64_t m_next_read;

	/**
	 * 次に書く位置。
	 */
	uint64_t m_next_write;

};

#include "ring_buffer.cpp"

