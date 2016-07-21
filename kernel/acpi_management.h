/**
 * @file	acpi_management.h
 * @brief	ACPI 関連の関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

#include "loader_info.h"

void acpi_init(struct loader_info *li);

int acpi_foreach_processor_apic(int (*function)(uint64_t));

int acpi_foreach_irqchip_apic(int (*function)(uint64_t, uint64_t, uint64_t));

