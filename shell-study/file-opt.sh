#!/bin/bash

FILE="/tmp/aa"

IFS=,
echo "the script name is $0"
echo '$@ is :'
echo "$@"
echo '$* is :'
echo "$*"
echo '$# is :'
echo "$#"

if [ -r ${FILE} ]
then
    echo "-r ${FILE}: has read access"
else
    echo "-r ${FILE}: not has read access"
fi    

if [ -w ${FILE} ]
then
    echo "-w ${FILE}: has write access"
else
    echo "-w ${FILE}: not has write access"
fi    

if [ -x ${FILE} ]
then
    echo "-x ${FILE}: has execute access"
else
    echo "-x ${FILE}: not has execute access"
fi    

if [ -f ${FILE} ]
then
    echo "-f ${FILE}: is a ordinary FILE"
else
    echo "-f ${FILE}: is a sepcial FILE"
fi    

if [ -d ${FILE} ]
then
    echo "-d ${FILE}: is a directory"
else
    echo "-d ${FILE}: is not a directory"
fi    

if [ -s ${FILE} ]
then
    echo "-s ${FILE}: size is not zero"
else
    echo "-s ${FILE}: size is zero"
fi    

if test -e ${FILE}
then
    echo "-e ${FILE}: is exist"
else
    echo "-e ${FILE}: is not exist"
fi    

echo '================================================='

[ -a $FILE ] && echo "[ -a $FILE ]: $FILE found" || echo "[ -a $FILE ]: $FILE not found"
[ ! -a $FILE ] && { echo "can not found $FILE create it"; mkdir -p $FILE; }











