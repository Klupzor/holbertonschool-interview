#! /usr/bin/python3
"""
Min operatation: Copy All and Paste
"""


def minOperations(n):
    min = 0
    for i in range(2, n+1):
        while(n % i == 0):
            min += i
            n = n/i
    return(min)