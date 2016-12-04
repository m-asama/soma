/**
 * @file	linked_list.h
 * @brief	リンクリストのクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "bidir_node.h"

/**
 * リンクリストのクラス。
 */
template<class V>
class linked_list {

public:
	/**
	 * コンストラクタ。
	 */
	linked_list();

	/**
	 * デストラクタ。
	 */
	virtual ~linked_list();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	linked_list(const linked_list<V> &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	linked_list(const linked_list<V> &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const linked_list<V> &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const linked_list<V> &&src) = delete;

	/**
	 * リンクリストの先頭に値を格納する。
	 * @param v 格納したい値。
	 * @return 正常時に 0 を返す。
	 */
	int insert_head(V &v);

	/**
	 * リンクリストの末尾に値を格納する。
	 * @param v 格納したい値。
	 * @return 正常時に 0 を返す。
	 */
	int insert_tail(V &v);

	/**
	 * リンクリストから値を削除する。
	 * @param v 削除したい値。
	 * @return 正常終了時に 0 を返す。
	 */
	int remove(const V &v);

	/**
	 * リンクリストから引数に渡された値と同じオブジェクトへの参照を返す。
	 * @param v 検索したいオブジェクト。
	 * @return リンクリスト内に格納されていた引数と等しいオブジェクトへの参照。
	 */
	V *find(const V &v);

	/**
	 * リンクリストの先頭の bidir_node へのポインタを返す。
	 * @return リンクリストの先頭の bidir_node へのポインタ。
	 */
	bidir_node<V> *head();

	/**
	 * リンクリストの末尾の bidir_node へのポインタを返す
	 * @return リンクリストの末尾の bidir_node へのポインタ。
	 */
	bidir_node<V> *tail();

	/**
	 * リンクリストに登録された値の数。
	 */
	int nodes();

private:
	/**
	 * リンクリストの先頭の bidir_node へのポインタ。
	 */
	bidir_node<V> *m_head;

	/**
	 * リンクリストの末尾の bidir_node へのポインタ。
	 */
	bidir_node<V> *m_tail;

	/**
	 * リンクリストに登録された値の数。
	 */
	int m_nodes;

};

#include "linked_list.cpp"

