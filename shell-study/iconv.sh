#!/bin/bash

ext=$1
files=`find . -type f -name "*.$ext"`
from=$2
to=$3

for file in $files; do
    echo $file
    cp $file $file".bak"
    iconv -f $from -t $to $file -o $file
done
