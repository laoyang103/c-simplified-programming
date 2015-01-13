#!/bin/bash


array=(
"aa"
"bb pp"
"cc"
"dd"
)
array[4]="ff 222"

echo ${array[0]}
echo ${array[1]}
echo ${array[2]}
echo ${array[3]}
echo ${array[4]}

echo ${array[*]}
echo ${array[@]}

echo ${#array[*]}
echo ${#array[@]}
echo ${#array[4]}
