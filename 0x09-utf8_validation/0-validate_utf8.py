#!/usr/bin/python3


def validUTF8(data):
    n_bytes = 0
    mask1 = 1 << 7
    mask2 = 1 << 6

    for char in data:
        mask = 1 << 7
        if n_bytes == 0:
            while mask & char:
                n_bytes += 1
                mask = mask >> 1

            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (char & mask1 and not (char & mask2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
