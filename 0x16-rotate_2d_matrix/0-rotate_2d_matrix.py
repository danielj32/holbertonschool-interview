#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it
90 degrees clockwise
Do not return anything.
The matrix must be edited in-place.
You can assume the matrix will have 2 dimensions and will not be empty.
"""


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix,
    rotate it
    90 degrees clockwise """
    begin = 0
    ult = len(matrix) - 1
    while begin < ult:
        for x in range(begin, ult):
            temp = matrix[x][ult]
            matrix[x][ult] = matrix[begin][x]
            temp2 = matrix[ult][ult + begin - x]
            matrix[ult][ult + begin - x] = temp
            temp = matrix[ult + begin - x][begin]
            matrix[ult + begin - x][begin] = temp2
            matrix[begin][x] = temp
        begin = begin + 1
        ult = ult - 1
