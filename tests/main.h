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
 * テスト結果表示関数。
 */
void print_test_result(char const *test_name, test_result test_result);

