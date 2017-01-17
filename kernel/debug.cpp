/**
 *
 */

#include "type.h"
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
dp(char const *s)
{
	while (*s != '\0') {
		dpc(*s);
		++s;
	}
}

