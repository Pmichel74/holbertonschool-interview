#!/usr/bin/python3
"""Module that checks if all boxes can be opened."""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened using available keys

    Args:
        boxes (list): List of lists where boxes[i] contains keys for
                     other boxes

    Returns:
        bool: True if all boxes can be opened, False otherwise
    """
    opened = [False] * len(boxes)
    opened[0] = True
    keys = [0]

    while keys:
        current = keys.pop(0)

        for key in boxes[current]:
            if 0 <= key < len(boxes) and not opened[key]:
                opened[key] = True
                keys.append(key)

    return all(opened)
