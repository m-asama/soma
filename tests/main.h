/**
 * @file	main.h
 * @brief	テストのメイン。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

/**
 * テスト結果。
 */
enum class test_result {
	pass,
	fail,
};

/**
 * メモリリークテスト開始関数
 */
void memory_leak_test_begin();

/**
 * メモリリークテスト終了関数
 * @param title テスト名
 */
void memory_leak_test_end(char const *title);

/**
 * テスト結果表示関数。
 */
void print_test_result(char const *test_name, test_result test_result);

