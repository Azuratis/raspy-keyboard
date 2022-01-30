echo "
#ifndef _VALUES__HPP
#define _VALUES__HPP

#define STDIO__BAUD $3

#endif
" > $2values.hpp

while [ true ]
do
  clear
  ls -1shp --ignore=node_modules $2
  ls -1shp --ignore=node_modules res__system
  echo "---------------------------------"/
  arduino-cli compile -b $1 $2
  sleep 25
done
