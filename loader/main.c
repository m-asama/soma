/*
 * Author:
 * 	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include <efi.h>
#include <eficonsctl.h>

#include "main.h"
#include "print.h"
#include "loader.h"

#include "loader_info.h"

EFI_SYSTEM_TABLE		*systab;
EFI_HANDLE			*image;
EFI_BOOT_SERVICES		*BS;

EFI_GUID			ConsoleControlGUID = EFI_CONSOLE_CONTROL_PROTOCOL_GUID;
EFI_GUID			GraphicsOutputGUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
EFI_GUID			BlockIoGUID = BLOCK_IO_PROTOCOL;
EFI_GUID			DevicePathGUID = DEVICE_PATH_PROTOCOL;
EFI_GUID			ACPI20TableGUID = ACPI_20_TABLE_GUID;

const uint64_t			kernel_base_addr = 0x0000000000100000;

UINTN mapkey;

int
set_efifb_info(struct loader_info *li)
{
	EFI_GRAPHICS_OUTPUT *gop;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *mode;
	EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
	EFI_STATUS status;

	status = BS->LocateProtocol(&GraphicsOutputGUID, NULL, (VOID **)&gop);
	if (EFI_ERROR(status)) {
		printstr("set_efifb_info: LocateProtocol failed.\n");
		return -1;
	}

	mode = gop->Mode;
	info = gop->Mode->Info;

	li->fb_addr = mode->FrameBufferBase;
	li->fb_size = mode->FrameBufferSize;
	li->fb_height = info->VerticalResolution;
	li->fb_width = info->HorizontalResolution;
	li->fb_stride = info->PixelsPerScanLine;

	switch (info->PixelFormat) {
	case PixelRedGreenBlueReserved8BitPerColor:
		li->fb_mask_red = 0x000000ff;
		li->fb_mask_green = 0x0000ff00;
		li->fb_mask_blue = 0x00ff0000;
		li->fb_mask_reserved = 0xff000000;
		break;
	case PixelBlueGreenRedReserved8BitPerColor:
		li->fb_mask_red = 0x00ff0000;
		li->fb_mask_green = 0x0000ff00;
		li->fb_mask_blue = 0x000000ff;
		li->fb_mask_reserved = 0xff000000;
		break;
	case PixelBitMask:
		li->fb_mask_red = info->PixelInformation.RedMask;
		li->fb_mask_green = info->PixelInformation.GreenMask;
		li->fb_mask_blue = info->PixelInformation.BlueMask;
		li->fb_mask_reserved = info->PixelInformation.ReservedMask;
		break;
	default:
		printstr("set_efifb_info: unknown PixelFormat.\n");
		return -1;
	}

	return 0;
}

static int
is_equal_efi_guid(EFI_GUID *a, EFI_GUID *b)
{
	int i;
	if ((a->Data1 != b->Data1)
	 || (a->Data2 != b->Data2)
	 || (a->Data3 != b->Data3))
		return 0;
	for (i = 0; i < 8; ++i)
		if (a->Data4[i] != b->Data4[i])
			return 0;
	return 1;
}

int
set_rsdp_info(struct loader_info *li)
{
	EFI_GUID *id;
	int i;

	for (i = 0; i < systab->NumberOfTableEntries; ++i) {
		id = &systab->ConfigurationTable[i].VendorGuid;
		if (is_equal_efi_guid(id, &ACPI20TableGUID)) {
			li->rsdp_table = (uint64_t)systab->ConfigurationTable[i].VendorTable;
			return 0;
		}
	}

	return -1;
}

int
set_memmap_info(struct loader_info *li)
{
	UINTN total_size, desc_size, pages;
	UINT32 desc_ver;
	EFI_STATUS status;
	EFI_MEMORY_DESCRIPTOR *map, *p;
	struct li_memdesc *limd;
	int i, descs;

	total_size = 0;
	BS->GetMemoryMap(&total_size, 0, &mapkey, &desc_size, &desc_ver);

	pages = (total_size / 4096);
	if (total_size % 4096)
		++pages;
	map = (EFI_MEMORY_DESCRIPTOR *)kernel_base_addr;
	status = BS->AllocatePages(AllocateMaxAddress, EfiLoaderData, pages, (EFI_PHYSICAL_ADDRESS *)&map);
	if (EFI_ERROR(status)) {
		printstr("set_memmap_info: AllocatePages(1) failed.\n");
		return -1;
	}

	descs = total_size / desc_size;
	pages = ((descs * sizeof(struct li_memdesc)) / 4096);
	if ((descs * sizeof(struct li_memdesc)) % 4096)
		++pages;
	limd = (struct li_memdesc *)kernel_base_addr;
	status = BS->AllocatePages(AllocateMaxAddress, EfiLoaderData, pages, (EFI_PHYSICAL_ADDRESS *)&limd);
	if (EFI_ERROR(status)) {
		printstr("set_memmap_info: AllocatePages(2) failed.\n");
		return -1;
	}

	status = BS->GetMemoryMap(&total_size, map, &mapkey, &desc_size, &desc_ver);
	if (EFI_ERROR(status)) {
		printstr("set_memmap_info: GetMemoryMap failed.\n");
		return -1;
	}

	li->mm_mds = limd;
	for (i = 0, p = map; i < descs; ++i, p = (EFI_MEMORY_DESCRIPTOR *)(((UINT8 *) p) + desc_size)) {
		li->mm_mds[i].md_type = p->Type;
		li->mm_mds[i].md_phys_start = p->PhysicalStart;
		li->mm_mds[i].md_virt_start = p->VirtualStart;
		li->mm_mds[i].md_num_of_pages = p->NumberOfPages;
		li->mm_mds[i].md_attr = p->Attribute;
	}
	li->mm_num_of_mds = descs;

	return 0;
}

struct loader_info *
alloc_loader_info(void)
{
	struct loader_info *li = (struct loader_info *)kernel_base_addr;
	UINTN pages;
	EFI_STATUS status;

	pages = sizeof(struct loader_info) / 4096;
	if (sizeof(struct loader_info) % 4096)
		++pages;

	status = BS->AllocatePages(AllocateMaxAddress, EfiLoaderData, pages, (EFI_PHYSICAL_ADDRESS *)&li);
	if (EFI_ERROR(status)) {
		printstr("alloc_loader_info: AllocateMaxAddress failed.\n");
		return NULL;
	}

	return li;
}

EFI_STATUS
efi_main(EFI_HANDLE Ximage, EFI_SYSTEM_TABLE* Xsystab)
{
	EFI_CONSOLE_CONTROL_PROTOCOL *ConsoleControl = NULL;
	EFI_STATUS status;
	struct loader_info *li;
	void (*kernel_main)(void *ptr) = (void (*)(void *ptr))kernel_base_addr;

	systab = Xsystab;
	image = Ximage;
	BS = systab->BootServices;

	status = BS->LocateProtocol(&ConsoleControlGUID, NULL, (VOID **)&ConsoleControl);
	if (status == EFI_SUCCESS)
		(void)ConsoleControl->SetMode(ConsoleControl, EfiConsoleControlScreenText);

	printstr("loader\n");

	li = alloc_loader_info();
	if (!li)
		goto exit;

	if (set_efifb_info(li))
		goto exit;

	if (set_rsdp_info(li))
		goto exit;

	if (load_kernel_and_config(li))
		goto exit;

	if (set_memmap_info(li))
		goto exit;

	status = BS->ExitBootServices(image, mapkey);
	if (EFI_ERROR(status)) {
		printstr("efi_main: ExitBootServices failed.\n");
		goto exit;
	}

	kernel_main((void *)li);

exit:
	while (1) {}
	return EFI_SUCCESS;
}

