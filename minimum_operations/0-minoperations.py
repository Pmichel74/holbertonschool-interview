#!/usr/bin/python3
# Shebang: indique au système d'utiliser Python 3 pour exécuter ce script
"""
Module qui calcule le nombre minimum d'opérations pour obtenir n caractères H.

Ce module contient une fonction qui résout le problème des opérations minimales
en utilisant uniquement deux opérations : "Copier Tout" et "Coller".
La solution utilise la décomposition en facteurs premiers.
"""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to result in exactly n H
    characters.

    Args:
        n (int): The target number of H characters.

    Returns:
        int: The minimum number of operations needed, or 0 if impossible.
    """
    # Cas de base: si n <= 1, impossible ou déjà atteint
    if n <= 1:
        return 0

    # Compteur du nombre total d'opérations
    operations = 0
    # Commencer par le plus petit nombre premier (2)
    divisor = 2

    # Continuer tant que n n'est pas réduit à 1
    while n > 1:
        # Tant que le diviseur actuel divise n exactement
        while n % divisor == 0:
            # Ajouter le diviseur au nombre d'opérations
            operations += divisor
            # Diviser n par le diviseur (division entière)
            n //= divisor
        # Passer au diviseur suivant
        divisor += 1

    # Retourner le nombre total d'opérations
    return operations
