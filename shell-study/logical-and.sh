#!/bin/bash

rm /tmp/x123 && echo 'rm /tmp/x123 deleted.' || echo 'rm /tmp/x123 not exist'
grep -i laoyang /etc/passwd && echo 'user laoyang found' || echo 'user laoyang not found'
test ! -d /tmp/x123 && echo '/tmp/x123 does not exist' || echo '/tmp/x123 exist'

cat /etc/passwd1 2>/dev/null || echo 'fail to open file /etc/passwd'
test `id -u` -eq 0 && echo 'you are root' || echo 'you are root'

