#!/usr/bin/python3
""" Unlock boxes """


def canUnlockAll(boxes):
    keys = boxes[0]

    for i in range(len(boxes) - 1):
        if i + 1 in keys:
            keys = keys + boxes[i + 1]
        else:
            return False

    return True
