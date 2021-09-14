#!/bin/bash
gcc ex1.c -o ex1
for run int {1..10}; do ./ex1; done
