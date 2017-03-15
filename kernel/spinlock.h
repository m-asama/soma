/**
 * @file	spinlock.h
 * @brief	スピンロッククラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * スピンロッククラス。
 */
class spinlock {

public:
	/**
	 * コンストラクタ。
	 */
	spinlock();

	/**
	 * デストラクタ。
	 */
	virtual ~spinlock();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	spinlock(const spinlock &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	spinlock(spinlock &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	spinlock &operator=(const spinlock &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	spinlock &operator=(spinlock &&src) = delete;

	/**
	 * スピンロックを取得する。
	 */
	void acquire();

	/**
	 * スピンロックを解放する。
	 */
	void release();

private:
	/**
	 * スピンロックの状態。
	 */
	uint64_t m_locked;

	/**
	 * ロックを取得しているプロセッサ ID。
	 */
	uint64_t m_processor_id;

	/**
	 * 割り込み状態のバックアップ。
	 */
	uint64_t m_interrupts[256];

};

