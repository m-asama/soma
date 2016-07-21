/**
 * @file	util.cpp
 * @brief	アーキテクチャ非依存のユーティリティ関数群。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "util.h"

int
count_population_32(uint32_t bits)
{
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
	return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int
count_population_64(uint64_t bits)
{
	bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
	bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
	bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
	bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
	bits = (bits & 0x0000ffff0000ffff) + (bits >>16 & 0x0000ffff0000ffff);
	return (bits & 0x00000000ffffffff) + (bits >>32 & 0x00000000ffffffff);
}

int
count_leading_zero_32(uint32_t bits)
{
	bits = bits | (bits >> 1);
	bits = bits | (bits >> 2);
	bits = bits | (bits >> 4);
	bits = bits | (bits >> 8);
	bits = bits | (bits >> 16);
	return count_population_32(~bits);
}

int
count_leading_zero_64(uint64_t bits)
{
	bits = bits | (bits >> 1);
	bits = bits | (bits >> 2);
	bits = bits | (bits >> 4);
	bits = bits | (bits >> 8);
	bits = bits | (bits >> 16);
	bits = bits | (bits >> 32);
	return count_population_64(~bits);
}

int
count_training_zero_32(uint32_t bits)
{
	return count_population_32((~bits) & (bits - 1));
}

int
count_training_zero_64(uint64_t bits)
{
	return count_population_64((~bits) & (bits - 1));
}

int
round_up_32(uint32_t &target, uint32_t align)
{
	uint32_t tmp;
	if (count_population_32(align) != 1) {
		return -1;
	}
	tmp = target & ~(align - 1);
	if ((target & (align - 1)) != 0) {
		target = tmp + align;
	} else {
		target = tmp;
	}
	return 0;
}

int
round_down_32(uint32_t &target, uint32_t align)
{
	if (count_population_32(align) != 1) {
		return -1;
	}
	target = target & ~(align - 1);
	return 0;
}

int
round_up_64(uint64_t &target, uint64_t align)
{
	uint64_t tmp;
	if (count_population_64(align) != 1) {
		return -1;
	}
	tmp = target & ~(align - 1);
	if ((target & (align - 1)) != 0) {
		target = tmp + align;
	} else {
		target = tmp;
	}
	return 0;
}

int
round_down_64(uint64_t &target, uint64_t align)
{
	if (count_population_64(align) != 1) {
		return -1;
	}
	target = target & ~(align - 1);
	return 0;
}

void
panic()
{
	while (1) {}
}

