#!/bin/bash

echo "\"it is a test\""

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
