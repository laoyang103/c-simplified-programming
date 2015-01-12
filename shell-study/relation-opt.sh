#!/bin/bash


a=10
b=20

if [ ${a} -eq ${b} ]
then
    echo "${a} -eq ${b}: TRUE"
else    
    echo "${a} -eq ${b}: FLASE"
fi    

if [ ${a} -ne ${b} ]
then
    echo "${a} -ne ${b}: TRUE"
else    
    echo "${a} -ne ${b}: FLASE"
fi    

if [ ${a} -gt ${b} ]
then
    echo "${a} -gt ${b}: TRUE"
else    
    echo "${a} -gt ${b}: FLASE"
fi    

if [ ${a} -lt ${b} ]
then
    echo "${a} -lt ${b}: TRUE"
else    
    echo "${a} -lt ${b}: FLASE"
fi    

if [ ${a} -ge ${b} ]
then
    echo "${a} -ge ${b}: TRUE"
else    
    echo "${a} -ge ${b}: FLASE"
fi    

if [ ${a} -le ${b} ]
then
    echo "${a} -le ${b}: TRUE"
else    
    echo "${a} -le ${b}: FLASE"
fi    

if [ ${a} -le ${b} -a ${a} -gt 0 ]
then
    echo "${a} -le ${b} -a ${a} -gt 0: TRUE"
else    
    echo "${a} -le ${b} -a ${a} -gt 0: FLASE"
fi    

if [ ${a} -ge ${b} -o ${a} -gt 10 ]
then
    echo "${a} -le ${b} -o ${a} -gt 0: TRUE"
else    
    echo "${a} -le ${b} -o ${a} -gt 0: FLASE"
fi    



