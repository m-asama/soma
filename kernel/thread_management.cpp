/**
 * @file	thread_management.cpp
 * @brief	スレッド管理の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "thread.h"
#include "sorted_list.h"
#include "string.h"
#include "processor_management.h"

#include "intel64_assembly.h"

static sorted_list<thread> *threads = nullptr;

extern "C" void io_thread_main();

void
io_thread_main()
{
	while (1) {
//		printhex8(processor_id()); printstr(": ");
//		printhex64(cr3()); printstr(": ");
//		printhex64(rsp()); printstr(":\n");

		processor_base *processor = processor_current();
		if (processor == nullptr) {
			printstr("processor() が取得できませんでした。\n");
			panic();
		}
		
		idle();
	}
}

void
thread_init()
{
	threads = new sorted_list<thread>;

	if (threads == nullptr) {
		printstr("スレッドの初期化に失敗しました。");
		panic();
	}
}

thread *
thread_alloc(void (*main)())
{
	thread *new_thread = nullptr;
	string new_thread_name;
	bidir_node<thread> *bn;
	uint64_t id;

	id = 0;
	for (bn = threads->head(); bn != nullptr; bn = bn->next()) {
		if (id != bn->v().id()) {
			break;
		}
		++id;
	}

	new_thread_name = "thread/";
	new_thread_name.append_uint64(id, 0);

	new_thread = new thread(main);
	if (new_thread != nullptr) {
		new_thread->init(id, new_thread_name);
		threads->insert(*new_thread);
	}
	return new_thread;
}

void
thread_free(thread *ptr)
{
	threads->remove(*ptr);
	delete ptr;
}

void
thread_dump()
{
	bidir_node<thread> *bn;
	for (bn = threads->head(); bn != nullptr; bn = bn->next()) {
		bn->v().dump();
	}
}

