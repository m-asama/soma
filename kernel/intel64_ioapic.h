/**
 * @file	intel64_ioapic.h
 * @brief	Intel64 I/O APIC の初期化等を行う関数群宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "irqchip_base.h"

/**
 * Intel64 I/O APIC を格納するクラス。
 */
class intel64_ioapic : public irqchip_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_ioapic();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_ioapic();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_ioapic(const intel64_ioapic &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_ioapic(intel64_ioapic &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_ioapic &operator=(const intel64_ioapic &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_ioapic &operator=(intel64_ioapic &&src) = delete;

private:
	/**
	 *
	 */

};

