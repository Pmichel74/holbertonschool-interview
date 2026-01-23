# Rotate 2D Matrix

## Description

This project contains a Python function that rotates an n x n 2D matrix 90 degrees clockwise in-place.

## Requirements

- Python 3.x
- The matrix must be a square (n x n)
- The matrix will not be empty
- The rotation is performed in-place (no return value)

## Algorithm

The rotation is achieved using a two-step approach:

1. **Transpose the matrix**: Swap elements across the main diagonal (swap `matrix[i][j]` with `matrix[j][i]`)
2. **Reverse each row**: Reverse the elements in each row

### Example

**Original Matrix:**
```
1 2 3
4 5 6
7 8 9
```

**After Transpose:**
```
1 4 7
2 5 8
3 6 9
```

**After Reversing Each Row (Final Result):**
```
7 4 1
8 5 2
9 6 3
```

## Time and Space Complexity

- **Time Complexity**: O(n²) - We visit each element once during transpose and once during row reversal
- **Space Complexity**: O(1) - The rotation is performed in-place with no additional data structures

## Prototype

```python
def rotate_2d_matrix(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.
    
    Args:
        matrix: n x n 2D matrix to rotate
    """
```

## Usage

```python
#!/usr/bin/python3
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

rotate_2d_matrix(matrix)
print(matrix)
```

**Output:**
```
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```

## Testing

Run the test file:
```bash
./main_0.py
```

## Files

- `0-rotate_2d_matrix.py` - Contains the rotate_2d_matrix function
- `main_0.py` - Test file

## Author

Holberton School Interview Preparation
