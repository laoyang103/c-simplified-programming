#!/bin/bash

echo "\"it is a test\""

echo 'My favorite movie name is Gongfu'
echo 'Director name is Xingchi Zhou'

NAME="aa"

echo "${NAME} is a test"

echo "OK\n"
echo "laoyang"

echo "OK\n"`date`

if [ ${NAME} == "HEIHEI" -a 1 == 1 ]
then
    echo 'good' 
elif [ ${NAME} == "aa" ]
then
    echo 'bad' 
fi    

read -p 'Press Enter to exit' entryKey
cd /etc/init.d
ls -a

