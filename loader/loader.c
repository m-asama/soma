/*
 * Author:
 * 	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include <efi.h>

#include "main.h"
#include "print.h"

#include "loader_info.h"

static int
is_kernel(unsigned char *p)
{
	if (p[ 0] == 'S' &&
	    p[ 1] == 'O' &&
	    p[ 2] == 'M' &&
	    p[ 3] == 'A' &&
	    p[ 4] == 'K' &&
	    p[ 5] == 'E' &&
	    p[ 6] == 'R' &&
	    p[ 7] == 'N' &&
	    p[ 8] == 'B' &&
	    p[ 9] == 'I' &&
	    p[10] == 'N') {
		return 1;
	}
	return 0;
}

static int
is_config(unsigned char *p)
{
	if (p[ 0] == 'S' &&
	    p[ 1] == 'O' &&
	    p[ 2] == 'M' &&
	    p[ 3] == 'A' &&
	    p[ 4] == 'C' &&
	    p[ 5] == 'O' &&
	    p[ 6] == 'N' &&
	    p[ 7] == 'F' &&
	    p[ 8] == 'T' &&
	    p[ 9] == 'X' &&
	    p[10] == 'T') {
		return 1;
	}
	return 0;
}

static int
search_file(EFI_BLOCK_IO *blkio, EFI_LBA *head, UINTN *size, int (*is_target)(unsigned char *p))
{
	EFI_STATUS status;
	unsigned char buf[512], *p;
	int i;

	unsigned long root_dir_sectors;
	unsigned long first_root_dir_sec_num;
	unsigned long first_data_sector;
	unsigned long fatsz;
	unsigned long bpb_byts_per_sec;
	unsigned long bpb_sec_per_clus;
	unsigned long bpb_resvd_sec_cnt;
	unsigned long bpb_num_fats;
	unsigned long bpb_root_ent_cnt;
	unsigned long bpb_fat_sz_16;
	unsigned long bpb_fat_sz_32;
	unsigned long bpb_root_clus;

	unsigned long cluster;

	status = blkio->ReadBlocks(blkio, blkio->Media->MediaId, 0, 512, buf);
	if (EFI_ERROR(status))
		return -1;

	bpb_byts_per_sec = buf[11] + (buf[12] << 8);
	bpb_sec_per_clus = buf[13];
	bpb_resvd_sec_cnt = buf[14] + (buf[15] << 8);
	bpb_num_fats = buf[16];
	bpb_root_ent_cnt = buf[17] + (buf[18] << 8);
	bpb_fat_sz_16 = buf[22] + (buf[23] << 8);
	bpb_fat_sz_32 = buf[36] + (buf[37] << 8) + (buf[38] << 16) + (buf[39] << 24);
	bpb_root_clus = buf[44] + (buf[45] << 8) + (buf[46] << 16) + (buf[47] << 24);

	if (bpb_fat_sz_16 != 0) {
		fatsz = bpb_fat_sz_16;
	} else {
		fatsz = bpb_fat_sz_32;
	}

	root_dir_sectors = ((bpb_root_ent_cnt * 32) + (bpb_byts_per_sec - 1)) / bpb_byts_per_sec;
	first_data_sector = bpb_resvd_sec_cnt + (bpb_num_fats * fatsz) + root_dir_sectors;

	if (bpb_root_ent_cnt == 0) {
		first_root_dir_sec_num = ((bpb_root_clus - 2) * bpb_sec_per_clus) + first_data_sector;
	} else {
		first_root_dir_sec_num = bpb_resvd_sec_cnt + (bpb_num_fats * bpb_fat_sz_16);
	}

	status = blkio->ReadBlocks(blkio, blkio->Media->MediaId, first_root_dir_sec_num, 512, buf);
	if (EFI_ERROR(status))
		return -1;

	for (i = 0; i < 16; ++i) {
		p = &buf[32 * i];

		if (p[0] == 0xe5)
			continue;

		if (p[0] == 0x00)
			return -1;

		if (is_target(p)) {
			cluster = p[26] + (p[27] << 8) + (p[20] << 16) + (p[21] << 24);
			*head = ((cluster - 2) * bpb_sec_per_clus) + first_data_sector;
			*size = p[28] + (p[29] << 8) + (p[30] << 16) + (p[31] << 24);
			return 0;
		}
	}

	return -1;
}

static int
search_kernel(EFI_BLOCK_IO *blkio, EFI_LBA *head, UINTN *size)
{
	return search_file(blkio, head, size, is_kernel);
}

static int
search_config(EFI_BLOCK_IO *blkio, EFI_LBA *head, UINTN *size)
{
	return search_file(blkio, head, size, is_config);
}

static int
load_file(EFI_BLOCK_IO *blkio, EFI_LBA *head, UINTN *size, unsigned char *base)
{
	unsigned char *pagesp = base;
	UINTN pages;
	EFI_STATUS status;

	pages = *size / 4096;
	if (*size % 4096)
		++pages;

	status = BS->AllocatePages(AllocateAddress, EfiLoaderData, pages, (EFI_PHYSICAL_ADDRESS *)&pagesp);
	if (EFI_ERROR(status)) {
		printstr("load_file: AllocatePages failed.\n");
		return -1;
	}

	status = blkio->ReadBlocks(blkio, blkio->Media->MediaId, *head, pages * 4096, pagesp);
	if (EFI_ERROR(status)) {
		printstr("load_file: ReadBlocks failed.\n");
		return -1;
	}

	return 0;
}

static int
load_kernel(EFI_BLOCK_IO *blkio, EFI_LBA *head, UINTN *size, struct loader_info *li)
{
	int ret;
	ret = load_file(blkio, head, size, (unsigned char *)kernel_base_addr);
	if (!ret) {
		li->kernel_base = kernel_base_addr;
		li->kernel_size = *size;
	} else {
		li->kernel_base = 0;
		li->kernel_size = 0;
	}
	return ret;
}

static int
load_config(EFI_BLOCK_IO *blkio, EFI_LBA *head, UINTN *size, struct loader_info *li)
{
	unsigned long config_base_addr, t;
	int ret;
	t = li->kernel_size / 4096;
	if (li->kernel_size % 4096)
		++t;
	t *= 4096;
	config_base_addr = li->kernel_base + t;
	ret = load_file(blkio, head, size, (unsigned char *)config_base_addr);
	if (!ret) {
		li->config_base = config_base_addr;
		li->config_size = *size;
	} else {
		li->config_base = 0;
		li->config_size = 0;
	}
	return ret;
}

int
load_kernel_and_config(struct loader_info *li)
{
	EFI_HANDLE handles[128];
	EFI_BLOCK_IO *blkio;
	UINTN i, nparts = sizeof(handles);
	EFI_STATUS status;
	EFI_DEVICE_PATH *devpath;
	unsigned char buf[512];
	EFI_LBA head;
	UINTN size;

	status = systab->BootServices->LocateHandle(ByProtocol, &BlockIoGUID, NULL, &nparts, handles);
	nparts /= sizeof(handles[0]);

	for (i = 0; i < nparts; i++) {

		status = systab->BootServices->HandleProtocol(handles[i], &DevicePathGUID, (void **)&devpath); 
		if (EFI_ERROR(status))
			continue;

		while (!IsDevicePathEnd(NextDevicePathNode(devpath)))
			devpath = NextDevicePathNode(devpath);

		status = systab->BootServices->HandleProtocol(handles[i], &BlockIoGUID, (void **)&blkio); 
		if (EFI_ERROR(status))
			continue;

		if (!blkio->Media->LogicalPartition)
			continue;

		status = blkio->ReadBlocks(blkio, blkio->Media->MediaId, 0, 512, buf);
		if (EFI_ERROR(status))
			continue;

		if (buf[0] != 0xeb && buf[0] != 0xe9)
			continue;

		if (buf[510] != 0x55 || buf[511] != 0xaa)
			continue;

		/* ここまできたら blkio は FAT ファイルシステム */

		if (search_kernel(blkio, &head, &size))
			continue;

		if (load_kernel(blkio, &head, &size, li))
			return -1;

		printstr("KERNEL BASE: ");
		printhex64(li->kernel_base);
		putchar('\n');
		printstr("KERNEL SIZE: ");
		printhex64(li->kernel_size);
		putchar('\n');

		if (search_config(blkio, &head, &size)
		  || (size == 0)
		  || load_config(blkio, &head, &size, li)) {
			li->config_base = 0;
			li->config_size = 0;
		}

		printstr("CONFIG BASE: ");
		printhex64(li->config_base);
		putchar('\n');
		printstr("CONFIG SIZE: ");
		printhex64(li->config_size);
		putchar('\n');

		/* 正常完了 */
		return 0;
	}

	/* 失敗 */
	return -1;
}

