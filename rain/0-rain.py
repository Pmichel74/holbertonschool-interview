#!/usr/bin/python3
"""
Module to calculate trapped rainwater
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains

    Given a list of non-negative integers representing the heights of walls
    with unit width 1, calculate how many square units of water will be
    retained after it rains.

    Args:
        walls (list): List of non-negative integers representing wall heights

    Returns:
        int: Total amount of rainwater retained

    Example:
        >>> rain([0, 1, 0, 2, 0, 3, 0, 4])
        6
        >>> rain([2, 0, 0, 4, 0, 0, 1, 0])
        6
    """
    # Handle edge cases
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    total_water = 0

    # Create arrays to store maximum heights
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array
    # left_max[i] contains the maximum height from index 0 to i
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array
    # right_max[i] contains the maximum height from index i to n-1
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water trapped at each position
    for i in range(n):
        # Water level at position i is determined by the minimum of
        # the maximum heights on both sides
        water_level = min(left_max[i], right_max[i])
        # Water trapped = water level - current wall height
        water_trapped = water_level - walls[i]
        # Add to total (only if positive)
        if water_trapped > 0:
            total_water += water_trapped

    return total_water
