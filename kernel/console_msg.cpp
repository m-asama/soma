/**
 * @file	console_msg.cpp
 * @brief	コンソールから用いられるメッセージの実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "console_msg.h"

msg msg_null[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "",
	},
};

