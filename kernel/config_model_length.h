/**
 * @file	config_model_length.h
 * @brief	設定モデルノードで用いられる長さクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"

class config_model_length {

public:
	/**
	 * コンストラクタ。
	 */
	config_model_length() = delete;

	/**
	 * コンストラクタ。
	 */
	config_model_length(utf8str length);

	/**
	 * デストラクタ。
	 */
	virtual ~config_model_length();

	/**
	 *
	 */
	bool operator==(const config_model_length &rhs);

	/**
	 * チェックメソッド。
	 */
	bool check(utf8str value);

private:
	/**
	 * 範囲。
	 */
	utf8str m_length;

};

