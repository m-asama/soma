/**
 * @file	buffer_test.cpp
 * @brief	リングバッファのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"
#include "utf8str.h"

#include "ring_buffer.h"

void
ring_buffer_test()
{
	test_result res;
	ring_buffer<uint8_t> *x;
	uint8_t d, d1, d2;
	bool b1, b2;

	memory_leak_test_begin();

	x = new ring_buffer<uint8_t>(7);

	if (x->m_buffer != nullptr) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->m_buffer != nullptr", res);

	if (sizeof(x->m_buffer) == 8) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("sizeof(x->m_buffer) == 64", res);

	if (x->m_size == 8) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->m_size == 8", res);

	if (x->readable() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->readable() == 0", res);

	if (x->writeable() == 7) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->writeable == 7", res);

	d = 1;
	x->write(d);
	d = 2;
	x->write(d);
	if (x->readable() == 2) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->readable() == 2", res);

	if (x->writeable() == 5) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->writeable() == 5", res);

	if (((*x)[0] == 1) && ((*x)[1] == 2)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("((*x)[0] == 1) && ((*x)[1] == 2)", res);

	b1 = x->read(d1);
	b2 = x->read(d2);
	if ((b1 == true) && (b2 == true) && (d1 == 1) && (d2 == 2)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("(d1 == 1) && (d2 == 2)", res);

	if (x->readable() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->readable() == 0", res);

	if (x->writeable() == 7) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->writeable == 7", res);

	d = 3;
	x->write(d);
	d = 4;
	x->write(d);
	d = 5;
	x->write(d);
	d = 6;
	x->write(d);
	d = 7;
	x->write(d);
	d = 8;
	x->write(d);
	d = 9;
	x->write(d);

	if (x->readable() == 7) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->readable() == 7", res);

	if (x->writeable() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->writeable == 0", res);

	if (((*x)[0] == 3)
	 && ((*x)[1] == 4)
	 && ((*x)[2] == 5)
	 && ((*x)[3] == 6)
	 && ((*x)[4] == 7)
	 && ((*x)[5] == 8)
	 && ((*x)[6] == 9)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("(*x)[0] ~ (*x)[6]", res);

	b1 = x->read(d1);
	b2 = x->read(d2);
	if ((b1 == true) && (b2 == true) && (d1 == 3) && (d2 == 4)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("(d1 == 3) && (d2 == 4)", res);

	b1 = x->read(d1);
	b2 = x->read(d2);
	if ((b1 == true) && (b2 == true) && (d1 == 5) && (d2 == 6)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("(d1 == 5) && (d2 == 6)", res);

	b1 = x->read(d1);
	b2 = x->read(d2);
	if ((b1 == true) && (b2 == true) && (d1 == 7) && (d2 == 8)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("(d1 == 7) && (d2 == 8)", res);

	d = 10;
	x->write(d);
	b1 = x->read(d1);
	b2 = x->read(d2);
	if ((b1 == true) && (b2 == true) && (d1 == 9) && (d2 == 10)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("(d1 == 9) && (d2 == 10)", res);

	if (x->readable() == 0) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->readable() == 0", res);

	if (x->writeable() == 7) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("x->writeable == 7", res);

/*
	if () {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("", res);

	if () {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("", res);

	if () {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("", res);

	if () {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("", res);

	if () {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("", res);
*/
	delete x;

	memory_leak_test_end("リングバッファメモリリークチェック");
}

