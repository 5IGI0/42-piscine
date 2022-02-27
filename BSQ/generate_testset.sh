#!/bin/sh

rm -f ./testset/*

mkdir -p ./testset/

for i in $(seq 50)
do
	./gen_map $(( ( RANDOM % 150 )  + 10 )) $(( ( RANDOM % 150 )  + 10 )) $(( ( RANDOM % 100 )  )) > "./testset/${i}.txt"
done
