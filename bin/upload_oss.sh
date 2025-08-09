#!/bin/sh

for i in $@
do
  echo $i

  ossutil64 cp $i oss://apache-doris-releases/

  echo
done
