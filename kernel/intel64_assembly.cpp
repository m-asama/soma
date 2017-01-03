/**
 * @file	intel64_assembly.cpp
 * @brief	インラインアセンブリで書かれた関数実装。
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "type.h"
#include "print.h"

uint8_t
inb(uint16_t port)
{
	uint8_t ret;
	asm volatile ("inb %%dx,%%al" : "=a"(ret) : "d"(port));
	return ret;
}

void
outb(uint16_t port, uint8_t val)
{
	asm volatile ("outb %%al,%%dx": :"d"(port), "a"(val));
}

uint16_t
inw(uint16_t port)
{
	uint16_t ret;
	asm volatile ("inw %%dx,%%ax" : "=a"(ret) : "d"(port));
	return ret;
}

void
outw(uint16_t port, uint16_t val)
{
	asm volatile ("outw %%ax,%%dx": :"d"(port), "a"(val));
}

uint32_t
inl(uint16_t port)
{
	uint32_t ret;
	asm volatile ("inl %%dx,%%eax" : "=a"(ret) : "d"(port));
	return ret;
}

void
outl(uint16_t port, uint32_t val)
{
	asm volatile ("outl %%eax,%%dx": :"d"(port), "a"(val));
}

void
sti()
{
	asm volatile ("sti");
}

void
cli()
{
	asm volatile ("cli");
}

void
hlt()
{
	asm volatile ("hlt");
}

void
int_0x20()
{
	asm volatile ("int $0x20");
}

uint64_t
rflags()
{
	uint64_t ret;
	asm volatile ("pushfq");
	asm volatile ("popq %%rax" : "=a"(ret) : :);
	return ret;
}

void
cpuid(uint32_t &eax, uint32_t &ebx, uint32_t &ecx, uint32_t &edx)
{
	asm volatile ("movl %0, %%eax" : : "r"(eax) :);
	asm volatile ("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : :);
}

void
rdmsr(uint32_t msr, uint32_t *lo, uint32_t *hi)
{
	asm volatile("rdmsr" : "=a"(*lo), "=d"(*hi) : "c"(msr));
}

void
wrmsr(uint32_t msr, uint32_t lo, uint32_t hi)
{
	asm volatile("wrmsr" : : "a"(lo), "d"(hi), "c"(msr));
}

/*
void
cr3(uint64_t cr3)
{
	asm volatile ("movq %0, %%cr3" : : "r"(cr3) :);
}
*/
/*
uint64_t
cr3()
{
	uint64_t ret;
	asm volatile ("movq %%cr3, %0" : "=r"(ret) : :);
	return ret;
}
*/
/*
void
rsp(uint64_t rsp)
{
	asm volatile ("movq %0, %%rsp" : : "r"(rsp) :);
}
*/
/*
uint64_t
rsp()
{
	uint64_t ret;
	asm volatile ("movq %%rsp, %0" : "=r"(ret) : :);
	return ret;
}
*/

uint16_t
segment_register_cs()
{
	uint16_t ret;
	asm volatile ("movw %%cs, %0" : "=r"(ret) : :);
	return ret;
}

uint16_t
segment_register_ds()
{
	uint16_t ret;
	asm volatile ("movw %%ds, %0" : "=r"(ret) : :);
	return ret;
}

uint16_t
segment_register_ss()
{
	uint16_t ret;
	asm volatile ("movw %%ss, %0" : "=r"(ret) : :);
	return ret;
}

uint16_t
segment_register_es()
{
	uint16_t ret;
	asm volatile ("movw %%es, %0" : "=r"(ret) : :);
	return ret;
}

uint16_t
segment_register_fs()
{
	uint16_t ret;
	asm volatile ("movw %%fs, %0" : "=r"(ret) : :);
	return ret;
}

uint16_t
segment_register_gs()
{
	uint16_t ret;
	asm volatile ("movw %%gs, %0" : "=r"(ret) : :);
	return ret;
}

void
lgdt(void *ptr, uint16_t code_segment_selector, uint16_t data_segment_selector)
{
	uint64_t tmp1, tmp2;
	uint16_t segment_selector;

	asm volatile ("lgdt 0(%0)" : : "r"(ptr) :);

	asm volatile ("jmp 1f; nop; 1:");

	asm volatile ("movw %1, %0" : "=r"(segment_selector) : "r"(data_segment_selector) :);
	asm volatile ("movw %0, %%ds" : : "r"(segment_selector) :);
	asm volatile ("movw %0, %%es" : : "r"(segment_selector) :);
	asm volatile ("movw %0, %%fs" : : "r"(segment_selector) :);
	asm volatile ("movw %0, %%gs" : : "r"(segment_selector) :);
	asm volatile ("movw %0, %%ss" : : "r"(segment_selector) :);

	asm volatile ("pop %rbp");

	tmp2 = code_segment_selector;
	asm volatile ("popq %0" : "=r"(tmp1) : :);
	asm volatile ("pushq %0" : : "r"(tmp2) :);
	asm volatile ("pushq %0" : : "r"(tmp1) :);

	asm volatile ("lretq");

}

void
sgdt(void *ptr)
{
	asm volatile ("sgdt 0(%0)" : : "r"(ptr) :);
}

void
lidt(void *ptr)
{
	asm volatile ("lidt 0(%0)" : : "r"(ptr) :);
}

void
sidt(void *ptr)
{
	asm volatile ("sidt 0(%0)" : : "r"(ptr) :);
}

