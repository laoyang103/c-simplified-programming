#!/bin/bash

x=1
while [ $x -lt 5 ]
do
    echo "this is $x times"
    x=`expr $x + 1`
    # x=$(( $x + 1 ))
done

x=5
n=1
printf "$x factorial is"
while [ $x -gt 0 ]
do
    n=`expr $n \* $x`
    x=`expr $x - 1`
    # x=$(( $x - 1 ))
done
printf " $n\n"

FILE=$1
exec 3<&0
exec 0<$FILE
while read line
do
    echo $line
done
exec 0<&3

