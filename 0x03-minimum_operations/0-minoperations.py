#!/usr/bin/python3
"""
Min operatation: Copy All and Paste
"""


def minOperations(n):
    if type(n) is not int:
        return(0)
    min = 0
    i = 2
    while i <= n:
        if n % i == 0:
            min += i
            n = n / i
        else:
            i += 1
    return(min)
