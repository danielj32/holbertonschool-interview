#!/usr/bin/python3
""" 0. Change comes
from within """


def makeChange(coins, total):
    """ Given a pile of coins
    of different values,
    determine the fewest number
    of coins needed to meet
    a given amount total """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    sm = 0
    aux = 0
    temp = 0
    n_coins = len(coins)
    while sm < total and aux < n_coins:
        while coins[aux] <= total - sm:
            sm += coins[aux]
            temp = temp + 1
            if sm == total:
                return temp
        aux = aux + 1
    return -1
