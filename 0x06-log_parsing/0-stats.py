#!/usr/bin/python3
""" stats
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
<status code> <file size>"""
import sys

Tsize = 0
cont = 0
status_code = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    500: 0
}

for arg in sys.stdin:
    args = arg.split(" ")
    if len(args) > 2:
        size = args[-1]
        code = int(args[-2])
        if code in status_code:
            status_code[code] += 1

        Tsize += int(size)
        cont += 1
    if cont == 10:
        print("File size: {}".format(Tsize))

        for k, v in sorted(status_code.items()):
            print("{}: {}".format(k, v))
        cont = 0
