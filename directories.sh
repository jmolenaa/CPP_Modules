#!/bin/bash

# Just a simple bash script to create the directory structure for a module plus adds a default Makefile to the roots fo the exercises
# Use by running the script with two arguments, first being the number of the module, the second being however many exercises there are

if [ $# != 2 ]
then
  echo "usage: ./directories.sh [module number] [amount of exercises in module]"
  exit
fi

mkdir CPP_0$1
for (( i=0; i <= $2 ; i++))
do
  mkdir CPP_0$1/ex0$i
  mkdir CPP_0$1/ex0$i/incs
  mkdir CPP_0$1/ex0$i/src
  cp Makefile CPP_0$1/ex0$i/
  cp defines.h CPP_0$1/ex0$i/incs/
done

