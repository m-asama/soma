/**
 * @file	unicode.cpp
 * @brief	UNICODE と UTF-8 に関連する関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"

int
unicode_to_utf8(const uint32_t *unicode, char *utf8)
{
	if (*unicode <= 0x0000007f) {
		utf8[0] = *unicode & 0x7f;
		return 1;
	}
	if ((0x00000080 <= *unicode) && (*unicode <= 0x000007ff)) {
		utf8[1] = (*unicode & 0x3f) | 0x80;
		utf8[0] = ((*unicode >> 6) & 0x1f) | 0xc0;
		return 2;
	}
	if ((0x00000800 <= *unicode) && (*unicode <= 0x0000ffff)) {
		utf8[2] = (*unicode & 0x3f) | 0x80;
		utf8[1] = ((*unicode >> 6) & 0x3f) | 0x80;
		utf8[0] = ((*unicode >> 12) & 0x0f) | 0xe0;
		return 3;
	}
	if ((0x00010000 <= *unicode) && (*unicode <= 0x001fffff)) {
		utf8[3] = (*unicode & 0x3f) | 0x80;
		utf8[2] = ((*unicode >> 6) & 0x3f) | 0x80;
		utf8[1] = ((*unicode >> 12) & 0x3f) | 0x80;
		utf8[0] = ((*unicode >> 18) & 0x07) | 0xf0;
		return 4;
	}
	if ((0x00200000 <= *unicode) && (*unicode <= 0x03ffffff)) {
		utf8[4] = (*unicode & 0x3f) | 0x80;
		utf8[3] = ((*unicode >> 6) & 0x3f) | 0x80;
		utf8[2] = ((*unicode >> 12) & 0x3f) | 0x80;
		utf8[1] = ((*unicode >> 18) & 0x3f) | 0x80;
		utf8[0] = ((*unicode >> 24) & 0x03) | 0xf8;
		return 5;
	}
	if ((0x04000000 <= *unicode) && (*unicode <= 0x7fffffff)) {
		utf8[5] = (*unicode & 0x3f) | 0x80;
		utf8[4] = ((*unicode >> 6) & 0x3f) | 0x80;
		utf8[3] = ((*unicode >> 12) & 0x3f) | 0x80;
		utf8[2] = ((*unicode >> 18) & 0x3f) | 0x80;
		utf8[1] = ((*unicode >> 24) & 0x3f) | 0x80;
		utf8[0] = ((*unicode >> 30) & 0x01) | 0xfc;
		return 6;
	}
	return 0;
}

int
utf8_to_unicode(const char *utf8, uint32_t *unicode)
{
	if ((utf8[0] & 0x80) == 0x00) {
		*unicode = utf8[0];
		return 1;
	} 
	if (((utf8[0] & 0xe0) == 0xc0)
	 && ((utf8[1] & 0xc0) == 0x80)) {
		*unicode = utf8[1] & 0x3f;
		*unicode |= (utf8[0] & 0x1f) << 6;
		return 2;
	}
	if (((utf8[0] & 0xf0) == 0xe0)
	 && ((utf8[1] & 0xc0) == 0x80)
	 && ((utf8[2] & 0xc0) == 0x80)) {
		*unicode = utf8[2] & 0x3f;
		*unicode |= (utf8[1] & 0x3f) << 6;
		*unicode |= (utf8[0] & 0x0f) << 12;
		return 3;
	}
	if (((utf8[0] & 0xf8) == 0xf0)
	 && ((utf8[1] & 0xc0) == 0x80)
	 && ((utf8[2] & 0xc0) == 0x80)
	 && ((utf8[3] & 0xc0) == 0x80)) {
		*unicode = utf8[3] & 0x3f;
		*unicode |= (utf8[2] & 0x3f) << 6;
		*unicode |= (utf8[1] & 0x3f) << 12;
		*unicode |= (utf8[0] & 0x07) << 18;
		return 4;
	}
	if (((utf8[0] & 0xfc) == 0xf8)
	 && ((utf8[1] & 0xc0) == 0x80)
	 && ((utf8[2] & 0xc0) == 0x80)
	 && ((utf8[3] & 0xc0) == 0x80)
	 && ((utf8[4] & 0xc0) == 0x80)) {
		*unicode = utf8[4] & 0x3f;
		*unicode |= (utf8[3] & 0x3f) << 6;
		*unicode |= (utf8[2] & 0x3f) << 12;
		*unicode |= (utf8[1] & 0x3f) << 18;
		*unicode |= (utf8[0] & 0x03) << 24;
		return 5;
	}
	if (((utf8[0] & 0xfe) == 0xfc)
	 && ((utf8[1] & 0xc0) == 0x80)
	 && ((utf8[2] & 0xc0) == 0x80)
	 && ((utf8[3] & 0xc0) == 0x80)
	 && ((utf8[4] & 0xc0) == 0x80)
	 && ((utf8[5] & 0xc0) == 0x80)) {
		*unicode = utf8[5] & 0x3f;
		*unicode |= (utf8[4] & 0x3f) << 6;
		*unicode |= (utf8[3] & 0x3f) << 12;
		*unicode |= (utf8[2] & 0x3f) << 18;
		*unicode |= (utf8[1] & 0x3f) << 24;
		*unicode |= (utf8[0] & 0x01) << 30;
		return 5;
	}
	return 0;
}

