/**
 * @file	utf8str.cpp
 * @brief	文字列のクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "memory_management.h"
#include "unicode.h"
#include "font.h"
#include "font_data.h"

#include "print.h"
#include "debug.h"

#include "utf8str.h"

const static size_t buffer_block_size = 256;
const static size_t max_width = 256;

static inline size_t
length(const char *s)
{
	size_t length = 0;

	if (s == nullptr) {
		return 0;
	}

	while (s[length] != '\0') {
		++length;
	}

	return length;
}

static inline size_t
width(const char *s)
{
	size_t width = 0;
	size_t i = 0;
	uint32_t c;
	struct font_data *font;

	if (s == nullptr) {
		return 0;
	}

	while (s[i] != '\0') {
		i += utf8_to_unicode(&s[i], &c);
		font = font_find(c);
		if (font != nullptr) {
			width += font->width / 8;
		} else {
			++width;
		}
	}

	return width;
}

static inline int
copy(const char *src, char *dst)
{
	int i = 0;

	if ((src == nullptr) || (dst == nullptr)) {
		return 0;
	}

	while (src[i] != '\0') {
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';

	return i;
}

utf8str::utf8str()
{
	m_buffer = nullptr;
	m_buffer_size = 0;
}

utf8str::~utf8str()
{
	if (m_buffer != nullptr) {
		memory_free(m_buffer);
	}

	m_buffer = nullptr;
	m_buffer_size = 0;
}

utf8str::utf8str(const utf8str &src)
{
	init_utf8str(src.ptr());
}

utf8str::utf8str(const char *s)
{
	init_utf8str(s);
}

utf8str &
utf8str::operator=(const utf8str &src)
{
	return assign_utf8str(src.ptr());
}

utf8str &
utf8str::operator=(const char *s)
{
	return assign_utf8str(s);
}

utf8str &
utf8str::operator+=(const utf8str &s)
{
	return append_utf8str(s.ptr(), 0);
}

utf8str &
utf8str::operator+=(const char *s)
{
	return append_utf8str(s, 0);
}

bool
utf8str::operator==(const utf8str &s)
{
	return is_equal(s.ptr());
}

bool
utf8str::operator==(const char *s)
{
	return is_equal(s);
}

bool
utf8str::operator!=(const utf8str &s)
{
	return !is_equal(s.ptr());
}

bool
utf8str::operator!=(const char *s)
{
	return !is_equal(s);
}

bool
utf8str::operator>(const utf8str &s)
{
	return is_large(s.ptr());
}

bool
utf8str::operator>(const char *s)
{
	return is_large(s);
}

bool
utf8str::operator<(const utf8str &s)
{
	return is_small(s.ptr());
}

bool
utf8str::operator<(const char *s)
{
	return is_small(s);
}

void
utf8str::init_utf8str(const char *s)
{
	size_t buffer_size = 0;

	m_buffer = nullptr;
	m_buffer_size = 0;

	if (s == nullptr) {
		return;
	}

	while (buffer_size <= ::length(s)) {
		buffer_size += buffer_block_size;
	}

	m_buffer = (char *)memory_alloc(buffer_size);
	m_buffer_size = 0;
	if (m_buffer == nullptr) {
		return;
	}
	m_buffer_size = buffer_size;

	::copy(s, m_buffer);
}

utf8str &
utf8str::assign_utf8str(const char *s)
{
	size_t buffer_size = 0;

	if (s == nullptr) {
		return *this;
	}

	if (m_buffer != nullptr) {
		memory_free(m_buffer);
	}
	m_buffer_size = 0;

	while (buffer_size <= ::length(s)) {
		buffer_size += buffer_block_size;
	}
	m_buffer = (char *)memory_alloc(buffer_size);
	m_buffer_size = 0;
	if (m_buffer == nullptr) {
		return *this;
	}
	m_buffer_size = buffer_size;

	::copy(s, m_buffer);

	return *this;
}

utf8str &
utf8str::append_utf8str(const char *s, size_t width)
{
	size_t length = 0;
	char *buffer = nullptr;
	size_t buffer_size = 0;
	char *ptr;
	int n1, n2, i;

	if (s == nullptr) {
		return *this;
	}
/*
	if (width < ::length(s)) {
		width = ::length(s);
	}
*/
	if (width < ::width(s)) {
		width = ::width(s);
	}
	length = this->length() + width + 1;
	while (buffer_size <= length) {
		buffer_size += buffer_block_size;
	}

	buffer = (char *)memory_alloc(buffer_size);
	if (buffer == nullptr) {
		return *this;
	}

	ptr = buffer;
	n1 = ::copy(m_buffer, ptr);
	ptr += n1;
	n2 = ::copy(s, ptr);
	ptr += n2;
	for (i = 0; i < (width - ::width(s)); ++i) {
		*ptr = ' ';
		++ptr;
	}
	*ptr = '\0';

	if (m_buffer != nullptr) {
		memory_free(m_buffer);
	}

	m_buffer = buffer;
	m_buffer_size = buffer_size;

	return *this;
}

