#!/usr/bin/perl -w

@days   = 1..31;
@months = 1..12;
@years  = 90..98;

foreach $day (@days) {
	foreach $month (@months) {
		foreach $year (@years) {
			print ("$day$month$year\n");
			print ("$year$month$day\n");
			print ("$day${month}19$year\n");
			print ("19$year$month$day\n");
		}
	}
}
