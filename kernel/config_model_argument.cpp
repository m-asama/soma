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

void
config_model_argument::label(utf8str label)
{
	m_label = label;
}

utf8str
config_model_argument::label()
{
	return m_label;
}

void
config_model_argument::value(sint64_t value)
{
	m_value = value;
}

sint64_t
config_model_argument::value()
{
	return m_value;
}

