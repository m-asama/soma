/**
 * @file	command_management.cpp
 * @brief	コマンド管理関連の実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "print.h"
#include "unicode.h"
#include "console_base.h"
#include "config_management.h"
#include "command_node.h"
#include "command_debug.h"

#include "command_management.h"

command_node *command_node_root;
command_node *cn_set;
command_node *cn_get;
command_node *cn_delete;
command_node *cn_edit;
command_node *cn_top;
command_node *cn_commit;
command_node *cn_show;
command_node *cn_reset;
command_node *cn_clear;

msg command_node_root_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "",
	},
};

bool
command_node_root_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_set_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "パラメータを設定する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "set",
	},
};

bool
cn_set_execute(console_base &cb, utf8str command)
{
	if (!command.beginning("set ")
	 || (command == "set ")) {
		return false;
	}

	utf8str path, newpath;
	path = command.unicode_substring(4, 0);
	while ((path.unicode_length() > 0) && (path[-1] == ' ')) {
		path.truncate(1);
	}

	newpath = cb.edit_path();
	if (newpath != "") {
		newpath += " ";
	}
	newpath += path;

	config_data_node_set(config_data_node_candidate, newpath);
	return true;
}

msg cn_get_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "現在の設定を取得する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "get",
	},
};

bool
cn_get_execute(console_base &cb, utf8str command)
{
	if (!command.beginning("get")) {
		return false;
	}

	utf8str path, newpath;
	if (command.unicode_length() > 3) {
		path = command.unicode_substring(3, 0);
	} else {
		path = "";
	}
	while ((path.unicode_length() > 0) && (path[0] == ' ')) {
		path = path.unicode_substring(1, 0);
	}
	while ((path.unicode_length() > 0) && (path[-1] == ' ')) {
		path.truncate(1);
	}

	newpath = cb.edit_path();
	if (newpath != "") {
		newpath += " ";
	}
	newpath += path;

	utf8str result;
	config_data_node_get(newpath, result);
	cb.print(result);
	return true;
}

msg cn_delete_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "設定を削除する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "delete",
	},
};

bool
cn_delete_execute(console_base &cb, utf8str command)
{
	if (!command.beginning("delete ")
	 || (command == "delete ")) {
		return false;
	}

	utf8str path, newpath;
	path = command.unicode_substring(7, 0);
	while ((path.unicode_length() > 0) && (path[-1] == ' ')) {
		path.truncate(1);
	}

	newpath = cb.edit_path();
	if (newpath != "") {
		newpath += " ";
	}
	newpath += path;

	config_data_node_delete(config_data_node_candidate, newpath);
	return true;
}

msg cn_edit_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "編集パスを設定する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "edit",
	},
};

bool
cn_edit_execute(console_base &cb, utf8str command)
{
	if (!command.beginning("edit ")
	 || (command == "edit ")) {
		return false;
	}

	utf8str path, remaining, newpath;
	path = command.unicode_substring(5, 0);
	while ((path.unicode_length() > 0) && (path[-1] == ' ')) {
		path.truncate(1);
	}

	newpath = cb.edit_path();
	if (newpath != "") {
		newpath += " ";
	}
	newpath += path;

	config_model_node *cmn;
	uint64_t pos;
	config_model_node_nearest(newpath, cmn, remaining, pos, true);
	if (config_model_node_completed(cmn, pos)) {
		cb.edit_path(newpath);
		return true;
	}

	return false;
}

msg cn_top_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "トップレベルの編集パスに移動する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "top",
	},
};

bool
cn_top_execute(console_base &cb, utf8str command)
{
	if ((command != "top")
	 && (command != "top ")) {
		return false;
	}

	cb.edit_path("");
	return true;
}

msg cn_commit_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "設定を反映する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "commit",
	},
};

bool
cn_commit_execute(console_base &cb, utf8str command)
{
	/* XXX: */
	*config_data_node_running = *config_data_node_candidate;
	return true;
}

msg cn_show_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "各種情報を表示する。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "show",
	},
};

bool
cn_show_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_reset_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "接続などをリセットする。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "reset",
	},
};

bool
cn_reset_execute(console_base &cb, utf8str command)
{
	return true;
}

msg cn_clear_msg[] = {
	{
		.lang = console_lang::lang_ja,
		.msg  = "各種の値をクリアする。",
	},
	{
		.lang = console_lang::lang_en,
		.msg  = "clear",
	},
};

bool
cn_clear_execute(console_base &cb, utf8str command)
{
	return true;
}

