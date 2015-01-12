#!/bin/bash


a="abc"
b="xyz"

if [ ${a} == ${b} ]
then
    echo "${a} == ${b}: TRUE"
else    
    echo "${a} == ${b}: FLASE"
fi    

if [ ${a} != ${b} ]
then
    echo "${a} != ${b}: TRUE"
else    
    echo "${a} != ${b}: FLASE"
fi    

if [ -z ${a} ]
then
    echo "-z(string length is zero) ${a}: TRUE"
else    
    echo "-z(string length is zero) ${a}: FLASE"
fi    

if [ -n ${a} ]
then
    echo "-n(string length is not zero) ${a}: TRUE"
else    
    echo "-n(string length is not zero) ${a}: FLASE"
fi    

if [ ${a} ]
then
    echo "(string is not empty) ${a}: TRUE"
else    
    echo "(string is not empty) ${a}: FLASE"
fi    
