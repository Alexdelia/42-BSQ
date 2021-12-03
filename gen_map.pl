#!/usr/bin/perl

use warnings;
use strict;

die "Usage: perl [LEN_LINES] [NBR_LINES] [DENSITY]\n" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.oX\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}
