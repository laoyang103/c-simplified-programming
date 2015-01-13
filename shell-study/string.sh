#!/bin/bash

NAME='laoyang'
STR="you name is ${NAME}"

echo ${NAME}${STR} 
NAME1=${NAME}"fff"
NAME=${NAME1}
echo ${NAME}
echo ${NAME1}

echo ${#NAME1}
echo ${NAME1:1:5}

echo `expr index "${STR}" "is"`
