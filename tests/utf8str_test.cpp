/**
 * @file	utf8str_test.h
 * @brief	文字列のテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "utf8str.h"

void
utf8str_test_one(utf8str &s, char const *teststr, utf8str title)
{
	test_result res;
	int size = 0;
	if (teststr != nullptr) {
		for (int i = 0; teststr[i] != '\0'; ++i) {
			++size;
		}
		++size;
	}

	/* **** */
	if ((teststr != nullptr && s.m_buffer != nullptr)
	    || (teststr == nullptr && s.m_buffer == nullptr)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(title);
	s1 += "の m_buffer";
	print_test_result(s1, res);

	/* **** */
	if (s.m_buffer_size >= size) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(title);
	s2 += "の m_buffer_size";
	print_test_result(s2, res);

	if (s.m_buffer == nullptr || teststr == nullptr) {
		return;
	}

	/* **** */
	int i;
	res = test_result::pass;
	for (i = 0; teststr[i] != '\0'; ++i) {
		if (s.byte_at(i) != teststr[i]) {
			res = test_result::fail;
		}
	}
//	if (s.byte_at(i) != teststr[i]) {
//		res = test_result::fail;
//	}
	utf8str s3(title);
	s3 += "の値比較";
	print_test_result(s3, res);
}

void
utf8str_test_str(char const *teststr, char const *title)
{
	{
		utf8str titlestr(title);
		titlestr += ": C 文字列で初期化した文字列";
		utf8str s(teststr);
		utf8str_test_one(s, teststr, titlestr);
	}
	{
		utf8str titlestr(title);
		titlestr += ": utf8str で初期化した文字列";
		utf8str ss(teststr);
		utf8str s(ss);
		utf8str_test_one(s, teststr, titlestr);
	}
	{
		utf8str titlestr(title);
		titlestr += ": C 文字列を代入した文字列";
		utf8str s;
		s = teststr;
		utf8str_test_one(s, teststr, titlestr);
	}
	{
		utf8str titlestr(title);
		titlestr += ": utf8str を代入した文字列";
		utf8str ss(teststr);
		utf8str s;
		s = ss;
		utf8str_test_one(s, teststr, titlestr);
	}
	/*
	{
		utf8str titlestr(title);
		titlestr += ": C 文字列を += した文字列";
		utf8str s("teststr");
		s += teststr;
		utf8str_test_one(s, teststr, titlestr);
	}
	{
		utf8str titlestr(title);
		titlestr += ": utf8str を += した文字列";
		utf8str ss(teststr);
		utf8str s("teststr");
		s += ss;
		utf8str_test_one(s, teststr, titlestr);
	}
	*/
}

void
utf8str_test()
{
	char const *teststr1 = "文字列";
	char const *teststr2 = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

	memory_leak_test_begin();
	{
		utf8str titlestr("デフォルトコンストラクタで初期化した文字列");
		utf8str s;
		utf8str_test_one(s, nullptr, titlestr);
	}
	{
		utf8str titlestr("nullptr で初期化した文字列");
		utf8str s(nullptr);
		utf8str_test_one(s, nullptr, titlestr);
	}
	{
		utf8str titlestr("デフォルト utf8str で初期化した文字列");
		utf8str ss;
		utf8str s(ss);
		utf8str_test_one(s, nullptr, titlestr);
	}
	utf8str_test_str(teststr1, "teststr1");
	utf8str_test_str(teststr2, "teststr2");
	{
		test_result res;
		utf8str s1("abcde");
		utf8str s2("abc");
		s1.truncate(2);
		if (s1 == s2) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("abcde:abcd", res);
	}
	{
		test_result res;
		utf8str s1("abcde");
		utf8str s2("");
		s1.truncate(5);
		if (s1 == s2) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("abcde:abcd", res);
	}
	{
		test_result res;
		utf8str s1("abcde");
		utf8str s2("");
		s1.truncate(8);
		if (s1 == s2) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("abcde:abcd", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		utf8str s2("アイウエ");
		s1.truncate(1);
		if (s1 == s2) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("アイウエオ:アイウエ", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		utf8str s2("アイウ");
		s1.truncate(2);
		if (s1 == s2) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("abcde:abcd", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		utf8str s2("");
		s1.truncate(8);
		if (s1 == s2) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("abcde:abcd", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		if (s1.unicode_length() == 5) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("unicode_length(1)", res);
	}
	{
		test_result res;
		utf8str s1("abcde");
		if (s1.unicode_length() == 5) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("unicode_length(1)", res);
	}
	{
		test_result res;
		utf8str s1("aイcエe");
		if (s1.unicode_length() == 5) {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("unicode_length(1)", res);
	}
	{
		test_result res;
		utf8str s1("aイcエe");
		if (s1[0] == 'a') {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("[](1)", res);
	}
	{
		test_result res;
		utf8str s1("aイcエe");
		if (s1[5] == 'a') {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("[](1)", res);
	}
	{
		test_result res;
		utf8str s1("aイcエe");
		if (s1[-1] == 'e') {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("[](1)", res);
	}
	{
		test_result res;
		utf8str s1("aイcエe");
		if (s1[2] == 'c') {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("[](1)", res);
	}
	{
		test_result res;
		utf8str s1("abcde");
		if (s1.byte_substring(1, 4) == "bcd") {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("byte_substring(1)", res);
	}
	{
		test_result res;
		utf8str s1("abcde");
		if (s1.byte_substring(2, 0) == "cde") {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("byte_substring(1)", res);
	}
	{
		test_result res;
		utf8str s1("abcde");
		if (s1.byte_substring(1, -1) == "bcd") {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("byte_substring(1)", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		if (s1.unicode_substring(1, 4) == "イウエ") {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("unicode_substring(1)", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		if (s1.unicode_substring(2, 0) == "ウエオ") {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("unicode_substring(1)", res);
	}
	{
		test_result res;
		utf8str s1("アイウエオ");
		if (s1.unicode_substring(1, -1) == "イウエ") {
			res = test_result::pass;
		} else {
			res = test_result::fail;
		}
		print_test_result("unicode_substring(1)", res);
	}
	memory_leak_test_end("文字列メモリリークチェック");
}

