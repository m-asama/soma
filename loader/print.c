/*
 * Author:
 * 	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include <efi.h>

#include "main.h"

int
putchar(char c)
{
	CHAR16 buf[2];

	if (c == '\n') {
		buf[0] = '\r';
		buf[1] = 0;
		systab->ConOut->OutputString(systab->ConOut, buf);
	}
	buf[0] = c;
	buf[1] = 0;
	systab->ConOut->OutputString(systab->ConOut, buf);
	return 1;
}

int
printhex8(unsigned char uc)
{
	unsigned char u, l;

	u = 0xf & (uc >> 4);
	l = 0xf & uc;
	if (0 <= u && u <= 9) {
		putchar('0' + u);
	} else {
		putchar('a' + u - 10);
	}
	if (0 <= l && l <= 9) {
		putchar('0' + l);
	} else {
		putchar('a' + l - 10);
	}

	return 0;
}

int
printhex64(unsigned long ul)
{
	int i;

	for (i = 0; i < 8; ++i) {
		printhex8((ul >> (8*(7-i))) & 0xff);
	}

	return 0;
}

int
printstr(char *str)
{
	while (*str != '\0') {
		putchar(*str);
		++str;
	}

	return 0;
}

