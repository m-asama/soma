/**
 * @file	font_data.h
 * @brief	フォントのビットマップを格納するための構造体。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "type.h"

struct font_data {

	/*
	 *
	 */
	uint32_t unicode;

	/*
	 *
	 */
	uint8_t width;

	/*
	 *
	 */
	uint8_t height;

	/*
	 *
	 */
	uint16_t data[16];

	/*
	 *
	 */
	bool operator==(const struct font_data &rhs)
	{
		return (unicode == rhs.unicode);
	}

};

extern struct font_data font_data[];

