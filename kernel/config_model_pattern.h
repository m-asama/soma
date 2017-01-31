/**
 * @file	config_model_pattern.h
 * @brief	設定モデルノードで用いられるパターンクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"

class config_model_pattern {

public:
	/**
	 * コンストラクタ。
	 */
	config_model_pattern() = delete;

	/**
	 * コンストラクタ。
	 */
	config_model_pattern(utf8str pattern);

	/**
	 * デストラクタ。
	 */
	virtual ~config_model_pattern();

	/**
	 *
	 */
	bool operator==(const config_model_pattern &rhs);

	/**
	 *
	 */
	void pattern(utf8str pattern);

	/**
	 *
	 */
	utf8str pattern();

	/**
	 * チェックメソッド。
	 */
	bool check(utf8str value);

private:
	/**
	 * 範囲。
	 */
	utf8str m_pattern;

};

