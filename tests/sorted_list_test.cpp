/**
 * @file	sorted_list_test.h
 * @brief	整列リストのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "sorted_list.h"

void
sorted_list_test_common(sorted_list<int> &x, utf8str s, int count, int sum)
{
	test_result res;
	bidir_node<int> *bn;
	int countt;
	int sumt;

	countt = 0;
	sumt = 0;
	for (bn = x.head(); bn != nullptr; bn = bn->next()) {
		++countt;
		sumt += bn->v();
	}

	if (countt == count) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(s);
	s1 += ": 正順 count";
	print_test_result(s1, res);

	if (sumt == sum) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(s);
	s2 += ": 正順 sum";
	print_test_result(s2, res);

	countt = 0;
	sumt = 0;
	for (bn = x.tail(); bn != nullptr; bn = bn->prev()) {
		++countt;
		sumt += bn->v();
	}

	if (countt == count) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s3(s);
	s3 += ": 逆順 count";
	print_test_result(s3, res);

	if (sumt == sum) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s4(s);
	s4 += ": 逆順 sum";
	print_test_result(s4, res);

	int t = 0;
	res = test_result::pass;
	for (bn = x.head(); bn != nullptr; bn = bn->next()) {
		if (t > bn->v()) {
			res = test_result::fail;
		}
		t = bn->v();
	}
	utf8str s5(s);
	s5 += ": 順序";
	print_test_result(s5, res);
}

void
sorted_list_test()
{
	int test_data[6][3] = {
		{ 1, 2, 4 },
		{ 1, 4, 2 },
		{ 2, 1, 4 },
		{ 2, 4, 1 },
		{ 4, 1, 2 },
		{ 4, 2, 1 },
	};
	memory_leak_test_begin();
	for (int i = 0; i < 6; ++i) {
		for (int r = 0; r < 6; ++r) {
			sorted_list<int> x;
			int sum = 0;
			utf8str s;
			s += "i[";
			s.append_sint64(test_data[i][0], 1);
			s += ",";
			s.append_sint64(test_data[i][1], 1);
			s += ",";
			s.append_sint64(test_data[i][2], 1);
			s += "] r[";
			s.append_sint64(test_data[r][0], 1);
			s += ",";
			s.append_sint64(test_data[r][1], 1);
			s += ",";
			s.append_sint64(test_data[r][2], 1);
			s += "] ";

			utf8str s0(s);
			s0 += "(0)";
			sorted_list_test_common(x, s0, 0, sum);

			utf8str s1(s);
			s1 += "(1)";
			x.insert(test_data[i][0]);
			sum += test_data[i][0];
			sorted_list_test_common(x, s1, 1, sum);

			utf8str s2(s);
			s2 += "(2)";
			x.insert(test_data[i][1]);
			sum += test_data[i][1];
			sorted_list_test_common(x, s2, 2, sum);

			utf8str s3(s);
			s3 += "(3)";
			x.insert(test_data[i][2]);
			sum += test_data[i][2];
			sorted_list_test_common(x, s3, 3, sum);

			utf8str s4(s);
			s4 += "(4)";
			x.remove(test_data[r][0]);
			sum -= test_data[r][0];
			sorted_list_test_common(x, s4, 2, sum);

			utf8str s5(s);
			s5 += "(5)";
			x.remove(test_data[r][1]);
			sum -= test_data[r][1];
			sorted_list_test_common(x, s5, 1, sum);

			utf8str s6(s);
			s6 += "(6)";
			x.remove(test_data[r][2]);
			sum -= test_data[r][2];
			sorted_list_test_common(x, s6, 0, sum);
		}
	}
	memory_leak_test_end("整列リストメモリリークチェック");
}

