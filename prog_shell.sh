#!/bin/bash

file="./my_prog"
if [ -f "$file" ]
then
  echo "$file found."
else
  echo "gcc -std=c99 -Wall -o my_prog my_prog.c"
fi