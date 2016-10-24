#!/usr/bin/perl -w

chomp($radius = <STDIN>);
if ($radius < 0) {
	$radius = 0;
}
$res = 2 * 3.141592654 * $radius;
print $res;
