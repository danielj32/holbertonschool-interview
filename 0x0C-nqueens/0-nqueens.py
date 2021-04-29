#!/usr/bin/python3
""" N Queens """
import sys


def checkSafe(Board, rows, column):
    """ function checks if we can insert queen
    at column in that rows in the Board"""
    for x in range(rows):
        if (Board[x] == column or
                Board[x] + rows - x == column or
                Board[x] + x - rows == column):
            return False
    return True


def stored_board(Board, rows):
    """ stored each rows
    of the board with the right index """
    for i in range(len(Board)):
        if checkSafe(Board, rows, i):
            Board[rows] = i
            if rows < len(Board) - 1:
                stored_board(Board, rows + 1)
            else:
                print([[i, Board[i]] for i in range(len(Board))])

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)
try:
    n = int(sys.argv[1])
except:
    print("N must be a number")
    sys.exit(1)
if n < 4:
    print("N must be at least 4")
    sys.exit(1)

Board = [-1 for i in range(n)]
stored_board(Board, 0)
