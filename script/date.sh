#!/bin/bash

c_date=$(date "+%y%m%d%H%M%S")
mkdir $c_date
dir_count=$(ls -d */ | wc -l)
while [ $dir_count -gt 3 ]
do
	to_del=$(ls -d */ | sort | head -n 1)
	rm -ri $to_del
	dir_count=$(ls -d */ | wc -l)
done

