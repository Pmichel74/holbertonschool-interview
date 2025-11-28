#!/usr/bin/python3
# Shebang pour indiquer que le script utilise Python 3
"""
UTF-8 Validation Module
"""
# Docstring du module pour décrire son objectif


def validUTF8(data):
    # Définition de la fonction qui valide l'encodage UTF-8
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: List of integers where each integer represents 1 byte

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    # Docstring de la fonction avec description, paramètres et retour

    # Compteur pour suivre le nombre d'octets restants à traiter
    # pour le caractère UTF-8 actuel
    nb_bytes_remaining = 0

    # Masque pour vérifier le 7ème bit (bit le plus significatif): 10000000
    mask_1 = 1 << 7  # 10000000
    # Masque pour vérifier le 6ème bit: 01000000
    mask_2 = 1 << 6  # 01000000

    # Parcourt chaque entier dans la liste de données
    for num in data:
        # Garde seulement les 8 bits les moins significatifs de l'entier
        byte = num & 0xFF

        # Si on n'attend pas d'octets de continuation
        if nb_bytes_remaining == 0:
            # On commence un nouveau caractère UTF-8

            # Initialise le masque pour compter les bits à 1 au début
            mask = 1 << 7
            # Compte combien de bits consécutifs sont à 1 au début de l'octet
            while mask & byte:
                # Incrémente le nombre d'octets pour ce caractère
                nb_bytes_remaining += 1
                # Décale le masque d'un bit vers la droite
                mask = mask >> 1

            # Si aucun bit à 1 au début (commence par 0)
            if nb_bytes_remaining == 0:
                # C'est un caractère ASCII sur 1 octet, passe au suivant
                continue

            # Un caractère UTF-8 ne peut pas avoir exactement 1 octet
            # qui commence par 10xxxxxx (octet de continuation)
            # ni avoir plus de 4 octets
            if nb_bytes_remaining == 1 or nb_bytes_remaining > 4:
                # Encodage invalide
                return False

            # Décrémente car on a déjà compté le premier octet
            nb_bytes_remaining -= 1
        else:
            # On traite un octet de continuation (doit commencer par 10xxxxxx)

            # Vérifie que le 7ème bit est à 1 ET le 6ème bit est à 0
            if not (byte & mask_1 and not (byte & mask_2)):
                # L'octet ne commence pas par 10, encodage invalide
                return False

            # Un octet de continuation a été traité, décrémente le compteur
            nb_bytes_remaining -= 1

    # Retourne True si tous les caractères sont complets (aucun octet manquant)
    return nb_bytes_remaining == 0
