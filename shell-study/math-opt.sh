#!/bin/bash

a=30
b=20

val=`expr ${a} + ${b}`
echo "a + b = ${val}"

val=`expr ${a} - ${b}`
echo "a - b = ${val}"

val=`expr ${a} \* ${b}`
echo "a * b = ${val}"

val=`expr ${a} / ${b}`
echo "a / b = ${val}"

val=`expr ${a} % ${b}`
echo "a % b = ${val}"

if [ ${a} == ${b} ]
then
    echo "values is equal"
fi    

if [ ${a} != ${b} ]
then
    echo "values is not equal"
fi    
