#!/bin/bash

fsname="$1"
size="$2"
filepass=$fsname/$size
#mkdir $fsname
#touch $filepass
for i in 1 2 3 4 5 6 7 8 9 10
do
	sleep 1
	echo $'\n' $i $size-$i 
	dd if=/dev/zero of=/mnt/$fsname/$size-$i ibs=$size obs=$size count=1 oflag=nocache
done
