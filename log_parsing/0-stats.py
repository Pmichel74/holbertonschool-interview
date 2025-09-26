#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""

import sys


def print_stats(total_size, status_codes):
    """
    Print computed statistics.

    Args:
        total_size: Total file size
        status_codes: Dictionary with counts of each status code
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0
    status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
    }

    try:
        for line in sys.stdin:
            line_count += 1

            # Parse the line
            try:
                parts = line.split()
                # Ensure we have at least 2 parts to extract status and file size
                if len(parts) < 2:
                    continue

                # Extract status code and file size
                status = parts[-2]
                file_size = parts[-1]

                # Update status code count if it's a valid code
                if status in status_codes:
                    status_codes[status] += 1

                # Update total file size
                total_size += int(file_size)
            except (IndexError, ValueError):
                # Skip lines with invalid format
                continue

            # Print stats every 10 lines
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Handle Ctrl+C
        print_stats(total_size, status_codes)
        raise

    # Final stats (if the number of lines is not a multiple of 10)
    print_stats(total_size, status_codes)
