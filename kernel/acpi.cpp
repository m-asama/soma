/**
 * @file	acpi.cpp
 * @brief	ACPI 関連のクラス定義。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "util.h"
#include "string.h"
#include "print.h"

#include "loader_info.h"

#include "acpi_management.h"

#include "acpi.h"

struct acpi_table_signature acpi_table_signatures[] = {
	{
		.signature = "APIC",
		.table = acpi_table::apic,
	},
};
const size_t acpi_table_signatures_size = sizeof(acpi_table_signatures) / sizeof(struct acpi_table_signature);

acpi_apic::acpi_apic(uint8_t *apic_address)
{
	m_apic_address = apic_address;
}

acpi_apic::~acpi_apic()
{
}

char *
acpi_apic::signature()
{
	return (char *)m_apic_address;
}

uint32_t
acpi_apic::length()
{
	uint32_t *lengthp = (uint32_t *)&m_apic_address[4];
	return *lengthp;
}

int
acpi_apic::foreach_processor_apic(int (*function)(uint64_t))
{
	uint8_t *ptr = m_apic_address;
	uint32_t *u32p, length;
	uint8_t *tail;
	int ret;
	u32p = (uint32_t *)&m_apic_address[4];
	length = *u32p;
	tail = ptr + length;
	ptr += 44;
	while (ptr < tail) {
		length = ptr[1];
		if (ptr[0] == 0) {
			ret = function(ptr[3]);
			if (ret != 0) {
				return ret;
			}
		}
		ptr += length;
	}
	return 0;
}

int
acpi_apic::foreach_irqchip_apic(int (*function)(uint64_t, uint64_t, uint64_t))
{
	uint8_t *ptr = m_apic_address;
	uint32_t *u32p, length, apic_address, gsi_base;
	uint8_t *tail;
	int ret;
	u32p = (uint32_t *)&m_apic_address[4];
	length = *u32p;
	tail = ptr + length;
	ptr += 44;
	while (ptr < tail) {
		length = ptr[1];
		if (ptr[0] == 1) {
			u32p = (uint32_t *)&ptr[4];
			apic_address = *u32p;
			u32p = (uint32_t *)&ptr[8];
			gsi_base = *u32p;
			ret = function(ptr[2], apic_address, gsi_base);
			if (ret != 0) {
				return ret;
			}
		}
		ptr += length;
	}
	return 0;
}

void
acpi_apic::dump()
{
	uint8_t *ptr = m_apic_address;
	uint32_t *u32p, length;
	uint8_t *tail;
	uint64_t *u64p = nullptr;
	u32p = (uint32_t *)&m_apic_address[4];
	length = *u32p;
	tail = ptr + length;
	u32p = (uint32_t *)&m_apic_address[36];
	printstr("Local Interrupt Controller Address = "); printhex64((uint64_t)*u32p); printstr("\n");
	u32p = (uint32_t *)&m_apic_address[40];
	printstr("Flags = "); printhex64((uint64_t)*u32p); printstr("\n");
	ptr += 44;
	while (ptr < tail) {
		printstr("  Type = "); printhex8(ptr[0]);
		length = ptr[1];
		//printstr("  Length = "); printhex8(ptr[1]); printstr("\n");
		if (ptr[0] == 0) {
			printstr(" ACPI ProcUID  = "); printhex8(ptr[2]);
			printstr(" APIC ID       = "); printhex8(ptr[3]);
			u32p = (uint32_t *)&ptr[4];
			printstr(" Flags         = "); printhex64(*u32p);
		}
		if (ptr[0] == 1) {
			printstr(" I/O APIC ID   = "); printhex8(ptr[2]);
			u32p = (uint32_t *)&ptr[4];
			printstr(" I/O APIC Addr = "); printhex64(*u32p);
			u64p = (uint64_t *)u32p;
			u32p = (uint32_t *)&ptr[8];
			printstr(" GSInterr Base = "); printhex64(*u32p);
		}
		if (ptr[0] == 2) {
			u32p = (uint32_t *)&ptr[4];
			printstr(" Bus = "); printhex8(ptr[2]);
			printstr(" Src = "); printhex8(ptr[3]);
			printstr(" GSI = "); printhex64(*u32p);
			printstr(" F1 = "); printhex8(ptr[8]);
			printstr(" F2 = "); printhex8(ptr[9]);
		}
		printstr("\n");
		ptr += length;
	}
}

acpi_xsdt::acpi_xsdt(uint8_t *xsdt_address)
{
	m_xsdt_address = xsdt_address;
}

acpi_xsdt::~acpi_xsdt()
{
}

char *
acpi_xsdt::signature()
{
	return (char *)m_xsdt_address;
}

uint32_t
acpi_xsdt::length()
{
	uint32_t *lengthp = (uint32_t *)&m_xsdt_address[4];
	return *lengthp;
}

size_t
acpi_xsdt::acpi_table_size()
{
	size_t size = (length() - 36) / 8;
	return size;
}

acpi_table
acpi_xsdt::acpi_table_at(size_t index)
{
	char *ptr = (char *)acpi_table_address_at(index);

	if (ptr == nullptr) {
		return acpi_table::null;
	}

	for (int i = 0; i < acpi_table_signatures_size; ++i) {
		if ((acpi_table_signatures[i].signature[0] == ptr[0])
		 && (acpi_table_signatures[i].signature[1] == ptr[1])
		 && (acpi_table_signatures[i].signature[2] == ptr[2])
		 && (acpi_table_signatures[i].signature[3] == ptr[3])) {
			return acpi_table_signatures[i].table;
		}
	}

	return acpi_table::null;
}

uint8_t *
acpi_xsdt::acpi_table_address_at(size_t index)
{
	uint8_t *ptr = m_xsdt_address;
	uint64_t *u64ptr;

	if (index >= acpi_table_size()) {
		return nullptr;
	}

	ptr += 36 + (8 * index);
	u64ptr = (uint64_t *)ptr;

	return (uint8_t *)*u64ptr;
}

acpi_rsdp::acpi_rsdp(uint8_t *rsdp_address)
{
	m_rsdp_address = rsdp_address;
}

acpi_rsdp::~acpi_rsdp()
{
}

char *
acpi_rsdp::signature()
{
	return (char *)m_rsdp_address;
}

acpi_xsdt *
acpi_rsdp::xsdt()
{
	char *ptr = (char *)m_rsdp_address;
	string xsdt("XSDT");
	char buf[5];
	uint64_t *addrp;

	if (ptr == nullptr) {
		printstr("rsdp_address is nullptr.\n");
		panic();
	}

	ptr += 24;
	addrp = (uint64_t *)ptr;
	ptr = (char *)*addrp;

	for (int i = 0; i < 4; ++i) {
		buf[i] = ptr[i];
	}
	buf[4] = '\0';

	if (xsdt != buf) {
		printstr("Cannot find XSDT.\n");
		panic();
	}

	return new acpi_xsdt((uint8_t *)ptr);
}

