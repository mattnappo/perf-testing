#!/bin/bash

# user configuration
flags="-Wall -g3 -O0 -mavx"
perf_flags="-Wall -O3 -mavx"
target="spmd"
nprocs=4

# script meta
set -e
mkdir -p bin/
target="bin/$target"

# compilation step
if [ "$1" == "perf" ]; then
    echo "compiling with perf flags"
    gcc *.c $perf_flags -o $target
elif [ "$1" == "asm" ]; then
    gcc -S -mavx vector_math.c -o bin/vector_math.S
    exit
else
    echo "compiling with debug flags"
    gcc *.c $flags -o $target
fi

# run step
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
