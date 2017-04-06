/**
 * @file	intel64_processor_state.cpp
 * @brief	Intel64 CPU の状態を格納するクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"
#include "memory_management.h"

#include "intel64_processor_state.h"

intel64_processor_state::intel64_processor_state()
{
	m_pml4_table = nullptr;
	m_stack_pointer = 0x0000000000000000ul;
}

intel64_processor_state::~intel64_processor_state()
{
	pml4_table_free(m_pml4_table);
	m_pml4_table = nullptr;
	m_stack_pointer = 0x0000000000000000ul;
}

int
intel64_processor_state::init(uint64_t thread_main, uint64_t thread_arg)
{
	intel64_pd_table *pdt = nullptr;
	intel64_pdpt_table *pdptt = nullptr;
	void *page = nullptr;
	uint64_t pt;

	pdt = new intel64_pd_table;
	if (pdt == nullptr) {
		return -1;
	}

	page = memory_alloc_page_lo(memory_page_size::page_size_2m, 1);
	if (page == nullptr) {
		delete pdt;
		return -1;
	}

	m_pml4_table = pml4_table_alloc();
	if (m_pml4_table == nullptr) {
		delete pdt;
		memory_free(page);
		return -1;
	}
	pt = (uint64_t)m_pml4_table->get_page_table();

	(*pdt)[511].page_frame_address((uint64_t)page);
	(*pdt)[511].present(true);
	(*pdt)[511].read_write(true);
	(*pdt)[511].page_size(true);

	pdptt = m_pml4_table->pdpt_table_at(0);
	(*pdptt)[511].pd_table_address((uint64_t)pdt->get_page_table());
	(*pdptt)[511].present(true);
	(*pdptt)[511].read_write(true);
	pdptt->pd_table_at(511, pdt);
	m_stack_pointer = 0x0000007ffffffff8ul;

	m_processor_state.cr3 = (uint64_t)m_pml4_table->get_page_table();
	m_processor_state.ss = 0x0000000000000010;
	m_processor_state.rsp = m_stack_pointer;
	m_processor_state.rflags = 0x0000000000000202;
	m_processor_state.cs = 0x0000000000000008;
	m_processor_state.rip = thread_main;
	m_processor_state.rdi = thread_arg;

	return 0;
}

/*
void
intel64_processor_state::backup(uint64_t *processor_state)
{
}
*/

/*
void
intel64_processor_state::restore(uint64_t *processor_state)
{
}
*/

void
intel64_processor_state::dump()
{
	print("stack_pointer:\n");
	print("    "); printhex64(m_stack_pointer); print("\n");
	print("pml4_table:\n");
	uint64_t prev[4];
	uint64_t x[4];
	uint64_t *p[4];
	prev[0] = prev[1] = prev[2] = prev[3] = 0x1ul;
	x[0] = (uint64_t)m_pml4_table->get_page_table();;
	//print("x[0] = "); printhex64(x[0]); print("\n");
	p[0] = (uint64_t *)(x[0] & 0x0000fffffffff000ul);
	for (int i = 0; i < 512; ++i) {
		x[0] = p[0][i];
		//print("x[0] = "); printhex64(x[0]); print("\n");
		if (x[0] & 0x1) {
			p[1] = (uint64_t *)(x[0] & 0x0000fffffffff000ul);
			for (int j = 0; j < 512; ++j) {
				x[1] = p[1][j];
				if (x[1] & 0x1) {
					p[2] = (uint64_t *)(x[1] & 0x0000fffffffff000ul);
					for (int k = 0; k < 512; ++k) {
						x[2] = p[2][k];
						if ((k == 0) || (k == 511) || (prev[2] != (x[2] & 0x1))) {
						//if (j == 63) {
						//if (x[2] & 0x0000000000000010ul) {
							printhex16(i); putchar(' ');
							printhex64(x[0]); putchar(' ');
							printhex16(j); putchar(' ');
							printhex64(x[1]); putchar(' ');
							printhex16(k); putchar(' ');
							printhex64(x[2]); putchar(' ');
							putchar('\n');
						}
						prev[2] = x[2] & 0x1;
					}
				}
				prev[1] = x[1] & 0x1;
			}
		}
		prev[0] = x[0] & 0x1;
	}
}

intel64_pml4_table *
intel64_processor_state::pml4_table()
{
	return m_pml4_table;
}


uint64_t
intel64_processor_state::page_table()
{
	uint64_t page_table = 0;
	if (m_pml4_table != nullptr) {
		page_table = (uint64_t)m_pml4_table->get_page_table();
	}
	return page_table;
}

uint64_t
intel64_processor_state::stack_pointer()
{
	return m_stack_pointer;
}

void *
intel64_processor_state::processor_state_address()
{
	return (void *)&m_processor_state;
}
