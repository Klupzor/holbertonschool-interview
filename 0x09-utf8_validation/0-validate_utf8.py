#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    errors = ['0c', '1c', '5f', '7f', '8f', '9f',
              'af', 'bf', 'cf', 'df', 'df', 'ef', 'ff']
    chars = [hex(num) for num in data]
    for char in chars:
        hexnum = char[2:]
        if hexnum in errors:
            return(False)

    return(True)
