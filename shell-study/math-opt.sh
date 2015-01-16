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

declare -r a=10
declare -r b=20
declare -i c=0
c=$(( a+b ))
echo "$a + $b = $c"
