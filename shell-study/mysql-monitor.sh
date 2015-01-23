#!/bin/bash

mysql_log=/var/log/mysql/error.log
error=`grep -ic "error" $mysql_log`

if test $error -ge 1
then
    echo "mysql hava $error errors ..."
else    
    echo 'mysql normal ...'
fi    
