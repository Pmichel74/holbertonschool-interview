#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_filled - Check if a position should be filled
 * @x: X coordinate
 * @y: Y coordinate
 * @level: Current level
 *
 * Return: 1 if position should be filled, 0 otherwise
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
 * menger - Draw a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 *
 * Description: Draws a Menger Sponge at the given level.
 *              Does nothing if level < 0.
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
