#!/usr/bin/python3
"""
determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    ctBytes = 0
    first = 1 << 7
    second = 1 << 6

    for i in data:
        mask_n_byte = 1 << 7
        if ctBytes == 0:
            while mask_n_byte & i:
                ctBytes += 1
                mask_n_byte = mask_n_byte >> 1

            if ctBytes == 0:
                continue
            if ctBytes == 1 or ctBytes > 4:
                return False
        else:
            if not (i & first and not (i & second)):
                return False
        ctBytes -= 1
    if ctBytes == 0:
        return True
    return False
