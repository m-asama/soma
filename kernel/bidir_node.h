/**
 * @file	bidir_node.h
 * @brief	双方向リンクリストのノード。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "memory_pool.h"

#include "loader_info.h"

/**
 * 双方向リンクリストのノード。
 * linked_list や sorted_list 、 hash_table が保持するオブジェクトごとに用意され、
 * それらを双方向でつなぐためのノード。
 */
template<class V>
class bidir_node {

	/**
	 * メモリ管理の初期化の際は private: な変数にアクセスするため、
	 * memory_init を friend とする必要がある。
	 */
	friend void memory_init(struct loader_info *li);

public:
	/**
	 * コンストラクタ。
	 */
	bidir_node(V &v);

	/**
	 * デストラクタ。
	 */
	virtual ~bidir_node();

	/**
	 * メモリ割当演算子。 memory_pool から割り当てる。
	 * @param size メモリを割り当てる大きさ。
	 * @return 確保されたメモリ領域へのポインタ。
	 */
	static void *operator new(size_t size);

	/**
	 * メモリ削除演算子。メモリプールに返す。
	 * @param 解放するメモリへのポインタ。
	 */
	static void operator delete(void *ptr);

	/**
	 * このノードが保持するオブジェクトへの参照を返す。
	 * @return このノードが保持するオブジェクトへの参照を返す。
	 */
	V &v();

	/**
	 * このノードの次のノードへのポインタを設定する。
	 * @param next 
	 */
	void next(bidir_node<V> *next);

	/**
	 * このノードの次のノードへのポインタを返す。
	 */
	bidir_node<V> *next();

	/**
	 * このノードの前のノードへのポインタを設定する。
	 */
	void prev(bidir_node<V> *prev);

	/**
	 * このノードの前のノードへのポインタを返す。
	 */
	bidir_node<V> *prev();

	/**
	 * 現在割り当てられているノードの数を返す。
	 */
	static uint64_t count();

private:
	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	bidir_node();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	bidir_node(const bidir_node<V> &src);

	/**
	 * 代入演算子。代入は禁止。
	 */
	void operator=(const bidir_node<V> &src);

	/**
	 * bidir_node を管理するメモリプール。
	 */
	static memory_pool<bidir_node<V>> s_mem_pool;

	/**
	 * この bidir_node に対応するオブジェクトへの参照。
	 */
	V &m_v;

	/**
	 * このノードの次のノードへのポインタ。
	 */
	bidir_node<V> *m_next;

	/**
	 * このノードの前のノードへのポインタ。
	 */
	bidir_node<V> *m_prev;

};

#include "bidir_node.cpp"

