/**
 * @file	irqchip_base.h
 * @brief	I/O PIC の基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 *
 */
class irqchip_base {

public:
	/**
	 *
	 */
	irqchip_base();

	/**
	 *
	 */
	virtual ~irqchip_base();

	/**
	 *
	 */
	irqchip_base(const irqchip_base &src) = delete;

	/**
	 *
	 */
	irqchip_base(const irqchip_base &&src) = delete;

	/**
	 *
	 */
	irqchip_base &operator=(const irqchip_base &src) = delete;

	/**
	 *
	 */
	irqchip_base &operator=(const irqchip_base &&src) = delete;

	/**
	 *
	 */
	bool operator==(const irqchip_base &rhs);

	/**
	 *
	 */
	bool operator>(const irqchip_base &rhs);

	/**
	 *
	 */
	void id(uint64_t id);

	/**
	 *
	 */
	uint64_t id() const;

	/**
	 *
	 */
	void apic_address(uint64_t apic_address);

	/**
	 *
	 */
	uint64_t apic_address() const;

	/**
	 *
	 */
	void gsi_base(uint64_t gsi_base);

	/**
	 *
	 */
	uint64_t gsi_base() const;

	/**
	 *
	 */
	virtual void dump();

protected:
	/**
	 *
	 */
	uint64_t m_id;

	/**
	 *
	 */
	uint64_t m_apic_address;

	/**
	 *
	 */
	uint64_t m_gsi_base;

};

