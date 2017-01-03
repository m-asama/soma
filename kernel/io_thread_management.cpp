/**
 * @file	io_thread_management.cpp
 * @brief	I/O スレッド管理の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "processor_management.h"
#include "utf8str.h"

#include "intel64_assembly.h"

extern "C" void io_thread_main();

void
io_thread_main()
{
	while (true) {

		utf8str x("I I: 0x");
		x.append_hex64(processor_id(), 2);
		x += " CR3:0x";
		x.append_hex64((uint64_t)cr3(), 16);
		x += " RSP:0x";
		x.append_hex64((uint64_t)rsp(), 16);
		x += "\n";
		printstr(x);

		idle();
	}
}

