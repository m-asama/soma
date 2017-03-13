/**
 * @file	pci_device_base.h
 * @brief	PCI デバイスの基底クラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * PCI デバイスの基底クラス宣言。
 */
class pci_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	pci_device_base();

	/**
	 * デストラクタ。
	 */
	virtual ~pci_device_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	pci_device_base(const pci_device_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	pci_device_base(pci_device_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	pci_device_base &operator=(const pci_device_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	pci_device_base &operator=(pci_device_base &&src) = delete;

private:

};

