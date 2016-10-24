#!/usr/bin/perl -w

print 'number ? ';
$num = <STDIN>;
if ($num % 2) {
	print "odd\n";
}
else {
	print "even\n"
}
