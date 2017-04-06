/**
 * @file	packet_buffer_test.cpp
 * @brief	パケットバッファのテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"
#include "utf8str.h"
#include "packet_buffer.h"

void
packet_buffer_test()
{
	test_result res = test_result::pass;

/*
	if (sizeof(packet_buffer_ring_descriptor) == 16) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("sizeof(packet_buffer_ring_descriptor) == 16", res);
*/

	utf8str s;

	packet_buffer *p = new packet_buffer;

	s = "p = 0x";
	s.append_hex64((uint64_t)p, 16);
	print_test_result(s, res);

	s = "i = 0x";
	s.append_hex64(p->initial_head_address(), 16);
	print_test_result(s, res);

	s = "x = 0x";
	s.append_hex64((uint64_t)packet_buffer_from_initial_head_address(p->initial_head_address()), 16);
	print_test_result(s, res);

	if (packet_buffer_from_initial_head_address(p->initial_head_address()) == p) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("packet_buffer_from_initial_head_address", res);

	uint8_t *initial_head = p->head();
	uint8_t *initial_tail = p->tail();
	//uint64_t initial_size = p->size();

	s = "hr = 0x";
	s.append_hex64(p->headroom(), 16);
	print_test_result(s, test_result::pass);

	s = "tr = 0x";
	s.append_hex64(p->tailroom(), 16);
	print_test_result(s, test_result::pass);

	uint8_t buf[100];

	p->prepend(buf, 100);

	if (p->size() == 100) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("prepend: size", res);

	if (p->head() == (initial_head - 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("prepend: head", res);

	if (p->tail() == initial_tail) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("prepend: tail", res);

	p->append(buf, 100);

	if (p->size() == 200) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("append: size", res);

	if (p->head() == (initial_head - 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("append: head", res);

	if (p->tail() == (initial_tail + 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("append: tail", res);

	p->head_move(-10);

	if (p->size() == 210) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("head_move-: size", res);

	if (p->head() == (initial_head - 110)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("head_move-: head", res);

	if (p->tail() == (initial_tail + 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("head_move-: tail", res);

	p->head_move(10);

	if (p->size() == 200) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("head_move+: size", res);

	if (p->head() == (initial_head - 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("head_move+: head", res);

	if (p->tail() == (initial_tail + 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("head_move+: tail", res);

	p->tail_move(-10);

	if (p->size() == 190) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("tail_move-: size", res);

	if (p->head() == (initial_head - 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("tail_move-: head", res);

	if (p->tail() == (initial_tail + 90)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("tail_move-: tail", res);

	p->tail_move(10);

	if (p->size() == 200) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("tail_move+: size", res);

	if (p->head() == (initial_head - 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("tail_move+: head", res);

	if (p->tail() == (initial_tail + 100)) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("tail_move+: tail", res);

}

