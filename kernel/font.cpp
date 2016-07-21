/**
 * @file	font.cpp
 * @brief	フォント関連の関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"
#include "font_data.h"
#include "hash_table.h"

uint64_t
font_data_hash(const struct font_data &fd)
{
	uint64_t hash;
	hash = fd.unicode;
	hash ^= (hash >> 40);
	hash ^= (hash >> 20);
	hash ^= (hash >> 10);
	hash ^= (hash >> 5);
	return hash;
}

bool
font_data_equal(const struct font_data &fdl, const struct font_data &fdr)
{
	return (fdl.unicode == fdr.unicode);
}

static hash_table<struct font_data> *fonts;

struct font_data *
font_find(uint64_t unicode)
{
	struct font_data key;
	key.unicode = unicode;
	return fonts->find(key);
}

void
font_init()
{
	fonts = new hash_table<struct font_data>(font_data_hash, font_data_equal);
	struct font_data *fdp;
	for (fdp = font_data; fdp->unicode != 0; ++fdp) {
		fonts->insert(*fdp);
	}
	fonts->insert(*fdp);
}

