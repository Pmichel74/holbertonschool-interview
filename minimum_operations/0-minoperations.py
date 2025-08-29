#!/usr/bin/python3
"""
Module pour calculer le nombre minimum d'opérations pour obtenir n caractères H.

Ce module utilise la factorisation en nombres premiers pour trouver la solution
optimale au problème du nombre minimum d'opérations avec les opérations 
Copier Tout et Coller.
"""


def minOperations(n):
    """
    Calcule le nombre minimum d'opérations nécessaires pour obtenir exactement
    n caractères H dans le fichier.

    L'algorithme utilise la factorisation en nombres premiers : pour chaque 
    facteur premier p, nous avons besoin d'exactement p opérations pour 
    multiplier le nombre actuel par p.

    Args:
        n (int): Le nombre cible de caractères H

    Returns:
        int: Le nombre minimum d'opérations nécessaires, ou 0 si impossible

    Example:
        >>> minOperations(9)
        6
        >>> minOperations(4)
        4
    """
    # Cas de base : si n <= 1, impossible ou déjà atteint
    if n <= 1:
        return 0
    
    # Compteur du nombre total d'opérations
    operations = 0
    # Commencer par le plus petit nombre premier (2)
    factor = 2
    
    # Continuer tant que factor² <= n (optimisation racine carrée)
    while factor * factor <= n:
        # Tant que le facteur actuel divise n exactement
        while n % factor == 0:
            # Ajouter le facteur au nombre d'opérations
            operations += factor
            # Diviser n par le facteur (division entière)
            n //= factor
        # Passer au facteur suivant
        factor += 1
    
    # Si n > 1 après la boucle, alors n est un nombre premier restant
    if n > 1:
        # Ajouter ce dernier facteur premier aux opérations
        operations += n
    
    # Retourner le nombre total d'opérations
    return operations
