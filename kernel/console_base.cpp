/**
 * @file	console_base.cpp
 * @brief	コンソールの基底クラス。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "unicode.h"
#include "command_node.h"
#include "command_management.h"
#include "config_model_node.h"
#include "config_data_node.h"
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
console_base::edit_path(utf8str edit_path)
{
	m_edit_path = edit_path;
}

utf8str
console_base::edit_path()
{
	return m_edit_path;
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
console_base::handle_config_model_completion(uint32_t c, config_model_node *&cmn, config_data_node *&cdn, utf8str &remaining, uint64_t pos, bool exclude_leaf)
{
	// 次にノードの先頭が期待される時。
	if (config_model_node_completed(cmn, pos)) {
		bidir_node<config_model_node> *bn, *match_bn = nullptr;
		int match = 0;
		sorted_list<config_model_node> &children = cmn->children();
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			config_model_node &node = bn->v();
			if ((node.config() == false)
			 || (node.is_key() == true)
			 || ((exclude_leaf == true)
			  && ((node.statement() == config_model_node_statement::statement_leaf)
			   || (node.statement() == config_model_node_statement::statement_leaf_list)))) {
				continue;
			}
			if (node.identifier().beginning(remaining)) {
				++match;
				match_bn = bn;
			}
		}
		if (match == 1) {
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
			print("\n");
			for (bn = children.head(); bn != nullptr; bn = bn->next()) {
				config_model_node &node = bn->v();
				if ((node.config() == false)
				 || (node.is_key() == true)
				 || ((exclude_leaf == true)
				  && ((node.statement() == config_model_node_statement::statement_leaf)
				   || (node.statement() == config_model_node_statement::statement_leaf_list)))) {
					continue;
				}
				print_description(node.identifier(), node.description());
			}
			print_prompt();
		}
		return;
	}

	// 次にリーフやリストの変数部分が期待される時。
	int i = 0;
	bidir_node<config_model_node> *bn;
	config_model_node *t = nullptr;
	switch (cmn->statement()) {
	case config_model_node_statement::statement_container:
		break;
	case config_model_node_statement::statement_list:
		// リストの変数部分の時。
		for (bn = cmn->key().head(); bn != nullptr; bn = bn->next()) {
			if (i == pos) {
				break;
			}
			++i;
		}
		if (bn == nullptr) {
			break;
		}
		t = &bn->v();
		// このまま次の処理へ流れる。
	case config_model_node_statement::statement_leaf:
	case config_model_node_statement::statement_leaf_list:
		// リーフかリーフリストの時。
		if (t == nullptr) {
			t = cmn;
		}
		int match = 0;
		bidir_node<config_model_type> *bnt;
		for (bnt = t->types().head(); bnt != nullptr; bnt = bnt->next()) {
			config_model_type &type = bnt->v();
			bidir_node<config_model_argument> *bna, *match_bna = nullptr;
			switch (type.type()) {
			case config_model_node_type::type_bits:
			case config_model_node_type::type_boolean:
			case config_model_node_type::type_enumeration:
			case config_model_node_type::type_identityref:
				for (bna = type.arguments().head(); bna != nullptr; bna = bna->next()) {
					config_model_argument &argument = bna->v();
					if (argument.label().beginning(remaining)) {
						++match;
						match_bna = bna;
					}
				}
				if (match == 1) {
					m_command_line.truncate(remaining.unicode_length());
					m_command_line += match_bna->v().label();
					m_command_line += ' ';
					for (int i = 0; i < remaining.unicode_length(); ++i) {
						putchar(0x7f);
					}
					print(match_bna->v().label());
					print(" ");
				} else {
					print("\n");
					for (bna = type.arguments().head(); bna != nullptr; bna = bna->next()) {
						config_model_argument &argument = bna->v();
						print_description(argument.label(), argument.description());
					}
					print_prompt();
				}
				return;
				break;
			default:
				if ((cdn != nullptr) && (c == '\t') && (remaining != "")) {
					bidir_node<config_data_node> *cdnbn, *match_cdnbn = nullptr;
					for (cdnbn = cdn->children().head(); cdnbn != nullptr; cdnbn = cdnbn->next()) {
						config_data_node &cdnt = cdnbn->v();
						if (cdnt.label().beginning(remaining)) {
							++match;
							match_cdnbn = cdnbn;
						}
					}
					if (match == 1) {
						m_command_line.truncate(remaining.unicode_length());
						m_command_line += match_cdnbn->v().label();
						m_command_line += ' ';
						for (int i = 0; i < remaining.unicode_length(); ++i) {
							putchar(0x7f);
						}
						print(match_cdnbn->v().label());
						print(" ");
						return;
					}
				}
			}
		}
		print("\n");
		for (bnt = t->types().head(); bnt != nullptr; bnt = bnt->next()) {
			config_model_type &type = bnt->v();
			print_description(type.format(), type.description());
		}
		if (cdn != nullptr) {
			bidir_node<config_data_node> *cdnbn;
			for (cdnbn = cdn->children().head(); cdnbn != nullptr; cdnbn = cdnbn->next()) {
				config_data_node &cdnt = cdnbn->v();
				print_description(cdnt.label(), nullptr);
			}
		}
		print_prompt();
		break;
	}
}

void
console_base::handle_command_completion(uint32_t c, command_node *&cn, config_model_node *&cmn, config_data_node *&cdn, utf8str &remaining, uint64_t pos)
{
	bidir_node<command_node> *bn, *match_bn = nullptr;
	int match = 0;
	sorted_list<command_node> &children = cn->children();
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		command_node &node = bn->v();
		switch (node.node_type()) {
		case command_node_type::type_keyword:
			if (node.keyword_label().beginning(remaining)) {
				++match;
				match_bn = bn;
			}
			break;
		case command_node_type::type_variable:
			break;
		case command_node_type::type_config_model:
			handle_config_model_completion(c, cmn, cdn, remaining, pos, false);
			return;
			break;
		case command_node_type::type_config_model_woleafs:
			handle_config_model_completion(c, cmn, cdn, remaining, pos, true);
			return;
			break;
		case command_node_type::type_root:
			break;
		}
	}
	if (match == 1) {
		command_node &node = match_bn->v();
		switch (node.node_type()) {
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
		case command_node_type::type_config_model_woleafs:
			break;
		case command_node_type::type_root:
			break;
		}
	} else {
		print("\n");
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			command_node &node = bn->v();
			switch (node.node_type()) {
			case command_node_type::type_keyword:
				print_description(node.keyword_label(), node.description());
				break;
			case command_node_type::type_variable:
				break;
			case command_node_type::type_config_model:
				break;
			case command_node_type::type_config_model_woleafs:
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
	config_data_node *cdn = config_data_node_candidate;
	utf8str remaining("");

	command_node_nearest(m_command_line, cn, remaining);
	sorted_list<command_node> &children = cn->children();
	bidir_node<command_node> *bn;
	bool config_model = false;
	uint64_t pos = 0;
	bool exclude_leaf = false;
	for (bn = children.head(); bn != nullptr; bn = bn->next()) {
		command_node &cmnt = bn->v();
		if (cmnt.node_type() == command_node_type::type_config_model) {
			config_model = true;
			break;
		}
		if (cmnt.node_type() == command_node_type::type_config_model_woleafs) {
			config_model = true;
			exclude_leaf = true;
			break;
		}
	}
	if (config_model == true) {
		utf8str path = m_edit_path;
		if (path != "") {
			path += " ";
		}
		path += remaining;
		utf8str remaining2;
		config_model_node_nearest(path, cmn, remaining, pos, exclude_leaf);
		config_data_node_nearest(path, cdn, remaining2);
		if ((cdn != nullptr) && (cdn->config_model_node_() != cmn)) {
			cdn = nullptr;
		}
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
			handle_command_completion(c, cn, cmn, cdn, remaining, pos);
		}
		break;
	case '\r':
	case '\n':
		if ((remaining == "")
		 && ((cmn == nullptr)
		  || ((cmn != nullptr)
		   && (config_model_node_completed(cmn, pos))))) {
			bool success = false;
			putchar(c);
			if (cn->execute() != nullptr) {
				success = cn->execute()(*this, m_command_line);
			}
			if (success == true) {
				m_command_line = "";
			}
			print_prompt();
		}
		break;
	default:
		if (((cmn == nullptr)
		  && (cn->children().nodes() > 0))
		 || ((cmn != nullptr)
		  && (((cmn->statement() != config_model_node_statement::statement_leaf)
		    && (cmn->statement() != config_model_node_statement::statement_leaf_list))
	 	   || (!config_model_node_completed(cmn, pos))
		   || (m_command_line[-1] != ' ')))) {
			m_command_line += c;
			putchar(c);
		}
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
		utf8str s;
		s += "    ";
		s += label;
		s += "\n";
		print(s);
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
console_base::print_description(msg *label, msg *description)
{
	if (label == nullptr) {
		return;
	}

	utf8str l;
	l = label[0].msg;
	for (int i = 0; i < sizeof(console_lang); ++i) {
		if (label[i].lang == m_current_lang) {
			l = label[i].msg;
			break;
		}
	}

	print_description(l, description);
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

