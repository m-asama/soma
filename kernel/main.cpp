/**
 * @file	main.cpp
 * @brief	ソーマ・カーネルのエントリーポイントとなる main 関数を定義。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "utf8str.h"
#include "print.h"
#include "memory_management.h"
#include "font.h"
#include "console_management.h"
#include "acpi.h"
#include "processor_management.h"
#include "irqchip_management.h"
#include "pci_management.h"
#include "thread_management.h"
#include "config_management.h"
#include "command_management.h"

#include "loader_info.h"

extern "C" void main(void *ptr);

/**
 * エントリーポイント。
 * @param ptr ブートローダから渡される loader_info 構造体を指す。
 * @return 何も返さない。
 */
void
main(void *ptr)
{
	struct loader_info *li = (struct loader_info *)ptr;

//	disable_interrupt();

	memory_init(li);

	font_init();

	console_init1(li);

	thread_init();

	acpi_init(li);

	irqchip_init();

	processor_init(li);

	console_init2();

	pci_init();

	config_init();
	command_init();

	processor_dump();
	irqchip_dump();
	thread_dump();

//	memory_dump();
	memory_stats();

	printstr("日本語のテスト\n");

	printstr("End of main...\n");

	processor_start();
}

extern "C" int atexit(void (*func)(void));

/**
 * exit の際に実行されるコールバック関数を設定するための関数。
 * 何もしない。
 * @param func コールバックされる関数へのポインタ。
 * @return 何もせず 0 を返す。
 */
int
atexit(void (*func)(void))
{
	return 0;
}

extern "C" void __cxa_pure_virtual(void);

/**
 *
 */
void
__cxa_pure_virtual(void) {
}

extern "C" void __cxa_deleted_virtual(void);

/**
 *
 */
void
__cxa_deleted_virtual(void) {
}

