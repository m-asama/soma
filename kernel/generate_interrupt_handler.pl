#!/usr/bin/perl
#
# Author:
# 	Masakazu Asama <m-asama@ginzado.co.jp>
#

use strict;

open(OUT, ">intel64_processor_interrupt_handler.cpp");

print OUT "/**\n";
print OUT " * \@file\tintel64_processor_interrupt_handler.cpp\n";
print OUT " * \@brief\tIntel64 CPU の割り込みハンドラ関連の関数実装。\n";
print OUT " * \@author\tMasakazu Asama <m-asama\@ginzado.co.jp>\n";
print OUT " */\n";
print OUT "\n";
print OUT "#include \"intel64_assembly.h\"\n";
print OUT "#include \"intel64_processor.h\"\n";
print OUT "#include \"processor_management.h\"\n";
print OUT "\n";

for (my $i = 0; $i < 256; $i++) {
	my $gsi = sprintf("0x\%02x", $i);;
	print OUT "static void\n";
	print OUT "interrupt_handler_$gsi()\n";
	print OUT "{\n";
	print OUT "\tinterrupt_handler($gsi, rsp());\n";
	print OUT "\t*((uint32_t *)0x00000000fee000b0ul) = 0x00000000;\n";
	print OUT "\tasm volatile (\"pop \%rbp\");\n";
	print OUT "\tasm volatile (\"iretq\");\n";
	print OUT "}\n";
	print OUT "\n";
}

print OUT "void\n";
print OUT "interrupt_handler_init(intel64_idt_entry *idt, uint16_t code_segment_selector)\n";
print OUT "{\n";

for (my $i = 0; $i < 256; $i++) {
	my $gsi = sprintf("0x\%02x", $i);
	print OUT "\tidt[$gsi].offset((uint64_t)interrupt_handler_$gsi);\n";
	print OUT "\tidt[$gsi].p(true);\n";
	print OUT "\tidt[$gsi].type(0x0e);\n";
	print OUT "\tidt[$gsi].segment_selector(code_segment_selector);\n";
	print OUT "\n";
}

print OUT "}\n";
print OUT "\n";
