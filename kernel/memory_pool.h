/**
 * @file	memory_pool.h
 * @brief	ある型のメモリ領域をまとめて管理するプールを表すクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

const int memory_pool_free_bits_size = 8;
const int memory_pool_vacancy_threshold1 = 16;
const int memory_pool_vacancy_threshold2 = 512 + 64;

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

	/**
	 * テスト関数は friend に設定する必要がある。
	 */
	friend void memory_pool_test();

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
	memory_pool(memory_pool<T> &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const memory_pool<T> &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(memory_pool<T> &&src) = delete;

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
	 * 割当済みプールの先頭を返す。
	 * @return 先頭のメモリプール。
	 */
	memory_pool<T> *head();

	/**
	 * 割当済みプールの末尾を返す。
	 * @return 末尾のメモリプール。
	 */
	memory_pool<T> *tail();

	/**
	 * 現在割り当てられている数を返す関数。
	 * @return 現在割り当てられている数。
	 */
	uint64_t count();

	/**
	 * 現在割り当てられているうち空きの数を返す関数。
	 * @return 現在割り当てられているうち空きの数。
	 */
	uint64_t vacancy();

	/**
	 * 割当済みオブジェクト内のアドレスからオブジェクトのポインタを返す関数。
	 * @param address オブジェクト内のアドレス。
	 * @return 渡されたアドレスを中にもつオブジェクトのポインタ。
	 */
	T *container_of(uint64_t address);

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

	/**
	 * 前のメモリプールのアドレスを指すポインタ。
	 */
	memory_pool<T> *m_prev;

	/**
	 * 呼び割り当てフラグ。
	 */
	bool m_allocating;

};

#include "memory_pool.cpp"

