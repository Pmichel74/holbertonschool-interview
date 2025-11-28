#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
N Queens Problem Solver
Resout le puzzle des N reines avec l'algorithme de backtracking
Version optimisee combinant efficacite et clarte
"""
import sys


def is_safe(board, row, col):
    """
    Verifie si on peut placer une reine a la position (row, col)

    Args:
        board: Liste des positions des reines [[row, col], ...]
        row: Ligne actuelle a verifier
        col: Colonne ou placer la reine

    Returns:
        True si la position est safe, False sinon
    """
    # Verifie si une reine deja placee attaque cette position
    for queen in board:
        # Meme colonne
        if queen[1] == col:
            return False

        # Les deux diagonales verifiees avec une seule condition elegante
        # Diagonale \: difference de lignes = difference de colonnes
        # Diagonale /: difference de lignes = difference de colonnes (signes opposes)
        if abs(queen[0] - row) == abs(queen[1] - col):
            return False

    return True


def solve_nqueens(n, row, board, solutions):
    """
    Resout le probleme des N reines en utilisant le backtracking recursif

    Args:
        n: Taille de l'echiquier (N x N)
        row: Ligne actuelle ou placer une reine
        board: Etat actuel de l'echiquier (liste des positions des reines)
        solutions: Liste pour stocker toutes les solutions
    """
    # Cas de base: toutes les reines ont ete placees avec succes
    if row == n:
        # Cree une copie de la solution pour eviter les problemes de reference
        solutions.append(board[:])
        return

    # Essaie de placer une reine dans chaque colonne de la ligne actuelle
    for col in range(n):
        if is_safe(board, row, col):
            # Place la reine
            board.append([row, col])

            # Recursion vers la ligne suivante
            solve_nqueens(n, row + 1, board, solutions)

            # Backtrack: retire la reine pour essayer la position suivante
            board.pop()


def print_solutions(solutions):
    """
    Affiche toutes les solutions trouvees

    Args:
        solutions: Liste de toutes les solutions
    """
    for solution in solutions:
        print(solution)


def main():
    """
    Fonction principale: valide l'entree et lance le solveur
    """
    # Verifie le nombre d'arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Valide que N est un entier
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Valide que N est au moins 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialise et resout
    solutions = []
    solve_nqueens(n, 0, [], solutions)

    # Affiche les resultats
    print_solutions(solutions)


if __name__ == "__main__":
    main()
