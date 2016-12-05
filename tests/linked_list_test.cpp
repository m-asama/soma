/**
 * @file	linked_list_test.cpp
 * @brief	リンクリストのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "linked_list.h"

void
linked_list_test_0()
{
	linked_list<int> x;
	test_result res;
	int a = 1;

	if (x.head() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("空のリンクリストの先頭", res);

	if (x.tail() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("空のリンクリストの末尾", res);

	if (x.nodes() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("空のリンクリストのノード数", res);

	if (x.find(a) == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("空のリンクリストの検索結果", res);
}

void
linked_list_test_1_head()
{
	linked_list<int> x;
	test_result res;
	int a = 1;
	int b = 2;
	int *p = nullptr;

	x.insert_head(a);

	if (x.head() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) のリンクリストの先頭", res);

	if (x.tail() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) のリンクリストの末尾", res);

	if (x.head() == x.tail()) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) のリンクリストの先頭と末尾", res);

	if (x.nodes() == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) のリンクリストのノード数", res);

	p = x.find(a);
	if (p != nullptr && *p == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) のリンクリストの検索結果(1)", res);

	p = x.find(b);
	if (p == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) のリンクリストの検索結果(2)", res);

	x.remove(a);

	if (x.head() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) 削除後のリンクリストの先頭", res);

	if (x.tail() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) 削除後のリンクリストの末尾", res);

	if (x.nodes() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_head) 削除後のリンクリストのノード数", res);
}

void
linked_list_test_1_tail()
{
	linked_list<int> x;
	test_result res;
	int a = 1;

	x.insert_tail(a);

	if (x.head() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) のリンクリストの先頭", res);

	if (x.tail() != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) のリンクリストの末尾", res);

	if (x.head() == x.tail()) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) のリンクリストの先頭と末尾", res);

	if (x.nodes() == 1) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) のリンクリストのノード数", res);

	x.remove(a);

	if (x.head() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) 削除後のリンクリストの先頭", res);

	if (x.tail() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) 削除後のリンクリストの末尾", res);

	if (x.nodes() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 1(insert_tail) 削除後のリンクリストのノード数", res);
}

void
linked_list_test_2_head()
{
	linked_list<int> x;
	test_result res;
	int a = 1;
	int b = 2;

	x.insert_head(a);
	x.insert_head(b);

	x.remove(a);
	x.remove(b);

	if (x.head() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 2(insert_head) 削除後のリンクリストの先頭", res);

	if (x.tail() == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 2(insert_head) 削除後のリンクリストの末尾", res);

	if (x.nodes() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("ノード数 2(insert_head) 削除後のリンクリストのノード数", res);
}

void
linked_list_test()
{
	linked_list_test_0();
	linked_list_test_1_head();
	linked_list_test_1_tail();
/*
	bidir_node<int> *bn;
	for (bn = x.head(); bn != nullptr; bn = bn->next()) {
	}
*/
}

