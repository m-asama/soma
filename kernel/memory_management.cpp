/**
 * @file	memory_management.cpp
 * @brief	メモリ管理に関連する関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"
#include "memory_management.h"
#include "sorted_list.h"
#include "hash_table.h"
#include "memory_block.h"

#include "loader_info.h"

static sorted_list<memory_block> free_block;
static hash_table<memory_block> alloc_block(memory_block_hash, memory_block_equal);

void *
memory_alloc(size_t size)
{
	void *ptr;
	bidir_node<memory_block> *bn;
	memory_block *mb;

	//printstr("memory_alloc\n");

	if (size & 0x7) {
		size &= ~ 0x7;
		size += 0x8;
	}

	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		if (bn->v().size() >= size)
			break;
	}

	if (bn == nullptr)
		return nullptr;

	ptr = (void *)bn->v().base();
	bn->v().base(bn->v().base() + size);
	bn->v().size(bn->v().size() - size);

	if (bn->v().size() == 0) {
		memory_block *tmp = &bn->v();
		free_block.remove(bn->v());
		delete tmp;
	}

	mb = new memory_block((uint64_t)ptr, size);
	alloc_block.insert(*mb);

	return ptr;
}

void
memory_free(void *ptr)
{
	memory_block key((uint64_t)ptr, 0ul);
	memory_block *mb;
	bidir_node<memory_block> *bn;
	char *cp;
	int i;

	//printstr("memory_free\n");

	mb = alloc_block.find(key);
	if (mb == nullptr)
		return;

	alloc_block.remove(*mb);
	free_block.insert(*mb);

	// XXX:
	cp = (char *)mb->base();
	for (i = 0; i < mb->size(); ++i) {
		cp[i] = 0;
	}

retry:
	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		if (bn->next() == nullptr)
			break;
		if (bn->v().base() > (uint64_t)ptr)
			break;
		if ((bn->v().base() + bn->v().size()) == bn->next()->v().base()) {
			/*
			printstr("memory_free: merge\n");
			printstr("    base = 0x");
			printhex64(bn->v().base());
			printstr(" size = 0x");
			printhex64(bn->v().size());
			printstr("\n");
			printstr("    base = 0x");
			printhex64(bn->next()->v().base());
			printstr(" size = 0x");
			printhex64(bn->next()->v().size());
			printstr("\n");
			*/
			bn->v().size(bn->v().size() + bn->next()->v().size());
			mb = &bn->next()->v();
			free_block.remove(bn->next()->v());
			delete mb;
			goto retry;
		}
	}
}

void *
memory_alloc_page_lo(memory_page_size page_size)
{
	void *ptr;
	bidir_node<memory_block> *bn;
	memory_block *mb;
	size_t size;
	uint64_t base;

	switch (page_size) {
	case memory_page_size::page_size_4k:
		size = 0x1000;
		break;
	case memory_page_size::page_size_2m:
		size = 0x200000;
		break;
	default:
		return nullptr;
	}

	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		//base = bn->v().base();
		//size = bn->v().size();
		base = bn->v().base();
		round_up_64(base, size);
		if ((bn->v().base() <= base) &&
		    ((bn->v().base() + bn->v().size()) >= (base + size))) {
			break;
		}
	}

	if (bn == nullptr)
		return nullptr;

	ptr = (void *)base;
	if ((bn->v().base() == base) &&
	    ((bn->v().base() + bn->v().size()) == (base + size))) {
		/* 割り当てるブロックがスッポリと空きブロックに収まる場合 */
		memory_block *tmp = &bn->v();
		free_block.remove(bn->v());
		delete tmp;
	} else if (bn->v().base() == base) {
		/* 割り当てるブロックの先頭アドレスと空きブロックの先頭アドレスが等しい場合 */
		bn->v().base(bn->v().base() + size);
		bn->v().size(bn->v().size() - size);
	} else if ((bn->v().base() + bn->v().size()) == (base + size)) {
		/* 割り当てるブロックの末尾アドレスと空きブロックの末尾アドレスが等しい場合 */
		bn->v().size(bn->v().size() - size);
	} else {
		/* 割り当てるブロックで空きブロックを分割する場合 */
		mb = new memory_block(base + size, (bn->v().base() + bn->v().size()) - (base + size));
		free_block.insert(*mb);
		bn->v().size(base - bn->v().base());
	}

	mb = new memory_block((uint64_t)ptr, size);
	alloc_block.insert(*mb);

	return ptr;
}

/*
void *
memory_alloc_page_hi(memory_page_size page_size)
{
	return nullptr;
}
*/

void *
operator new(size_t size)
{
	//printstr("new\n");
	return memory_alloc(size);
}

void *
operator new[](size_t size)
{
	//printstr("new[]\n");
	return memory_alloc(size);
}

void
operator delete(void* ptr) noexcept
{
	//printstr("delete\n");
	memory_free(ptr);
}

void
operator delete[](void* ptr) noexcept
{
	//printstr("delete[]\n");
	memory_free(ptr);
}

