#!/bin/bash

user=$1
passwddb=/etc/passwd

[ $# -eq 0 ] && { echo "Usage: $0 username"; exit 1; }

grep ^$user $passwddb > /dev/null
[ $? -eq 0 ] && echo "$user found" || echo "$user not found"

res=$(grep ^$user $passwddb)
[ ! -z $res ] && echo "$user found" || echo "$user not found"

SOURCE=/etc/apt
TOBACKUP=/tmp/etc-backup
ERRORLOG=/tmp/error.log

[ ! -d $SOURCE ] && { echo "$SOURCE not found ..."; exit 1; }
[ ! -d $TOBACKUP ] && { echo "$TOBACKUP not found, create it ..."; mkdir -p $TOBACKUP; }

tar -zcvf $TOBACKUP"/etc-backup.tar.gz" $SOURCE 2>$ERRORLOG

if [ $? -ne 0 ]; then
    echo "An error occurred during backup ses $ERRORLOG"
    exit 2
fi
