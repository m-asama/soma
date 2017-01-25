/**
 * @file	irqchip_base.cpp
 * @brief	I/O PIC の基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"

#include "irqchip_base.h"

irqchip_base::irqchip_base()
{
}

irqchip_base::~irqchip_base()
{
}

bool
irqchip_base::operator==(const irqchip_base &rhs)
{
	return (this->id() == rhs.id());
}

bool
irqchip_base::operator>(const irqchip_base &rhs)
{
	return (this->id() > rhs.id());
}

void
irqchip_base::id(uint64_t id)
{
	m_id = id;
}

uint64_t
irqchip_base::id() const
{
	return m_id;
}

void
irqchip_base::apic_address(uint64_t apic_address)
{
	m_apic_address = apic_address;
}

uint64_t
irqchip_base::apic_address() const
{
	return m_apic_address;
}

void
irqchip_base::gsi_base(uint64_t gsi_base)
{
	m_gsi_base = gsi_base;
}

uint64_t
irqchip_base::gsi_base() const
{
	return m_gsi_base;
}

void
irqchip_base::dump()
{
	utf8str s;
	s += "irqchip";
	s.append_uint64(m_id, 0);
	s += ": MMIO BASE = 0x";
	s.append_hex64(m_apic_address, 16);
	s += " GSI BASE = 0x";
	s.append_hex64(m_gsi_base, 16);
	s += "\n";
	print(s);
}

