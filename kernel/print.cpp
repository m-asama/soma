/**
 * @file	print.cpp
 * @brief	表示関連の処理をする関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
//#include "assembly.h"
#include "console_management.h"
#include "unicode.h"
#include "string.h"

int
putchar(const uint32_t c)
{
	console_putchar(c);
	return 1;
}

int
printhex8(const uint8_t uc)
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
printhex16(const uint16_t us)
{
	int i;

	for (i = 0; i < 2; ++i) {
		printhex8((us >> (8*(1-i))) & 0xff);
	}

	return 0;
}

int
printhex32(const uint32_t ui)
{
	int i;

	for (i = 0; i < 4; ++i) {
		printhex8((ui >> (8*(3-i))) & 0xff);
	}

	return 0;
}

int
printhex64(const uint64_t ul)
{
	int i;

	for (i = 0; i < 8; ++i) {
		printhex8((ul >> (8*(7-i))) & 0xff);
	}

	return 0;
}

int
printstr(const char *str)
{
	int b;
	uint32_t c;

	while (*str != '\0') {
		b = utf8_to_unicode(str, &c);
		putchar(c);
		str += b;
	}

	return 0;
}

int
printstr(const string &str)
{
	return printstr(str.ptr());
}


