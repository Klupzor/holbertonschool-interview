#!/usr/bin/python3
""" Unlock boxes """


def canUnlockAll(boxes):
    locked = {box: True for box in range(1, len(boxes))}
    locked.update({0: False})
    keys = boxes[0]
    unlock(boxes, locked, keys)

    if True in locked.values():
        return False
    return True


def unlock(boxes, locked, keys):
    for key in keys:
        if locked[key]:
            locked[key] = False
            unlock(boxes, locked, boxes[key])
