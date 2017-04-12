#!/bin/bash

for i in 'seq 50' # now we have iterate over from 1 to 50
do
	if [ i < 25 ]
		echo $i
	else
		./my_prog > "$i".out
done