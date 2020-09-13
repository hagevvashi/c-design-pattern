#!/usr/bin/env bash

gcc -std=c11 -o dist/main.out src/main.c

runtest() {
    output=$(echo $1 | ./dist/main.out)
    echo $output
}

runtest "
6 3
0 1 2 3 4 5
" "3 4 5 0 1 2"
