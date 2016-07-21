/**
 * @file	irqchip_management.h
 * @brief	I/O PIC の初期化等を行う関数群宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "irqchip_base.h"

/**
 *
 */
void irqchip_init();

/**
 *
 */
irqchip_base *irqchip_alloc();

/**
 *
 */
void irqchip_free(irqchip_base *ptr);

/**
 *
 */
void irqchip_dump();

