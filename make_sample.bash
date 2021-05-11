#!/bin/bash

make clean
make

rm -rf ./result
mkdir ./result

let i=4
let max=32768
let end_number=1

if [ ! -z $1 ];
then
    end_number=$1
fi

# echo $end_number

for (( i=4; i <= max; i*=2))
do
    ./matrix_generator $i $i $end_number
done