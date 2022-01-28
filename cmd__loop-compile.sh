echo "
#ifndef _VALUES__HPP
#define _VALUES__HPP

#define STDIO__BAUD $3

#endif
" > $2values.hpp

while [ true ]
do
  sleep 10
  clear
  ls -l --ignore=node_modules $2
  ls -l --ignore=node_modules res__system/
  arduino-cli compile -b $1 $2
done
