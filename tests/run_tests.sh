#bin/bash

cc tests.c -ggdb -o tests.out -Ideps/ -I../
./tests.out