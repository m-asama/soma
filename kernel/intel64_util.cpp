/**
 * @file	intel64_util.cpp
 * @brief	Intel64 依存のユーティリティ関数群。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "intel64_assembly.h"

#include "util.h"

static uint16_t
getit()
{
	uint16_t hi, lo;
	outb(0x43, 0x00);
	lo = inb(0x40);
	hi = inb(0x40);
	return ((hi << 8) | (lo & 0xff));
}

void
sleep(uint64_t n)
{
	uint16_t delta, prev_tick, tick;
	int ticks_left;

	if (n <= 0) {
		ticks_left = 0;
	} else if (n < 256) {
		ticks_left = (n * 39099 + (1 << 15) - 1) >> 15;
	} else {
		ticks_left = (n * 1193182 + 999999) / 1000000;
	}

	prev_tick = getit();
	while (ticks_left > 0) {
		tick = getit();
		delta = prev_tick - tick;
		prev_tick = tick;
		ticks_left -= delta;
	}
}

uint64_t
xchg(volatile uint64_t *addr, uint64_t newval)
{
	uint64_t result;
	asm volatile("lock; xchgq %0, %1" : "+m" (*addr), "=a" (result) : "1" (newval) : "cc");
	return result;
}

