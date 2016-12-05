/**
 * @file	main.cpp
 * @brief	テストのメイン。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include <iostream>

#include "loader_info.h"
#include "memory_management.h"
#include "font.h"
#include "utf8str.h"
#include "unicode.h"

#include "linked_list_test.h"
#include "sorted_list_test.h"
#include "hash_table_test.h"
#include "memory_pool_test.h"
#include "memory_block_test.h"

#include "main.h"

// 256MB + 4kB
unsigned char mem[4096 * 65537];

struct li_memdesc mds = {
	.md_type		= 7,
	.md_phys_start		= 0,
	.md_virt_start		= 0,
	.md_num_of_pages	= 65536,
	.md_attr		= 0,
};

struct loader_info li = {
	.mm_mds			= &mds,
	.mm_num_of_mds		= 1,
};

struct test_module {
	char const *name;
	void (*func)();
} test_modules[] = {
	{
		.name	= "リンクリスト",
		.func	= linked_list_test,
	},
	{
		.name	= "整列リスト",
		.func	= sorted_list_test,
	},
	{
		.name	= "ハッシュテーブル",
		.func	= hash_table_test,
	},
	{
		.name	= "メモリプール",
		.func	= memory_pool_test,
	},
	{
		.name	= "メモリブロック",
		.func	= memory_block_test,
	},
	{
		.func	= nullptr,
	},
};

int test_pass	= 0;
int test_fail	= 0;

int
main(int argc, char *argv[])
{
	li.mm_mds[0].md_phys_start = ((unsigned long long)&mem) >> 12;
	li.mm_mds[0].md_phys_start++;
	li.mm_mds[0].md_phys_start = li.mm_mds[0].md_phys_start << 12;
	memory_init(&li);
	font_init();

	std::cout << std::endl;

	for (struct test_module *test_module = test_modules;
	    test_module->func; ++test_module) {
		std::cout << "  o " << test_module->name << std::endl;
		test_module->func();
	}

	std::cout << std::endl;

	utf8str pass_s;
	pass_s.append_uint64(test_pass, 8);
	std::cout << "            PASS" << pass_s.ptr() << std::endl;

	utf8str fail_s;
	fail_s.append_uint64(test_fail, 8);
	std::cout << "            FAIL" << fail_s.ptr() << std::endl;

	std::cout << std::endl;

	return 0;
}

void
print_test_result(char const *name, test_result res)
{
	utf8str n(name);
	int w = n.width();
	std::cout << "      * " << n.ptr() << " ";
	for (int i = (62 - w); i > 0; --i) { std::cout << "."; }
	switch (res) {
	case test_result::pass:
		std::cout << " [PASS]";
		++test_pass;
		break;
	case test_result::fail:
		std::cout << " [FAIL]";
		++test_fail;
		break;
	}
	std::cout << std::endl;
}

void
console_putchar(unsigned int c)
{
	char utf8str[8];
	unicode_to_utf8(&c, utf8str);
	std::cout << utf8str;
}

extern "C" int atexit(void (*func)(void));

int
atexit(void (*func)(void))
{
	return 0;
}

extern "C" void __cxa_pure_virtual(void);

void
__cxa_pure_virtual(void) {
}

extern "C" void __cxa_deleted_virtual(void);

void
__cxa_deleted_virtual(void) {
}

