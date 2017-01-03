#!/usr/bin/perl
#
# Author:
# 	Masakazu Asama <m-asama@ginzado.co.jp>
#

use strict;

open(OUT1, ">intel64_processor_interrupt_handler_init.cpp");

print OUT1 "/**\n";
print OUT1 " * \@file\tintel64_processor_interrupt_handler_init.cpp\n";
print OUT1 " * \@brief\tIntel64 CPU の割り込みハンドラ関連の関数実装。\n";
print OUT1 " * \@author\tMasakazu Asama <m-asama\@ginzado.co.jp>\n";
print OUT1 " */\n";
print OUT1 "\n";
print OUT1 "#include \"type.h\"\n";
print OUT1 "#include \"intel64_processor.h\"\n";
print OUT1 "\n";

for (my $i = 0; $i < 256; $i++) {
	my $gsi = sprintf("0x\%02x", $i);;
	print OUT1 "extern \"C\" void interrupt_handler_$gsi();\n";
}

print OUT1 "\n";
print OUT1 "void\n";
print OUT1 "interrupt_handler_init(intel64_idt_entry *idt, uint16_t code_segment_selector)\n";
print OUT1 "{\n";

for (my $i = 0; $i < 256; $i++) {
	my $gsi = sprintf("0x\%02x", $i);
	print OUT1 "\tidt[$gsi].offset((uint64_t)interrupt_handler_$gsi);\n";
	print OUT1 "\tidt[$gsi].p(true);\n";
	print OUT1 "\tidt[$gsi].type(0x0e);\n";
	print OUT1 "\tidt[$gsi].segment_selector(code_segment_selector);\n";
	print OUT1 "\n";
}

print OUT1 "}\n";
print OUT1 "\n";

close(OUT1);

open(OUT2, ">intel64_processor_interrupt_handler_entry.S");

print OUT2 "/**\n";
print OUT2 " * \@file\tintel64_processor_interrupt_handler_entry.S\n";
print OUT2 " * \@brief\tIntel64 CPU の割り込みハンドラ関連の関数実装。\n";
print OUT2 " * \@author\tMasakazu Asama <m-asama\@ginzado.co.jp>\n";
print OUT2 " */\n";
print OUT2 "\n";
print OUT2 "\t.code64\n";

for (my $i = 0; $i < 256; $i++) {
	my $gsi = sprintf("0x\%02x", $i);
	my $stacksize = 40;
	if (($gsi eq "0x08")	# Double Fault
	 || ($gsi eq "0x0a")	# Invalid TSS
	 || ($gsi eq "0x0b")	# Segment Not Present
	 || ($gsi eq "0x0c")	# Stack-Segment Fault
	 || ($gsi eq "0x0d")	# General Protection
	 || ($gsi eq "0x0e")	# Page Fault
	 || ($gsi eq "0x11")) {	# Alignment Check
		$stacksize += 8;
	}
	print OUT2 "\n";
	print OUT2 "\t.global\tinterrupt_handler_$gsi\n";
	print OUT2 "interrupt_handler_$gsi:\n";
	print OUT2 "\tpushq\t\$$gsi\n";
	print OUT2 "\tpushq\t\$$stacksize\n";
	print OUT2 "\tjmp\tinterrupt_handler_common\n";
}

close(OUT2);

