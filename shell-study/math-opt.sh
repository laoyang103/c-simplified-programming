#!/bin/bash

a=30
b=20

val=`expr ${a} + ${b}`
echo "a + b = ${val}"
val=$(( $a + $b ))
echo "a + b = ${val}"

val=`expr ${a} - ${b}`
echo "a - b = ${val}"
val=$(( $a - $b ))
echo "a - b = ${val}"

val=`expr ${a} \* ${b}`
echo "a * b = ${val}"
val=$(( $a * $b ))
echo "a * b = ${val}"

val=`expr ${a} / ${b}`
echo "a / b = ${val}"
val=$(( $a / $b ))
echo "a / b = ${val}"

val=`expr ${a} % ${b}`
echo "a % b = ${val}"
val=$(( $a % $b ))
echo "a % b = ${val}"

if [ ${a} == ${b} ]
then
    echo "values is equal"
fi    

if [ ${a} != ${b} ]
then
    echo "values is not equal"
fi    

x=5
echo "x++ is: $(( x++ ))"
echo "x-- is: $(( x-- ))"
echo "x** is: $(( x**2 ))"
