#!/usr/bin/perl
#
# Author:
# 	Masakazu Asama <m-asama@ginzado.co.jp>
#

use strict;

my %j2u = ();
my %u = ();

open(MAPPING, "JIS0201.TXT");
foreach my $line (<MAPPING>) {
	my @x = split(/\s+/, $line);
	my $sjis = hex($x[0]);
	my $unicode = hex($x[1]);
	$j2u{$sjis} = $unicode;
}
close(MAPPING);

open(MAPPING, "JIS0208.TXT");
foreach my $line (<MAPPING>) {
	my @x = split(/\s+/, $line);
	my $sjis = hex($x[0]);
	my $jisx208 = hex($x[1]);
	my $unicode = hex($x[2]);
	$j2u{$jisx208} = $unicode;
}
close(MAPPING);

print "/**\n";
print " * \@file\tfont_data.cpp\n";
print " * \@brief\tフォントデータの配列。\n";
print " * \@author\tMasakazu Asama <m-asama\@ginzado.co.jp>\n";
print " */\n";
print "\n";
print "#include \"font_data.h\"\n";
print "\n";
print "struct font_data font_data[] = {\n";

my $encoding = undef;
my $inbitmap = 0;
my @bitmap = ();
open(FONT, "8x16rk.bdf");
foreach my $line (<FONT>) {
	if ($line =~ m/^ENCODING (\d+)/) {
		$encoding = int($1);
	}
	if ($line =~ m/^ENDCHAR/) {
		unless (exists $u{sprintf("\%08x", $j2u{$encoding})} or $j2u{$encoding} == 0) {
			print "\t{\n";
			print "\t\t.unicode = 0x" . sprintf("\%08x", $j2u{$encoding}) . ",";
			#print " /* '".pack('U', $encoding)."' */";
			print "\n";
			print "\t\t.width = 8,\n";
			print "\t\t.height = 16,\n";
			print "\t\t.data = {";
			my $c = 0;
			foreach my $x (@bitmap) {
				if (($c % 8) == 0) {
					print "\n\t\t\t";
				}
				print "$x,";
				$c++;
			}
			print "\n";
			print "\t\t},\n";
			print "\t},\n";
		}
		$u{sprintf("\%08x", $j2u{$encoding})} = 1;
		$encoding = undef;
		$inbitmap = 0;
		@bitmap = ();
	}
	if ($inbitmap == 1) {
		if ($line =~ m/^([0-9a-fA-F][0-9a-fA-F])$/) {
			push(@bitmap, "0x".$1."00");
		}
	}
	if ($line =~ m/^BITMAP/) {
		$inbitmap = 1;
		@bitmap = ();
	}
}
close(FONT);

my $encoding = undef;
my $inbitmap = 0;
my @bitmap = ();
open(FONT, "jiskan16.bdf");
foreach my $line (<FONT>) {
	if ($line =~ m/^ENCODING (\d+)/) {
		$encoding = int($1);
	}
	if ($line =~ m/^ENDCHAR/) {
		unless (exists $u{sprintf("\%08x", $j2u{$encoding})} or $j2u{$encoding} == 0) {
			print "\t{\n";
			print "\t\t.unicode = 0x" . sprintf("\%08x", $j2u{$encoding}) . ",";
			#print " /* '".pack('U', $encoding)."' */";
			print "\n";
			print "\t\t.width = 16,\n";
			print "\t\t.height = 16,\n";
			print "\t\t.data = {";
			my $c = 0;
			foreach my $x (@bitmap) {
				if (($c % 8) == 0) {
					print "\n\t\t\t";
				}
				print "$x,";
				$c++;
			}
			print "\n";
			print "\t\t},\n";
			print "\t},\n";
		}
		$u{sprintf("\%08x", $j2u{$encoding})} = 1;
		$encoding = undef;
		$inbitmap = 0;
		@bitmap = ();
	}
	if ($inbitmap == 1) {
		if ($line =~ m/^([0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F])$/) {
			push(@bitmap, "0x".$1);
		}
	}
	if ($line =~ m/^BITMAP/) {
		$inbitmap = 1;
		@bitmap = ();
	}
}
close(FONT);

print "\t{\n";
print "\t\t.unicode = 0x00000000,\n";
print "\t\t.width = 8,\n";
print "\t\t.height = 16,\n";
print "\t\t.data = {\n";
print "\t\t\t0x9200,0x9200,0x4400,0x4400,0x9200,0x9200,0x4400,0x4400,\n";
print "\t\t\t0x9200,0x9200,0x4400,0x4400,0x9200,0x9200,0x0000,0x0000,\n";
print "\t\t},\n";
print "\t},\n";

print "};\n";
print "\n";

