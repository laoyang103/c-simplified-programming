#!/bin/bash

read -p 'Input any domain name separated by space:' domains

for domain in $domains
do
    printf "%-20s address is:" $domain
    echo `nslookup $domain | grep -E 'Address|Server'`
done

read -p 'Input any files to backup to /tmp(separated by space):' files
for file in $files
do
    if [ -f $file ]; then
        backup_file="${file##/*/}.backup"
        echo "backup $file to /tmp/$backup_file..."
        cp $file /tmp/$backup_file
    elif [ -d $file ]; then
        echo "make dir $file to /tmp/"
        mkdir -p "/tmp/$file"
    else
        echo "ship $file ..."
    fi    
done

read -p 'Input the total of money:' money
echo "10 percent of total money is: $(( $money/10 ))"

read -p 'Input two number:' a b
read -p 'operand(+ - * /):' opt
echo "$a $opt $b = $(( $a$opt$b ))"
