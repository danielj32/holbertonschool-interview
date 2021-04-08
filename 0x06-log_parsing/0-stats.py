#!/usr/bin/python3
""" Log parsing reads stdin l by l"""
from sys import stdin


n_list = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

ct = 0


def printing():
        """ Function that prints logs
            reads stdin l by l and computes metrics:
            (if the format is not this one, the l must be skipped)
            Total file size: File size: <total size>
            where <total size> is the sum of all previous
            Number of ls by status code:
            possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
            format: <status code>: <number>
            status codes should be printed in ascending order
         """
        print("File size: {}".format(ct))
        for k in sorted(n_list.keys()):
            if n_list[k] and isinstance(int(k), int):
                print("{}: {}".format(k, n_list[k]))


if __name__ == "__main__":
    iter = 0
    try:
        for line in stdin:
            iter += 1
            inf = line.split()
            ct += int(inf[-1])
            if len(inf) > 2:
                    if inf[-2] in n_list and isinstance(int(inf[-2]), int):
                            n_list[inf[-2]] += 1
                            if iter % 10 == 0:
                                    printing()
    except Exception:
        pass
    finally:
        printing()
