#!/bin/bash

user=$1
passwddb=/etc/passwd

[ $# -eq 0 ] && { echo "Usage: $0 username"; exit 1; }

grep ^$user $passwddb > /dev/null
[ $? -eq 0 ] && echo "$user found" || echo "$user not found"

res=$(grep ^$user $passwddb)
[ ! -z $res ] && echo "$user found" || echo "$user not found"
