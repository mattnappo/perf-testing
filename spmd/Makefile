FLAGS = -Wall -Iinclude
DEBUG_FLAGS = -g3 -O0
SCALAR_FLAGS = -O3
AVX_FLAGS = -O3 -mavx

SRCS = $(wildcard src/*.c)
BINDIR = bin

TARGET_DEBUG  = $(BINDIR)/spmd_debug
TARGET_SCALAR = $(BINDIR)/spmd_scalar
TARGET_AVX    = $(BINDIR)/spmd_avx

all: scalar avx

debug: $(SRCS)
	gcc $(SRCS) $(FLAGS) $(DEBUG_FLAGS) -o $(TARGET_DEBUG)

scalar: $(SRCS)
	gcc $(SRCS) $(FLAGS) $(SCALAR_FLAGS) -o $(TARGET_SCALAR)

avx: $(SRCS)
	gcc $(SRCS) $(FLAGS) $(AVX_FLAGS) -o $(TARGET_AVX)

test-debug: debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(TARGET_DEBUG)

test-avx: avx
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(TARGET_AVX)

.PHONY: clean
clean:
	rm -f $(BINDIR)/*
	rm -f vgcore.*
	rmdir bin/

