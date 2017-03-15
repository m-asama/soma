/**
 * @file	hash_table.h
 * @brief	ハッシュテーブルのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "bidir_node.h"

#include "loader_info.h"

const int hash_table_init_size = 0x100;

/**
 * ハッシュテーブルのクラス。
 */
template<class V>
class hash_table {

	/**
	 * メモリ管理の初期化の際は private: な変数にアクセスするため、
	 * memory_init を friend とする必要がある。
	 */
	friend void memory_init(struct loader_info *li);

public:
	/**
	 * コンストラクタ。
	 * @param hash_fn 値のハッシュ値を計算するための関数。
	 * @param equal_fn 値が等しいかを調べるための関数。
	 */
	hash_table(uint64_t (*hash_fn)(const V &v), bool (*equal_fn)(const V &vl, const V &vr));

	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	hash_table() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~hash_table();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	hash_table(const hash_table<V> &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	hash_table(hash_table<V> &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const hash_table<V> &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(hash_table<V> &&src) = delete;

	/**
	 * ハッシュテーブルに値を格納する。
	 * @param v 格納したい値。
	 * @return 正常終了時に 0 を返す。
	 */
	int insert(V &v);

	/**
	 * ハッシュテーブルから値を削除する。
	 * @param v 削除したい値。
	 * @return 正常終了時に 0 を返す。
	 */
	int remove(const V &v);

	/**
	 * ハッシュテーブルから引数に渡された値と同じオブジェクトへの参照を返す。
	 * @param v 検索したいオブジェクト。
	 * @return ハッシュテーブル内に格納されていた引数と等しいオブジェクトへの参照。
	 */
	V *find(const V &v);

	/**
	 * ハッシュテーブルのサイズを返す。
	 * @return ハッシュテーブルのサイズ。
	 */
	uint64_t table_size();

	/**
	 * ハッシュテーブル(bidir_node の配列へのポインタ)を返す。
	 * @return ハッシュテーブル(bidir_node の配列へのポインタ)。
	 */
	bidir_node<V> **table();

	/**
	 * ハッシュテーブルに登録された値の数を返す。
	 * @return ハッシュテーブルに登録された値の数。
	 */
	uint64_t nodes();

private:
	/**
	 * ハッシュテーブルを拡張する。
	 */
	void expand();

	/**
	 * 値のハッシュ値を求める関数。
	 */
	uint64_t (*m_hash_fn)(const V &v);

	/**
	 * 値が等しいかを返す関数。
	 */
	bool (*m_equal_fn)(const V &vl, const V &vr);

	/**
	 * ハッシュテーブルのサイズ。
	 */
	uint64_t m_table_size;

	/**
	 * ハッシュテーブル。
	 */
	bidir_node<V> **m_table;

	/**
	 * ハッシュテーブルに登録された値の数。
	 */
	uint64_t m_nodes;

	/**
	 * 拡張中ステータス。
	 */
	bool m_expanding;

};

#include "hash_table.cpp"

