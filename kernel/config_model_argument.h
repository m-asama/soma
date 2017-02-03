/**
 * @file	config_model_argument.h
 * @brief	設定モデルノードで用いられる引数クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "utf8str.h"
#include "console_msg.h"

class config_model_argument {

public:
	/**
	 * コンストラクタ。
	 */
	config_model_argument() = delete;

	/**
	 * コンストラクタ。
	 */
	config_model_argument(utf8str label, sint64_t value);

	/**
	 * デストラクタ。
	 */
	virtual ~config_model_argument();

	/**
	 *
	 */
	bool operator==(const config_model_argument &rhs);

	/**
	 *
	 */
	void label(utf8str label);

	/**
	 *
	 */
	utf8str label();

	/**
	 *
	 */
	void value(sint64_t value);

	/**
	 *
	 */
	sint64_t value();

	/**
	 *
	 */
	void description(msg *description);

	/**
	 *
	 */
	msg *description();

private:
	/**
	 * 引数。
	 */
	utf8str m_label;

	/**
	 * 値。
	 */
	sint64_t m_value;

	/**
	 * 説明。
	 */
	msg *m_description;

};

