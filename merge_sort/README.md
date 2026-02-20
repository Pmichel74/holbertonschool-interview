# Merge Sort (Top-Down)

Write a top-down (recursive) Merge Sort implementation to sort an array of
integers in ascending order.

Requirements and constraints:
- Implement the top-down merge sort algorithm.
- When splitting, the left subarray size must be less than or equal to the
  right subarray size (e.g. {1,2,3,4,5} -> {1,2}, {3,4,5}).
- Sort the left subarray before the right subarray.
- `printf` is allowed.
- You may call `malloc` and `free` only once (one temporary array allocated
  for merging is acceptable).

Prototype:

- `void merge_sort(int *array, size_t size);`

Compile and run the provided main to see the merging steps and final result:

```sh
cd holbertonschool-interview/merge_sort
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge_test && ./merge_test
```
