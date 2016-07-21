/*
 * Author:
 * 	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

extern EFI_SYSTEM_TABLE		*systab;
extern EFI_HANDLE		*image;
extern EFI_BOOT_SERVICES	*BS;

extern EFI_GUID			ConsoleControlGUID;
extern EFI_GUID			GraphicsOutputGUID;
extern EFI_GUID			BlockIoGUID;
extern EFI_GUID			DevicePathGUID;

extern const uint64_t		kernel_base_addr;

