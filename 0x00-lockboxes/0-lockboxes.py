#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    method that determines if all the boxes can be opened
    """
    firstbox = [0]
    for k in firstbox:
        for keyMaster in boxes[k]:
            if keyMaster not in firstbox:
                if keyMaster < len(boxes):
                    firstbox.append(keyMaster)
    if len(firstbox) == len(boxes):
        return True
    return False
