#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_filled - Détermine si une position doit être remplie (#) ou vide (espace)
 * @x: Coordonnée x
 * @y: Coordonnée y
 * @level: Niveau actuel
 *
 * Return: 1 si la position doit être remplie, 0 sinon
 */
int is_filled(int x, int y, int level)
{
	while (level > 0)
	{
		int size = (int)pow(3, level - 1);

		if (x >= size && x < size * 2 && y >= size && y < size * 2)
			return (0);

		x %= size;
		y %= size;
		level--;
	}
	return (1);
}

/**
 * menger - Dessine un Menger Sponge 2D
 * @level: Niveau du Menger Sponge à dessiner
 *
 * Description: Dessine un Menger Sponge de niveau donné.
 *              Si level < 0, ne fait rien.
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_filled(x, y, level))
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
