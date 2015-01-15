#!/bin/bash

while :
do
    # display menu
    clear
    echo "Server Name - `hostname`"
    echo "-------------------------------"
    echo "     M A I N - M E N U"
    echo "-------------------------------"
    echo "1. Display date and time."
    echo "2. Display what users are doing."
    echo "3. Display network connections."
    echo "4. Exit"
    read -p 'Enter your select:' select
    case $select in
        1)
            echo "Now is `date`"
            read -p "Press [Enter] key to continue..." readEnterKey
            ;;
        2)
            w
            read -p "Press [Enter] key to continue..." readEnterKey
            ;;
        3)
            netstat -anp | grep tcp
            read -p "Press [Enter] key to continue..." readEnterKey
            ;;
        4)
            echo 'bye'
            break
            ;;
        *)
            echo 'You do not select 1-4'
            read -p "Press [Enter] key to continue..." readEnterKey
            ;;
    esac        
done

while :
do
    read -p 'Enter two number (-1 to quit)' a b
    if [ $a -eq -1 ]; then
        break
    fi    
    sum=`expr $a + $b`
    echo "$a add $b is $sum"
done

while true
do
    echo 'forever loop press Ctrl+C to stop'
    sleep 1
done