utf8str &
utf8str::append_sint64(sint64_t val, size_t width)
{
	char buf[max_width + 1];
	bool pos = true;
	uint64_t div, mod;
	int i;

	if (val < 0) {
		pos = false;
		val = val * -1;
	}

	if (width > max_width) {
		width = max_width;
	}

	for (i = 0; i < max_width; ++i) {
		buf[i] = ' ';
	}
	buf[max_width] = '\0';

	mod = val % 10;
	div = val / 10;
	i = max_width - 1;
	buf[i] = '0' + mod;
	while (div > 0) {
		mod = div % 10;
		div = div / 10;
		--i;
		buf[i] = '0' + mod;
	}

	if (!pos) {
		--i;
		buf[i] = '-';
	}

	if ((max_width - i) < width) {
		i = max_width - width;
	}

	append_utf8str(&buf[i], 0);

	return *this;
}

utf8str &
utf8str::append_uint64(uint64_t val, size_t width)
{
	char buf[max_width + 1];
	uint64_t div, mod;
	int i;

	if (width > max_width) {
		width = max_width;
	}

	for (i = 0; i < max_width; ++i) {
		buf[i] = ' ';
	}
	buf[max_width] = '\0';

	mod = val % 10;
	div = val / 10;
	i = max_width - 1;
	buf[i] = '0' + mod;
	while (div > 0) {
		mod = div % 10;
		div = div / 10;
		--i;
		buf[i] = '0' + mod;
	}

	if ((max_width - i) < width) {
		i = max_width - width;
	}

	append_utf8str(&buf[i], 0);

	return *this;
}

utf8str &
utf8str::append_hex64(uint64_t val, size_t width)
{
	char buf[max_width + 1];
	uint8_t c;
	int i;

	if (width > max_width) {
		width = max_width;
	}

	for (i = 0; i < max_width; ++i) {
		buf[i] = ' ';
	}
	buf[max_width] = '\0';

	for (i = 0; i < 16; ++i) {
		c = (val >> (i * 4)) & 0xf;
		if (0 <= c && c <= 9) {
			buf[max_width - 1 - i] = '0' + c;
		} else {
			buf[max_width - 1 - i] = 'a' + c - 10;
		}
	}

	append_utf8str(&buf[max_width - width], 0);

	return *this;
}

bool
utf8str::is_equal(const char *s)
{
	int i = 0;

	if ((m_buffer == nullptr) && (s == nullptr)) {
		return true;
	}

	if ((m_buffer == nullptr) || (s == nullptr)) {
		return false;
	}

	while ((m_buffer[i] != '\0') && (s[i] != '\0')) {
		if (m_buffer[i] != s[i]) {
			return false;
		}
		++i;
	}

	if (m_buffer[i] != s[i]) {
		return false;
	}

	return true;
}

bool
utf8str::is_large(const char *s)
{
	int i = 0;

	if ((m_buffer == nullptr) && (s == nullptr)) {
		return false;
	}

	if (m_buffer == nullptr) {
		return false;
	}

	if (s == nullptr) {
		return true;
	}

	while ((m_buffer[i] != '\0') && (s[i] != '\0')) {
		if (m_buffer[i] > s[i]) {
			return true;
		} else if (m_buffer[i] < s[i]) {
			return false;
		}
		++i;
	}

	if (m_buffer[i] != '\0') {
		return true;
	}

	return false;
}

bool
utf8str::is_small(const char *s)
{
	int i = 0;

	if ((m_buffer == nullptr) && (s == nullptr)) {
		return false;
	}

	if (m_buffer == nullptr) {
		return true;
	}

	if (s == nullptr) {
		return false;
	}

	while ((m_buffer[i] != '\0') && (s[i] != '\0')) {
		if (m_buffer[i] > s[i]) {
			return false;
		} else if (m_buffer[i] < s[i]) {
			return true;
		}
		++i;
	}

	if (m_buffer[i] != '\0') {
		return false;
	}

	return false;
}

const char *
utf8str::ptr() const
{
	return m_buffer;
}

size_t
utf8str::length() const
{
	if (m_buffer == nullptr) {
		return 0;
	}
	return ::length(m_buffer);
}

size_t
utf8str::width() const
{
	if (m_buffer == nullptr) {
		return 0;
	}
	return ::width(m_buffer);
}

