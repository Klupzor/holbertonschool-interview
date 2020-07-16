#!/usr/bin/env python3
from math import ceil, floor


def karatsuba(num1, num2):
    if num1 < 10 and num2 < 10:
        return num1 * num2

    n = max(len(str(num1)), len(str(num2)))
    m = ceil(n/2)

    h1 = floor(num1 / 10**m)
    l1 = num1 % (10**m)

    h2 = floor(num2 / 10**m)
    l2 = num2 % (10**m)

    z0 = karatsuba(l1, l2)
    z1 = karatsuba(h1 + l1, h2 + l2)
    z2 = karatsuba(h1, h2)

    return int(z2*(10**(m*2)) + (z1 - z2 - z0)*(10**m) + z0)


print(karatsuba(200, 300))
