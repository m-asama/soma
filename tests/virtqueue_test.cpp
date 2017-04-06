/**
 * @file	virtqueue_test.cpp
 * @brief	Virtqueue のテスト。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "main.h"
#include "utf8str.h"
#include "virtqueue.h"

void
virtqueue_test()
{
	test_result res = test_result::pass;

/*
	if (sizeof(virtqueue_ring_descriptor) == 16) {
		res = test_result::pass;
	} else {
		res = test_result::fail;
	}
	print_test_result("sizeof(virtqueue_ring_descriptor) == 16", res);
*/


	virtqueue *vq = new virtqueue(0x100);
	utf8str x;

	x = "queue_size:      ";
	x.append_hex64(vq->queue_size(), 8);
	print_test_result(x, res);

	x = "base:            ";
	x.append_hex64((uint64_t)vq->base(), 8);
	print_test_result(x, res);

	x = "ring_descriptor: ";
	x.append_hex64((uint64_t)vq->ring_descriptor(), 8);
	print_test_result(x, res);

	x = "ring_available:  ";
	x.append_hex64((uint64_t)vq->ring_available(), 8);
	print_test_result(x, res);

	x = "ring_used:       ";
	x.append_hex64((uint64_t)vq->ring_used(), 8);
	print_test_result(x, res);

	uint16_t d1 = vq->ring_descriptor_alloc();
	x = "d1 = "; x.append_hex64(d1, 2);
	print_test_result(x, res);

	uint16_t d2 = vq->ring_descriptor_alloc();
	x = "d2 = "; x.append_hex64(d2, 2);
	print_test_result(x, res);

	uint16_t d3 = vq->ring_descriptor_alloc();
	x = "d3 = "; x.append_hex64(d3, 2);
	print_test_result(x, res);

	x = "count = "; x.append_hex64(vq->allocated_descriptor_count(), 2);
	print_test_result(x, res);

	vq->ring_descriptor_free(d1);
	vq->ring_descriptor_free(d2);
	vq->ring_descriptor_free(d3);

	x = "count = "; x.append_hex64(vq->allocated_descriptor_count(), 2);
	print_test_result(x, res);

}

