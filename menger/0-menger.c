#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_empty - Determines if a position should be empty
 * @row: Row position
 * @col: Column position
 *
 * Return: 1 if position should be empty, 0 otherwise
 */
int is_empty(int row, int col)
{
	/* Parcourt tous les niveaux de la fractale */
	while (row > 0 || col > 0)
	{
		/* Vérifie si la position est au centre d'une grille 3x3 */
		/* row % 3 == 1 : au centre horizontalement */
		/* col % 3 == 1 : au centre verticalement */
		if (row % 3 == 1 && col % 3 == 1)
			return (1); /* Centre trouvé → position vide */

		/* Monte au niveau supérieur en divisant par 3 */
		row /= 3; /* row = row / 3 (division entière) */
		col /= 3; /* col = col / 3 (division entière) */
	}
	/* Aucun centre trouvé à aucun niveau → position remplie */
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: Level of the Menger Sponge to draw
 *
 * Description: Draws a 2D Menger sponge of the specified level.
 *              If level is lower than 0, the function does nothing.
 */
void menger(int level)
{
	int size, row, col;

	/* Si le niveau est négatif, ne rien faire */
	if (level < 0)
		return;

	/* Calcule la taille de la grille : 3^level */
	/* Niveau 0: 3^0 = 1, Niveau 1: 3^1 = 3, Niveau 2: 3^2 = 9, etc. */
	size = pow(3, level);

	/* Parcourt chaque ligne de la grille (axe Y) */
	for (row = 0; row < size; row++)
	{
		/* Parcourt chaque colonne de la ligne actuelle (axe X) */
		for (col = 0; col < size; col++)
		{
			/* Vérifie si cette position doit être vide */
			if (is_empty(row, col))
				printf(" ");  /* Affiche un espace (trou) */
			else
				printf("#");  /* Affiche un dièse (matière) */
		}
		/* Passe à la ligne suivante après avoir parcouru toutes les colonnes */
		printf("\n");
	}
}
