#!/bin/bash

TAR=/bin/tar
MYSQL=/usr/bin/mysql
MYSQL_DUMP=/usr/bin/mysqldump
USERNAME=root
PASSWORD=123456

DATABASES=`$MYSQL -u$USERNAME -p$PASSWORD -Bse 'show databases'`

for DB in $DATABASES
do
    if [ $DB != "ipm" ]; then
        $MYSQL_DUMP -u$USERNAME -p$PASSWORD $DB > $DB.backup.sql 
        if [ $? -eq 0 ]; then
           DB_BACKUP_FILES_TAR=$DB_BACKUP_FILES_TAR" "$DB".backup.sql"
        else
            echo "ship backup $DB ..."
        fi
        DB_BACKUP_FILES=$DB_BACKUP_FILES" "$DB".backup.sql"
    fi
done

$TAR -zcvf "mysql-backup-`date "+%Y-%m-%d"`.tar.gz" $DB_BACKUP_FILES_TAR
rm -f $DB_BACKUP_FILES
