#!/bin/bash

rrdfile=/tmp/rrd/mysqld_cpu.rrd
web_root=/opt/apache-tomcat-6.0.37/webapps/ROOT/
pic=$web_root"/mysqld_cpu.png"
now=`date +%s`
now_930=`expr $now - 930`

rrdtool graph $pic\
            --start=$now_930 --end $now \
            -h 334 -w 543 -l 0 -a PNG -v "%" \
            DEF:x1=$rrdfile:VALUE:AVERAGE \
            VDEF:min=x1,MINIMUM \
            VDEF:max=x1,MAXIMUM \
            VDEF:avg=x1,AVERAGE \
            VDEF:lst=x1,LAST \
            "COMMENT: \l" \
            "COMMENT:           Minimum" \
            "COMMENT:           Maximum" \
            "COMMENT:           Average" \
            "COMMENT:           Current" \
            "COMMENT:   " \
            AREA:x1#EDA362:x1  \
            "GPRINT:min:%5.1lf " \
            "GPRINT:max:%5.1lf " \
            "GPRINT:avg:%5.1lf " \
            "GPRINT:lst:%5.1lf " 
