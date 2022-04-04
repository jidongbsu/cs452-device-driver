#!/bin/bash

./toyota_load

./test-toyota 0 0 r
./test-toyota 0 1 r
./test-toyota 0 2 r
./test-toyota 0 10 r
./test-toyota 0 10 r 
./test-toyota 0 100 r
./test-toyota 0 1000 r
./test-toyota 0 10000 r
./test-toyota 0 100000 r
./test-toyota 0 200000 r

./test-toyota 0 1000 w
./test-toyota 1 1000 w
./test-toyota 2 1000 w
./test-toyota 3 1000 w

./test-toyota 0 0 r | wc -m
./test-toyota 0 1 r | wc -m
./test-toyota 0 2 r | wc -m
./test-toyota 0 10 r | wc -m
./test-toyota 0 10 r  | wc -m
./test-toyota 0 100 r | wc -m
./test-toyota 0 1000 r | wc -m
./test-toyota 0 10000 r | wc -m
./test-toyota 0 100000 r | wc -m
./test-toyota 0 200000 r | wc -m


./toyota_unload
