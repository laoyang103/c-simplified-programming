#!/bin/bash

echo '1 2 3 4 '
for i in 1 2 3 4 
do
    echo "this is ${i}"
done    

echo 'this is a string' 'aaa'
for str in 'this is a string' 'aaa'
do
    echo "${str}"
done    

echo '{1..5}'
for i in {1..5}
do
    echo "this is ${i}"
done    

echo '{1..10..3}'
for i in {1..10..3}
do
    echo "this is ${i}"
done    

echo '`seq 1 2 10 `'
for i in `seq 1 2 10 `
do
    echo "this is ${i}"
done

echo '((c = 1;c <= 5;c++))'
for ((c = 1;c <= 5;c++))
do
    echo "this is ${c}"
done

echo 'FILE in $HOME/.bash*'
for FILE in $HOME/.bash*
do
    echo $FILE
done    

echo 'find num nameserver in /etc/resolv.conf.'
for FILE in /etc/*
do
    if [ "$FILE" == "/etc/resolv.conf" ] 
    then
        NUM_NAME_SERVER=`grep -c nameserver /etc/resolv.conf`
        echo "There have $NUM_NAME_SERVER nameserver in your host."
        break
    fi
done    

echo 'make backup of all file names specified on command line'
FILES=$@
for FILE in $FILES
do
    if [ -e $FILE -a -f $FILE ]; then
        if [ -e $FILE.backup ]; then
            echo "ship $FILE ..."
            continue
        fi
        echo "backup $FILE to $FILE.backup ..."
        /bin/cp $FILE $FILE.backup
    else
        echo "ship $FILE ..."
    fi
done    
if [ "$xxxff" -o ! -e "/tmp/aa" ]; then
    echo "laoyang..."
fi
