# N Queens Problem

## Description

The N Queens puzzle is a classic backtracking problem: place N chess queens on an N×N chessboard so that no two queens attack each other.

A queen can attack horizontally, vertically, and diagonally.

## Requirements

- Python 3.x
- Only the `sys` module is imported

## Usage

```bash
./0-nqueens.py N
```

Where `N` is an integer ≥ 4 representing the size of the chessboard.

## Examples

```bash
$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]

$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

Each solution is a list of `[row, column]` positions where queens are placed.

## Error Handling

```bash
$ ./0-nqueens.py
Usage: nqueens N

$ ./0-nqueens.py abc
N must be a number

$ ./0-nqueens.py 3
N must be at least 4
```

## Algorithm

The solution uses **backtracking**:

1. Place queens row by row
2. For each row, try all columns
3. Check if position is safe (no conflicts with previous queens)
4. If safe, place queen and recurse to next row
5. If stuck, backtrack and try next position

### Safety Checks

A position is safe if no previous queen:
- Is in the same **column**: `queen[1] == col`
- Is on the same **diagonal**: `abs(queen[0] - row) == abs(queen[1] - col)`

## Files

- `0-nqueens.py` - Main program solving the N Queens problem

## Author

Holberton School Interview Preparation
