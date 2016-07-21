/**
 * @file	acpi_management.cpp
 * @brief	ACPI 関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "util.h"
#include "string.h"
#include "print.h"

#include "loader_info.h"

#include "acpi.h"
#include "acpi_management.h"

static acpi_rsdp *rsdp = nullptr;
static acpi_xsdt *xsdt = nullptr;
static acpi_apic *apic = nullptr;

void
acpi_init(struct loader_info *li)
{
	char *ptr = (char *)li->rsdp_table;
	string rsd_ptr_("RSD PTR ");
	char buf[9];

	if (ptr == nullptr) {
		printstr("rsdp_table が nullptr です。\n");
		panic();
	}

	for (int i = 0; i < 8; ++i) {
		buf[i] = ptr[i];
	}
	buf[8] = '\0';

	if (rsd_ptr_ != buf) {
		printstr("rsdp_table が RSDP ではありません。\n");
		panic();
	}

	rsdp = new acpi_rsdp((uint8_t *)li->rsdp_table);
	xsdt = rsdp->xsdt();

	for (int i = 0; i < xsdt->acpi_table_size(); ++i) {
		if (xsdt->acpi_table_at(i) == acpi_table::apic) {
			apic = new acpi_apic((uint8_t *)xsdt->acpi_table_address_at(i));
		}
	}

	if (apic == nullptr) {
		printstr("APIC テーブルが見つかりませんでした。\n");
		panic();
	}
}

int
acpi_foreach_processor_apic(int (*function)(uint64_t))
{
	return apic->foreach_processor_apic(function);
}

int
acpi_foreach_irqchip_apic(int (*function)(uint64_t, uint64_t, uint64_t))
{
	return apic->foreach_irqchip_apic(function);
}

