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
	 *
	 */
	intel64_ioapic();

	/**
	 *
	 */
	virtual ~intel64_ioapic();

	/**
	 *
	 */
	intel64_ioapic(const intel64_ioapic &src) = delete;

	/**
	 *
	 */
	intel64_ioapic(const intel64_ioapic &&src) = delete;

	/**
	 *
	 */
	intel64_ioapic &operator=(const intel64_ioapic &src) = delete;

	/**
	 *
	 */
	intel64_ioapic &operator=(const intel64_ioapic &&src) = delete;

private:
	/**
	 *
	 */

};

