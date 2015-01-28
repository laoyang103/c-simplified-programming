#!/bin/bash

[ 54 == 54 ] && echo "54 is equals 54" || echo "54 is not equals 54"
[ "qwer" == "wqer" ] && echo "qwer is equals wqer" || echo "qwer is not equals wqer"

[ -d /tmp/aa ] && echo "/tmp/aa is exist" || echo "/tmp/aa is not exist"

STR=zxcv
[[ $STR == z* ]] && echo '[[ $STR == z* ]] is true' || echo '[[ $STR == z* ]] is false' 
[[ $STR == "z*" ]] && echo '[[ $STR == "z*" ]] is true' || echo '[[ $STR == "z*" ]] is false' 

[ $STR == z* ] && echo '[ $STR == z* ] is true' || echo '[ $STR == z* ] is false' 
[ $STR == "z*" ] && echo '[ $STR == "z*" ] is true' || echo '[ $STR == "z*" ] is false' 

if test -z $STR; then
    echo "$STR length is zero"
else     
    echo "$STR length is not zero"
fi
