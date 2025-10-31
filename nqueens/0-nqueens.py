#!/usr/bin/python3
"""
N Queens Problem Solver
Solves the N queens puzzle using backtracking algorithm
Optimized version combining efficiency and clarity
"""
import sys


def is_safe(board, row, col):
    """
    Check if it's safe to place a queen at position (row, col)

    Args:
        board: List of queen positions [[row, col], ...]
        row: Current row to check
        col: Current column to place queen

    Returns:
        True if safe to place queen, False otherwise
    """
    # Check if any previously placed queen attacks this position
    for queen in board:
        # Same column
        if queen[1] == col:
            return False

        # Both diagonals checked with one elegant condition
        # Diagonal \: row difference = col difference
        # Diagonal /: row difference = col difference (but opposite signs)
        if abs(queen[0] - row) == abs(queen[1] - col):
            return False

    return True


def solve_nqueens(n, row, board, solutions):
    """
    Recursively solve N Queens using backtracking

    Args:
        n: Size of the board (N x N)
        row: Current row to place queen
        board: Current board state (list of queen positions)
        solutions: List to store all solutions
    """
    # Base case: all queens placed successfully
    if row == n:
        # Make a copy of the solution to avoid reference issues
        solutions.append(board[:])
        return

    # Try placing queen in each column of current row
    for col in range(n):
        if is_safe(board, row, col):
            # Place queen
            board.append([row, col])

            # Recurse to next row
            solve_nqueens(n, row + 1, board, solutions)

            # Backtrack: remove queen to try next position
            board.pop()


def print_solutions(solutions):
    """
    Print all found solutions

    Args:
        solutions: List of all solutions
    """
    for solution in solutions:
        print(solution)


def main():
    """
    Main function: validate input and launch solver
    """
    # Check number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Validate N is an integer
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Validate N is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialize and solve
    solutions = []
    solve_nqueens(n, 0, [], solutions)

    # Display results
    print_solutions(solutions)


if __name__ == "__main__":
    main()
