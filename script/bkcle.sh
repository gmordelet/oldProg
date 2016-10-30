#!/bin/bash

src=$HOME/git/oldProg/script/src
dest=$HOME/git/oldProg/script/dest
c_date=$(date "+%y%m%d%H%M%S")

dir_dest=$(ls -d $dest)
if [ -z $dir_dest ]
then
	mkdir -v $dest
fi

dir_count=$(ls $dest -p | tr ' ' '\n' | grep '/' | wc -l)
if [ $dir_count -lt 3 ]
then
	mkdir -v $dest/$c_date
	rsync -arv $src $dest/$c_date
else
	first=$(ls $dest | sort | head -n 1)
	mv -v $dest/$first $dest/$c_date
	rsync -arv --delete $src $dest/$c_date 
fi
