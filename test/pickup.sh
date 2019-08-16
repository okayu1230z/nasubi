#!/bin/bash

less stderr.log | grep "pid" | awk '{print $4 " "$5}' | sed -e "s/,//g" | sort | uniq -c | sort -n -r
