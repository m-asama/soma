/**
 * @file	loader_info.h
 * @brief	ブートローダからカーネルへデータを渡すための構造体。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

struct li_memdesc {
	uint32_t		md_type;
	uint64_t		md_phys_start;
	uint64_t		md_virt_start;
	uint64_t		md_num_of_pages;
	uint64_t		md_attr;
};

struct loader_info {

	/* カーネルと設定ファイルの情報 */
	uint64_t		kernel_base;
	uint64_t		kernel_size;
	uint64_t		config_base;
	uint64_t		config_size;

	/* UEFI フレームバッファ情報 */
	uint64_t		fb_addr;
	uint64_t		fb_size;
	int			fb_height;
	int			fb_width;
	int			fb_stride;
	uint32_t		fb_mask_red;
	uint32_t		fb_mask_green;
	uint32_t		fb_mask_blue;
	uint32_t		fb_mask_reserved;

	/* ACPI RSDP テーブル情報 */
	uint64_t		rsdp_table;

	/* メモリマッピング情報 */
	struct li_memdesc	*mm_mds;
	int			mm_num_of_mds;

};

