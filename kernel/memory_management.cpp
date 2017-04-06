/**
 * @file	memory_management.cpp
 * @brief	メモリ管理に関連する関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"
#include "debug.h"
#include "memory_management.h"
#include "sorted_list.h"
#include "hash_table.h"
#include "memory_block.h"

#include "intel64_assembly.h"

#include "loader_info.h"

static struct loader_info *li = nullptr;

static sorted_list<memory_block> free_block;
static hash_table<memory_block> alloc_block(memory_block_hash, memory_block_equal);

void *
memory_alloc(size_t size)
{
	void *ptr;
	bidir_node<memory_block> *bn;
	memory_block *mb;

	//print("memory_alloc\n");

	if (size & 0x7) {
		size &= ~ 0x7;
		size += 0x8;
	}

	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		if (bn->v().size() >= size)
			break;
	}

	if (bn == nullptr) {
		return nullptr;
	}

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

	//print("memory_free\n");

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
			print("memory_free: merge\n");
			print("    base = 0x");
			printhex64(bn->v().base());
			print(" size = 0x");
			printhex64(bn->v().size());
			print("\n");
			print("    base = 0x");
			printhex64(bn->next()->v().base());
			print(" size = 0x");
			printhex64(bn->next()->v().size());
			print("\n");
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
memory_alloc_page_lo(memory_page_size page_size, uint64_t page_count)
{
	void *ptr;
	bidir_node<memory_block> *bn;
	memory_block *mb;
	size_t size, size_page;
	uint64_t base;

	switch (page_size) {
	case memory_page_size::page_size_4k:
		size = 0x1000 * page_count;
		size_page = 0x1000;
		break;
	case memory_page_size::page_size_2m:
		size = 0x200000 * page_count;
		size_page = 0x200000;
		break;
	default:
		return nullptr;
	}

	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		//base = bn->v().base();
		//size = bn->v().size();
		base = bn->v().base();
		round_up_64(base, size_page);
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
memory_alloc_page_hi(memory_page_size page_size, uint64_t page_count)
{
	return nullptr;
}
*/

void *
operator new(size_t size)
{
	//print("new\n");
	return memory_alloc(size);
}

void *
operator new[](size_t size)
{
	//print("new[]\n");
	return memory_alloc(size);
}

void
operator delete(void* ptr) noexcept
{
	//print("delete\n");
	memory_free(ptr);
}

void
operator delete[](void* ptr) noexcept
{
	//print("delete[]\n");
	memory_free(ptr);
}

void
memory_init(struct loader_info *lit)
{
	int i;
	struct li_memdesc *limd = nullptr;
	uint64_t first_base, first_size, base, size;
	uint64_t mb_size, bn_size, ht_size;
	memory_block *mb;

	li = lit;

	for (i = 0; i < li->mm_num_of_mds; ++i) {
		if (li->mm_mds[i].md_type == 7) {
			limd = &li->mm_mds[i];
			break;
		}
	}

	if (limd == nullptr) {
		print("memory_init: Cannot find conventional memory.\n");
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
		print("memory_init: Out of memory.\n");
		print("first base = 0x");
		printhex64(first_base);
		print(" first size = 0x");
		printhex64(first_size);
		print(" required size = 0x");
		printhex64(mb_size + bn_size + ht_size);
		print("\n");
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
	memory_block::s_mem_pool.m_prev = nullptr;

	// bidir_node<memory_block> 用メモリプールの初期化
	for (i = 0; i < memory_pool_free_bits_size; ++i) {
		bidir_node<memory_block>::s_mem_pool.m_free_bits[i] = 0xfffffffffffffffful;
	}
	bidir_node<memory_block>::s_mem_pool.m_table = (bidir_node<memory_block> *)first_base;
	first_base += bn_size;
	first_size -= bn_size;
	bidir_node<memory_block>::s_mem_pool.m_next = nullptr;
	bidir_node<memory_block>::s_mem_pool.m_prev = nullptr;

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
			print("memory_init: memory_block alloc failed.\n");
			panic();
		}
		free_block.insert(*mb);
	}

	mb = new memory_block((uint64_t)memory_block::s_mem_pool.m_table, mb_size);
	if (mb == nullptr) {
		print("memory_init: memory_block alloc failed.\n");
		panic();
	}
	alloc_block.insert(*mb);

	mb = new memory_block((uint64_t)bidir_node<memory_block>::s_mem_pool.m_table, bn_size);
	if (mb == nullptr) {
		print("memory_init: memory_block alloc failed.\n");
		panic();
	}
	alloc_block.insert(*mb);

	mb = new memory_block((uint64_t)alloc_block.m_table, ht_size);
	if (mb == nullptr) {
		print("memory_init: memory_block alloc failed.\n");
		panic();
	}
	alloc_block.insert(*mb);

	//memory_dump();
}

uint64_t
memory_alloc_size()
{
	uint64_t alloc_size = 0;
	bidir_node<memory_block> *bn;

	for (int i = 0; i < alloc_block.table_size(); ++i) {
		if (alloc_block.table()[i] == nullptr)
			continue;
		for (bn = alloc_block.table()[i]; bn != nullptr; bn = bn->next()) {
			alloc_size += bn->v().size();
		}
	}

	return alloc_size;
}

uint64_t
memory_free_size()
{
	uint64_t free_size = 0;
	bidir_node<memory_block> *bn;

	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		free_size += bn->v().size();
	}

	return free_size;
}

