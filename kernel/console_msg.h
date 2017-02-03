/**
 * @file	console_msg.h
 * @brief	コンソールから用いられるメッセージの宣言。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

/**
 * コンソールの言語。
 */
enum class console_lang {
	lang_ja,
	lang_en,
};

/**
 * 多言語対応文字列。
 */
struct msg {
	console_lang lang;
	char const *msg;
};

extern msg msg_null[];

