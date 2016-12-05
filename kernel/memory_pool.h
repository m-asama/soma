/**
 * @file	memory_pool.h
 * @brief	ある型のメモリ領域をまとめて管理するプールを表すクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

const int memory_pool_free_bits_size = 8;

/**
 * ある型のメモリ領域をまとめて管理するプールを表すクラス。
 */
template<class T>
class memory_pool {

	/**
	 * メモリ管理の初期化の際は private: な変数にアクセスするため、
	 * memory_init を friend とする必要がある。
	 */
	friend void memory_init(struct loader_info *li);

public:
	/**
	 * コンストラクタ。
	 */
	memory_pool();

	/**
	 * デストラクタ。
	 */
	virtual ~memory_pool();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	memory_pool(const memory_pool<T> &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	memory_pool(const memory_pool<T> &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const memory_pool<T> &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const memory_pool<T> &&src) = delete;

	/**
	 * メモリブロックから未使用のものを見つけ出し割り当てる関数。
	 * @return 割り当てられたアドレスへのポインタ。
	 */
	T *alloc();

	/**
	 * 割り当てられたものを回収するための関数。
	 * @param ptr 回収するアドレスへのポインタ。
	 */
	void free(T *ptr);

	/**
	 * 現在割り当てられている数を返す関数。
	 * @return 現在割り当てられている数。
	 */
	uint64_t count();

private:
	/**
	 * 割り当てを管理するためのビット列。
	 */
	uint64_t m_free_bits[memory_pool_free_bits_size];

	/**
	 * メモリブロックへのポインタ。
	 */
	T *m_table;

	/**
	 * 次のメモリプールのアドレスを指すポインタ。
	 */
	memory_pool<T> *m_next;

};

#include "memory_pool.cpp"

