# Advanced Binary Search

## Description

This project implements an advanced binary search algorithm that returns the **first occurrence** of a value in a sorted array, even when the value appears multiple times. Unlike standard binary search which may return any occurrence, this implementation guarantees finding the leftmost (first) index.

## How it Works

The algorithm uses **recursive binary search** with a key modification:

1. **Standard binary search logic**: Divides the search space in half at each step
2. **First occurrence guarantee**: When the target value is found, the algorithm checks if there are earlier occurrences to the left
3. **Continue searching left**: If the found element is not the first occurrence, recursively search the left subarray
4. **Visual debugging**: Prints each subarray being searched for visualization

### Time Complexity

- **Best case**: O(1) - Value found immediately and is the first occurrence
- **Average case**: O(log n)
- **Worst case**: O(log n)

The algorithm maintains logarithmic complexity while ensuring the first occurrence is returned.

## Files

- `0-advanced_binary.c`: Implementation of the advanced binary search
- `search_algos.h`: Header file with function prototypes
- `0-main.c`: Test program demonstrating the algorithm

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o advanced_binary
```

## Usage

```bash
./advanced_binary
```

## Example Output

```
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

Note how when searching for `5` (which appears at indices 3 and 4), the algorithm correctly returns index **3** (the first occurrence).

## Main Functions

### `int advanced_binary(int *array, size_t size, int value)`
Main function that initiates the search.
- **array**: Pointer to the first element of the sorted array
- **size**: Number of elements in the array
- **value**: Value to search for
- **Returns**: Index of the first occurrence, or -1 if not found

### `int advanced_binary_helper(int *array, size_t left, size_t right, int value)`
Recursive helper function that performs the actual search.
- Uses binary search with modification to find the first occurrence
- Prints each subarray being searched

### `void print_array(int *array, size_t left, size_t right)`
Utility function to display the current subarray being searched.
- Only loop in the entire program (as per requirements)

## Key Features

- **First occurrence guarantee**: Always returns the leftmost index when duplicates exist
- **Recursive implementation**: Uses recursion as required
- **Single loop constraint**: Only one loop used (for printing)
- **Visual feedback**: Displays each search step for educational purposes
- **Edge case handling**: Properly handles NULL arrays and missing values

## Algorithm Logic

The critical logic (lines 45-52 in [0-advanced_binary.c](advanced_binary_search/0-advanced_binary.c#L45-L52)):

```c
if (array[mid] == value)
{
    /* Check if this is the first occurrence */
    if (mid == left || array[mid - 1] != value)
        return ((int)mid);

    /* Otherwise, continue searching left */
    return (advanced_binary_helper(array, left, mid, value));
}
```

This ensures that even when we find the value, we continue searching left if there are earlier occurrences.

## Author

Project completed as part of Holberton School
