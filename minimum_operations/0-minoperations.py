#!/usr/bin/python3
"""
Module for calculating minimum operations to get n H characters.

This module uses prime factorization to find the optimal solution
for the minimum operations problem with Copy All and Paste operations.
"""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to result in exactly
    n H characters in the file.

    The algorithm uses prime factorization: for each prime factor p,
    we need exactly p operations to multiply the current count by p.

    Args:
        n (int): The target number of H characters

    Returns:
        int: The minimum number of operations needed, or 0 if impossible

    Example:
        >>> minOperations(9)
        6
        >>> minOperations(4)
        4
    """
    if n <= 1:
        return 0
    operations = 0
    factor = 2
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1
    if n > 1:
        operations += n
    return operations