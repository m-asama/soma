/**
 * @file	memory_pool_test.cpp
 * @brief	メモリプールのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"

#include "type.h"
#include "memory_management.h"

#include "memory_pool.h"

void
memory_pool_test()
{
	uint64_t ma[9];
	uint64_t mf[9];
	memory_pool<int> *mp;
	int *ip1[64 * 8];
	int *ip2[64 * 8];
	int *ip3[64 * 8];
	test_result res;

	memory_leak_test_begin();

	for (int i = 0; i < 9; ++i) {
		ma[i] = 0ul;
		mf[i] = 0ul;
	}

	ma[0] = memory_alloc_size();
	mf[0] = memory_free_size();

	/*
	 * 初期状態
	 */

	mp = new memory_pool<int>();

	ma[1] = memory_alloc_size();
	mf[1] = memory_free_size();

	if (mp->count() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("初期状態の count", res);

	if ((mp->m_free_bits[0] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[1] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[2] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[3] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[4] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[5] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[6] == 0xfffffffffffffffful)
	 && (mp->m_free_bits[7] == 0xfffffffffffffffful)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("初期状態の m_free_bits", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("初期状態の m_table", res);

	if (mp->m_next == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("初期状態の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("初期状態の m_prev", res);

	/*
	 * 最初の m_table が全て埋まった状態
	 */

	for (int i = 0; i < 64 * 8; ++i) {
		ip1[i] = mp->alloc();
	}

	ma[2] = memory_alloc_size();
	mf[2] = memory_free_size();

	if (mp->count() == 64 * 8) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の count", res);

	if ((mp->m_free_bits[0] == 0x0000000000000000ul)
	 && (mp->m_free_bits[1] == 0x0000000000000000ul)
	 && (mp->m_free_bits[2] == 0x0000000000000000ul)
	 && (mp->m_free_bits[3] == 0x0000000000000000ul)
	 && (mp->m_free_bits[4] == 0x0000000000000000ul)
	 && (mp->m_free_bits[5] == 0x0000000000000000ul)
	 && (mp->m_free_bits[6] == 0x0000000000000000ul)
	 && (mp->m_free_bits[7] == 0x0000000000000000ul)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の m_free_bits", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の m_table", res);

	if (mp->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の m_prev", res);

	/*
	 * 二つの m_table が全て埋まった状態
	 */

	for (int i = 0; i < 64 * 8; ++i) {
		ip2[i] = mp->alloc();
	}

	ma[3] = memory_alloc_size();
	mf[3] = memory_free_size();

	if (mp->count() == 64 * 8 * 2) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の count", res);

	if ((mp->m_free_bits[0] == 0x0000000000000000ul)
	 && (mp->m_free_bits[1] == 0x0000000000000000ul)
	 && (mp->m_free_bits[2] == 0x0000000000000000ul)
	 && (mp->m_free_bits[3] == 0x0000000000000000ul)
	 && (mp->m_free_bits[4] == 0x0000000000000000ul)
	 && (mp->m_free_bits[5] == 0x0000000000000000ul)
	 && (mp->m_free_bits[6] == 0x0000000000000000ul)
	 && (mp->m_free_bits[7] == 0x0000000000000000ul)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_free_bits", res);

	if (mp->m_next != nullptr
	 && (mp->m_next->m_free_bits[0] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[1] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[2] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[3] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[4] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[5] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[6] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[7] == 0x0000000000000000ul)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_free_bits", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_table", res);

	if (mp->m_next != nullptr && mp->m_next->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_table", res);

	if (mp->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_next", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_prev", res);

	if (mp->m_next != nullptr && mp->m_next->m_prev == mp) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_prev", res);

	/*
	 * 三つの m_table が全て埋まった状態
	 */

	for (int i = 0; i < 64 * 8; ++i) {
		ip3[i] = mp->alloc();
	}

	ma[4] = memory_alloc_size();
	mf[4] = memory_free_size();

	if (mp->count() == 64 * 8 * 3) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の count", res);

	if ((mp->m_free_bits[0] == 0x0000000000000000ul)
	 && (mp->m_free_bits[1] == 0x0000000000000000ul)
	 && (mp->m_free_bits[2] == 0x0000000000000000ul)
	 && (mp->m_free_bits[3] == 0x0000000000000000ul)
	 && (mp->m_free_bits[4] == 0x0000000000000000ul)
	 && (mp->m_free_bits[5] == 0x0000000000000000ul)
	 && (mp->m_free_bits[6] == 0x0000000000000000ul)
	 && (mp->m_free_bits[7] == 0x0000000000000000ul)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の一つ目の m_free_bits", res);

	if (mp->m_next != nullptr
	 && (mp->m_next->m_free_bits[0] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[1] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[2] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[3] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[4] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[5] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[6] == 0x0000000000000000ul)
	 && (mp->m_next->m_free_bits[7] == 0x0000000000000000ul)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の二つ目の m_free_bits", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr
	 && (mp->m_next->m_next->m_free_bits[0] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[1] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[2] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[3] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[4] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[5] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[6] == 0x0000000000000000ul)
	 && (mp->m_next->m_next->m_free_bits[7] == 0x0000000000000000ul)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の三つ目の m_free_bits", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の一つ目の m_table", res);

	if (mp->m_next != nullptr && mp->m_next->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の二つ目の m_table", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr
	    && mp->m_next->m_next->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の三つ目の m_table", res);

	if (mp->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の一つ目の m_next", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の二つ目の m_next", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr
	    && mp->m_next->m_next->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の三つ目の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の一つ目の m_prev", res);

	if (mp->m_next != nullptr && mp->m_next->m_prev == mp) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の二つ目の m_prev", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr
	    && mp->m_next->m_next->m_prev == mp->m_next) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 3 の三つ目の m_prev", res);

	/*
	 * 真ん中の m_table を全て free した状態
	 */

	for (int i = 0; i < 64 * 8; ++i) {
		mp->free(ip2[i]);
	}

	ma[5] = memory_alloc_size();
	mf[5] = memory_free_size();

	if (mp->count() == 64 * 8 * 2) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の count", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_table", res);

	if (mp->m_next != nullptr && mp->m_next->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_table", res);

	if (mp->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_next", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の一つ目の m_prev", res);

	if (mp->m_next != nullptr && mp->m_next->m_prev == mp) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 2 の二つ目の m_prev", res);

	/*
	 * 最初の m_table を全て free した状態
	 */

	for (int i = 0; i < 64 * 8; ++i) {
		mp->free(ip1[i]);
	}

	ma[6] = memory_alloc_size();
	mf[6] = memory_free_size();

	if (mp->count() == 64 * 8) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の count", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の一つ目の m_table", res);

	if (mp->m_next != nullptr && mp->m_next->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の二つ目の m_table", res);

	if (mp->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の一つ目の m_next", res);

	if (mp->m_next != nullptr && mp->m_next->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の二つ目の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の一つ目の m_prev", res);

	if (mp->m_next != nullptr && mp->m_next->m_prev == mp) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("m_table x 1 の二つ目の m_prev", res);

	/*
	 * 最後の m_table を全て free した状態
	 */

	for (int i = 0; i < 64 * 8; ++i) {
		mp->free(ip3[i]);
	}

	ma[7] = memory_alloc_size();
	mf[7] = memory_free_size();

	if (mp->count() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("最終状態の count", res);

	if (mp->m_table != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("最終状態の m_table", res);

	if (mp->m_next != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("最終状態の m_next", res);

	if (mp->m_prev == nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("最終状態の m_prev", res);

	utf8str x;
	x = "mp->count() ";
	x.append_uint64(mp->count(), 10);
	print_test_result(x, res);
	x = "mp->m_next->count() ";
	x.append_uint64(mp->m_next->count(), 10);
	print_test_result(x, res);
	if (mp->m_next->m_next != nullptr) {
		print_test_result("3 個", res);
	}

	/*
	 * mp の削除
	 */

	delete mp;

	ma[8] = memory_alloc_size();
	mf[8] = memory_free_size();

	for (int i = 0; i < 9; ++i) {
		utf8str x;
		x.append_sint64(i, 3);
		x += " ma: ";
		x.append_sint64(ma[i], 12);
		x += " mf: ";
		x.append_sint64(mf[i], 12);
		x += " sum: ";
		x.append_sint64(ma[i] + mf[i], 12);
		print_test_result(x, test_result::pass);
	}

	memory_leak_test_end("メモリプールメモリリークチェック");
}

