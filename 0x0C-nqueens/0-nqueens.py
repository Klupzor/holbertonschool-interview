#!/usr/bin/python3
"""
N Queens
"""
import sys


if len(sys.argv) is not 2:
    print("Usage: nqueens N")
    exit(1)

try:
    nQueens = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if nQueens < 4:
    print("N must be at least 4")
    exit(1)


def attack(square, queen):
    (row1, col1) = square
    (row2, col2) = queen
    return (row1 == row2) or (col1 == col2) or\
        abs(row1 - row2) == abs(col1 - col2)


def safe(square, queens):
    for queen in queens:
        if attack(square, queen):
            return 0
    return 1


def solve(n):
    if n == 0:
        return [[]]
    smaller_solutions = solve(n-1)
    return [solution+[(n, i+1)]
            for i in range(nQueens)
            for solution in smaller_solutions
            if safe((n, i+1), solution)]


for answer in reversed(solve(nQueens)):
    queensPos = [list(pos) for pos in answer]
    temp = []
    for p in queensPos:
        temp.append([i - 1 for i in p])

    print(temp)
