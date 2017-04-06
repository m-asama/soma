/**
 * @file	block_device_base.h
 * @brief	ブロックデバイス基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

/**
 * ブロックデバイス基底クラス。
 */
class block_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	block_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~block_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	block_device_base(const block_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	block_device_base(block_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	block_device_base &operator=(const block_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	block_device_base &operator=(block_device_base &&src) = delete;

protected:

};

