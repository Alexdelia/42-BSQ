#!/usr/bin/perl -w

if ((scalar @ARGV) != 3)
{
    print "$0 [COLS] [LINES] [DENSITY]\n";
    exit;
}

my $x = $ARGV[0];
my $y = $ARGV[1];
my $density = $ARGV[2];
my $i = 0;
my $j = 0;

print $y . ".o#\n";

while ($i < $y)
{
    $j = 0;
    while ($j < $x)
    {
	if (int(rand($y)*2) < $density)
	{
	    print "o";
	}
	else
	{
	    print ".";
	}
	$j++;
    }
    print "\n";
    $i++;
}
