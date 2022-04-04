#!/bin/bash

./toyota_load

echo
cat /proc/driver/toyota
echo

./test-toyota 0 100 r &
./test-toyota 1 100 r &
./test-toyota 2 100 r &
./test-toyota 3 100 r &
./test-toyota 3 100 w &
./test-toyota 2 100 w &
./test-toyota 1 100 w &
./test-toyota 0 100 w &

wait

echo
cat /proc/driver/toyota
echo

./toyota_unload
