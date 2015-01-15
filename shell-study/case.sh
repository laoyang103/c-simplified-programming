#!/bin/bash

echo 'Input a number between 1-4:'
read NUM

case ${NUM} in
    1) echo 'You select 1';;
    2) echo 'You select 2';;
    3) echo 'You select 3';;
    4) echo 'You select 4';;
    *) echo 'You do not select 1-4';;
esac

OPT=$1
FILE=$2

case ${OPT} in
    -f) echo "file name is ${FILE}";;
    -d) echo "dir name is ${FILE}";;
    *)  echo "`basename $0`: usage: [-f file] [-d] dir";;
esac    
