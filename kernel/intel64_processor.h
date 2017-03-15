/**
 * @file	intel64_processor.h
 * @brief	Intel64 CPU の初期化等を行う関数群宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"
#include "processor_base.h"

/**
 * GDT エントリーを格納するためのクラス。
 */
class intel64_gdt_entry {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_gdt_entry();

	/*
	 * sizeof(intel64_gdt_entry) は 8 でなければならないが、
	 * デストラクタを書くと 8 でなくなるのでコメントアウト。
	 */
	//virtual ~intel64_gdt_entry();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_gdt_entry(const intel64_gdt_entry &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_gdt_entry(intel64_gdt_entry &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_gdt_entry &operator=(const intel64_gdt_entry &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_gdt_entry &operator=(intel64_gdt_entry &&src) = delete;

	/**
	 *
	 */
	void l(bool l);

	/**
	 *
	 */
	bool l();

	/**
	 *
	 */
	void avl(bool avl);

	/**
	 *
	 */
	bool avl();

	/**
	 *
	 */
	void base(uint64_t base);

	/**
	 *
	 */
	uint64_t base();

	/**
	 *
	 */
	void db(bool db);

	/**
	 *
	 */
	bool db();

	/**
	 *
	 */
	void dpl(uint8_t dpl);

	/**
	 *
	 */
	uint8_t dpl();

	/**
	 *
	 */
	void g(bool g);

	/**
	 *
	 */
	bool g();

	/**
	 *
	 */
	void limit(uint64_t limit);

	/**
	 *
	 */
	uint64_t limit();

	/**
	 *
	 */
	void p(bool p);

	/**
	 *
	 */
	bool p();

	/**
	 *
	 */
	void s(bool s);

	/**
	 *
	 */
	bool s();

	/**
	 *
	 */
	void type(uint8_t type);

	/**
	 *
	 */
	uint8_t type();

	/**
	 *
	 */
	void set_intel64_gdt_entry(uint64_t intel64_gdt_entry);

	/**
	 *
	 */
	uint64_t get_intel64_gdt_entry();

private:
	/**
	 *
	 */
	uint64_t m_intel64_gdt_entry;

};

/**
 * GDTR を格納するためのクラス。
 */
