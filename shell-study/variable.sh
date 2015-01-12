#!/bin/bash

DEFNAME="laoyang"
# 取消变量
# unset DEFNAME

# 只读变量
readonly DEFNAME
echo "default name is ${DEFNAME}"
# DEFNAME="lao"

# 特殊变量
echo "File Name: $0"
echo "First Parameter : $1"
echo "Second Parameter : $2"
echo "Quoted Values: $@"
echo "Quoted Values: $*"
echo "Total Number of Parameters : $#"

# 变量替换
unset DATE
echo ${DATE:-"DATE not set"}
echo "1 - value of DATE is ${DATE}"

DATE=`date`
echo ${DATE:=`date`}
echo "2 - value of DATE is ${DATE}"

echo ${DATE:+"DATE has set"}
echo "3 - value of DATE is ${DATE}"

unset DATE
echo ${DATE:?"DATE not set stop ..."}

# echo 'Input your name:'
# read NAME
# echo "Your name is ${NAME}"
