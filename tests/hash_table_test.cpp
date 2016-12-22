/**
 * @file	hash_table_test.cpp
 * @brief	ハッシュテーブルのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "hash_table.h"

uint64_t
int_hash(const int &i)
{
	uint64_t hash;
	hash = i;
	return hash;
}

bool
int_equal(const int &il, const int &ir)
{
	return (il == ir);
}

void
hash_table_test_common(hash_table<int> &x, char const *s, int count, int sum)
{
	test_result res;
	bidir_node<int> *bn;
	bidir_node<int> *last;
	int countt;
	int sumt;

	countt = 0;
	sumt = 0;
	if (x.table() != nullptr) {
		for (int i = 0; i < x.table_size(); ++i) {
			for (bn = x.table()[i]; bn != nullptr; bn = bn->next()) {
				++countt;
				sumt += bn->v();
			}
		}
	}

	if (countt == count) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s1(s);
	s1 += ": 正順 count";
	print_test_result(s1.ptr(), res);

	if (sumt == sum) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s2(s);
	s2 += ": 正順 sum";
	print_test_result(s2.ptr(), res);

	countt = 0;
	sumt = 0;
	if (x.table() != nullptr) {
		for (int i = 0; i < x.table_size(); ++i) {
			last = nullptr;
			for (bn = x.table()[i]; bn != nullptr; bn = bn->next()) {
				last = bn;
			}
			for (bn = last; bn != nullptr; bn = bn->prev()) {
				++countt;
				sumt += bn->v();
			}
		}
	}

	if (countt == count) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s3(s);
	s3 += ": 逆順 count";
	print_test_result(s3.ptr(), res);

	if (sumt == sum) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s4(s);
	s4 += ": 逆順 sum";
	print_test_result(s4.ptr(), res);

	if (x.nodes() == count) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	utf8str s5(s);
	s5 += ":nodes()";
	print_test_result(s5.ptr(), res);
}

void
hash_table_test()
{
	hash_table<int> *x;
	int test_data[1024];
	int count;
	int sum;

	for (int i = 0; i < 1024; ++i) {
		test_data[i] = i;
	}

	memory_leak_test_begin();

	x = new hash_table<int>(int_hash, int_equal);

	count = 0;
	sum = 0;

	hash_table_test_common(*x, "初期状態", count, sum);

	x->insert(test_data[0]);
	++count;
	sum += test_data[0];
	hash_table_test_common(*x, "insert 1", count, sum);

	x->insert(test_data[1]);
	++count;
	sum += test_data[1];
	hash_table_test_common(*x, "insert 2", count, sum);

	for (int i = 2; i < 1024; ++i) {
		x->insert(test_data[i]);
		++count;
		sum += test_data[i];
	}
	hash_table_test_common(*x, "insert 1023", count, sum);

	for (int i = 2; i < 1024; ++i) {
		x->remove(test_data[i]);
		--count;
		sum -= test_data[i];
	}
	hash_table_test_common(*x, "remove", count, sum);

	x->remove(test_data[0]);
	x->remove(test_data[1]);
	hash_table_test_common(*x, "全削除", 0, 0);

	delete x;

	x = new hash_table<int>(int_hash, int_equal);

	count = 0;
	sum = 0;

	for (int i = 0; i < 1024; i += 256) {
		x->insert(test_data[i]);
		++count;
		sum += test_data[i];
	}
	hash_table_test_common(*x, "衝突(1)", count, sum);

	x->remove(test_data[256]);
	--count;
	sum -= test_data[256];
	hash_table_test_common(*x, "衝突(2)", count, sum);

	x->remove(test_data[768]);
	--count;
	sum -= test_data[768];
	hash_table_test_common(*x, "衝突(3)", count, sum);

	x->remove(test_data[0]);
	--count;
	sum -= test_data[0];
	hash_table_test_common(*x, "衝突(4)", count, sum);

	x->remove(test_data[512]);
	--count;
	sum -= test_data[512];
	hash_table_test_common(*x, "衝突(5)", count, sum);

	delete x;

	memory_leak_test_end("ハッシュテーブルメモリリークチェック");
}

