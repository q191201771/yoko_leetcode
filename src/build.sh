#!/bin/bash

if [ $# != 1 ] ; then
  echo 'Usage: ./build.sh <source file>'
  exit 1
fi

g++ $1 -DYOKO_DEBUG -std=c++11 -O0 -g
