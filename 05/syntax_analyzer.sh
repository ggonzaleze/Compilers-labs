#!/bin/bash

function isValid {
	echo "$1 :"
	echo $1 | ./syntax_analyzer
}
make > /dev/null
input=$1
while IFS= read -r line
do
isValid $line
done < "$input"
