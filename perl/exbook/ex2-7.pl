#!/usr/bin/perl -w

print 'number ? ';
while ($num = <STDIN>) {
	chomp $num;
	$sum += $num;
	print 'number ? ';
}
print "\n";
if (defined ($sum)) {
	print "sum = $sum\n";
}
else {
	print "\n";
}
