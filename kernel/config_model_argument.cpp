/**
 * @file	config_model_argument.cpp
 * @brief	設定モデルノードで用いられる引数クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_argument.h"

config_model_argument::config_model_argument(utf8str label, sint64_t value)
	: m_label(label), m_value(value)
{
}

config_model_argument::~config_model_argument()
{
}

bool
config_model_argument::operator==(const config_model_argument &rhs)
{
	return (this == &rhs);
}

