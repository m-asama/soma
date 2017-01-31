/**
 *
 */

#include "type.h"
#include "utf8str.h"
#include "intel64_assembly.h"

static uint16_t m_io_port_base = 0x3f8;

static
void
dpc(char c)
{
	while ((inb(m_io_port_base+5) & 0x20) == 0);
	outb(m_io_port_base, c);
}

void
dp(utf8str s)
{
	for (int i = 0; i < s.byte_length(); ++i) {
		dpc(s.byte_at(i));
	}
}

void
dp(char const *s)
{
	utf8str str(s);
	dp(str);
}

