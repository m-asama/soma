/**
 * @file	config_model_range.cpp
 * @brief	設定モデルノードで用いられる範囲クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_range.h"

config_model_range::config_model_range(utf8str range)
	: m_range(range)
{
}

config_model_range::~config_model_range()
{
}

bool
config_model_range::operator==(const config_model_range &rhs)
{
	return (this == &rhs);
}

void
config_model_range::range(utf8str range)
{
	m_range = range;
}

utf8str
config_model_range::range()
{
	return m_range;
}

bool
config_model_range::check(utf8str value)
{
	return true;
}

