/**
 * @file	config_model_range.h
 * @brief	設定モデルノードで用いられる範囲クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "utf8str.h"

class config_model_range {

public:
	/**
	 * コンストラクタ。
	 */
	config_model_range() = delete;

	/**
	 * コンストラクタ。
	 */
	config_model_range(utf8str range);

	/**
	 * デストラクタ。
	 */
	virtual ~config_model_range();

	/**
	 *
	 */
	bool operator==(const config_model_range &rhs);

	/**
	 * チェックメソッド。
	 */
	bool check(utf8str value);

private:
	/**
	 * 範囲。
	 */
	utf8str m_range;

};

