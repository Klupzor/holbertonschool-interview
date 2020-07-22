#!/usr/bin/python3
""" Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Rotate 2D Matrix n*n
    """
    list_of_tuples = zip(*matrix[::-1])
    temp = [list(elem) for elem in list_of_tuples]

    for i, row in enumerate(temp):
        matrix[i] = temp[i]
