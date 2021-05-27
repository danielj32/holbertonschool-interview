#!/usr/bin/python3
"""
0x10. Rain
"""


def rain(walls):
    """Given a list of non-negative integers
    representing walls of width 1,
    calculate how much water
    will be retained after it rains.
    """
    if not walls:
        return 0
    if len(walls) < 3:
        return 0
    waterRainbow = 0
    for key in range(1, len(walls) - 1):
        l_column = max(walls[:key])
        r_column = max(walls[key + 1:])
        minium = min(l_column, r_column)
        if walls[key] < minium:
            waterRainbow += minium - walls[key]
    return waterRainbow
