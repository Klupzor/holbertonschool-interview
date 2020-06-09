#!/usr/bin/python3
""" Rain
"""


def rain(walls):
    """ returns how much water will be retained after it rains
    """
    water = 0
    left_max = 0
    right_max = 0
    low = 0
    high = len(walls) - 1

    while(low <= high):
        if(walls[low] < walls[high]):
            if(walls[low] > left_max):
                left_max = walls[low]
            else:
                water += left_max - walls[low]
            low += 1
        else:
            if(walls[high] > right_max):
                right_max = walls[high]
            else:
                water += right_max - walls[high]
            high -= 1

    return water
