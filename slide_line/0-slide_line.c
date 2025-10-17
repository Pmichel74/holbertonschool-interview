#include "slide_line.h"
/**
 * slide_left - Glisse et fusionne le tableau vers la gauche
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans le tableau
 */
static void slide_left(int *line, size_t size)
{
    size_t i, j, k;
    /* Étape 1 : Glisse tous les éléments non-zéro vers la gauche */
    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            if (i != j)
                line[i] = 0;
            j++;
        }
    }
    /* Étape 2 : Fusionne les valeurs identiques adjacentes */
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }
    /* Étape 3 : Re-glisse pour supprimer les zéros créés par la fusion */
    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            if (i != j)
                line[i] = 0;
            j++;
        }
    }
    /* Étape 4 : Remplit les positions restantes avec des zéros */
    for (k = j; k < size; k++)
        line[k] = 0;
}
/**
 * slide_right - Glisse et fusionne le tableau vers la droite
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans le tableau
 */
static void slide_right(int *line, size_t size)
{
    size_t i, j, write_pos;
    /* Étape 1 : Glisse tous les éléments non-zéro vers la droite */
    for (i = size - 1, j = size - 1; i < size; i--)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            if (i != j)
                line[i] = 0;
            j--;
        }
    }
    /* Étape 2 : Fusionne les valeurs identiques adjacentes (de droite à gauche) */
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] != 0 && line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }
    /* Étape 3 : Re-glisse pour supprimer les zéros créés par la fusion */
    for (i = size - 1, j = size - 1; i < size; i--)
    {
        if (line[i] != 0)
        {
            line[j] = line[i];
            if (i != j)
                line[i] = 0;
            j--;
        }
    }
    /* Étape 4 : Remplit les positions restantes à gauche avec des zéros */
    write_pos = (j >= size) ? 0 : j + 1;
    for (i = 0; i < write_pos; i++)
        line[i] = 0;
}
/**
 * slide_line - Glisse et fusionne un tableau d'entiers
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans le tableau
 * @direction: Direction de glissement (SLIDE_LEFT ou SLIDE_RIGHT)
 *
 * Return: 1 en cas de succès, 0 en cas d'échec
 */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || size == 0)
        return (0);
    if (direction == SLIDE_LEFT)
    {
        slide_left(line, size);
        return (1);
    }
    else if (direction == SLIDE_RIGHT)
    {
        slide_right(line, size);
        return (1);
    }
    return (0);
}
