#!/usr/bin/python3
"""unlock boxes """


def canUnlockAll(boxes):
    """
    method that determines if all the boxes can be opened
    * boxes is a list of lists
    * A key with the same number as a box opens that box
    """
    for key in range(1, len(boxes) - 1):
        validation = False
        for idx in range(len(boxes)):
            validation = key in boxes[idx] and key != idx
            if validation:
                break
        if not validation:
            return validation
    return True
