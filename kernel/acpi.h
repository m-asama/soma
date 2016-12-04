/**
 * @file	acpi.h
 * @brief	ACPI 関連のクラス定義。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "acpi_management.h"

/**
 * ACPI テーブルの種類を表すための enum class。
 */
enum class acpi_table {
	null,
	apic,
};

/**
 * ACPI テーブルのシグネチャと enum class acpi_table の対応を表す構造体。
 */
struct acpi_table_signature {
	const char *signature;
	acpi_table table;
};

/**
 * ACPI APIC テーブル。
 */
class acpi_apic {

public:
	/**
	 * コンストラクタ。
	 * @param apic_address ACPI APIC テーブルへのポインタ。
	 */
	acpi_apic(uint8_t *apic_address);

	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	acpi_apic() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~acpi_apic();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	acpi_apic(const acpi_apic &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	acpi_apic(const acpi_apic &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	acpi_apic &operator=(const acpi_apic &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	acpi_apic &operator=(const acpi_apic &&src) = delete;

	/**
	 * ACPI APIC テーブルのシグネチャへのポインタを返す。
	 * @return ACPI APIC テーブルのシグネチャへのポインタ。
	 */
	char *signature();

	/**
	 * ACPI APIC テーブルの長さを返す。
	 * @return 長さ。
	 */
	uint32_t length();

	/**
	 * 全てのプロセッサのエントリに関数を実行する。
	 * @param function コールバック関数。
	 * @return 結果。
	 */
	int foreach_processor_apic(int (*function)(uint64_t));

	/**
	 * 全ての IRQ チップのエントリに関数を実行する。
	 * @param function コールバック関数。
	 * @return 結果。
	 */
	int foreach_irqchip_apic(int (*function)(uint64_t, uint64_t, uint64_t));

	/**
	 * ACPI APIC テーブルの内容を表示する。
	 */
	void dump();

private:
	/**
	 * ACPI APIC テーブルへのポインタ。
	 */
	uint8_t *m_apic_address;

};

/**
 * ACPI XSDT テーブル。
 */
class acpi_xsdt {

public:
	/**
	 * コンストラクタ。
	 * @param xsdt_address ACPI XSDT テーブルへのポインタ。
	 */
	acpi_xsdt(uint8_t *xsdt_address);

	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	acpi_xsdt() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~acpi_xsdt();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	acpi_xsdt(const acpi_xsdt &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	acpi_xsdt(const acpi_xsdt &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	acpi_xsdt &operator=(const acpi_xsdt &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	acpi_xsdt &operator=(const acpi_xsdt &&src) = delete;

	/**
	 * ACPI XSDT テーブルのシグネチャへのポインタを返す。
	 * @return ACPI XSDT テーブルのシグネチャへのポインタ。
	 */
	char *signature();

	/**
	 * ACPI XSDT テーブルの長さを返す。
	 * @return 長さ。
	 */
	uint32_t length();

	/**
	 *  ACPI テーブルの数を返す。
	 * @return ACPI テーブルの数。
	 */
	size_t acpi_table_size();

	/**
	 * インデックスを指定してその ACPI テーブルのエントリーを返す。
	 * @param index インデックス。
	 * @return ACPI テーブル。
	 */
	acpi_table acpi_table_at(size_t index);

	/**
	 * インデックスを指定してその ACPI テーブルのエントリーへのポインタを返す。
	 * @param index インデックス。
	 * @return ACPI テーブルへのポインタ。
	 */
	uint8_t *acpi_table_address_at(size_t index);

private:
	/**
	 * ACPI XSDT テーブルへのポインタ。
	 */
	uint8_t *m_xsdt_address;

};

/**
 * ACPI RSDP テーブル。
 */
class acpi_rsdp {

public:
	/**
	 * コンストラクタ。
	 * @param rsdp_address RSDP へのポインタ。
	 */
	acpi_rsdp(uint8_t *rsdp_address);

	/**
	 * コンストラクタ。引数なしのコンストラクタは禁止。
	 */
	acpi_rsdp() = delete;

	/**
	 * デストラクタ。
	 */
	virtual ~acpi_rsdp();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	acpi_rsdp(const acpi_rsdp &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	acpi_rsdp(const acpi_rsdp &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	acpi_rsdp &operator=(const acpi_rsdp &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	acpi_rsdp &operator=(const acpi_rsdp &&src) = delete;

	/**
	 * ACPI RSDP テーブルのシグネチャへのポインタを返す。
	 * @return ACPI RSDP テーブルのシグネチャへのポインタ。
	 */
	char *signature();

	/**
	 * ACPI XSDT テーブルへのポインタを返す。
	 * @return ACPI XSDT テーブルへのポインタ。
	 */
	acpi_xsdt *xsdt();

private:
	/**
	 * ACPI RSDP テーブルへのポインタ。
	 */
	uint8_t *m_rsdp_address;

};

