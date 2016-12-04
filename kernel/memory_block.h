/**
 * @file	memory_block.h
 * @brief	メモリ内の位置と大きさを表すブロックを表現するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "memory_pool.h"

/**
 * メモリ内の位置と大きさを表すブロックを表現するクラス。
 */
class memory_block {

	/**
	 * メモリ管理の初期化の際は private: な変数にアクセスするため、
	 * memory_init を friend とする必要がある。
	 */
	friend void memory_init(struct loader_info *li);

public:
	/**
	 * コンストラクタ。
	 * @param base
	 * @param size
	 */
	memory_block(uint64_t base, uint64_t size);

	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	memory_block() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~memory_block();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	memory_block(const memory_block &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	memory_block(const memory_block &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const memory_block &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const memory_block &&src) = delete;

	/**
	 * new 演算子。
	 */
	static void *operator new(size_t size);

	/**
	 * delete 演算子。
	 */
	static void operator delete(void *ptr);

	/**
	 * メモリブロック同士を比較するための等価演算子。
	 * @param rhs 比較対象のオブジェクト。
	 * @return メモリブロックが等しい時に true を返す。
	 */
	bool operator==(const memory_block &rhs);

	/**
	 * メモリブロック同士を比較するための比較演算子。
	 * @param rhs 比較対象のオブジェクト。
	 * @return メモリブロックが引数よりも大きい時に true を返す。
	 */
	bool operator>(const memory_block &rhs);

	/**
	 * メモリブロックのベースアドレスを設定する。
	 * @param base メモリブロックのベースアドレス。
	 */
	void base(uint64_t base);

	/**
	 * メモリブロックのベースアドレスを返す。
	 * @return メモリブロックのベースアドレス。
	 */
	uint64_t base() const;

	/**
	 * メモリブロックのサイズを設定する。
	 * @param size メモリブロックのサイズ。
	 */
	void size(uint64_t size);

	/**
	 * メモリブロックのサイズを返す。
	 * @return メモリブロックのサイズ。
	 */
	uint64_t size() const;

	/**
	 * メモリブロックの数を返す。
	 * @return メモリブロックの数。
	 */
	static uint64_t count();

private:
	/**
	 * メモリブロックのメモリプール。
	 */
	static memory_pool<memory_block> s_mem_pool;

	/**
	 * メモリブロックのベースアドレス。
	 */
	uint64_t m_base;

	/**
	 * メモリブロックのサイズ。
	 */
	uint64_t m_size;

};

/**
 * メモリブロックからハッシュ値を計算するための関数。
 */
uint64_t memory_block_hash(const memory_block &mb);

/**
 * メモリブロックが等しいかどうか比較するための関数。
 */
bool memory_block_equal(const memory_block &mbl, const memory_block &mbr);

