/**
 * @file	sorted_list.h
 * @brief	整列されたリストのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "bidir_node.h"

/**
 * 整列されたリストのクラス。
 */
template<class V>
class sorted_list {

	/**
	 * メモリ管理の初期化の際は private: な変数にアクセスするため、
	 * memory_init を friend とする必要がある。
	 */
	friend void memory_init(struct loader_info *li);

public:
	/**
	 * コンストラクタ。
	 */
	sorted_list();

	/**
	 * デストラクタ。
	 */
	virtual ~sorted_list();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	sorted_list(const sorted_list<V> &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	sorted_list(const sorted_list<V> &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const sorted_list<V> &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const sorted_list<V> &&src) = delete;

	/**
	 * 整列リストに値を格納する。
	 * @param v 格納したい値。
	 * @return 正常終了時に 0 を返す。
	 */
	int
	insert(V &v);

	/**
	 * 整列リストから値を削除する。
	 * @param v 削除したい値。
	 * @return 正常終了時に 0 を返す。
	 */
	int
	remove(V &v);

	/**
	 * 整列リストから引数に渡された値と同じオブジェクトへの参照を返す。
	 * @param v 検索したいオブジェクト。
	 * @return 整列リスト内に格納されていた引数と等しいオブジェクトへの参照。
	 */
	const V *
	find(const V &v);

	/**
	 * 整列リストを再度整列する。
	 * @return 正常終了時に 0 を返す。
	 */
	int
	resort();

	/**
	 * 整列リストの先頭の bidir_node へのポインタを返す。
	 * @return 整列リストの先頭の bidir_node へのポインタ。
	 */
	bidir_node<V> *head();

	/**
	 * 整列リストの末尾の bidir_node へのポインタを返す。
	 * @return 整列リストの末尾の bidir_node へのポインタ。
	 */
	bidir_node<V> *tail();

	/**
	 * 整列リストに登録された値の数。
	 */
	int nodes();

private:
	/**
	 * 整列リストの先頭の bidir_node へのポインタ。
	 */
	bidir_node<V> *m_head;

	/**
	 * 整列リストの末尾の bidir_node へのポインタ。
	 */
	bidir_node<V> *m_tail;

	/**
	 * 整列リストに登録された値の数。
	 */
	int m_nodes;

};

#include "sorted_list.cpp"

