#!/bin/bash

if [ $# != 2 ]
then
  echo Wrong usage lol
  exit
fi

mkdir CPP_0$1
for (( i=0; i <= $2 ; i++))
do
  mkdir CPP_0$1/ex0$i
  mkdir CPP_0$1/ex0$i/incs
  mkdir CPP_0$1/ex0$i/src
  cp Makefile CPP_0$1/ex0$i/
done

