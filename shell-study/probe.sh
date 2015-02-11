#!/bin/bash

now=`date +%s`
now_40=`expr $now - 40`
db=/tmp/test.rrd

pid_list=2147483647
proc_list="top"
# proc_list="Xorg vim top terminator"

for proc in $proc_list; do
    pid=`ps -e | grep $proc | sed -n 1,1p | awk '{ print $1 }'`
    if [ $pid ]; then
        pid_list=$pid_list","$pid
    fi
done

top -n 30 -b -p $pid_list -d 5
