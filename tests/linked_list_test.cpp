/**
 * @file	linked_list_test.cpp
 * @brief	リンクリストのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "linked_list.h"

void
linked_list_test_node0(linked_list<int> &x, char const *s)
{
	test_result res;
	int a = 1;

	/* **** */
	if (x.head() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(s);
	s1 += ": ノード数 0 の先頭";
	print_test_result(s1, res);

	/* **** */
	if (x.tail() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(s);
	s2 += ": ノード数 0 の末尾";
	print_test_result(s2, res);

	/* **** */
	if (x.nodes() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s3(s);
	s3 += ": ノード数 0 のノード数";
	print_test_result(s3, res);

	/* **** */
	if (x.find(a) == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s4(s);
	s4 += ": ノード数 0 の検索結果";
	print_test_result(s4, res);
}

void
linked_list_test_node1(linked_list<int> &x, char const *s)
{
	test_result res;
	int a = 1;
	int b = 2;
	int *p = nullptr;

	/* **** */
	if (x.head() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(s);
	s1 += ": ノード数 1 の先頭";
	print_test_result(s1, res);

	/* **** */
	if (x.tail() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(s);
	s2 += ": ノード数 1 の末尾";
	print_test_result(s2, res);

	/* **** */
	if (x.head() == x.tail()) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s3(s);
	s3 += ": ノード数 1 の先頭と末尾";
	print_test_result(s3, res);

	/* **** */
	if (x.head() != nullptr && x.head()->next() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s4(s);
	s4 += ": ノード数 1 のノードの next";
	print_test_result(s4, res);

	/* **** */
	if (x.head() != nullptr && x.head()->prev() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s5(s);
	s5 += ": ノード数 1 のノードの prev";
	print_test_result(s5, res);

	/* **** */
	if (x.nodes() == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s6(s);
	s6 += ": ノード数 1 のノード数";
	print_test_result(s6, res);

	/* **** */
	p = x.find(a);
	if (p != nullptr && *p == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s7(s);
	s7 += ": ノード数 1 の検索結果(1)";
	print_test_result(s7, res);

	/* **** */
	p = x.find(b);
	if (p == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s8(s);
	s8 += ": ノード数 1 の検索結果(2)";
	print_test_result(s8, res);
}

void
linked_list_test_node2(linked_list<int> &x, char const *s)
{
	test_result res;
	int a = 1;
	int b = 2;
	int c = 4;
	int *p = nullptr;

	/* **** */
	if (x.head() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(s);
	s1 += ": ノード数 2 の先頭";
	print_test_result(s1, res);

	/* **** */
	if (x.tail() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(s);
	s2 += ": ノード数 2 の末尾";
	print_test_result(s2, res);

	/* **** */
	if (x.head() != nullptr && x.head()->next() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s3(s);
	s3 += ": ノード数 2 の先頭のノードの next";
	print_test_result(s3, res);

	/* **** */
	if (x.head() != nullptr && x.head()->prev() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s4(s);
	s4 += ": ノード数 2 の先頭のノードの prev";
	print_test_result(s4, res);

	/* **** */
	if (x.tail() != nullptr && x.tail()->next() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s5(s);
	s5 += ": ノード数 2 の末尾のノードの next";
	print_test_result(s5, res);

	/* **** */
	if (x.tail() != nullptr && x.tail()->prev() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s6(s);
	s6 += ": ノード数 2 の末尾のノードの prev";
	print_test_result(s6, res);

	/* **** */
	bidir_node<int> *bn;
	int sum = 0;
	for (bn = x.head(); bn != nullptr; bn = bn->next()) {
		sum += bn->v();
	}
	if (sum == 3) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s7(s);
	s7 += ": ノード数 2 の値の合計";
	print_test_result(s7, res);

	/* **** */
	p = x.find(a);
	if (p != nullptr && *p == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s8(s);
	s8 += ": ノード数 2 の検索結果(1)";
	print_test_result(s8, res);

	/* **** */
	p = x.find(b);
	if (p != nullptr && *p == 2) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s9(s);
	s9 += ": ノード数 2 の検索結果(2)";
	print_test_result(s9, res);

	/* **** */
	p = x.find(c);
	if (p == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s10(s);
	s10 += ": ノード数 2 の検索結果(3)";
	print_test_result(s10, res);
}

void
linked_list_test_node3(linked_list<int> &x, char const *s)
{
	test_result res;
	int a = 1;
	int b = 2;
	int c = 4;
	int d = 8;
	int *p = nullptr;

	/* **** */
	if (x.head() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(s);
	s1 += ": ノード数 3 の先頭";
	print_test_result(s1, res);

	/* **** */
	if (x.tail() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(s);
	s2 += ": ノード数 3 の末尾";
	print_test_result(s2, res);

	/* **** */
	if (x.head() != nullptr && x.head()->next() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s3(s);
	s3 += ": ノード数 3 の先頭のノードの next";
	print_test_result(s3, res);

	/* **** */
	if (x.head() != nullptr && x.head()->prev() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s4(s);
	s4 += ": ノード数 3 の先頭のノードの prev";
	print_test_result(s4, res);

	/* **** */
	if (x.tail() != nullptr && x.tail()->next() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s5(s);
	s5 += ": ノード数 3 の末尾のノードの next";
	print_test_result(s5, res);

	/* **** */
	if (x.tail() != nullptr && x.tail()->prev() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s6(s);
	s6 += ": ノード数 3 の末尾のノードの prev";
	print_test_result(s6, res);

	/* **** */
	bidir_node<int> *bn;
	int sum = 0;
	for (bn = x.head(); bn != nullptr; bn = bn->next()) {
		sum += bn->v();
	}
	if (sum == 7) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s7(s);
	s7 += ": ノード数 3 の値の合計";
	print_test_result(s7, res);

	/* **** */
	p = x.find(a);
	if (p != nullptr && *p == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s8(s);
	s8 += ": ノード数 3 の検索結果(1)";
	print_test_result(s8, res);

	/* **** */
	p = x.find(b);
	if (p != nullptr && *p == 2) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s9(s);
	s9 += ": ノード数 3 の検索結果(2)";
	print_test_result(s9, res);

	/* **** */
	p = x.find(c);
	if (p != nullptr && *p == 4) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s10(s);
	s10 += ": ノード数 3 の検索結果(3)";
	print_test_result(s10, res);

	/* **** */
	p = x.find(d);
	if (p == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s11(s);
	s11 += ": ノード数 3 の検索結果(4)";
	print_test_result(s11, res);
}

void
linked_list_test_0()
{
	linked_list<int> x;
	linked_list_test_node0(x, "初期状態");
}

void
linked_list_test_1_head()
{
	linked_list<int> x;
	int a = 1;

	x.insert_head(a);

	linked_list_test_node1(x, "insert_head");

	x.remove(a);

	linked_list_test_node0(x, "insert_head");
}

void
linked_list_test_1_tail()
{
	linked_list<int> x;
	int a = 1;

	x.insert_tail(a);

	linked_list_test_node1(x, "insert_tail");

	x.remove(a);

	linked_list_test_node0(x, "insert_tail");
}

void
linked_list_test_2_head()
{
	linked_list<int> x;
	int a = 1;
	int b = 2;

	x.insert_head(a);
	x.insert_head(b);

	linked_list_test_node2(x, "insert_head x 2");

	x.remove(b);

	linked_list_test_node1(x, "insert_head x 2");

	x.remove(a);

	linked_list_test_node0(x, "insert_head x 2");
}

void
linked_list_test_2_tail()
{
	linked_list<int> x;
	int a = 1;
	int b = 2;

	x.insert_tail(a);
	x.insert_tail(b);

	linked_list_test_node2(x, "insert_tail x 2");

	x.remove(b);

	linked_list_test_node1(x, "insert_tail x 2");

	x.remove(a);

	linked_list_test_node0(x, "insert_tail x 2");
}

void
linked_list_test_3_head()
{
	linked_list<int> x;
	int a = 1;
	int b = 2;
	int c = 4;

	x.insert_head(a);
	x.insert_head(b);
	x.insert_head(c);

	linked_list_test_node3(x, "insert_head x 3");

	x.remove(c);

	linked_list_test_node2(x, "insert_head x 3");

	x.remove(b);

	linked_list_test_node1(x, "insert_head x 3");

	x.remove(a);

	linked_list_test_node0(x, "insert_head x 3");
}

void
linked_list_test_3_tail()
{
	linked_list<int> x;
	int a = 1;
	int b = 2;
	int c = 4;

	x.insert_tail(a);
	x.insert_tail(b);
	x.insert_tail(c);

	linked_list_test_node3(x, "insert_tail x 3");

	x.remove(c);

	linked_list_test_node2(x, "insert_tail x 3");

	x.remove(b);

	linked_list_test_node1(x, "insert_tail x 3");

	x.remove(a);

	linked_list_test_node0(x, "insert_tail x 3");
}

void
linked_list_test()
{
	memory_leak_test_begin();
	linked_list_test_0();
	linked_list_test_1_head();
	linked_list_test_1_tail();
	linked_list_test_2_head();
	linked_list_test_2_tail();
	linked_list_test_3_head();
	linked_list_test_3_tail();
	memory_leak_test_end("リンクリストメモリリークチェック");
}

