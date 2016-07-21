#!/usr/bin/perl
#
# Author:
#       Masakazu Asama <m-asama@ginzado.co.jp>
#

use strict;

my $size = hex(`objdump -h kernel | grep .bss | awk '{print \$3}'`);
my $base = hex(`objdump -h kernel | grep .bss | awk '{print \$4}'`);

open KERNEL, "+<kernel.bin" or die($!);
seek KERNEL, ($base - hex("0x100000")) + $size - 1, 0 or die($!);
print KERNEL pack('C', 0) or die($!);

