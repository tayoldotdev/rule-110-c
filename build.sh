#!/bin/sh

set -xe

clang -Wall -Wextra -std=c11 -pedantic -ggdb -o main main.c
