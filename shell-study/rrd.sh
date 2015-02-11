#!/bin/bash

curr=`date +"%s"`
curr_100=`expr $curr - 100`

rrdtool create /tmp/test.rrd --start $curr_100 --step 10 DS:VALUE:GAUGE:90:U:U RRA:AVERAGE:0.5:1:144000
rrdtool update /tmp/test.rrd `expr $curr_100 + 10`:100.0
rrdtool update /tmp/test.rrd `expr $curr_100 + 20`:111.0
rrdtool update /tmp/test.rrd `expr $curr_100 + 30`:112.0
rrdtool update /tmp/test.rrd `expr $curr_100 + 40`:113.0
rrdtool update /tmp/test.rrd `expr $curr_100 + 50`:114.0
rrdtool update /tmp/test.rrd `expr $curr_100 + 60`:115.0
rrdtool update /tmp/test.rrd `expr $curr_100 + 70`:116.0
rrdtool fetch  /tmp/test.rrd AVERAGE --start -330 --end -10