class intel64_gdtr {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_gdtr();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_gdtr();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_gdtr(const intel64_gdtr &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_gdtr(intel64_gdtr &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_gdtr &operator=(const intel64_gdtr &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_gdtr &operator=(intel64_gdtr &&src) = delete;

	/**
	 *
	 */
	void base(uint64_t base);

	/**
	 *
	 */
	uint64_t base();

	/**
	 *
	 */
	void limit(uint16_t limit);

	/**
	 *
	 */
	uint16_t limit();

	/**
	 *
	 */
	void code_segment_selector(uint16_t code_segment_selector);

	/**
	 *
	 */
	uint16_t code_segment_selector();

	/**
	 *
	 */
	void data_segment_selector(uint16_t data_segment_selector);

	/**
	 *
	 */
	uint16_t data_segment_selector();

	/**
	 *
	 */
	int load();

	/**
	 *
	 */
	int store();

	/**
	 *
	 */
	void set_intel64_gdtr0(uint64_t intel64_gdtr0);

	/**
	 *
	 */
	uint64_t get_intel64_gdtr0();

	/**
	 *
	 */
	void set_intel64_gdtr1(uint64_t intel64_gdtr1);

	/**
	 *
	 */
	uint64_t get_intel64_gdtr1();

private:
	/**
	 *
	 */
	uint64_t m_intel64_gdtr[2];

	/**
	 *
	 */
	uint16_t m_code_segment_selector;

	/**
	 *
	 */
	uint16_t m_data_segment_selector;

};

/**
 * IDT エントリーを格納するためのクラス。
 */
class intel64_idt_entry {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_idt_entry();

	/*
	 * sizeof(intel64_idt_entry) は 16 でなければならないが、
	 * デストラクタを書くと 16 でなくなるのでコメントアウト。
	 */
	//virtual ~intel64_idt_entry();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_idt_entry(const intel64_idt_entry &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_idt_entry(intel64_idt_entry &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_idt_entry &operator=(const intel64_idt_entry &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_idt_entry &operator=(intel64_idt_entry &&src) = delete;

	/**
	 *
	 */
	void dpl(uint8_t dpl);

	/**
	 *
	 */
	uint8_t dpl();

	/**
	 *
	 */
	void offset(uint64_t offset);

	/**
	 *
	 */
	uint64_t offset();

	/**
	 *
	 */
	void p(bool p);

	/**
	 *
	 */
	bool p();

	/**
	 *
	 */
	void segment_selector(uint16_t segment_selector);

	/**
	 *
	 */
	uint16_t segment_selector();

	/**
	 *
	 */
	void ist(uint8_t ist);

	/**
	 *
	 */
	uint8_t ist();

	/**
	 *
	 */
	void type(uint8_t type);

	/**
	 *
	 */
	uint8_t type();

	/**
	 *
	 */
	void set_intel64_idt_entry0(uint64_t intel64_idt_entry0);

	/**
	 *
	 */
	uint64_t get_intel64_idt_entry0();

	/**
	 *
	 */
	void set_intel64_idt_entry1(uint64_t intel64_idt_entry1);

	/**
	 *
	 */
	uint64_t get_intel64_idt_entry1();

private:
	/**
	 *
	 */
	uint64_t m_intel64_idt_entry[2];

};

/**
 * IDTR を格納するためのクラス。
 */
class intel64_idtr {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_idtr();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_idtr();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_idtr(const intel64_idtr &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_idtr(intel64_idtr &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_idtr &operator=(const intel64_idtr &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_idtr &operator=(intel64_idtr &&src) = delete;

	/**
	 *
	 */
	void base(uint64_t base);

	/**
	 *
	 */
	uint64_t base();

	/**
	 *
	 */
	void limit(uint16_t limit);

	/**
	 *
	 */
	uint16_t limit();

	/**
	 *
	 */
	int load();

	/**
	 *
	 */
	int store();

	/**
	 *
	 */
	void set_intel64_idtr0(uint64_t intel64_idtr0);

	/**
	 *
	 */
	uint64_t get_intel64_idtr0();

	/**
	 *
	 */
	void set_intel64_idtr1(uint64_t intel64_idtr1);

	/**
	 *
	 */
	uint64_t get_intel64_idtr1();

private:
	/**
	 *
	 */
	uint64_t m_intel64_idtr[2];

};

/**
 * ページングエントリー基底クラス
 */
class intel64_page_entry_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_page_entry_base();

	/*
	 * デストラクタ。
	 */
	//virtual ~intel64_page_entry_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_page_entry_base(const intel64_page_entry_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_page_entry_base(intel64_page_entry_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_page_entry_base &operator=(const intel64_page_entry_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_page_entry_base &operator=(intel64_page_entry_base &&src) = delete;

	/**
	 *
	 */
	void init();

	/**
	 *
	 */
	void present(bool present);

	/**
	 *
	 */
	bool present();

	/**
	 *
	 */
	void read_write(bool read_write);

	/**
	 *
	 */
	bool read_write();

	/**
	 *
	 */
	void user_supervisor(bool user_supervisor);

	/**
	 *
	 */
	bool user_supervisor();

	/**
	 *
	 */
	void page_level_write_through(bool page_level_write_through);

	/**
	 *
	 */
	bool page_level_write_through();

	/**
	 *
	 */
	void page_level_cache_disable(bool page_level_cache_disable);

	/**
	 *
	 */
	bool page_level_cache_disable();

	/**
	 *
	 */
	void accessed(bool accessed);

	/**
	 *
	 */
	bool accessed();

	/**
	 *
	 */
	uint64_t get_page_table_entry();

protected:
	/**
	 *
	 */
	uint64_t m_page_table_entry;

};

/**
 * ページングテーブル基底クラス
 */
class intel64_page_table_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_page_table_base();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_page_table_base();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_page_table_base(const intel64_page_table_base &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_page_table_base(intel64_page_table_base &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_page_table_base &operator=(const intel64_page_table_base &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_page_table_base &operator=(intel64_page_table_base &&src) = delete;

	/**
	 *
	 */
	uint64_t *get_page_table();

protected:
	/**
	 *
	 */
	intel64_page_entry_base *m_page_table;

};

/**
 * ページディレクトリエントリー
 */
class intel64_pd_entry : public intel64_page_entry_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_pd_entry();

	/*
	 * デストラクタ。
	 */
	//virtual ~intel64_pd_entry();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_pd_entry(const intel64_pd_entry &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_pd_entry(intel64_pd_entry &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_pd_entry operator=(const intel64_pd_entry &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_pd_entry operator=(intel64_pd_entry &&src) = delete;

	/**
	 *
	 */
	void dirty(bool dirty);

	/**
	 *
	 */
	bool dirty();

	/**
	 *
	 */
	void page_size(bool page_size);

	/**
	 *
	 */
	bool page_size();

	/**
	 *
	 */
	void global(bool global);

	/**
	 *
	 */
	bool global();

	/**
	 *
	 */
	void pat(bool pat);

	/**
	 *
	 */
	bool pat();

	/**
	 *
	 */
	void page_frame_address(uint64_t page_frame_address);

	/**
	 *
	 */
	uint64_t page_frame_address();

};

/**
 * ページディレクトリテーブル
 */
class intel64_pd_table : public intel64_page_table_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_pd_table();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_pd_table();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_pd_table(const intel64_pd_table &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_pd_table(intel64_pd_table &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_pd_table &operator=(const intel64_pd_table &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_pd_table &operator=(intel64_pd_table &&src) = delete;

	/**
	 *
	 */
	intel64_pd_entry &operator[](size_t index);

};

/**
 * ページディレクトリポインターエントリー
 */
class intel64_pdpt_entry : public intel64_page_entry_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_pdpt_entry();

	/*
	 * デストラクタ。
	 */
	//virtual ~intel64_pdpt_entry();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_pdpt_entry(const intel64_pdpt_entry &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_pdpt_entry(intel64_pdpt_entry &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_pdpt_entry &operator=(const intel64_pdpt_entry &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_pdpt_entry &operator=(intel64_pdpt_entry &&src) = delete;

	/**
	 *
	 */
	void page_size(bool page_size);

	/**
	 *
	 */
	bool page_size();

	/**
	 *
	 */
	void pd_table_address(uint64_t pd_table_address);

	/**
	 *
	 */
	uint64_t pd_table_address();

};

/**
 * ページディレクトリポインターテーブル
 */
class intel64_pdpt_table : public intel64_page_table_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_pdpt_table();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_pdpt_table();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_pdpt_table(const intel64_pdpt_table &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_pdpt_table(intel64_pdpt_table &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_pdpt_table &operator=(const intel64_pdpt_table &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_pdpt_table &operator=(intel64_pdpt_table &&src) = delete;

	/**
	 *
	 */
	intel64_pdpt_entry &operator[](size_t index);

	/**
	 *
	 */
	void pd_table_at(int index, intel64_pd_table *pd_table);

	/**
	 *
	 */
	intel64_pd_table *pd_table_at(int index);

private:
	/**
	 *
	 */
	intel64_pd_table *m_intel64_pd_tables[512];

};

/**
 * PML4 エントリー
 */
class intel64_pml4_entry : public intel64_page_entry_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_pml4_entry();

	/*
	 * デストラクタ。
	 */
	//virtual ~intel64_pml4_entry();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_pml4_entry(const intel64_pml4_entry &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_pml4_entry(intel64_pml4_entry &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_pml4_entry &operator=(const intel64_pml4_entry &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_pml4_entry &operator=(intel64_pml4_entry &&src) = delete;

	/**
	 *
	 */
	void pdpt_table_address(uint64_t pdpt_table_address);

	/**
	 *
	 */
	uint64_t pdpt_table_address();

};

/**
 * PML4 テーブル
 */
class intel64_pml4_table : public intel64_page_table_base {

public:
	/**
	 * コンストラクタ。
	 */
	intel64_pml4_table();

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_pml4_table();

	/**
	 * コピーコンストラクタ。コピーは禁止。
	 */
	intel64_pml4_table(const intel64_pml4_table &src) = delete;

	/**
	 * ムーブコンストラクタ。ムーブは禁止。
	 */
	intel64_pml4_table(intel64_pml4_table &&src) = delete;

	/**
	 * コピー代入演算子。コピー代入は禁止。
	 */
	intel64_pml4_table &operator=(const intel64_pml4_table &src) = delete;

	/**
	 * ムーブ代入演算子。ムーブ代入は禁止。
	 */
	intel64_pml4_table &operator=(intel64_pml4_table &&src) = delete;

	/**
	 *
	 */
	intel64_pml4_entry &operator[](size_t index);

	/**
	 *
	 */
	void pdpt_table_at(int index, intel64_pdpt_table *pdpt_table);

	/**
	 *
	 */
	intel64_pdpt_table *pdpt_table_at(int index);

private:
	/**
	 *
	 */
	intel64_pdpt_table *m_intel64_pdpt_tables[512];

};

/**
 *
 */
class intel64_processor : public processor_base {

public:
	/**
	 * コンストラクタ。
	 * @param io_thread
	 */
	intel64_processor(thread &io_thread);

	/**
	 * デストラクタ。
	 */
	virtual ~intel64_processor();

private:
	/**
	 *
	 */

};

/**
 *
 */
intel64_pml4_table *pml4_table_alloc();

/**
 *
 */
void pml4_table_free(intel64_pml4_table *pml4t);

