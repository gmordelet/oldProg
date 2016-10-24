#!/usr/bin/perl -w

print 'number 1 ? ';
chomp($n1 = <STDIN>);
print 'number 2 ? ';
chomp($n2 = <STDIN>);
if ($n1 > $n2) {
	print "$n1\n";
}
else {
	print "$n2\n";
}
