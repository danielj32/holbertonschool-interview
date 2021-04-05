#!/usr/bin/python3
"""
determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need
    to handle the 8 least significant bits of each integer
    """
    ctByt = 0
    first = 1 << 7
    second = 1 << 6

    for j in data:
        mask_of_byt = 1 << 7
        if ctByt == 0:
            while mask_of_byt & j:
                ctByt += 1
                mask_of_byt = mask_of_byt >> 1

            if ctByt == 0:
                continue
            if ctByt == 1 or ctByt > 4:
                return False
        else:
            if not(j & first and not (j & second)):
                return False
        ctByt -= 1
        if ctByt == 0:
            return True
        return False
