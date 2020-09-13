#!/usr/bin/env bash

TEST_DIR=$(cd $(dirname $0); pwd)
PROJECT_DIR=$(cd $TEST_DIR; cd ..; pwd)
cd $PROJECT_DIR

gcc -std=c11 -o ./dist/main.out ./src/main.c

runtest() {
    input=$(cat < $1)
    result=$(./dist/main.out < "$1")
    expect=$(cat < "$2")

    if [ "$expect" != "$result" ]; then
        echo "$input: \"$expect\" expected, but got \"$result\""
        exit 1
    fi
    echo "$input => $result"
}

runtest "${TEST_DIR}/input1.txt" "${TEST_DIR}/output1.txt"
runtest "${TEST_DIR}/input2.txt" "${TEST_DIR}/output2.txt"
