#!/usr/bin/python3
"""
makeChance function
"""


def makeChange(coins, total):
    cont = 0
    coins.sort(reverse=True)

    for coin in coins:
        while coin <= total:
            total = total - coin
            cont += 1

    return cont if total == 0 else -1
