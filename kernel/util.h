/**
 * @file	util.h
 * @brief	ユーティリティ関数群。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

/*
 * ビット演算関連
 */

/* 1-bit の数を数える */
int count_population_32(uint32_t bits);
int count_population_64(uint64_t bits);

/* 左側から 0-bit が連続する数を数える */
int count_leading_zero_32(uint32_t bits);
int count_leading_zero_64(uint64_t bits);

/* 右側から 0-bit が連続する数を数える */
int count_training_zero_32(uint32_t bits);
int count_training_zero_64(uint64_t bits);

/* 指定した align で target を切り上げたり切り下げたりする */
int round_up_32(uint32_t &target, uint32_t align);
int round_down_32(uint32_t &target, uint32_t align);
int round_up_64(uint64_t &target, uint64_t align);
int round_down_64(uint64_t &target, uint64_t align);

void panic();

void sleep(uint64_t n);

uint64_t xchg(volatile uint64_t *addr, uint64_t newval);

