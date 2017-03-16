/**
 * @file	unknown_pci_device.h
 * @brief	未知の PCI デバイスクラス宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "pci_device_base.h"

/**
 * 未知の PCI デバイスクラス。
 */
class unknown_pci_device : public pci_device_base {

public:
	/**
	 * コンストラクタ。
	 */
	unknown_pci_device();

	/**
	 * デストラクタ。
	 */
	virtual ~unknown_pci_device();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	unknown_pci_device(const unknown_pci_device &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	unknown_pci_device(unknown_pci_device &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	unknown_pci_device &operator=(const unknown_pci_device &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	unknown_pci_device &operator=(unknown_pci_device &&src) = delete;

	/**
	 *
	 */
	virtual void pci_init();

	/**
	 *
	 */
	virtual utf8str pci_dump();

private:

};

pci_device_base *unknown_pci_device_alloc();

bool unknown_pci_device_init();

