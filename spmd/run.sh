#!/bin/bash

# bash > make

flags="-Wall -g3 -O0 -mavx"
target="spmd"
nprocs=4

set -e
mkdir -p bin/

target="bin/$target"
gcc *.c $flags -o $target

if [ "$1" == "test" ]; then
    SPMD_NUM_PROCS=$nprocs valgrind \
        --leak-check=full           \
        --show-leak-kinds=all       \
        --track-origins=yes         \
        --verbose                   \
        $target
else
    SPMD_NUM_PROCS=$nprocs $target
fi
