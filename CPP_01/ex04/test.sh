#!/bin/bash

make

  ./sed asd asd ""
  sed 's/asd//g' asd > sedtest

diff sedtest asd.replace


  ./sed asd asd asd
  sed 's/asd/asd/g' asd > sedtest

diff sedtest asd.replace

  ./sed asd asd as
  sed 's/asd/as/g' asd > sedtest

diff sedtest asd.replace

  ./sed asd a a
  sed 's/a/a/g' asd > sedtest

diff sedtest asd.replace

  ./sed asd " " 5
  sed 's/ /5/g' asd > sedtest

diff sedtest asd.replace

  ./sed asd asd $'\n'
  sed 's/asd/\n/g' asd > sedtest

diff sedtest asd.replace

  ./sed 42 42 1
  sed 's/42/1/g' 42 > sedtest

diff sedtest 42.replace

  ./sed 42 42 "            "
  sed 's/42/            /g' 42 > sedtest

diff sedtest 42.replace

  ./sed 42 4 2
  sed 's/4/2/g' 42 > sedtest

diff sedtest 42.replace

  ./sed 42 2 2
  sed 's/2/2/g' 42 > sedtest

diff sedtest 42.replace

  ./sed 42 2 4
  sed 's/2/4/g' 42 > sedtest

diff sedtest 42.replace

  ./sed 42 "  " ""
  sed 's/  //g' 42 > sedtest

diff sedtest 42.replace

rm sedtest 42.replace asd.replace


