#!/bin/bash

read -p "Enter your name:" name 
echo "Your name is: $name"

read -p "Enter first number:" num1
read -p "Enter second number:" num2
read -p "Enter third number:" num3
echo "First number is:  $num1"
echo "Second number is: $num2"
echo "Third number is:  $num3"

# 超时输入
read -t 5 -p "Enter your name in 10 sec:" name 
echo "Your name is: $name"

# 密码输入
read -s -p "Enter your password:" passwd
echo "Your pass word is: $passwd"

# 从变量中读入
nameservers="ns1.nixcraft.net ns2.nixcraft.net ns3.nixcraft.net"
read -r ns1 ns2 ns3  <<< "$nameservers"
echo $ns1
echo $ns2
echo $ns3

# 自定义读入分隔符
password="gitevivek:x:1002:1002::/home/gitevivek:/bin/sh"
old=$IFS
IFS=:
read -r login password uid gid info home shell <<< "$password"
printf "Your login name is %s, uid %d, gid %d, home dir set to %s with %s as login shell\n" $login $uid $gid $home $shell
IFS=$old
