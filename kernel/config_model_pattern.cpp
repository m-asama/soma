/**
 * @file	config_model_pattern.cpp
 * @brief	設定モデルノードで用いられるパターンクラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_pattern.h"

config_model_pattern::config_model_pattern(utf8str pattern)
	: m_pattern(pattern)
{
}

config_model_pattern::~config_model_pattern()
{
}

bool
config_model_pattern::operator==(const config_model_pattern &rhs)
{
	return (this == &rhs);
}

bool
config_model_pattern::check(utf8str value)
{
	return true;
}

