# Heap Sort Algorithm

## Description

This project implements the Heap Sort algorithm using the **sift-down** method. Heap Sort is an efficient comparison-based sorting algorithm that uses a binary heap data structure.

## How it Works

The algorithm operates in two main phases:

1. **Heap Construction (Heapify)**: Transforms the array into a max heap where each parent is greater than its children
2. **Extraction and Sorting**: Swaps the root (maximum element) with the last element of the heap, then reorganizes the remaining heap

### Time Complexity

- **Best case**: O(n log n)
- **Average case**: O(n log n)
- **Worst case**: O(n log n)

Heap Sort has constant complexity regardless of the initial data arrangement, making it a very predictable algorithm.

## Files

- `0-heap_sort.c`: Implementation of the heap sort algorithm
- `sort.h`: Header file with prototypes
- `print_array.c`: Utility function to display arrays
- `0-main.c`: Test program
- `0-O`: Big O notations of time complexities

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o heap_sort
```

## Usage

```bash
./heap_sort
```

## Example Output

```
Initial array:
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

After each swap:
19, 48, 99, 86, 13, 52, 96, 73, 71, 7
19, 86, 99, 48, 13, 52, 96, 73, 71, 7
...

Sorted array:
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Main Functions

### `void heap_sort(int *array, size_t size)`
Main function that sorts an array of integers in ascending order.

### `void sift_down(int *array, size_t size, size_t root, size_t heap_size)`
Reorganizes the heap by moving an element down until the heap property is restored.

### `void swap(int *array, size_t size, size_t i, size_t j)`
Swaps two elements in the array and prints the array state after the swap.

## Features

- In-place sorting: uses constant memory space O(1)
- Displays the array after each swap to visualize the sorting process
- Recursive implementation of the sift-down function
- Handles edge cases (empty arrays or size 1)

## Author

Project completed as part of Holberton School
