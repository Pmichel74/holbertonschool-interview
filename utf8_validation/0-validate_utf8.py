#!/usr/bin/python3
"""
UTF-8 Validation Module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: List of integers where each integer represents 1 byte

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    # Number of bytes remaining in the current UTF-8 character
    nb_bytes_remaining = 0

    # Masks to check the most significant bits
    mask_1 = 1 << 7  # 10000000
    mask_2 = 1 << 6  # 01000000

    for num in data:
        # Keep only the 8 least significant bits
        byte = num & 0xFF

        if nb_bytes_remaining == 0:
            # Determine the number of bytes in this UTF-8 character
            mask = 1 << 7
            while mask & byte:
                nb_bytes_remaining += 1
                mask = mask >> 1

            # If it's a 1-byte character (starts with 0)
            if nb_bytes_remaining == 0:
                continue

            # A UTF-8 character cannot have more than 4 bytes
            # nor have exactly 1 bit set to 1 (which would be 10xxxxxx,
            # a continuation byte)
            if nb_bytes_remaining == 1 or nb_bytes_remaining > 4:
                return False

            # Decrement because we count the current byte
            nb_bytes_remaining -= 1
        else:
            # Check that the byte starts with 10xxxxxx
            if not (byte & mask_1 and not (byte & mask_2)):
                return False

            nb_bytes_remaining -= 1

    # All characters must be complete
    return nb_bytes_remaining == 0
    