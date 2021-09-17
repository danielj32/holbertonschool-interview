#!/usr/bin/python3
"""
0. Pascal's Triangle
"""


def pascal_triangle(n):
    """ Returns an empty list if n <= 0
    You can assume n will be always an integer
    """
    if n <= 0:
        return []
    if n == 1:
        return [[1, ], ]
    if n == 2:
        return [[1, ], [1, 1]]
    pascal = [[1, ], [1, 1]]
    for i in range(3, n + 1):
        r = [1, ]
        for x in range(len(pascal[-1]) - 1):
            r.append(pascal[-1][x] + pascal[-1][x + 1])
        r.append(1)
        pascal.append(r)
    return pascal
