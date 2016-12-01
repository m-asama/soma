/**
 * @file	utf8str.h
 * @brief	文字列のクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

class utf8str {

public:
	/**
	 *
	 */
	utf8str();

	/**
	 *
	 */
	virtual ~utf8str();

	/**
	 *
	 */
	utf8str(const utf8str &src);

	/**
	 *
	 */
	utf8str(const utf8str &&src) = delete;

	/**
	 *
	 */
	utf8str(const char *s);

	/**
	 *
	 */
	utf8str &operator=(const utf8str &src);

	/**
	 *
	 */
	utf8str &operator=(const utf8str &&src) = delete;

	/**
	 *
	 */
	utf8str &operator=(const char *s);

	/**
	 *
	 */
	utf8str &operator+=(const utf8str &s);

	/**
	 *
	 */
	utf8str &operator+=(const char *s);

	/**
	 *
	 */
	bool operator==(const utf8str &s);

	/**
	 *
	 */
	bool operator==(const char *s);

	/**
	 *
	 */
	bool operator!=(const utf8str &s);

	/**
	 *
	 */
	bool operator!=(const char *s);

	/**
	 *
	 */
	void init_utf8str(const char *s);

	/**
	 *
	 */
	utf8str &assign_utf8str(const char *s);

	/**
	 *
	 */
	utf8str &append_utf8str(const char *s, size_t width);

	/**
	 *
	 */
	utf8str &append_sint64(int64_t val, size_t width);

	/**
	 *
	 */
	utf8str &append_uint64(uint64_t val, size_t width);

	/**
	 *
	 */
	utf8str &append_hex64(uint64_t val, size_t width);

	/**
	 *
	 */
	bool is_equal(const char *s);

	/**
	 *
	 */
	const char *ptr(void) const;

	/**
	 *
	 */
	size_t length() const;

	/**
	 *
	 */
	size_t width() const;

private:
	/**
	 *
	 */
	char *m_buffer;

	/**
	 *
	 */
	size_t m_buffer_size;

};

