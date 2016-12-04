/**
 * @file	thread.h
 * @brief	スレッドを表現するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "processor_state_base.h"

/**
 * スレッドの状態を表す enum class。
 */
enum class thread_state {
	idle,
	running,
};

typedef void (*main_fn)();

/**
 * スレッドを表現するクラス。
 */
class thread {

public:
	/**
	 * コンストラクタ。
	 * @param main スレッドのメイン関数。
	 */
	thread(main_fn main);

	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	thread() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~thread();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	thread(const thread &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	thread(const thread &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	thread &operator=(const thread &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	thread &operator=(const thread &&src) = delete;

	/**
	 * スレッドを比較するための等価演算子。
	 * @param rhs 比較対象のスレッド。
	 * @return スレッド ID が等しい時に true を返す。
	 */
	bool operator==(const thread &rhs);

	/**
	 * スレッドを比較するための比較演算子。
	 * @param rhs 比較致傷のスレッド。
	 * @return スレッド ID が引数よりも大きい時に true を返す。
	 */
	bool operator>(const thread &rhs);

	/**
	 * スレッドの初期化関数。
	 * @param id スレッド ID。
	 * @param name スレッド名。
	 * @return 正常終了で 0 を返す。
	 */
	int init(uint64_t id, const utf8str &name);

	/**
	 * スレッド ID を設定する関数。
	 * @param id スレッド ID。
	 */
	void id(uint64_t id);

	/**
	 * スレッド ID を返す関数。
	 * @return スレッド ID。
	 */
	uint64_t id() const;

	/**
	 * スレッド名を設定する関数。
	 * @param name スレッド名。
	 */
	void name(const utf8str &name);

	/**
	 * スレッド名を返す関数。
	 * @return スレッド名。
	 */
	const utf8str &name();

	/**
	 * スレッドの状態を設定する関数。
	 * @param state スレッドの状態。
	 */
	void state(thread_state state);

	/**
	 * スレッドの状態を返す関数。
	 * @return スレッドの状態。
	 */
	thread_state state();

	/**
	 * ページテーブルを返す関数。
	 * @return ページテーブル。
	 */
	uint64_t page_table();

	/**
	 * スタックポインタを返す関数。
	 * @return スタックポインタ。
	 */
	uint64_t stack_pointer();

	/**
	 * スレッドのメイン関数を返す関数。
	 * @return スレッドのメイン関数。
	 */
	main_fn main();

	/**
	 * スレッドの情報を表示する関数。
	 */
	void dump();

private:
	/**
	 * スレッド ID。
	 */
	uint64_t m_id;

	/**
	 * スレッド名。
	 */
	utf8str m_name;

	/**
	 * スレッドのメイン関数。
	 */
	main_fn m_main;

	/**
	 * プロセッサ状態。
	 */
	processor_state_base *m_processor_state;

	/**
	 * スレッドの状態。
	 */
	thread_state m_state;

};

