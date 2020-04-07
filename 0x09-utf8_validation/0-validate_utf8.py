#!/usr/bin/python3
"""
Main file for testing
"""
def validUTF8(data):
    chars = [chr(num) for num in data]
    print(chars)
    for char in chars:
        b = char.encode(encoding='UTF-8',errors='strict')
        string = str(b)
        cut = string.split("x")
        print (b, string, len(cut), cut)
        
    print("fin")

