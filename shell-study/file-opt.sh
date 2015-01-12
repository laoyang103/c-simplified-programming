#!/bin/bash

file="/tmp/aa"

if [ -r ${file} ]
then
    echo "-r ${file}: has read access"
else
    echo "-r ${file}: not has read access"
fi    

if [ -w ${file} ]
then
    echo "-w ${file}: has write access"
else
    echo "-w ${file}: not has write access"
fi    

if [ -x ${file} ]
then
    echo "-x ${file}: has execute access"
else
    echo "-x ${file}: not has execute access"
fi    

if [ -f ${file} ]
then
    echo "-f ${file}: is a ordinary file"
else
    echo "-f ${file}: is a sepcial file"
fi    

if [ -d ${file} ]
then
    echo "-d ${file}: is a directory"
else
    echo "-d ${file}: is not a directory"
fi    

if [ -s ${file} ]
then
    echo "-s ${file}: size is not zero"
else
    echo "-s ${file}: size is zero"
fi    

if test -e ${file}
then
    echo "-e ${file}: is exist"
else
    echo "-e ${file}: is not exist"
fi    













