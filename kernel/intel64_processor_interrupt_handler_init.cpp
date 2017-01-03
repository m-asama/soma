/**
 * @file	intel64_processor_interrupt_handler_init.cpp
 * @brief	Intel64 CPU の割り込みハンドラ関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "intel64_processor.h"

extern "C" void interrupt_handler_0x00();
extern "C" void interrupt_handler_0x01();
extern "C" void interrupt_handler_0x02();
extern "C" void interrupt_handler_0x03();
extern "C" void interrupt_handler_0x04();
extern "C" void interrupt_handler_0x05();
extern "C" void interrupt_handler_0x06();
extern "C" void interrupt_handler_0x07();
extern "C" void interrupt_handler_0x08();
extern "C" void interrupt_handler_0x09();
extern "C" void interrupt_handler_0x0a();
extern "C" void interrupt_handler_0x0b();
extern "C" void interrupt_handler_0x0c();
extern "C" void interrupt_handler_0x0d();
extern "C" void interrupt_handler_0x0e();
extern "C" void interrupt_handler_0x0f();
extern "C" void interrupt_handler_0x10();
extern "C" void interrupt_handler_0x11();
extern "C" void interrupt_handler_0x12();
extern "C" void interrupt_handler_0x13();
extern "C" void interrupt_handler_0x14();
extern "C" void interrupt_handler_0x15();
extern "C" void interrupt_handler_0x16();
extern "C" void interrupt_handler_0x17();
extern "C" void interrupt_handler_0x18();
extern "C" void interrupt_handler_0x19();
extern "C" void interrupt_handler_0x1a();
extern "C" void interrupt_handler_0x1b();
extern "C" void interrupt_handler_0x1c();
extern "C" void interrupt_handler_0x1d();
extern "C" void interrupt_handler_0x1e();
extern "C" void interrupt_handler_0x1f();
extern "C" void interrupt_handler_0x20();
extern "C" void interrupt_handler_0x21();
extern "C" void interrupt_handler_0x22();
extern "C" void interrupt_handler_0x23();
extern "C" void interrupt_handler_0x24();
extern "C" void interrupt_handler_0x25();
extern "C" void interrupt_handler_0x26();
extern "C" void interrupt_handler_0x27();
extern "C" void interrupt_handler_0x28();
extern "C" void interrupt_handler_0x29();
extern "C" void interrupt_handler_0x2a();
extern "C" void interrupt_handler_0x2b();
extern "C" void interrupt_handler_0x2c();
extern "C" void interrupt_handler_0x2d();
extern "C" void interrupt_handler_0x2e();
extern "C" void interrupt_handler_0x2f();
extern "C" void interrupt_handler_0x30();
extern "C" void interrupt_handler_0x31();
extern "C" void interrupt_handler_0x32();
extern "C" void interrupt_handler_0x33();
extern "C" void interrupt_handler_0x34();
extern "C" void interrupt_handler_0x35();
extern "C" void interrupt_handler_0x36();
extern "C" void interrupt_handler_0x37();
extern "C" void interrupt_handler_0x38();
extern "C" void interrupt_handler_0x39();
extern "C" void interrupt_handler_0x3a();
extern "C" void interrupt_handler_0x3b();
extern "C" void interrupt_handler_0x3c();
extern "C" void interrupt_handler_0x3d();
extern "C" void interrupt_handler_0x3e();
extern "C" void interrupt_handler_0x3f();
extern "C" void interrupt_handler_0x40();
extern "C" void interrupt_handler_0x41();
extern "C" void interrupt_handler_0x42();
extern "C" void interrupt_handler_0x43();
extern "C" void interrupt_handler_0x44();
extern "C" void interrupt_handler_0x45();
extern "C" void interrupt_handler_0x46();
extern "C" void interrupt_handler_0x47();
extern "C" void interrupt_handler_0x48();
extern "C" void interrupt_handler_0x49();
extern "C" void interrupt_handler_0x4a();
extern "C" void interrupt_handler_0x4b();
extern "C" void interrupt_handler_0x4c();
extern "C" void interrupt_handler_0x4d();
extern "C" void interrupt_handler_0x4e();
extern "C" void interrupt_handler_0x4f();
extern "C" void interrupt_handler_0x50();
extern "C" void interrupt_handler_0x51();
extern "C" void interrupt_handler_0x52();
extern "C" void interrupt_handler_0x53();
extern "C" void interrupt_handler_0x54();
extern "C" void interrupt_handler_0x55();
extern "C" void interrupt_handler_0x56();
extern "C" void interrupt_handler_0x57();
extern "C" void interrupt_handler_0x58();
extern "C" void interrupt_handler_0x59();
extern "C" void interrupt_handler_0x5a();
extern "C" void interrupt_handler_0x5b();
extern "C" void interrupt_handler_0x5c();
extern "C" void interrupt_handler_0x5d();
extern "C" void interrupt_handler_0x5e();
extern "C" void interrupt_handler_0x5f();
extern "C" void interrupt_handler_0x60();
extern "C" void interrupt_handler_0x61();
extern "C" void interrupt_handler_0x62();
extern "C" void interrupt_handler_0x63();
extern "C" void interrupt_handler_0x64();
extern "C" void interrupt_handler_0x65();
extern "C" void interrupt_handler_0x66();
extern "C" void interrupt_handler_0x67();
extern "C" void interrupt_handler_0x68();
extern "C" void interrupt_handler_0x69();
extern "C" void interrupt_handler_0x6a();
extern "C" void interrupt_handler_0x6b();
extern "C" void interrupt_handler_0x6c();
extern "C" void interrupt_handler_0x6d();
extern "C" void interrupt_handler_0x6e();
extern "C" void interrupt_handler_0x6f();
extern "C" void interrupt_handler_0x70();
extern "C" void interrupt_handler_0x71();
extern "C" void interrupt_handler_0x72();
extern "C" void interrupt_handler_0x73();
extern "C" void interrupt_handler_0x74();
extern "C" void interrupt_handler_0x75();
extern "C" void interrupt_handler_0x76();
extern "C" void interrupt_handler_0x77();
extern "C" void interrupt_handler_0x78();
extern "C" void interrupt_handler_0x79();
extern "C" void interrupt_handler_0x7a();
extern "C" void interrupt_handler_0x7b();
extern "C" void interrupt_handler_0x7c();
extern "C" void interrupt_handler_0x7d();
extern "C" void interrupt_handler_0x7e();
extern "C" void interrupt_handler_0x7f();
extern "C" void interrupt_handler_0x80();
extern "C" void interrupt_handler_0x81();
extern "C" void interrupt_handler_0x82();
extern "C" void interrupt_handler_0x83();
extern "C" void interrupt_handler_0x84();
extern "C" void interrupt_handler_0x85();
extern "C" void interrupt_handler_0x86();
extern "C" void interrupt_handler_0x87();
extern "C" void interrupt_handler_0x88();
extern "C" void interrupt_handler_0x89();
extern "C" void interrupt_handler_0x8a();
extern "C" void interrupt_handler_0x8b();
extern "C" void interrupt_handler_0x8c();
extern "C" void interrupt_handler_0x8d();
extern "C" void interrupt_handler_0x8e();
extern "C" void interrupt_handler_0x8f();
extern "C" void interrupt_handler_0x90();
extern "C" void interrupt_handler_0x91();
extern "C" void interrupt_handler_0x92();
extern "C" void interrupt_handler_0x93();
extern "C" void interrupt_handler_0x94();
extern "C" void interrupt_handler_0x95();
extern "C" void interrupt_handler_0x96();
extern "C" void interrupt_handler_0x97();
extern "C" void interrupt_handler_0x98();
extern "C" void interrupt_handler_0x99();
extern "C" void interrupt_handler_0x9a();
extern "C" void interrupt_handler_0x9b();
extern "C" void interrupt_handler_0x9c();
extern "C" void interrupt_handler_0x9d();
extern "C" void interrupt_handler_0x9e();
extern "C" void interrupt_handler_0x9f();
extern "C" void interrupt_handler_0xa0();
extern "C" void interrupt_handler_0xa1();
extern "C" void interrupt_handler_0xa2();
extern "C" void interrupt_handler_0xa3();
extern "C" void interrupt_handler_0xa4();
extern "C" void interrupt_handler_0xa5();
extern "C" void interrupt_handler_0xa6();
extern "C" void interrupt_handler_0xa7();
extern "C" void interrupt_handler_0xa8();
extern "C" void interrupt_handler_0xa9();
extern "C" void interrupt_handler_0xaa();
extern "C" void interrupt_handler_0xab();
extern "C" void interrupt_handler_0xac();
extern "C" void interrupt_handler_0xad();
extern "C" void interrupt_handler_0xae();
extern "C" void interrupt_handler_0xaf();
extern "C" void interrupt_handler_0xb0();
extern "C" void interrupt_handler_0xb1();
extern "C" void interrupt_handler_0xb2();
extern "C" void interrupt_handler_0xb3();
extern "C" void interrupt_handler_0xb4();
extern "C" void interrupt_handler_0xb5();
extern "C" void interrupt_handler_0xb6();
extern "C" void interrupt_handler_0xb7();
extern "C" void interrupt_handler_0xb8();
extern "C" void interrupt_handler_0xb9();
extern "C" void interrupt_handler_0xba();
extern "C" void interrupt_handler_0xbb();
extern "C" void interrupt_handler_0xbc();
extern "C" void interrupt_handler_0xbd();
extern "C" void interrupt_handler_0xbe();
extern "C" void interrupt_handler_0xbf();
extern "C" void interrupt_handler_0xc0();
extern "C" void interrupt_handler_0xc1();
extern "C" void interrupt_handler_0xc2();
extern "C" void interrupt_handler_0xc3();
extern "C" void interrupt_handler_0xc4();
extern "C" void interrupt_handler_0xc5();
extern "C" void interrupt_handler_0xc6();
extern "C" void interrupt_handler_0xc7();
extern "C" void interrupt_handler_0xc8();
extern "C" void interrupt_handler_0xc9();
extern "C" void interrupt_handler_0xca();
extern "C" void interrupt_handler_0xcb();
extern "C" void interrupt_handler_0xcc();
extern "C" void interrupt_handler_0xcd();
extern "C" void interrupt_handler_0xce();
extern "C" void interrupt_handler_0xcf();
extern "C" void interrupt_handler_0xd0();
extern "C" void interrupt_handler_0xd1();
extern "C" void interrupt_handler_0xd2();
extern "C" void interrupt_handler_0xd3();
extern "C" void interrupt_handler_0xd4();
extern "C" void interrupt_handler_0xd5();
extern "C" void interrupt_handler_0xd6();
extern "C" void interrupt_handler_0xd7();
extern "C" void interrupt_handler_0xd8();
extern "C" void interrupt_handler_0xd9();
extern "C" void interrupt_handler_0xda();
extern "C" void interrupt_handler_0xdb();
extern "C" void interrupt_handler_0xdc();
extern "C" void interrupt_handler_0xdd();
extern "C" void interrupt_handler_0xde();
extern "C" void interrupt_handler_0xdf();
extern "C" void interrupt_handler_0xe0();
extern "C" void interrupt_handler_0xe1();
extern "C" void interrupt_handler_0xe2();
extern "C" void interrupt_handler_0xe3();
extern "C" void interrupt_handler_0xe4();
extern "C" void interrupt_handler_0xe5();
extern "C" void interrupt_handler_0xe6();
extern "C" void interrupt_handler_0xe7();
extern "C" void interrupt_handler_0xe8();
extern "C" void interrupt_handler_0xe9();
extern "C" void interrupt_handler_0xea();
extern "C" void interrupt_handler_0xeb();
extern "C" void interrupt_handler_0xec();
extern "C" void interrupt_handler_0xed();
extern "C" void interrupt_handler_0xee();
extern "C" void interrupt_handler_0xef();
extern "C" void interrupt_handler_0xf0();
extern "C" void interrupt_handler_0xf1();
extern "C" void interrupt_handler_0xf2();
extern "C" void interrupt_handler_0xf3();
extern "C" void interrupt_handler_0xf4();
extern "C" void interrupt_handler_0xf5();
extern "C" void interrupt_handler_0xf6();
extern "C" void interrupt_handler_0xf7();
extern "C" void interrupt_handler_0xf8();
extern "C" void interrupt_handler_0xf9();
extern "C" void interrupt_handler_0xfa();
extern "C" void interrupt_handler_0xfb();
extern "C" void interrupt_handler_0xfc();
extern "C" void interrupt_handler_0xfd();
extern "C" void interrupt_handler_0xfe();
extern "C" void interrupt_handler_0xff();

void
interrupt_handler_init(intel64_idt_entry *idt, uint16_t code_segment_selector)
{
	idt[0x00].offset((uint64_t)interrupt_handler_0x00);
	idt[0x00].p(true);
	idt[0x00].type(0x0e);
	idt[0x00].segment_selector(code_segment_selector);

	idt[0x01].offset((uint64_t)interrupt_handler_0x01);
	idt[0x01].p(true);
	idt[0x01].type(0x0e);
	idt[0x01].segment_selector(code_segment_selector);

	idt[0x02].offset((uint64_t)interrupt_handler_0x02);
	idt[0x02].p(true);
	idt[0x02].type(0x0e);
	idt[0x02].segment_selector(code_segment_selector);

	idt[0x03].offset((uint64_t)interrupt_handler_0x03);
	idt[0x03].p(true);
	idt[0x03].type(0x0e);
	idt[0x03].segment_selector(code_segment_selector);

	idt[0x04].offset((uint64_t)interrupt_handler_0x04);
	idt[0x04].p(true);
	idt[0x04].type(0x0e);
	idt[0x04].segment_selector(code_segment_selector);

	idt[0x05].offset((uint64_t)interrupt_handler_0x05);
	idt[0x05].p(true);
	idt[0x05].type(0x0e);
	idt[0x05].segment_selector(code_segment_selector);

	idt[0x06].offset((uint64_t)interrupt_handler_0x06);
	idt[0x06].p(true);
	idt[0x06].type(0x0e);
	idt[0x06].segment_selector(code_segment_selector);

	idt[0x07].offset((uint64_t)interrupt_handler_0x07);
	idt[0x07].p(true);
	idt[0x07].type(0x0e);
	idt[0x07].segment_selector(code_segment_selector);

	idt[0x08].offset((uint64_t)interrupt_handler_0x08);
	idt[0x08].p(true);
	idt[0x08].type(0x0e);
	idt[0x08].segment_selector(code_segment_selector);

	idt[0x09].offset((uint64_t)interrupt_handler_0x09);
	idt[0x09].p(true);
	idt[0x09].type(0x0e);
	idt[0x09].segment_selector(code_segment_selector);

	idt[0x0a].offset((uint64_t)interrupt_handler_0x0a);
	idt[0x0a].p(true);
	idt[0x0a].type(0x0e);
	idt[0x0a].segment_selector(code_segment_selector);

	idt[0x0b].offset((uint64_t)interrupt_handler_0x0b);
	idt[0x0b].p(true);
	idt[0x0b].type(0x0e);
	idt[0x0b].segment_selector(code_segment_selector);

	idt[0x0c].offset((uint64_t)interrupt_handler_0x0c);
	idt[0x0c].p(true);
	idt[0x0c].type(0x0e);
	idt[0x0c].segment_selector(code_segment_selector);

	idt[0x0d].offset((uint64_t)interrupt_handler_0x0d);
	idt[0x0d].p(true);
	idt[0x0d].type(0x0e);
	idt[0x0d].segment_selector(code_segment_selector);

	idt[0x0e].offset((uint64_t)interrupt_handler_0x0e);
	idt[0x0e].p(true);
	idt[0x0e].type(0x0e);
	idt[0x0e].segment_selector(code_segment_selector);

	idt[0x0f].offset((uint64_t)interrupt_handler_0x0f);
	idt[0x0f].p(true);
	idt[0x0f].type(0x0e);
	idt[0x0f].segment_selector(code_segment_selector);

	idt[0x10].offset((uint64_t)interrupt_handler_0x10);
	idt[0x10].p(true);
	idt[0x10].type(0x0e);
	idt[0x10].segment_selector(code_segment_selector);

	idt[0x11].offset((uint64_t)interrupt_handler_0x11);
	idt[0x11].p(true);
	idt[0x11].type(0x0e);
	idt[0x11].segment_selector(code_segment_selector);

	idt[0x12].offset((uint64_t)interrupt_handler_0x12);
	idt[0x12].p(true);
	idt[0x12].type(0x0e);
	idt[0x12].segment_selector(code_segment_selector);

	idt[0x13].offset((uint64_t)interrupt_handler_0x13);
	idt[0x13].p(true);
	idt[0x13].type(0x0e);
	idt[0x13].segment_selector(code_segment_selector);

	idt[0x14].offset((uint64_t)interrupt_handler_0x14);
	idt[0x14].p(true);
	idt[0x14].type(0x0e);
	idt[0x14].segment_selector(code_segment_selector);

	idt[0x15].offset((uint64_t)interrupt_handler_0x15);
	idt[0x15].p(true);
	idt[0x15].type(0x0e);
	idt[0x15].segment_selector(code_segment_selector);

	idt[0x16].offset((uint64_t)interrupt_handler_0x16);
	idt[0x16].p(true);
	idt[0x16].type(0x0e);
	idt[0x16].segment_selector(code_segment_selector);

	idt[0x17].offset((uint64_t)interrupt_handler_0x17);
	idt[0x17].p(true);
	idt[0x17].type(0x0e);
	idt[0x17].segment_selector(code_segment_selector);

	idt[0x18].offset((uint64_t)interrupt_handler_0x18);
	idt[0x18].p(true);
	idt[0x18].type(0x0e);
	idt[0x18].segment_selector(code_segment_selector);

	idt[0x19].offset((uint64_t)interrupt_handler_0x19);
	idt[0x19].p(true);
	idt[0x19].type(0x0e);
	idt[0x19].segment_selector(code_segment_selector);

	idt[0x1a].offset((uint64_t)interrupt_handler_0x1a);
	idt[0x1a].p(true);
	idt[0x1a].type(0x0e);
	idt[0x1a].segment_selector(code_segment_selector);

	idt[0x1b].offset((uint64_t)interrupt_handler_0x1b);
	idt[0x1b].p(true);
	idt[0x1b].type(0x0e);
	idt[0x1b].segment_selector(code_segment_selector);

	idt[0x1c].offset((uint64_t)interrupt_handler_0x1c);
	idt[0x1c].p(true);
	idt[0x1c].type(0x0e);
	idt[0x1c].segment_selector(code_segment_selector);

	idt[0x1d].offset((uint64_t)interrupt_handler_0x1d);
	idt[0x1d].p(true);
	idt[0x1d].type(0x0e);
	idt[0x1d].segment_selector(code_segment_selector);

	idt[0x1e].offset((uint64_t)interrupt_handler_0x1e);
	idt[0x1e].p(true);
	idt[0x1e].type(0x0e);
	idt[0x1e].segment_selector(code_segment_selector);

	idt[0x1f].offset((uint64_t)interrupt_handler_0x1f);
	idt[0x1f].p(true);
	idt[0x1f].type(0x0e);
	idt[0x1f].segment_selector(code_segment_selector);

	idt[0x20].offset((uint64_t)interrupt_handler_0x20);
	idt[0x20].p(true);
	idt[0x20].type(0x0e);
	idt[0x20].segment_selector(code_segment_selector);

	idt[0x21].offset((uint64_t)interrupt_handler_0x21);
	idt[0x21].p(true);
	idt[0x21].type(0x0e);
	idt[0x21].segment_selector(code_segment_selector);

	idt[0x22].offset((uint64_t)interrupt_handler_0x22);
	idt[0x22].p(true);
	idt[0x22].type(0x0e);
	idt[0x22].segment_selector(code_segment_selector);

	idt[0x23].offset((uint64_t)interrupt_handler_0x23);
	idt[0x23].p(true);
	idt[0x23].type(0x0e);
	idt[0x23].segment_selector(code_segment_selector);

	idt[0x24].offset((uint64_t)interrupt_handler_0x24);
	idt[0x24].p(true);
	idt[0x24].type(0x0e);
	idt[0x24].segment_selector(code_segment_selector);

	idt[0x25].offset((uint64_t)interrupt_handler_0x25);
	idt[0x25].p(true);
	idt[0x25].type(0x0e);
	idt[0x25].segment_selector(code_segment_selector);

	idt[0x26].offset((uint64_t)interrupt_handler_0x26);
	idt[0x26].p(true);
	idt[0x26].type(0x0e);
	idt[0x26].segment_selector(code_segment_selector);

	idt[0x27].offset((uint64_t)interrupt_handler_0x27);
	idt[0x27].p(true);
	idt[0x27].type(0x0e);
	idt[0x27].segment_selector(code_segment_selector);

	idt[0x28].offset((uint64_t)interrupt_handler_0x28);
	idt[0x28].p(true);
	idt[0x28].type(0x0e);
	idt[0x28].segment_selector(code_segment_selector);

	idt[0x29].offset((uint64_t)interrupt_handler_0x29);
	idt[0x29].p(true);
	idt[0x29].type(0x0e);
	idt[0x29].segment_selector(code_segment_selector);

	idt[0x2a].offset((uint64_t)interrupt_handler_0x2a);
	idt[0x2a].p(true);
	idt[0x2a].type(0x0e);
	idt[0x2a].segment_selector(code_segment_selector);

	idt[0x2b].offset((uint64_t)interrupt_handler_0x2b);
	idt[0x2b].p(true);
	idt[0x2b].type(0x0e);
	idt[0x2b].segment_selector(code_segment_selector);

	idt[0x2c].offset((uint64_t)interrupt_handler_0x2c);
	idt[0x2c].p(true);
	idt[0x2c].type(0x0e);
	idt[0x2c].segment_selector(code_segment_selector);

	idt[0x2d].offset((uint64_t)interrupt_handler_0x2d);
	idt[0x2d].p(true);
	idt[0x2d].type(0x0e);
	idt[0x2d].segment_selector(code_segment_selector);

	idt[0x2e].offset((uint64_t)interrupt_handler_0x2e);
	idt[0x2e].p(true);
	idt[0x2e].type(0x0e);
	idt[0x2e].segment_selector(code_segment_selector);

	idt[0x2f].offset((uint64_t)interrupt_handler_0x2f);
	idt[0x2f].p(true);
	idt[0x2f].type(0x0e);
	idt[0x2f].segment_selector(code_segment_selector);

	idt[0x30].offset((uint64_t)interrupt_handler_0x30);
	idt[0x30].p(true);
	idt[0x30].type(0x0e);
	idt[0x30].segment_selector(code_segment_selector);

	idt[0x31].offset((uint64_t)interrupt_handler_0x31);
	idt[0x31].p(true);
	idt[0x31].type(0x0e);
	idt[0x31].segment_selector(code_segment_selector);

	idt[0x32].offset((uint64_t)interrupt_handler_0x32);
	idt[0x32].p(true);
	idt[0x32].type(0x0e);
	idt[0x32].segment_selector(code_segment_selector);

	idt[0x33].offset((uint64_t)interrupt_handler_0x33);
	idt[0x33].p(true);
	idt[0x33].type(0x0e);
	idt[0x33].segment_selector(code_segment_selector);

	idt[0x34].offset((uint64_t)interrupt_handler_0x34);
	idt[0x34].p(true);
	idt[0x34].type(0x0e);
	idt[0x34].segment_selector(code_segment_selector);

	idt[0x35].offset((uint64_t)interrupt_handler_0x35);
	idt[0x35].p(true);
	idt[0x35].type(0x0e);
	idt[0x35].segment_selector(code_segment_selector);

	idt[0x36].offset((uint64_t)interrupt_handler_0x36);
	idt[0x36].p(true);
	idt[0x36].type(0x0e);
	idt[0x36].segment_selector(code_segment_selector);

	idt[0x37].offset((uint64_t)interrupt_handler_0x37);
	idt[0x37].p(true);
	idt[0x37].type(0x0e);
	idt[0x37].segment_selector(code_segment_selector);

	idt[0x38].offset((uint64_t)interrupt_handler_0x38);
	idt[0x38].p(true);
	idt[0x38].type(0x0e);
	idt[0x38].segment_selector(code_segment_selector);

	idt[0x39].offset((uint64_t)interrupt_handler_0x39);
	idt[0x39].p(true);
	idt[0x39].type(0x0e);
	idt[0x39].segment_selector(code_segment_selector);

	idt[0x3a].offset((uint64_t)interrupt_handler_0x3a);
	idt[0x3a].p(true);
	idt[0x3a].type(0x0e);
	idt[0x3a].segment_selector(code_segment_selector);

	idt[0x3b].offset((uint64_t)interrupt_handler_0x3b);
	idt[0x3b].p(true);
	idt[0x3b].type(0x0e);
	idt[0x3b].segment_selector(code_segment_selector);

	idt[0x3c].offset((uint64_t)interrupt_handler_0x3c);
	idt[0x3c].p(true);
	idt[0x3c].type(0x0e);
	idt[0x3c].segment_selector(code_segment_selector);

	idt[0x3d].offset((uint64_t)interrupt_handler_0x3d);
	idt[0x3d].p(true);
	idt[0x3d].type(0x0e);
	idt[0x3d].segment_selector(code_segment_selector);

	idt[0x3e].offset((uint64_t)interrupt_handler_0x3e);
	idt[0x3e].p(true);
	idt[0x3e].type(0x0e);
	idt[0x3e].segment_selector(code_segment_selector);

	idt[0x3f].offset((uint64_t)interrupt_handler_0x3f);
	idt[0x3f].p(true);
	idt[0x3f].type(0x0e);
	idt[0x3f].segment_selector(code_segment_selector);

	idt[0x40].offset((uint64_t)interrupt_handler_0x40);
	idt[0x40].p(true);
	idt[0x40].type(0x0e);
	idt[0x40].segment_selector(code_segment_selector);

	idt[0x41].offset((uint64_t)interrupt_handler_0x41);
	idt[0x41].p(true);
	idt[0x41].type(0x0e);
	idt[0x41].segment_selector(code_segment_selector);

	idt[0x42].offset((uint64_t)interrupt_handler_0x42);
	idt[0x42].p(true);
	idt[0x42].type(0x0e);
	idt[0x42].segment_selector(code_segment_selector);

	idt[0x43].offset((uint64_t)interrupt_handler_0x43);
	idt[0x43].p(true);
	idt[0x43].type(0x0e);
	idt[0x43].segment_selector(code_segment_selector);

	idt[0x44].offset((uint64_t)interrupt_handler_0x44);
	idt[0x44].p(true);
	idt[0x44].type(0x0e);
	idt[0x44].segment_selector(code_segment_selector);

	idt[0x45].offset((uint64_t)interrupt_handler_0x45);
	idt[0x45].p(true);
	idt[0x45].type(0x0e);
	idt[0x45].segment_selector(code_segment_selector);

	idt[0x46].offset((uint64_t)interrupt_handler_0x46);
	idt[0x46].p(true);
	idt[0x46].type(0x0e);
	idt[0x46].segment_selector(code_segment_selector);

	idt[0x47].offset((uint64_t)interrupt_handler_0x47);
	idt[0x47].p(true);
	idt[0x47].type(0x0e);
	idt[0x47].segment_selector(code_segment_selector);

	idt[0x48].offset((uint64_t)interrupt_handler_0x48);
	idt[0x48].p(true);
	idt[0x48].type(0x0e);
	idt[0x48].segment_selector(code_segment_selector);

	idt[0x49].offset((uint64_t)interrupt_handler_0x49);
	idt[0x49].p(true);
	idt[0x49].type(0x0e);
	idt[0x49].segment_selector(code_segment_selector);

	idt[0x4a].offset((uint64_t)interrupt_handler_0x4a);
	idt[0x4a].p(true);
	idt[0x4a].type(0x0e);
	idt[0x4a].segment_selector(code_segment_selector);

	idt[0x4b].offset((uint64_t)interrupt_handler_0x4b);
	idt[0x4b].p(true);
	idt[0x4b].type(0x0e);
	idt[0x4b].segment_selector(code_segment_selector);

	idt[0x4c].offset((uint64_t)interrupt_handler_0x4c);
	idt[0x4c].p(true);
	idt[0x4c].type(0x0e);
	idt[0x4c].segment_selector(code_segment_selector);

	idt[0x4d].offset((uint64_t)interrupt_handler_0x4d);
	idt[0x4d].p(true);
	idt[0x4d].type(0x0e);
	idt[0x4d].segment_selector(code_segment_selector);

	idt[0x4e].offset((uint64_t)interrupt_handler_0x4e);
	idt[0x4e].p(true);
	idt[0x4e].type(0x0e);
	idt[0x4e].segment_selector(code_segment_selector);

	idt[0x4f].offset((uint64_t)interrupt_handler_0x4f);
	idt[0x4f].p(true);
	idt[0x4f].type(0x0e);
	idt[0x4f].segment_selector(code_segment_selector);

	idt[0x50].offset((uint64_t)interrupt_handler_0x50);
	idt[0x50].p(true);
	idt[0x50].type(0x0e);
	idt[0x50].segment_selector(code_segment_selector);

	idt[0x51].offset((uint64_t)interrupt_handler_0x51);
	idt[0x51].p(true);
	idt[0x51].type(0x0e);
	idt[0x51].segment_selector(code_segment_selector);

	idt[0x52].offset((uint64_t)interrupt_handler_0x52);
	idt[0x52].p(true);
	idt[0x52].type(0x0e);
	idt[0x52].segment_selector(code_segment_selector);

	idt[0x53].offset((uint64_t)interrupt_handler_0x53);
	idt[0x53].p(true);
	idt[0x53].type(0x0e);
	idt[0x53].segment_selector(code_segment_selector);

	idt[0x54].offset((uint64_t)interrupt_handler_0x54);
	idt[0x54].p(true);
	idt[0x54].type(0x0e);
	idt[0x54].segment_selector(code_segment_selector);

	idt[0x55].offset((uint64_t)interrupt_handler_0x55);
	idt[0x55].p(true);
	idt[0x55].type(0x0e);
	idt[0x55].segment_selector(code_segment_selector);

	idt[0x56].offset((uint64_t)interrupt_handler_0x56);
	idt[0x56].p(true);
	idt[0x56].type(0x0e);
	idt[0x56].segment_selector(code_segment_selector);

	idt[0x57].offset((uint64_t)interrupt_handler_0x57);
	idt[0x57].p(true);
	idt[0x57].type(0x0e);
	idt[0x57].segment_selector(code_segment_selector);

	idt[0x58].offset((uint64_t)interrupt_handler_0x58);
	idt[0x58].p(true);
	idt[0x58].type(0x0e);
	idt[0x58].segment_selector(code_segment_selector);

	idt[0x59].offset((uint64_t)interrupt_handler_0x59);
	idt[0x59].p(true);
	idt[0x59].type(0x0e);
	idt[0x59].segment_selector(code_segment_selector);

	idt[0x5a].offset((uint64_t)interrupt_handler_0x5a);
	idt[0x5a].p(true);
	idt[0x5a].type(0x0e);
	idt[0x5a].segment_selector(code_segment_selector);

	idt[0x5b].offset((uint64_t)interrupt_handler_0x5b);
	idt[0x5b].p(true);
	idt[0x5b].type(0x0e);
	idt[0x5b].segment_selector(code_segment_selector);

	idt[0x5c].offset((uint64_t)interrupt_handler_0x5c);
	idt[0x5c].p(true);
	idt[0x5c].type(0x0e);
	idt[0x5c].segment_selector(code_segment_selector);

	idt[0x5d].offset((uint64_t)interrupt_handler_0x5d);
	idt[0x5d].p(true);
	idt[0x5d].type(0x0e);
	idt[0x5d].segment_selector(code_segment_selector);

	idt[0x5e].offset((uint64_t)interrupt_handler_0x5e);
	idt[0x5e].p(true);
	idt[0x5e].type(0x0e);
	idt[0x5e].segment_selector(code_segment_selector);

	idt[0x5f].offset((uint64_t)interrupt_handler_0x5f);
	idt[0x5f].p(true);
	idt[0x5f].type(0x0e);
	idt[0x5f].segment_selector(code_segment_selector);

	idt[0x60].offset((uint64_t)interrupt_handler_0x60);
	idt[0x60].p(true);
	idt[0x60].type(0x0e);
	idt[0x60].segment_selector(code_segment_selector);

	idt[0x61].offset((uint64_t)interrupt_handler_0x61);
	idt[0x61].p(true);
	idt[0x61].type(0x0e);
	idt[0x61].segment_selector(code_segment_selector);

	idt[0x62].offset((uint64_t)interrupt_handler_0x62);
	idt[0x62].p(true);
	idt[0x62].type(0x0e);
	idt[0x62].segment_selector(code_segment_selector);

	idt[0x63].offset((uint64_t)interrupt_handler_0x63);
	idt[0x63].p(true);
	idt[0x63].type(0x0e);
	idt[0x63].segment_selector(code_segment_selector);

	idt[0x64].offset((uint64_t)interrupt_handler_0x64);
	idt[0x64].p(true);
	idt[0x64].type(0x0e);
	idt[0x64].segment_selector(code_segment_selector);

	idt[0x65].offset((uint64_t)interrupt_handler_0x65);
	idt[0x65].p(true);
	idt[0x65].type(0x0e);
	idt[0x65].segment_selector(code_segment_selector);

	idt[0x66].offset((uint64_t)interrupt_handler_0x66);
	idt[0x66].p(true);
	idt[0x66].type(0x0e);
	idt[0x66].segment_selector(code_segment_selector);

	idt[0x67].offset((uint64_t)interrupt_handler_0x67);
	idt[0x67].p(true);
	idt[0x67].type(0x0e);
	idt[0x67].segment_selector(code_segment_selector);

	idt[0x68].offset((uint64_t)interrupt_handler_0x68);
	idt[0x68].p(true);
	idt[0x68].type(0x0e);
	idt[0x68].segment_selector(code_segment_selector);

	idt[0x69].offset((uint64_t)interrupt_handler_0x69);
	idt[0x69].p(true);
	idt[0x69].type(0x0e);
	idt[0x69].segment_selector(code_segment_selector);

	idt[0x6a].offset((uint64_t)interrupt_handler_0x6a);
	idt[0x6a].p(true);
	idt[0x6a].type(0x0e);
	idt[0x6a].segment_selector(code_segment_selector);

	idt[0x6b].offset((uint64_t)interrupt_handler_0x6b);
	idt[0x6b].p(true);
	idt[0x6b].type(0x0e);
	idt[0x6b].segment_selector(code_segment_selector);

	idt[0x6c].offset((uint64_t)interrupt_handler_0x6c);
	idt[0x6c].p(true);
	idt[0x6c].type(0x0e);
	idt[0x6c].segment_selector(code_segment_selector);

	idt[0x6d].offset((uint64_t)interrupt_handler_0x6d);
	idt[0x6d].p(true);
	idt[0x6d].type(0x0e);
	idt[0x6d].segment_selector(code_segment_selector);

	idt[0x6e].offset((uint64_t)interrupt_handler_0x6e);
	idt[0x6e].p(true);
	idt[0x6e].type(0x0e);
	idt[0x6e].segment_selector(code_segment_selector);

	idt[0x6f].offset((uint64_t)interrupt_handler_0x6f);
	idt[0x6f].p(true);
	idt[0x6f].type(0x0e);
	idt[0x6f].segment_selector(code_segment_selector);

	idt[0x70].offset((uint64_t)interrupt_handler_0x70);
	idt[0x70].p(true);
	idt[0x70].type(0x0e);
	idt[0x70].segment_selector(code_segment_selector);

	idt[0x71].offset((uint64_t)interrupt_handler_0x71);
	idt[0x71].p(true);
	idt[0x71].type(0x0e);
	idt[0x71].segment_selector(code_segment_selector);

	idt[0x72].offset((uint64_t)interrupt_handler_0x72);
	idt[0x72].p(true);
	idt[0x72].type(0x0e);
	idt[0x72].segment_selector(code_segment_selector);

	idt[0x73].offset((uint64_t)interrupt_handler_0x73);
	idt[0x73].p(true);
	idt[0x73].type(0x0e);
	idt[0x73].segment_selector(code_segment_selector);

	idt[0x74].offset((uint64_t)interrupt_handler_0x74);
	idt[0x74].p(true);
	idt[0x74].type(0x0e);
	idt[0x74].segment_selector(code_segment_selector);

	idt[0x75].offset((uint64_t)interrupt_handler_0x75);
	idt[0x75].p(true);
	idt[0x75].type(0x0e);
	idt[0x75].segment_selector(code_segment_selector);

	idt[0x76].offset((uint64_t)interrupt_handler_0x76);
	idt[0x76].p(true);
	idt[0x76].type(0x0e);
	idt[0x76].segment_selector(code_segment_selector);

	idt[0x77].offset((uint64_t)interrupt_handler_0x77);
	idt[0x77].p(true);
	idt[0x77].type(0x0e);
	idt[0x77].segment_selector(code_segment_selector);

	idt[0x78].offset((uint64_t)interrupt_handler_0x78);
	idt[0x78].p(true);
	idt[0x78].type(0x0e);
	idt[0x78].segment_selector(code_segment_selector);

	idt[0x79].offset((uint64_t)interrupt_handler_0x79);
	idt[0x79].p(true);
	idt[0x79].type(0x0e);
	idt[0x79].segment_selector(code_segment_selector);

	idt[0x7a].offset((uint64_t)interrupt_handler_0x7a);
	idt[0x7a].p(true);
	idt[0x7a].type(0x0e);
	idt[0x7a].segment_selector(code_segment_selector);

	idt[0x7b].offset((uint64_t)interrupt_handler_0x7b);
	idt[0x7b].p(true);
	idt[0x7b].type(0x0e);
	idt[0x7b].segment_selector(code_segment_selector);

	idt[0x7c].offset((uint64_t)interrupt_handler_0x7c);
	idt[0x7c].p(true);
	idt[0x7c].type(0x0e);
	idt[0x7c].segment_selector(code_segment_selector);

	idt[0x7d].offset((uint64_t)interrupt_handler_0x7d);
	idt[0x7d].p(true);
	idt[0x7d].type(0x0e);
	idt[0x7d].segment_selector(code_segment_selector);

	idt[0x7e].offset((uint64_t)interrupt_handler_0x7e);
	idt[0x7e].p(true);
	idt[0x7e].type(0x0e);
	idt[0x7e].segment_selector(code_segment_selector);

	idt[0x7f].offset((uint64_t)interrupt_handler_0x7f);
	idt[0x7f].p(true);
	idt[0x7f].type(0x0e);
	idt[0x7f].segment_selector(code_segment_selector);

	idt[0x80].offset((uint64_t)interrupt_handler_0x80);
	idt[0x80].p(true);
	idt[0x80].type(0x0e);
	idt[0x80].segment_selector(code_segment_selector);

	idt[0x81].offset((uint64_t)interrupt_handler_0x81);
	idt[0x81].p(true);
	idt[0x81].type(0x0e);
	idt[0x81].segment_selector(code_segment_selector);

	idt[0x82].offset((uint64_t)interrupt_handler_0x82);
	idt[0x82].p(true);
	idt[0x82].type(0x0e);
	idt[0x82].segment_selector(code_segment_selector);

	idt[0x83].offset((uint64_t)interrupt_handler_0x83);
	idt[0x83].p(true);
	idt[0x83].type(0x0e);
	idt[0x83].segment_selector(code_segment_selector);

	idt[0x84].offset((uint64_t)interrupt_handler_0x84);
	idt[0x84].p(true);
	idt[0x84].type(0x0e);
	idt[0x84].segment_selector(code_segment_selector);

	idt[0x85].offset((uint64_t)interrupt_handler_0x85);
	idt[0x85].p(true);
	idt[0x85].type(0x0e);
	idt[0x85].segment_selector(code_segment_selector);

	idt[0x86].offset((uint64_t)interrupt_handler_0x86);
	idt[0x86].p(true);
	idt[0x86].type(0x0e);
	idt[0x86].segment_selector(code_segment_selector);

	idt[0x87].offset((uint64_t)interrupt_handler_0x87);
	idt[0x87].p(true);
	idt[0x87].type(0x0e);
	idt[0x87].segment_selector(code_segment_selector);

	idt[0x88].offset((uint64_t)interrupt_handler_0x88);
	idt[0x88].p(true);
	idt[0x88].type(0x0e);
	idt[0x88].segment_selector(code_segment_selector);

	idt[0x89].offset((uint64_t)interrupt_handler_0x89);
	idt[0x89].p(true);
	idt[0x89].type(0x0e);
	idt[0x89].segment_selector(code_segment_selector);

	idt[0x8a].offset((uint64_t)interrupt_handler_0x8a);
	idt[0x8a].p(true);
	idt[0x8a].type(0x0e);
	idt[0x8a].segment_selector(code_segment_selector);

	idt[0x8b].offset((uint64_t)interrupt_handler_0x8b);
	idt[0x8b].p(true);
	idt[0x8b].type(0x0e);
	idt[0x8b].segment_selector(code_segment_selector);

	idt[0x8c].offset((uint64_t)interrupt_handler_0x8c);
	idt[0x8c].p(true);
	idt[0x8c].type(0x0e);
	idt[0x8c].segment_selector(code_segment_selector);

	idt[0x8d].offset((uint64_t)interrupt_handler_0x8d);
	idt[0x8d].p(true);
	idt[0x8d].type(0x0e);
	idt[0x8d].segment_selector(code_segment_selector);

	idt[0x8e].offset((uint64_t)interrupt_handler_0x8e);
	idt[0x8e].p(true);
	idt[0x8e].type(0x0e);
	idt[0x8e].segment_selector(code_segment_selector);

	idt[0x8f].offset((uint64_t)interrupt_handler_0x8f);
	idt[0x8f].p(true);
	idt[0x8f].type(0x0e);
	idt[0x8f].segment_selector(code_segment_selector);

	idt[0x90].offset((uint64_t)interrupt_handler_0x90);
	idt[0x90].p(true);
	idt[0x90].type(0x0e);
	idt[0x90].segment_selector(code_segment_selector);

	idt[0x91].offset((uint64_t)interrupt_handler_0x91);
	idt[0x91].p(true);
	idt[0x91].type(0x0e);
	idt[0x91].segment_selector(code_segment_selector);

	idt[0x92].offset((uint64_t)interrupt_handler_0x92);
	idt[0x92].p(true);
	idt[0x92].type(0x0e);
	idt[0x92].segment_selector(code_segment_selector);

	idt[0x93].offset((uint64_t)interrupt_handler_0x93);
	idt[0x93].p(true);
	idt[0x93].type(0x0e);
	idt[0x93].segment_selector(code_segment_selector);

	idt[0x94].offset((uint64_t)interrupt_handler_0x94);
	idt[0x94].p(true);
	idt[0x94].type(0x0e);
	idt[0x94].segment_selector(code_segment_selector);

	idt[0x95].offset((uint64_t)interrupt_handler_0x95);
	idt[0x95].p(true);
	idt[0x95].type(0x0e);
	idt[0x95].segment_selector(code_segment_selector);

	idt[0x96].offset((uint64_t)interrupt_handler_0x96);
	idt[0x96].p(true);
	idt[0x96].type(0x0e);
	idt[0x96].segment_selector(code_segment_selector);

	idt[0x97].offset((uint64_t)interrupt_handler_0x97);
	idt[0x97].p(true);
	idt[0x97].type(0x0e);
	idt[0x97].segment_selector(code_segment_selector);

	idt[0x98].offset((uint64_t)interrupt_handler_0x98);
	idt[0x98].p(true);
	idt[0x98].type(0x0e);
	idt[0x98].segment_selector(code_segment_selector);

	idt[0x99].offset((uint64_t)interrupt_handler_0x99);
	idt[0x99].p(true);
	idt[0x99].type(0x0e);
	idt[0x99].segment_selector(code_segment_selector);

	idt[0x9a].offset((uint64_t)interrupt_handler_0x9a);
	idt[0x9a].p(true);
	idt[0x9a].type(0x0e);
	idt[0x9a].segment_selector(code_segment_selector);

	idt[0x9b].offset((uint64_t)interrupt_handler_0x9b);
	idt[0x9b].p(true);
	idt[0x9b].type(0x0e);
	idt[0x9b].segment_selector(code_segment_selector);

	idt[0x9c].offset((uint64_t)interrupt_handler_0x9c);
	idt[0x9c].p(true);
	idt[0x9c].type(0x0e);
	idt[0x9c].segment_selector(code_segment_selector);

	idt[0x9d].offset((uint64_t)interrupt_handler_0x9d);
	idt[0x9d].p(true);
	idt[0x9d].type(0x0e);
	idt[0x9d].segment_selector(code_segment_selector);

	idt[0x9e].offset((uint64_t)interrupt_handler_0x9e);
	idt[0x9e].p(true);
	idt[0x9e].type(0x0e);
	idt[0x9e].segment_selector(code_segment_selector);

	idt[0x9f].offset((uint64_t)interrupt_handler_0x9f);
	idt[0x9f].p(true);
	idt[0x9f].type(0x0e);
	idt[0x9f].segment_selector(code_segment_selector);

	idt[0xa0].offset((uint64_t)interrupt_handler_0xa0);
	idt[0xa0].p(true);
	idt[0xa0].type(0x0e);
	idt[0xa0].segment_selector(code_segment_selector);

	idt[0xa1].offset((uint64_t)interrupt_handler_0xa1);
	idt[0xa1].p(true);
	idt[0xa1].type(0x0e);
	idt[0xa1].segment_selector(code_segment_selector);

	idt[0xa2].offset((uint64_t)interrupt_handler_0xa2);
	idt[0xa2].p(true);
	idt[0xa2].type(0x0e);
	idt[0xa2].segment_selector(code_segment_selector);

	idt[0xa3].offset((uint64_t)interrupt_handler_0xa3);
	idt[0xa3].p(true);
	idt[0xa3].type(0x0e);
	idt[0xa3].segment_selector(code_segment_selector);

	idt[0xa4].offset((uint64_t)interrupt_handler_0xa4);
	idt[0xa4].p(true);
	idt[0xa4].type(0x0e);
	idt[0xa4].segment_selector(code_segment_selector);

	idt[0xa5].offset((uint64_t)interrupt_handler_0xa5);
	idt[0xa5].p(true);
	idt[0xa5].type(0x0e);
	idt[0xa5].segment_selector(code_segment_selector);

	idt[0xa6].offset((uint64_t)interrupt_handler_0xa6);
	idt[0xa6].p(true);
	idt[0xa6].type(0x0e);
	idt[0xa6].segment_selector(code_segment_selector);

	idt[0xa7].offset((uint64_t)interrupt_handler_0xa7);
	idt[0xa7].p(true);
	idt[0xa7].type(0x0e);
	idt[0xa7].segment_selector(code_segment_selector);

	idt[0xa8].offset((uint64_t)interrupt_handler_0xa8);
	idt[0xa8].p(true);
	idt[0xa8].type(0x0e);
	idt[0xa8].segment_selector(code_segment_selector);

	idt[0xa9].offset((uint64_t)interrupt_handler_0xa9);
	idt[0xa9].p(true);
	idt[0xa9].type(0x0e);
	idt[0xa9].segment_selector(code_segment_selector);

	idt[0xaa].offset((uint64_t)interrupt_handler_0xaa);
	idt[0xaa].p(true);
	idt[0xaa].type(0x0e);
	idt[0xaa].segment_selector(code_segment_selector);

	idt[0xab].offset((uint64_t)interrupt_handler_0xab);
	idt[0xab].p(true);
	idt[0xab].type(0x0e);
	idt[0xab].segment_selector(code_segment_selector);

	idt[0xac].offset((uint64_t)interrupt_handler_0xac);
	idt[0xac].p(true);
	idt[0xac].type(0x0e);
	idt[0xac].segment_selector(code_segment_selector);

	idt[0xad].offset((uint64_t)interrupt_handler_0xad);
	idt[0xad].p(true);
	idt[0xad].type(0x0e);
	idt[0xad].segment_selector(code_segment_selector);

	idt[0xae].offset((uint64_t)interrupt_handler_0xae);
	idt[0xae].p(true);
	idt[0xae].type(0x0e);
	idt[0xae].segment_selector(code_segment_selector);

	idt[0xaf].offset((uint64_t)interrupt_handler_0xaf);
	idt[0xaf].p(true);
	idt[0xaf].type(0x0e);
	idt[0xaf].segment_selector(code_segment_selector);

	idt[0xb0].offset((uint64_t)interrupt_handler_0xb0);
	idt[0xb0].p(true);
	idt[0xb0].type(0x0e);
	idt[0xb0].segment_selector(code_segment_selector);

	idt[0xb1].offset((uint64_t)interrupt_handler_0xb1);
	idt[0xb1].p(true);
	idt[0xb1].type(0x0e);
	idt[0xb1].segment_selector(code_segment_selector);

	idt[0xb2].offset((uint64_t)interrupt_handler_0xb2);
	idt[0xb2].p(true);
	idt[0xb2].type(0x0e);
	idt[0xb2].segment_selector(code_segment_selector);

	idt[0xb3].offset((uint64_t)interrupt_handler_0xb3);
	idt[0xb3].p(true);
	idt[0xb3].type(0x0e);
	idt[0xb3].segment_selector(code_segment_selector);

	idt[0xb4].offset((uint64_t)interrupt_handler_0xb4);
	idt[0xb4].p(true);
	idt[0xb4].type(0x0e);
	idt[0xb4].segment_selector(code_segment_selector);

	idt[0xb5].offset((uint64_t)interrupt_handler_0xb5);
	idt[0xb5].p(true);
	idt[0xb5].type(0x0e);
	idt[0xb5].segment_selector(code_segment_selector);

	idt[0xb6].offset((uint64_t)interrupt_handler_0xb6);
	idt[0xb6].p(true);
	idt[0xb6].type(0x0e);
	idt[0xb6].segment_selector(code_segment_selector);

	idt[0xb7].offset((uint64_t)interrupt_handler_0xb7);
	idt[0xb7].p(true);
	idt[0xb7].type(0x0e);
	idt[0xb7].segment_selector(code_segment_selector);

	idt[0xb8].offset((uint64_t)interrupt_handler_0xb8);
	idt[0xb8].p(true);
	idt[0xb8].type(0x0e);
	idt[0xb8].segment_selector(code_segment_selector);

	idt[0xb9].offset((uint64_t)interrupt_handler_0xb9);
	idt[0xb9].p(true);
	idt[0xb9].type(0x0e);
	idt[0xb9].segment_selector(code_segment_selector);

	idt[0xba].offset((uint64_t)interrupt_handler_0xba);
	idt[0xba].p(true);
	idt[0xba].type(0x0e);
	idt[0xba].segment_selector(code_segment_selector);

	idt[0xbb].offset((uint64_t)interrupt_handler_0xbb);
	idt[0xbb].p(true);
	idt[0xbb].type(0x0e);
	idt[0xbb].segment_selector(code_segment_selector);

	idt[0xbc].offset((uint64_t)interrupt_handler_0xbc);
	idt[0xbc].p(true);
	idt[0xbc].type(0x0e);
	idt[0xbc].segment_selector(code_segment_selector);

	idt[0xbd].offset((uint64_t)interrupt_handler_0xbd);
	idt[0xbd].p(true);
	idt[0xbd].type(0x0e);
	idt[0xbd].segment_selector(code_segment_selector);

	idt[0xbe].offset((uint64_t)interrupt_handler_0xbe);
	idt[0xbe].p(true);
	idt[0xbe].type(0x0e);
	idt[0xbe].segment_selector(code_segment_selector);

	idt[0xbf].offset((uint64_t)interrupt_handler_0xbf);
	idt[0xbf].p(true);
	idt[0xbf].type(0x0e);
	idt[0xbf].segment_selector(code_segment_selector);

	idt[0xc0].offset((uint64_t)interrupt_handler_0xc0);
	idt[0xc0].p(true);
	idt[0xc0].type(0x0e);
	idt[0xc0].segment_selector(code_segment_selector);

	idt[0xc1].offset((uint64_t)interrupt_handler_0xc1);
	idt[0xc1].p(true);
	idt[0xc1].type(0x0e);
	idt[0xc1].segment_selector(code_segment_selector);

	idt[0xc2].offset((uint64_t)interrupt_handler_0xc2);
	idt[0xc2].p(true);
	idt[0xc2].type(0x0e);
	idt[0xc2].segment_selector(code_segment_selector);

	idt[0xc3].offset((uint64_t)interrupt_handler_0xc3);
	idt[0xc3].p(true);
	idt[0xc3].type(0x0e);
	idt[0xc3].segment_selector(code_segment_selector);

	idt[0xc4].offset((uint64_t)interrupt_handler_0xc4);
	idt[0xc4].p(true);
	idt[0xc4].type(0x0e);
	idt[0xc4].segment_selector(code_segment_selector);

	idt[0xc5].offset((uint64_t)interrupt_handler_0xc5);
	idt[0xc5].p(true);
	idt[0xc5].type(0x0e);
	idt[0xc5].segment_selector(code_segment_selector);

	idt[0xc6].offset((uint64_t)interrupt_handler_0xc6);
	idt[0xc6].p(true);
	idt[0xc6].type(0x0e);
	idt[0xc6].segment_selector(code_segment_selector);

	idt[0xc7].offset((uint64_t)interrupt_handler_0xc7);
	idt[0xc7].p(true);
	idt[0xc7].type(0x0e);
	idt[0xc7].segment_selector(code_segment_selector);

	idt[0xc8].offset((uint64_t)interrupt_handler_0xc8);
	idt[0xc8].p(true);
	idt[0xc8].type(0x0e);
	idt[0xc8].segment_selector(code_segment_selector);

	idt[0xc9].offset((uint64_t)interrupt_handler_0xc9);
	idt[0xc9].p(true);
	idt[0xc9].type(0x0e);
	idt[0xc9].segment_selector(code_segment_selector);

	idt[0xca].offset((uint64_t)interrupt_handler_0xca);
	idt[0xca].p(true);
	idt[0xca].type(0x0e);
	idt[0xca].segment_selector(code_segment_selector);

	idt[0xcb].offset((uint64_t)interrupt_handler_0xcb);
	idt[0xcb].p(true);
	idt[0xcb].type(0x0e);
	idt[0xcb].segment_selector(code_segment_selector);

	idt[0xcc].offset((uint64_t)interrupt_handler_0xcc);
	idt[0xcc].p(true);
	idt[0xcc].type(0x0e);
	idt[0xcc].segment_selector(code_segment_selector);

	idt[0xcd].offset((uint64_t)interrupt_handler_0xcd);
	idt[0xcd].p(true);
	idt[0xcd].type(0x0e);
	idt[0xcd].segment_selector(code_segment_selector);

	idt[0xce].offset((uint64_t)interrupt_handler_0xce);
	idt[0xce].p(true);
	idt[0xce].type(0x0e);
	idt[0xce].segment_selector(code_segment_selector);

	idt[0xcf].offset((uint64_t)interrupt_handler_0xcf);
	idt[0xcf].p(true);
	idt[0xcf].type(0x0e);
	idt[0xcf].segment_selector(code_segment_selector);

	idt[0xd0].offset((uint64_t)interrupt_handler_0xd0);
	idt[0xd0].p(true);
	idt[0xd0].type(0x0e);
	idt[0xd0].segment_selector(code_segment_selector);

	idt[0xd1].offset((uint64_t)interrupt_handler_0xd1);
	idt[0xd1].p(true);
	idt[0xd1].type(0x0e);
	idt[0xd1].segment_selector(code_segment_selector);

	idt[0xd2].offset((uint64_t)interrupt_handler_0xd2);
	idt[0xd2].p(true);
	idt[0xd2].type(0x0e);
	idt[0xd2].segment_selector(code_segment_selector);

	idt[0xd3].offset((uint64_t)interrupt_handler_0xd3);
	idt[0xd3].p(true);
	idt[0xd3].type(0x0e);
	idt[0xd3].segment_selector(code_segment_selector);

	idt[0xd4].offset((uint64_t)interrupt_handler_0xd4);
	idt[0xd4].p(true);
	idt[0xd4].type(0x0e);
	idt[0xd4].segment_selector(code_segment_selector);

	idt[0xd5].offset((uint64_t)interrupt_handler_0xd5);
	idt[0xd5].p(true);
	idt[0xd5].type(0x0e);
	idt[0xd5].segment_selector(code_segment_selector);

	idt[0xd6].offset((uint64_t)interrupt_handler_0xd6);
	idt[0xd6].p(true);
	idt[0xd6].type(0x0e);
	idt[0xd6].segment_selector(code_segment_selector);

	idt[0xd7].offset((uint64_t)interrupt_handler_0xd7);
	idt[0xd7].p(true);
	idt[0xd7].type(0x0e);
	idt[0xd7].segment_selector(code_segment_selector);

	idt[0xd8].offset((uint64_t)interrupt_handler_0xd8);
	idt[0xd8].p(true);
	idt[0xd8].type(0x0e);
	idt[0xd8].segment_selector(code_segment_selector);

	idt[0xd9].offset((uint64_t)interrupt_handler_0xd9);
	idt[0xd9].p(true);
	idt[0xd9].type(0x0e);
	idt[0xd9].segment_selector(code_segment_selector);

	idt[0xda].offset((uint64_t)interrupt_handler_0xda);
	idt[0xda].p(true);
	idt[0xda].type(0x0e);
	idt[0xda].segment_selector(code_segment_selector);

	idt[0xdb].offset((uint64_t)interrupt_handler_0xdb);
	idt[0xdb].p(true);
	idt[0xdb].type(0x0e);
	idt[0xdb].segment_selector(code_segment_selector);

	idt[0xdc].offset((uint64_t)interrupt_handler_0xdc);
	idt[0xdc].p(true);
	idt[0xdc].type(0x0e);
	idt[0xdc].segment_selector(code_segment_selector);

	idt[0xdd].offset((uint64_t)interrupt_handler_0xdd);
	idt[0xdd].p(true);
	idt[0xdd].type(0x0e);
	idt[0xdd].segment_selector(code_segment_selector);

	idt[0xde].offset((uint64_t)interrupt_handler_0xde);
	idt[0xde].p(true);
	idt[0xde].type(0x0e);
	idt[0xde].segment_selector(code_segment_selector);

	idt[0xdf].offset((uint64_t)interrupt_handler_0xdf);
	idt[0xdf].p(true);
	idt[0xdf].type(0x0e);
	idt[0xdf].segment_selector(code_segment_selector);

	idt[0xe0].offset((uint64_t)interrupt_handler_0xe0);
	idt[0xe0].p(true);
	idt[0xe0].type(0x0e);
	idt[0xe0].segment_selector(code_segment_selector);

	idt[0xe1].offset((uint64_t)interrupt_handler_0xe1);
	idt[0xe1].p(true);
	idt[0xe1].type(0x0e);
	idt[0xe1].segment_selector(code_segment_selector);

	idt[0xe2].offset((uint64_t)interrupt_handler_0xe2);
	idt[0xe2].p(true);
	idt[0xe2].type(0x0e);
	idt[0xe2].segment_selector(code_segment_selector);

	idt[0xe3].offset((uint64_t)interrupt_handler_0xe3);
	idt[0xe3].p(true);
	idt[0xe3].type(0x0e);
	idt[0xe3].segment_selector(code_segment_selector);

	idt[0xe4].offset((uint64_t)interrupt_handler_0xe4);
	idt[0xe4].p(true);
	idt[0xe4].type(0x0e);
	idt[0xe4].segment_selector(code_segment_selector);

	idt[0xe5].offset((uint64_t)interrupt_handler_0xe5);
	idt[0xe5].p(true);
	idt[0xe5].type(0x0e);
	idt[0xe5].segment_selector(code_segment_selector);

	idt[0xe6].offset((uint64_t)interrupt_handler_0xe6);
	idt[0xe6].p(true);
	idt[0xe6].type(0x0e);
	idt[0xe6].segment_selector(code_segment_selector);

	idt[0xe7].offset((uint64_t)interrupt_handler_0xe7);
	idt[0xe7].p(true);
	idt[0xe7].type(0x0e);
	idt[0xe7].segment_selector(code_segment_selector);

	idt[0xe8].offset((uint64_t)interrupt_handler_0xe8);
	idt[0xe8].p(true);
	idt[0xe8].type(0x0e);
	idt[0xe8].segment_selector(code_segment_selector);

	idt[0xe9].offset((uint64_t)interrupt_handler_0xe9);
	idt[0xe9].p(true);
	idt[0xe9].type(0x0e);
	idt[0xe9].segment_selector(code_segment_selector);

	idt[0xea].offset((uint64_t)interrupt_handler_0xea);
	idt[0xea].p(true);
	idt[0xea].type(0x0e);
	idt[0xea].segment_selector(code_segment_selector);

	idt[0xeb].offset((uint64_t)interrupt_handler_0xeb);
	idt[0xeb].p(true);
	idt[0xeb].type(0x0e);
	idt[0xeb].segment_selector(code_segment_selector);

	idt[0xec].offset((uint64_t)interrupt_handler_0xec);
	idt[0xec].p(true);
	idt[0xec].type(0x0e);
	idt[0xec].segment_selector(code_segment_selector);

	idt[0xed].offset((uint64_t)interrupt_handler_0xed);
	idt[0xed].p(true);
	idt[0xed].type(0x0e);
	idt[0xed].segment_selector(code_segment_selector);

	idt[0xee].offset((uint64_t)interrupt_handler_0xee);
	idt[0xee].p(true);
	idt[0xee].type(0x0e);
	idt[0xee].segment_selector(code_segment_selector);

	idt[0xef].offset((uint64_t)interrupt_handler_0xef);
	idt[0xef].p(true);
	idt[0xef].type(0x0e);
	idt[0xef].segment_selector(code_segment_selector);

	idt[0xf0].offset((uint64_t)interrupt_handler_0xf0);
	idt[0xf0].p(true);
	idt[0xf0].type(0x0e);
	idt[0xf0].segment_selector(code_segment_selector);

	idt[0xf1].offset((uint64_t)interrupt_handler_0xf1);
	idt[0xf1].p(true);
	idt[0xf1].type(0x0e);
	idt[0xf1].segment_selector(code_segment_selector);

	idt[0xf2].offset((uint64_t)interrupt_handler_0xf2);
	idt[0xf2].p(true);
	idt[0xf2].type(0x0e);
	idt[0xf2].segment_selector(code_segment_selector);

	idt[0xf3].offset((uint64_t)interrupt_handler_0xf3);
	idt[0xf3].p(true);
	idt[0xf3].type(0x0e);
	idt[0xf3].segment_selector(code_segment_selector);

	idt[0xf4].offset((uint64_t)interrupt_handler_0xf4);
	idt[0xf4].p(true);
	idt[0xf4].type(0x0e);
	idt[0xf4].segment_selector(code_segment_selector);

	idt[0xf5].offset((uint64_t)interrupt_handler_0xf5);
	idt[0xf5].p(true);
	idt[0xf5].type(0x0e);
	idt[0xf5].segment_selector(code_segment_selector);

	idt[0xf6].offset((uint64_t)interrupt_handler_0xf6);
	idt[0xf6].p(true);
	idt[0xf6].type(0x0e);
	idt[0xf6].segment_selector(code_segment_selector);

	idt[0xf7].offset((uint64_t)interrupt_handler_0xf7);
	idt[0xf7].p(true);
	idt[0xf7].type(0x0e);
	idt[0xf7].segment_selector(code_segment_selector);

	idt[0xf8].offset((uint64_t)interrupt_handler_0xf8);
	idt[0xf8].p(true);
	idt[0xf8].type(0x0e);
	idt[0xf8].segment_selector(code_segment_selector);

	idt[0xf9].offset((uint64_t)interrupt_handler_0xf9);
	idt[0xf9].p(true);
	idt[0xf9].type(0x0e);
	idt[0xf9].segment_selector(code_segment_selector);

	idt[0xfa].offset((uint64_t)interrupt_handler_0xfa);
	idt[0xfa].p(true);
	idt[0xfa].type(0x0e);
	idt[0xfa].segment_selector(code_segment_selector);

	idt[0xfb].offset((uint64_t)interrupt_handler_0xfb);
	idt[0xfb].p(true);
	idt[0xfb].type(0x0e);
	idt[0xfb].segment_selector(code_segment_selector);

	idt[0xfc].offset((uint64_t)interrupt_handler_0xfc);
	idt[0xfc].p(true);
	idt[0xfc].type(0x0e);
	idt[0xfc].segment_selector(code_segment_selector);

	idt[0xfd].offset((uint64_t)interrupt_handler_0xfd);
	idt[0xfd].p(true);
	idt[0xfd].type(0x0e);
	idt[0xfd].segment_selector(code_segment_selector);

	idt[0xfe].offset((uint64_t)interrupt_handler_0xfe);
	idt[0xfe].p(true);
	idt[0xfe].type(0x0e);
	idt[0xfe].segment_selector(code_segment_selector);

	idt[0xff].offset((uint64_t)interrupt_handler_0xff);
	idt[0xff].p(true);
	idt[0xff].type(0x0e);
	idt[0xff].segment_selector(code_segment_selector);

}

