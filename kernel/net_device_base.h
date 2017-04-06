/**
 * @file	net_device_base.h
 * @brief	ネットワークデバイス基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

/**
 * ネットワークデバイス基底クラス。
 */
class net_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	net_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~net_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	net_device_base(const net_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	net_device_base(net_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	net_device_base &operator=(const net_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	net_device_base &operator=(net_device_base &&src) = delete;

protected:

};

