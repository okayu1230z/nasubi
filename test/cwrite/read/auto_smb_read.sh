#!/bin/bash

for s in 1 10 20 30 40 50 60
do
	sed -i "415d" /usr/local/bin/fuse_test-master/gdtnfs.cpp &&
	sed -ie "415i sleep\(${s}\)" /usr/local/bin/fuse_test-master/gdtnfs.cpp &&
	/usr/local/bin/fuse_test-master/compile.sh gdtnfs &&
	sudo /usr/local/bin/fuse_test-master/mount.sh &&
	for j in 1 10 100 1000 10000 100000 1000000 10000000 100000000
	do
		./read_throughput.sh sdfs $j &> smb_sdfs_$s/$s.log
    done
	rm /tmp/*
done
