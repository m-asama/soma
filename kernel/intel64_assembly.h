/**
 * @file	intel64_assembly.h
 * @brief	インラインアセンブリで書かれた関数宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/**
 * inb を実行。
 * @param port I/O ポート番号。
 * @return inb を実行した結果。
 */
uint8_t inb(uint16_t port);

/**
 * outb を実行。
 * @param port I/O ポート番号。
 * @param val outb への引数。
 */
void outb(uint16_t port, uint8_t val);

/**
 * inw を実行。
 * @param port I/O ポート番号。
 * @return inw を実行した結果。
 */
uint16_t inw(uint16_t port);

/**
 * outw を実行。
 * @param port I/O ポート番号。
 * @param val outw への引数。
 */
void outw(uint16_t port, uint16_t val);

/**
 * inl を実行。
 * @param port I/O ポート番号。
 * @return inl を実行した結果。
 */
uint32_t inl(uint16_t port);

/**
 * outl を実行。
 * @param port I/O ポート番号。
 * @param val outl への引数。
 */
void outl(uint16_t port, uint32_t val);

/**
 * sti を実行し割り込みを有効化。
 */
void sti();

/**
 * cli を実行し割り込みを無効化。
 */
void cli();

/**
 * hlt を実行。
 */
void hlt();

/**
 * int $0x20 を実行。
 */
void int_0x20();

/**
 * RFLAGS を取得する関数。
 * @return RFLAGS の値。
 */
uint64_t rflags();

void cpuid(uint32_t &eax, uint32_t &ebx, uint32_t &ecx, uint32_t &edx);

void rdmsr(uint32_t msr, uint32_t *lo, uint32_t *hi);
void wrmsr(uint32_t msr, uint32_t lo, uint32_t hi);

inline void
cr3(uint64_t cr3)
{
	asm volatile ("movq %0, %%cr3" : : "r"(cr3) :);
}

inline uint64_t
cr3()
{
	uint64_t ret;
	asm volatile ("movq %%cr3, %0" : "=r"(ret) : :);
	return ret;
}

inline void
rsp(uint64_t rsp)
{
	asm volatile ("movq %0, %%rsp" : : "r"(rsp) :);
}

inline uint64_t
rsp()
{
	uint64_t ret;
	asm volatile ("movq %%rsp, %0" : "=r"(ret) : :);
	return ret;
}

uint16_t segment_register_cs();
uint16_t segment_register_ds();
uint16_t segment_register_ss();
uint16_t segment_register_es();
uint16_t segment_register_fs();
uint16_t segment_register_gs();

void lgdt(void *ptr);

void lgdt(void *ptr, uint16_t code_segment_selector, uint16_t data_segment_selector);
void sgdt(void *ptr);

void lidt(void *ptr);
void sidt(void *ptr);