void
command_node_nearest(utf8str command, command_node *&node, utf8str &remaining)
{
	node = command_node_root;
	int i = 0;
	int len = command.unicode_length();
	while ((i < len) && (command[i] == ' ')) {
		++i;
	}
	utf8str token;
	while ((i < len) && (command[i] != '\0')) {
		token = "";
		while ((i < len)
		    && (command[i] != ' ') && (command[i] != '\0')) {
			token += command[i];
			++i;
		}
		sorted_list<command_node> &children = node->children();
		bidir_node<command_node> *bn;
		bool found = false;
		for (bn = children.head(); bn != nullptr; bn = bn->next()) {
			config_model_type *type;
			switch (bn->v().node_type()) {
			case command_node_type::type_keyword:
				if (bn->v().keyword_label() == token) {
					node = &bn->v();
					found = true;
					goto exit_loop;
				}
				break;
			case command_node_type::type_variable:
				type = bn->v().model_type();
				if ((type != nullptr) && type->valid(token)) {
					node = &bn->v();
					found = true;
					goto exit_loop;
				}
				break;
			case command_node_type::type_config_model:
			case command_node_type::type_config_model_woleafs:
			case command_node_type::type_root:
				break;
			}
		}
		exit_loop:
		if (found == false) {
			remaining = token;
			for (int j = i; j < len; ++j) {
				remaining += command[j];
			}
			return;
		}
		while ((i < len) && (command[i] == ' ')) {
			++i;
		}
	}
	remaining = "";
	return;
}

void
command_init()
{
	command_node *t;

	command_node_root = new command_node;
	t = command_node_root;
	t->node_type(command_node_type::type_root);
	t->keyword_label("[root]");
	t->execute(command_node_root_execute);
	t->description(command_node_root_msg);

	/* set */

	utf8str cn_set_keyword_label("set");
	cn_set = new command_node;
	t = cn_set;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_set_keyword_label);
	t->execute(cn_set_execute);
	t->description(cn_set_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_set);

	t = new command_node;
	t->node_type(command_node_type::type_config_model);
	t->keyword_label("[config]");
	t->execute(cn_set_execute);
	t->parent(cn_set);
	cn_set->add_child(*t);

	/* get */

	utf8str cn_get_keyword_label("get");
	cn_get = new command_node;
	t = cn_get;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_get_keyword_label);
	t->execute(cn_get_execute);
	t->description(cn_get_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_get);

	t = new command_node;
	t->node_type(command_node_type::type_config_model_woleafs);
	t->keyword_label("[config]");
	t->execute(cn_get_execute);
	t->parent(cn_get);
	cn_get->add_child(*t);

	/* delete */

	utf8str cn_delete_keyword_label("delete");
	cn_delete = new command_node;
	t = cn_delete;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_delete_keyword_label);
	t->execute(cn_delete_execute);
	t->description(cn_delete_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_delete);

	t = new command_node;
	t->node_type(command_node_type::type_config_model);
	t->keyword_label("[config]");
	t->execute(cn_delete_execute);
	t->parent(cn_delete);
	cn_delete->add_child(*t);

	/* edit */

	utf8str cn_edit_keyword_label("edit");
	cn_edit = new command_node;
	t = cn_edit;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_edit_keyword_label);
	t->execute(cn_edit_execute);
	t->description(cn_edit_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_edit);

	t = new command_node;
	t->node_type(command_node_type::type_config_model_woleafs);
	t->keyword_label("[config]");
	t->execute(cn_edit_execute);
	t->parent(cn_edit);
	cn_edit->add_child(*t);

	/* top */

	utf8str cn_top_keyword_label("top");
	cn_top = new command_node;
	t = cn_top;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_top_keyword_label);
	t->execute(cn_top_execute);
	t->description(cn_top_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_top);

	/* commit */

	utf8str cn_commit_keyword_label("commit");
	cn_commit = new command_node;
	t = cn_commit;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_commit_keyword_label);
	t->execute(cn_commit_execute);
	t->description(cn_commit_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_commit);

	/* show */

	utf8str cn_show_keyword_label("show");
	cn_show = new command_node;
	t = cn_show;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_show_keyword_label);
	t->execute(cn_show_execute);
	t->description(cn_show_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_show);

	/* reset */

	utf8str cn_reset_keyword_label("reset");
	cn_reset = new command_node;
	t = cn_reset;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_reset_keyword_label);
	t->execute(cn_reset_execute);
	t->description(cn_reset_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_reset);

	/* clear */

	utf8str cn_clear_keyword_label("clear");
	cn_clear = new command_node;
	t = cn_clear;
	t->node_type(command_node_type::type_keyword);
	t->keyword_label(cn_clear_keyword_label);
	t->execute(cn_clear_execute);
	t->description(cn_clear_msg);
	t->parent(command_node_root);
	command_node_root->add_child(*cn_clear);

	command_debug_init();

}

