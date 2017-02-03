/**
 * @file	console_base.h
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "linked_list.h"
#include "thread.h"
#include "console_msg.h"
//#include "command_node.h"
//#include "config_model_node.h"

class command_node;
class config_model_node;

/**
 * コンソールの権限。
 */
enum class console_role {
	role_administrator,
	role_operator,
};

/**
 * コンソールのモード。
 */
enum class console_mode {
	mode_login_prompt,
	mode_command_prompt,
	mode_dont_echo,
	mode_pager,
};

/**
 * 矢印キー。
 */
enum class console_arrow {
	arrow_up,
	arrow_down,
	arrow_right,
	arrow_left,
};

/**
 * コンソールの基底クラス。
 * すべてのコンソールに共通する変数や関数を定義。
 */
class console_base {

public:
	/**
	 * コンストラクタ。
	 */
	console_base();

	/**
	 * デストラクタ。
	 */
	virtual ~console_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	console_base(const console_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	console_base(const console_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	void operator=(const console_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	void operator=(const console_base &&src) = delete;

	/**
	 * コンソール同士を比較するための等価演算子。
	 * @param rhs 比較対象のオブジェクト。
	 * @return メモリ上のアドレスが等しい時に true を返す。
	 */
	bool operator==(const console_base &rhs);

	/**
	 * コンソール名を設定する。
	 * @param name コンソール名。
	 */
	void name(utf8str name);

	/**
	 * コンソール名を返す。
	 * @return コンソール名。
	 */
	utf8str name();

	/**
	 * コンソールの列数を設定する。
	 * @param cols 新しいコンソールの列数。
	 * @return 何も返さない。
	 */
	void cols(uint32_t cols);

	/**
	 * コンソールの列数を返す。
	 * @return 現在の列数を返す。
	 */
	uint32_t cols();

	/**
	 * コンソールの行数を設定する。
	 * @param rows 新しいコンソールの行数。
	 * @return 何も返さない。
	 */
	void rows(uint32_t rows);

	/**
	 * コンソールの行数を返す。
	 * @return 現在の行数を返す。
	 */
	uint32_t rows();

	/**
	 * コンソールバッファを設定する。
	 * @param buffer 新しいコンソールバッファへのポインタ。
	 */
	void buffer(uint32_t *buffer);

	/**
	 * コンソールバッファへのポインタを返す。
	 * @return コンソールバッファへのポインタ。
	 */
	uint32_t *buffer();

	/**
	 * カーソルの横方向の位置を設定する。
	 * @param cursor_x カーソルの横方向の位置。
	 */
	void cursor_x(uint32_t cursor_x);

	/**
	 * カーソルの横方向の位置を返す。
	 * @return カーソルの横方向の位置。
	 */
	uint32_t cursor_x();

	/**
	 * カーソルの縦方向の位置を設定する。
	 * @param cursor_y カーソルの縦方向の位置。
	 */
	void cursor_y(uint32_t cursor_y);

	/**
	 * カーソルの縦方向の位置を返す。
	 * @return カーソルの縦方向の位置。
	 */
	uint32_t cursor_y();

	/**
	 * コンソールスレッドへのポインタを設定。
	 * @param console_thread コンソールスレッドへのポインタ。
	 */
	void console_thread(thread *console_thread);

	/**
	 * コンソールスレッドへのポインタを返す。
	 * @return コンソールスレッドへのポインタ。
	 */
	thread *console_thread();

	/**
	 * 現在の権限を設定。
	 * @param current_role 現在の権限。
	 */
	void current_role(console_role current_role);

	/**
	 * 現在の権限を返す。
	 * @return 現在の権限。
	 */
	console_role current_role();

	/**
	 * 現在のモードを設定。
	 * @param current_mode 現在のモード。
	 */
	void current_mode(console_mode current_mode);

	/**
	 * 現在のモードを返す。
	 * @return 現在のモード。
	 */
	console_mode current_mode();

	/**
	 * 言語を設定。
	 * @param current_lang 言語。
	 */
	void current_lang(console_lang current_lang);

	/**
	 * 言語を返す。
	 * @return 言語。
	 */
	console_lang current_lang();

	/**
	 *
	 */
	void edit_path(utf8str edit_path);

	/**
	 *
	 */
	utf8str edit_path();

	/**
	 * コンソールをリセットする。
	 */
	virtual void reset();

	/**
	 * コンソールを再描画する。
	 */
	virtual void refresh();

	/**
	 * 入力ハンドラ。
	 */
	virtual void handler() = 0;

	/**
	 * コンソールへ一文字表示する。
	 */
	virtual void putchar(uint32_t c) = 0;

	/**
	 * コンソールへ一文字表示する。
	 */
	virtual void plotchar(uint32_t x, uint32_t y, uint32_t c) = 0;

	/**
	 *
	 */
	void handle_config_model_completion(uint32_t c, config_model_node *&cmn, utf8str &remaining, uint64_t pos, bool exclude_leaf);

	/**
	 *
	 */
	void handle_command_completion(uint32_t c, command_node *&cn, config_model_node *&cmn, utf8str &remaining, uint64_t pos);

	/**
	 *
	 */
	void handle_command_prompt(uint32_t c);

	/**
	 * コンソールで一文字処理する。
	 */
	void getchar(uint32_t c);

	/**
	 * 文字列を表示する。
	 */
	int print(const char *str);

	/**
	 * 文字列を表示する。
	 */
	int print(utf8str str);

	/**
	 * コンソールを一行送る。
	 */
	void line_shift();

	/**
	 * プロンプトを表示する。
	 */
	void print_prompt();

	/**
	 * 説明を表示する。
	 */
	void print_description(utf8str label, msg *description);

	/**
	 * 説明を表示する。
	 */
	void print_description(msg *label, msg *description);

	/**
	 * 矢印キーの処理。
	 */
	void handle_arrow(console_arrow arrow);

private:
	/**
	 * コンソール名。
	 */
	utf8str m_name;

	/**
	 * コンソールの列数。
	 */
	uint32_t m_cols;

	/**
	 * コンソールの行数。
	 */
	uint32_t m_rows;

	/**
	 * コンソールバッファ。
	 */
	uint32_t *m_buffer;

	/**
	 * カーソルの横方向の位置。
	 */
	uint32_t m_cursor_x;

	/**
	 * カーソルの縦方向の位置。
	 */
	uint32_t m_cursor_y;

	/**
	 * コンソールスレッド。
	 */
	thread *m_console_thread;

	/**
	 * 現在の権限。
	 */
	console_role m_current_role;

	/**
	 * 現在のモード。
	 */
	console_mode m_current_mode;

	/**
	 * 現在の言語。
	 */
	console_lang m_current_lang;

	/**
	 * 編集中の設定のパス。
	 */
	utf8str m_edit_path;

	/**
	 * コマンドライン上の文字列。
	 */
	utf8str m_command_line;

	/**
	 * 実行したコマンドの履歴。
	 */
	linked_list<utf8str> m_command_history;

};

