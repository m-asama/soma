/**
 * @file	string.h
 * @brief	文字列のクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

class string {

public:
	/**
	 *
	 */
	string();

	/**
	 *
	 */
	virtual ~string();

	/**
	 *
	 */
	string(const string &src);

	/**
	 *
	 */
	string(const string &&src) = delete;

	/**
	 *
	 */
	string(const char *s);

	/**
	 *
	 */
	string &operator=(const string &src);

	/**
	 *
	 */
	string &operator=(const string &&src) = delete;

	/**
	 *
	 */
	string &operator=(const char *s);

	/**
	 *
	 */
	string &operator+=(const string &s);

	/**
	 *
	 */
	string &operator+=(const char *s);

	/**
	 *
	 */
	bool operator==(const string &s);

	/**
	 *
	 */
	bool operator==(const char *s);

	/**
	 *
	 */
	bool operator!=(const string &s);

	/**
	 *
	 */
	bool operator!=(const char *s);

	/**
	 *
	 */
	void init_string(const char *s);

	/**
	 *
	 */
	string &assign_string(const char *s);

	/**
	 *
	 */
	string &append_string(const char *s, size_t width);

	/**
	 *
	 */
	string &append_sint64(int64_t val, size_t width);

	/**
	 *
	 */
	string &append_uint64(uint64_t val, size_t width);

	/**
	 *
	 */
	string &append_hex64(uint64_t val, size_t width);

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

