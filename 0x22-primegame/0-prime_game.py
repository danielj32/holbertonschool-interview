#!/usr/bin/python3
""" Maria and Ben are playing a game."""


def isWinner(x, nums):
    """ where x is"""
    name_player1 = "Maria"
    name_player2 = "Ben"

    if not nums:
        return None
    elif x < 1:
        return None
    n = max(nums)
    check_max = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not check_max[i]:
            continue
        for j in range(i*i, n + 1, i):
            check_max[j] = False

    check_max[0] = check_max[1] = False
    c = 0
    for i in range(len(check_max)):
        if check_max[i]:
            c += 1
        check_max[i] = c

    player1 = 0
    for n in nums:
        player1 += check_max[n] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 > len(nums):
        return name_player1
    return name_player2