void
memory_init(struct loader_info *li)
{
	int i;
	struct li_memdesc *limd = nullptr;
	uint64_t first_base, first_size, base, size;
	uint64_t mb_size, bn_size, ht_size;
	memory_block *mb;

	for (i = 0; i < li->mm_num_of_mds; ++i) {
		if (li->mm_mds[i].md_type == 7) {
			limd = &li->mm_mds[i];
			break;
		}
	}

	if (limd == nullptr) {
		printstr("memory_init: Cannot find conventional memory.\n");
		panic();
	}

	first_base = limd->md_phys_start;
	first_size = limd->md_num_of_pages * 4096;

	first_base += sizeof(void *);
	first_size -= sizeof(void *);

	mb_size = sizeof(memory_block) * 64 * memory_pool_free_bits_size;
	bn_size = sizeof(bidir_node<memory_block>) * 64 * memory_pool_free_bits_size;
	ht_size = sizeof(bidir_node<memory_block> *) * hash_table_init_size;

	if (first_size < (mb_size + bn_size + ht_size)) {
		printstr("memory_init: Out of memory.\n");
		printstr("first base = 0x");
		printhex64(first_base);
		printstr(" first size = 0x");
		printhex64(first_size);
		printstr(" required size = 0x");
		printhex64(mb_size + bn_size + ht_size);
		printstr("\n");
		panic();
	}

	// memory_block 用メモリプールの初期化
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		memory_block::s_mem_pool.m_free_bits[i] = 0xfffffffffffffffful;
	}
	memory_block::s_mem_pool.m_table = (memory_block *)first_base;
	first_base += mb_size;
	first_size -= mb_size;
	memory_block::s_mem_pool.m_next = nullptr;

	// bidir_node<memory_block> 用メモリプールの初期化
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		bidir_node<memory_block>::s_mem_pool.m_free_bits[i] = 0xfffffffffffffffful;
	}
	bidir_node<memory_block>::s_mem_pool.m_table = (bidir_node<memory_block> *)first_base;
	first_base += bn_size;
	first_size -= bn_size;
	bidir_node<memory_block>::s_mem_pool.m_next = nullptr;

	// free_block の初期化
	free_block.m_head = nullptr;
	free_block.m_tail = nullptr;
	free_block.m_nodes = 0;

	// alloc_block の初期化
	alloc_block.m_hash_fn = memory_block_hash;
	alloc_block.m_equal_fn = memory_block_equal;
	alloc_block.m_table_size = hash_table_init_size;
	alloc_block.m_table = (bidir_node<memory_block> **)first_base;
	first_base += ht_size;
	first_size -= ht_size;
	for (i = 0; i < hash_table_init_size; ++i) {
		alloc_block.m_table[i] = nullptr;
	}
	alloc_block.m_nodes = 0;

	for (i = 0; i < li->mm_num_of_mds; ++i) {
		if (li->mm_mds[i].md_type != 7)
			continue;
		if (&li->mm_mds[i] == limd) {
			base = first_base;
			size = first_size;
		} else {
			base = li->mm_mds[i].md_phys_start;
			size = li->mm_mds[i].md_num_of_pages * 4096;
		}
		mb = new memory_block(base, size);
		if (mb == nullptr) {
			printstr("memory_init: memory_block alloc failed.\n");
			panic();
		}
		free_block.insert(*mb);
	}

	mb = new memory_block((uint64_t)memory_block::s_mem_pool.m_table, mb_size);
	if (mb == nullptr) {
		printstr("memory_init: memory_block alloc failed.\n");
		panic();
	}
	alloc_block.insert(*mb);

	mb = new memory_block((uint64_t)bidir_node<memory_block>::s_mem_pool.m_table, bn_size);
	if (mb == nullptr) {
		printstr("memory_init: memory_block alloc failed.\n");
		panic();
	}
	alloc_block.insert(*mb);

	mb = new memory_block((uint64_t)alloc_block.m_table, ht_size);
	if (mb == nullptr) {
		printstr("memory_init: memory_block alloc failed.\n");
		panic();
	}
	alloc_block.insert(*mb);

	//memory_dump();
}

void
memory_dump()
{
	int i;
	uint64_t free = 0;
	bidir_node<memory_block> *bn;
	i = 0;
	printstr("FREE BLOCKS:\n");
	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		printstr("   0x");
		printhex8(i);
		printstr(" 0x");
		printhex64(bn->v().base());
		printstr(" 0x");
		printhex64(bn->v().size());
		printstr(" 0x");
		printhex64((uint64_t)&bn->v());
		printstr("\n");
		++i;
		free += bn->v().size();
	}
	printstr("ALLOC BLOCKS:\n");
	if (alloc_block.table() == nullptr) {
		printstr("    alloc_block.table == nullptr\n");
		return;
	}
	printstr("    alloc_block.table           = 0x");
	printhex64((uint64_t)alloc_block.table());
	printstr("\n");
	for (i = 0; i < alloc_block.table_size(); ++i) {
		if (alloc_block.table()[i] == nullptr)
			continue;
		printstr("   0x");
		printhex8(i);
		printstr("\n");
		for (bn = alloc_block.table()[i]; bn != nullptr; bn = bn->next()) {
			printstr("        0x");
			printhex64(bn->v().base());
			printstr(" 0x");
			printhex64(bn->v().size());
			printstr(" 0x");
			printhex64((uint64_t)&bn->v());
			printstr("\n");
		}
	}
	printstr("MEMORY POOL:\n");
	printstr("    bidir_node<memory_block>    = 0x");
	printhex64(bidir_node<memory_block>::count());
	printstr("\n");
	printstr("    memory_block                = 0x");
	printhex64(memory_block::count());
	printstr("\n");
	printstr("FREE BYTES: ");
	printhex64(free);
	printstr("\n");
}

