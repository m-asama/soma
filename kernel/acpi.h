/**
 * @file	acpi.h
 * @brief	ACPI 関連のクラス定義。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "acpi_management.h"

enum class acpi_table {
	null,
	apic,
};

struct acpi_table_signature {
	const char *signature;
	acpi_table table;
};

class acpi_apic {

public:
	/**
	 *
	 */
	acpi_apic(uint8_t *apic_address);

	/**
	 *
	 */
	virtual ~acpi_apic();

	/**
	 *
	 */
	acpi_apic() = delete;

	/**
	 *
	 */
	acpi_apic(const acpi_apic &src) = delete;

	/**
	 *
	 */
	acpi_apic(const acpi_apic &&src) = delete;

	/**
	 *
	 */
	acpi_apic &operator=(const acpi_apic &src) = delete;

	/**
	 *
	 */
	acpi_apic &operator=(const acpi_apic &&src) = delete;

	/**
	 *
	 */
	char *signature();

	/**
	 *
	 */
	uint32_t length();

	/**
	 *
	 */
	int foreach_processor_apic(int (*function)(uint64_t));

	/**
	 *
	 */
	int foreach_irqchip_apic(int (*function)(uint64_t, uint64_t, uint64_t));

	/**
	 *
	 */
	void dump();

private:
	/**
	 *
	 */
	uint8_t *m_apic_address;

};

class acpi_xsdt {

public:
	/**
	 *
	 */
	acpi_xsdt(uint8_t *xsdt_address);

	/**
	 *
	 */
	virtual ~acpi_xsdt();

	/**
	 *
	 */
	acpi_xsdt() = delete;

	/**
	 *
	 */
	acpi_xsdt(const acpi_xsdt &src) = delete;

	/**
	 *
	 */
	acpi_xsdt(const acpi_xsdt &&src) = delete;

	/**
	 *
	 */
	acpi_xsdt &operator=(const acpi_xsdt &src) = delete;

	/**
	 *
	 */
	acpi_xsdt &operator=(const acpi_xsdt &&src) = delete;

	/**
	 *
	 */
	char *signature();

	/**
	 *
	 */
	uint32_t length();

	/**
	 *
	 */
	size_t acpi_table_size();

	/**
	 *
	 */
	acpi_table acpi_table_at(size_t index);

	/**
	 *
	 */
	uint8_t *acpi_table_address_at(size_t index);

private:
	/**
	 *
	 */
	uint8_t *m_xsdt_address;

};

class acpi_rsdp {

public:
	/**
	 *
	 */
	acpi_rsdp(uint8_t *rsdp_address);

	/**
	 *
	 */
	virtual ~acpi_rsdp();

	/**
	 *
	 */
	acpi_rsdp() = delete;

	/**
	 *
	 */
	acpi_rsdp(const acpi_rsdp &src) = delete;

	/**
	 *
	 */
	acpi_rsdp(const acpi_rsdp &&src) = delete;

	/**
	 *
	 */
	acpi_rsdp &operator=(const acpi_rsdp &src) = delete;

	/**
	 *
	 */
	acpi_rsdp &operator=(const acpi_rsdp &&src) = delete;

	/**
	 *
	 */
	char *signature();

	/**
	 *
	 */
	acpi_xsdt *xsdt();

private:
	/**
	 *
	 */
	uint8_t *m_rsdp_address;

};

