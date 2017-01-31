/**
 * @file	console_base.cpp
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "unicode.h"
#include "command_node.h"
#include "command_management.h"
#include "config_management.h"
#include "debug.h"

#include "console_base.h"

console_base::console_base()
{
	m_cols = 0;
	m_rows = 0;
	m_buffer = nullptr;
	m_cursor_x = 0;
	m_cursor_y = 0;
	m_console_thread = nullptr;
	m_current_role = console_role::role_operator;
	m_current_mode = console_mode::mode_command_prompt;
	m_current_lang = console_lang::lang_ja;
}

console_base::~console_base()
{
	bidir_node<utf8str> *bn;
	m_cols = 0;
	m_rows = 0;
	if (m_buffer != nullptr)
		delete[] m_buffer;
	m_cursor_x = 0;
	m_cursor_y = 0;
	if (m_console_thread != nullptr)
		delete m_console_thread;
	while ((bn = m_command_history.head()) != nullptr) {
		m_command_history.remove(bn->v());
		delete &bn->v();
	}
}

bool
console_base::operator==(const console_base &rhs)
{
	return (this == &rhs);
}

void
console_base::name(utf8str name)
{
	m_name = name;
}

utf8str
console_base::name()
{
	return m_name;
}

void
console_base::cols(uint32_t cols)
{
	m_cols = cols;
}

uint32_t
console_base::cols()
{
	return m_cols;
}

void
console_base::rows(uint32_t rows)
{
	m_rows = rows;
}

uint32_t
console_base::rows()
{
	return m_rows;
}

void
console_base::buffer(uint32_t *buffer)
{
	m_buffer = buffer;
}

uint32_t *
console_base::buffer()
{
	return m_buffer;
}

void
console_base::cursor_x(uint32_t cursor_x)
{
	m_cursor_x = cursor_x;
}

uint32_t
console_base::cursor_x()
{
	return m_cursor_x;
}

void
console_base::cursor_y(uint32_t cursor_y)
{
	m_cursor_y = cursor_y;
}

uint32_t
console_base::cursor_y()
{
	return m_cursor_y;
}

void
console_base::console_thread(thread *console_thread)
{
	m_console_thread = console_thread;
}

thread *
console_base::console_thread()
{
	return m_console_thread;
}

void
console_base::current_role(console_role current_role)
{
	m_current_role = current_role;
}

console_role
console_base::current_role()
{
	return m_current_role;
}

void
console_base::current_mode(console_mode current_mode)
{
	m_current_mode = current_mode;
}

console_mode
console_base::current_mode()
{
	return m_current_mode;
}

void
console_base::current_lang(console_lang current_lang)
{
	m_current_lang = current_lang;
}
 
console_lang
console_base::current_lang()
{
	return m_current_lang;
}

void
console_base::reset()
{
	int x, y;

	if (m_buffer != nullptr)
		delete[] m_buffer;

	if (m_cols > 0 && m_rows > 0) {
		m_buffer = new uint32_t[m_cols * m_rows];
		for (y = 0; y < m_rows; ++y) {
			for (x = 0; x < m_cols; ++x) {
				m_buffer[m_cols * y + x] = ' ';
			}
		}
	}

	m_cursor_x = 0;
	m_cursor_y = 0;
}

void
console_base::refresh()
{
}

void
console_base::handle_config_model_completion(uint32_t c, config_model_node *&cmn, utf8str &remaining, uint64_t arg_parsed, bool exclude_leaf)
{
	bidir_node<config_model_node> *bn, *match_bn = nullptr;
	int match = 0;
	sorted_list<config_model_node> &children = cmn->children();
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		config_model_node &node = bn->v();
		if (node.config() == false) {
			continue;
		}
		if (arg_parsed > 0) {
			if (node.identifier().beginning(remaining)) {
				++match;
				match_bn = bn;
			}
		} else {
			//dp("\nid = ["); dp(node.identifier()); dp("]\n");
			//dp("rm = ["); dp(remaining); dp("]\n");
		}
	}
	if (match == 1) {
		if (arg_parsed > 0) {
			config_model_node &node = match_bn->v();
			m_command_line.truncate(remaining.unicode_length());
			m_command_line += node.identifier();
			m_command_line += ' ';
			for (int i = 0; i < remaining.unicode_length(); ++i) {
				putchar(0x7f);
			}
			print(node.identifier());
			print(" ");
		} else {


		}
	} else {
		print("\n");
		if (arg_parsed > 0) {
			for (bn = children.head(); bn != nullptr; bn = bn->next()) {
				config_model_node &node = bn->v();
				if (node.config() == false) {
					continue;
				}
				print_description(node.identifier(), node.description());
			}
		} else {
		}
		print_prompt();
	}
}

void
console_base::handle_command_completion(uint32_t c, command_node *&cn, config_model_node *&cmn, utf8str &remaining, uint64_t arg_parsed)
{
	bidir_node<command_node> *bn, *match_bn = nullptr;
	int match = 0;
	sorted_list<command_node> &children = cn->children();
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		command_node &node = bn->v();
		switch (node.type()) {
		case command_node_type::type_keyword:
			if (node.keyword_label().beginning(remaining)) {
				++match;
				match_bn = bn;
			}
			break;
		case command_node_type::type_variable:
			break;
		case command_node_type::type_config_model:
			handle_config_model_completion(c, cmn, remaining, arg_parsed, false);
			return;
			break;
		case command_node_type::type_config_model_edit:
			handle_config_model_completion(c, cmn, remaining, arg_parsed, true);
			return;
			break;
		case command_node_type::type_root:
			break;
		}
	}
	if (match == 1) {
		command_node &node = match_bn->v();
		switch (node.type()) {
		case command_node_type::type_keyword:
			m_command_line.truncate(remaining.unicode_length());
			m_command_line += node.keyword_label();
			m_command_line += ' ';
			for (int i = 0; i < remaining.unicode_length(); ++i) {
				putchar(0x7f);
			}
			print(node.keyword_label());
			print(" ");
			break;
		case command_node_type::type_variable:
			break;
		case command_node_type::type_config_model:
			break;
		case command_node_type::type_config_model_edit:
			break;
		case command_node_type::type_root:
			break;
		}
	} else {
		print("\n");
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			command_node &node = bn->v();
			switch (node.type()) {
			case command_node_type::type_keyword:
				print_description(node.keyword_label(), node.description());
				break;
			case command_node_type::type_variable:
				break;
			case command_node_type::type_config_model:
				break;
			case command_node_type::type_config_model_edit:
				break;
			case command_node_type::type_root:
				break;
			}
		}
		print_prompt();
	}
}

void
console_base::handle_command_prompt(uint32_t c)
{
	command_node *cn = nullptr;
	config_model_node *cmn = nullptr;
	utf8str remaining("");
	utf8str remaining1("");
	utf8str remaining2("");
	utf8str xxx("false");

	command_node_nearest(m_command_line, cn, remaining);
	remaining1 = remaining;
	sorted_list<command_node> &children = cn->children();
	bidir_node<command_node> *bn;
	bool config_model = false;
	uint64_t arg_parsed = 0;
	bool exclude_leaf = false;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		command_node &cmnt = bn->v();
		if (cmnt.type() == command_node_type::type_config_model) {
			config_model = true;
			break;
		}
		if (cmnt.type() == command_node_type::type_config_model_edit) {
			config_model = true;
			exclude_leaf = true;
			break;
		}
	}
	if (config_model == true) {
		xxx = "true";
		config_model_node_nearest(remaining, cmn, remaining, arg_parsed, exclude_leaf);
		remaining2 = remaining;
	}

	switch (c) {
	case 0x7f:
		if (m_command_line.byte_length() > 0) {
			m_command_line.truncate(1);
			putchar(c);
		}
		break;
	case ' ':
	case '\t':
		if ((remaining == "")
		 && (m_command_line.byte_length() > 0)
		 && (m_command_line[-1] != ' ')) {
			m_command_line += ' ';
			putchar(' ');
		} else {
			handle_command_completion(c, cn, cmn, remaining, arg_parsed);
		}
		break;
	case '\r':
	case '\n':
		if (remaining == "") {
			putchar(c);
			if (cn->execute() != nullptr) {
				cn->execute()(*this, m_command_line);
			}
			m_command_line = "";
			print_prompt();
		}
		break;
	case 0x1b:

		{
		utf8str s;
		s += "\n";
		s += "m_command_line    = ["; s += m_command_line; s += "]\n";
		s += "remaining1        = ["; s += remaining1; s += "]\n";
		s += "remaining2        = ["; s += remaining2; s += "]\n";
		s += "xxx               = ["; s += xxx; s += "]\n";
		s += "arg_parsed        = ["; 
		s.append_sint64(arg_parsed, 0);
		s += "]\n";
		command_node *cnt = cn;
		s += "command_node      = ";
		while (cnt != nullptr) {
			s += " < ";
			s += cnt->keyword_label();
			cnt = cnt->parent();
		}
		s += "\n";
		config_model_node *cmnt = cmn;
		s += "config_model_node = ";
		while (cmnt != nullptr) {
			s += " < ";
			s += cmnt->identifier();
			cmnt = cmnt->parent();
		}
		s += "\n";
		dp(s);
		}

		break;
	default:
		m_command_line += c;
		putchar(c);
	}
}

void
console_base::getchar(uint32_t c)
{
	switch (m_current_mode) {
	case console_mode::mode_login_prompt:
		break;
	case console_mode::mode_command_prompt:
		handle_command_prompt(c);
		break;
	case console_mode::mode_dont_echo:
		break;
	case console_mode::mode_pager:
		break;
	}
}

int
console_base::print(const char *str)
{
	utf8str s(str);
	return print(s);
}

int
console_base::print(utf8str str)
{
	int c = 0;
	for (int i = 0; i < str.unicode_length(); ++i) {
		putchar(str[i]);
		++c;
	}
	return c;
}

void
console_base::line_shift()
{
	int x, y;

	if (m_buffer == nullptr)
		return;

	for (y = 0; y < (m_rows - 1); ++y) {
		for (x = 0; x < m_cols; ++x) {
			m_buffer[m_cols * y + x] = m_buffer[m_cols * (y + 1) + x];
		}
	}
	for (x = 0; x < m_cols; ++x) {
		m_buffer[m_cols * (m_rows - 1) + x] = ' ';
	}

	refresh();
}

void
console_base::print_prompt()
{
	utf8str prompt;
	prompt += "[edit";
	if (m_edit_path.byte_length() > 0) {
		prompt += " ";
	}
	prompt += m_edit_path;
	prompt += "]\n";
	switch (m_current_role) {
	case console_role::role_administrator:
		prompt += "# ";
		break;
	case console_role::role_operator:
		prompt += "$ ";
		break;
	default:
		prompt += "? ";
	}
	prompt += m_command_line;
	print(prompt);
}

void
console_base::print_description(utf8str label, msg *description)
{
	if (description == nullptr) {
		return;
	}

	utf8str desc;
	desc = description[0].msg;
	for (int i = 0; i < sizeof(console_lang); ++i) {
		if (description[i].lang == m_current_lang) {
			desc = description[i].msg;
			break;
		}
	}

	utf8str s;
	s += "    ";
	s += label;
	if (label.width() < 15) {
		for (int i = label.width(); i < 15; ++i) {
			s += ' ';
		}
	} else {
		s += "\n                   ";
	}
	s += ' ';
	for (int i = 0; i < desc.unicode_length(); ++i) {
		if (s.width() > (m_cols - 2)) {
			s += "\n";
			print(s);
			s = "                    ";
			
		}
		s += desc[i];
	}
	s += "\n";
	print(s);
}

void
console_base::handle_arrow(console_arrow arrow)
{
	switch (arrow) {
	case console_arrow::arrow_up:
		putchar('u');
		break;
	case console_arrow::arrow_down:
		putchar('d');
		break;
	case console_arrow::arrow_right:
		putchar('r');
		break;
	case console_arrow::arrow_left:
		putchar('l');
		break;
	}
}

