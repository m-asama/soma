/**
 * @file	config_model_length.cpp
 * @brief	設定モデルノードで用いられる長さクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_length.h"

config_model_length::config_model_length(utf8str length)
	: m_length(length)
{
}

config_model_length::~config_model_length()
{
}

bool
config_model_length::operator==(const config_model_length &rhs)
{
	return (this == &rhs);
}

void
config_model_length::length(utf8str length)
{
	m_length = length;
}

utf8str
config_model_length::length()
{
	return m_length;
}

bool
config_model_length::check(utf8str value)
{
	return true;
}