uint64_t
memory_block_count()
{
	uint64_t block_count = 0;
	bidir_node<memory_block> *bn;

	for (int i = 0; i < alloc_block.table_size(); ++i) {
		if (alloc_block.table()[i] == nullptr)
			continue;
		for (bn = alloc_block.table()[i]; bn != nullptr; bn = bn->next()) {
			++block_count;
		}
	}

	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		++block_count;
	}

	return block_count;
}

uint64_t
memory_block_bidir_node_count()
{
	return bidir_node<memory_block>::count();
}

utf8str
memory_dump()
{
	int i;
	uint64_t free = 0;
	bidir_node<memory_block> *bn;
	i = 0;
	utf8str s;
	uint64_t base[256], size[256];
	s += "FREE BLOCKS:\n";
	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		base[i] = bn->v().base();
		size[i] = bn->v().size();
		++i;
		free += bn->v().size();
	}
	for (int j = 0; (j < i) && (j < 256); ++j) {
		s += "   0x";
		s.append_hex64(j, 2);
		s += " 0x";
		s.append_hex64(base[j], 16);
		s += " 0x";
		s.append_hex64(base[j] + size[j], 16);
		s += " 0x";
		s.append_hex64(size[j], 16);
		s += "\n";
	}
	return s;
	s += "ALLOC BLOCKS:\n";
	if (alloc_block.table() == nullptr) {
		s += "    alloc_block.table == nullptr\n";
		return s;
	}
	s += "    alloc_block.table           = 0x";
	s.append_hex64((uint64_t)alloc_block.table(), 16);
	s += "\n";
	for (i = 0; i < alloc_block.table_size(); ++i) {
		if (alloc_block.table()[i] == nullptr)
			continue;
		s += "   0x";
		s.append_hex64(i, 2);
		s += "\n";
		for (bn = alloc_block.table()[i]; bn != nullptr; bn = bn->next()) {
			s += "        0x";
			s.append_hex64(bn->v().base(), 16);
			s += " 0x";
			s.append_hex64(bn->v().size(), 16);
			s += " 0x";
			s.append_hex64((uint64_t)&bn->v(), 16);
			s += "\n";
		}
	}
	s += "MEMORY POOL:\n";
	s += "    bidir_node<memory_block>    = 0x";
	s.append_hex64(bidir_node<memory_block>::count(), 16);
	s += "\n";
	s += "    memory_block                = 0x";
	s.append_hex64(memory_block::count(), 16);
	s += "\n";
	s += "FREE BYTES: ";
	s.append_hex64(free, 16);
	s += "\n";
	return s;
}

void
memory_free_dump()
{
	int i;
	uint64_t free = 0;
	bidir_node<memory_block> *bn;
	i = 0;
	print("FREE BLOCKS:\n");
	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		print("   0x");
		printhex8(i);
		print(" 0x");
		printhex64(bn->v().base());
		print(" 0x");
		printhex64(bn->v().size());
		print(" 0x");
		printhex64((uint64_t)&bn->v());
		print("\n");
		++i;
		free += bn->v().size();
	}
}

void
memory_stats()
{
	int i;
	uint64_t alloc = 0;
	uint64_t free = 0;
	bidir_node<memory_block> *bn;
	for (i = 0; i < alloc_block.table_size(); ++i) {
		if (alloc_block.table()[i] == nullptr)
			continue;
		for (bn = alloc_block.table()[i]; bn != nullptr; bn = bn->next()) {
			alloc += bn->v().size();
		}
	}
	for (bn = free_block.head(); bn != nullptr; bn = bn->next()) {
		free += bn->v().size();
	}
	utf8str s;
	s += "ALLOC ";
	s.append_uint64(alloc, 12);
	s += "\n";
	s += "FREE  ";
	s.append_uint64(free, 12);
	s += "\n";
	s += "TOTAL ";
	s.append_uint64(alloc + free, 12);
	s += "\n";
	print(s);
}

utf8str
memory_debug_memory_map()
{
	int i;
	struct li_memdesc *limd = nullptr;
	utf8str s;
	s += "ID START      SIZE       TYPE\n";
	for (i = 0; i < li->mm_num_of_mds; ++i) {
		limd = &li->mm_mds[i];
		s.append_hex64(i, 2);
		s += " 0x";
		s.append_hex64(limd->md_phys_start, 8);
		s += " 0x";
		s.append_hex64(limd->md_num_of_pages * 4096, 8);
		switch (limd->md_type) {
		case 0:
			s += " EfiReservedMemoryType";
			break;
		case 1:
			s += " EfiLoaderCode";
			break;
		case 2:
			s += " EfiLoaderData";
			break;
		case 3:
			s += " EfiBootServicesCode";
			break;
		case 4:
			s += " EfiBootServicesData";
			break;
		case 5:
			s += " EfiRuntimeServiceCode";
			break;
		case 6:
			s += " EfiRuntimeServicesData";
			break;
		case 7:
			s += " EfiConventionalMemory";
			break;
		case 8:
			s += " EfiUnusableMemory";
			break;
		case 9:
			s += " EfiACPIReclaimMemory";
			break;
		case 10:
			s += " EfiACPIMemoryNVS";
			break;
		case 11:
			s += " EfiMemoryMappedIO";
			break;
		case 12:
			s += " EfiMemoryMappedIOPortSpace";
			break;
		case 13:
			s += " EfiPalCode";
			break;
		case 14:
			s += " EfiPersistentMemory";
			break;
		default:
			s += " ???";
		}
		s += "\n";
	}
	return s;
}

extern "C" void *memset(void *b, int c, size_t len);

__attribute__((unused))
void *
memset(void *b, int c, size_t len)
{
	unsigned char *ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = c;
	return b;
}

