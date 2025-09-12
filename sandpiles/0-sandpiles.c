#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Affiche une grille 3x3 formatée
 * @grid: grille 3x3 à afficher
 *
 * Description: Affiche la grille avec des espaces entre les nombres
 * et un retour à la ligne après chaque rangée
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Vérifie si une grille de sable est stable
 * @grid: grille 3x3 à vérifier
 *
 * Description: Une grille est stable si toutes ses cellules
 * contiennent 3 grains ou moins. Si une cellule contient plus
 * de 3 grains, la grille est considérée comme instable.
 *
 * Return: 1 si stable (toutes cellules <= 3), 0 si instable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Effectue un cycle de redistribution sur une grille instable
 * @grid: grille 3x3 sur laquelle appliquer la redistribution
 *
 * Description: Pour chaque cellule contenant plus de 3 grains,
 * retire 4 grains de cette cellule et distribue 1 grain à chacun
 * des 4 voisins adjacents si valides. Les voisins en dehors de la
 * grille 3x3 sont ignorés. Utilise une grille temporaire pour traiter
 * toutes les cellules instables simultanément.
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = grid[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Calcule la somme de deux grilles de sable
 * @grid1: Première grille (le résultat sera stocké ici)
 * @grid2: Deuxième grille (reste inchangée)
 *
 * Description: Additionne grid2 à grid1 cellule par cellule, puis
 * stabilise grid1 en effectuant des cycles de redistribution.
 * Affiche grid1 avant chaque cycle de redistribution si instable.
 * Continue jusqu'à ce que grid1 soit complètement stable.
 * L'algorithme des sandpiles: Une grille est stable si toutes ses
 * cellules sont <= 3. Si une cellule > 3, elle s'effondre et distribue
 * ses grains. Le processus est déterministe et converge toujours.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
