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
    for (i = 0, j = 0; i < size; i++) /* i parcourt, j indique où placer */
    {
        if (line[i] != 0) /* Si c'est un nombre (pas zéro) */
        {
            line[j] = line[i]; /* Place le nombre à la position j */
            if (i != j) /* Si on a déplacé le nombre */
                line[i] = 0; /* Efface l'ancienne position */
            j++; /* Prochaine position disponible */
        }
    }
    /* Étape 2 : Fusionne les valeurs identiques adjacentes */
    for (i = 0; i < size - 1; i++) /* Parcourt jusqu'à l'avant-dernier */
    {
        if (line[i] != 0 && line[i] == line[i + 1]) /* Si deux voisins identiques */
        {
            line[i] *= 2; /* Double la valeur du premier */
            line[i + 1] = 0; /* Efface le second */
        }
    }
    /* Étape 3 : Re-glisse pour supprimer les zéros créés par la fusion */
    for (i = 0, j = 0; i < size; i++) /* Même logique qu'à l'étape 1 */
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
    size_t i, j, k;
    /* Étape 1 : Glisse tous les éléments non-zéro vers la droite */
    for (i = size - 1, j = size - 1; i < size; i--) /* i parcourt de droite à gauche */
    {
        if (line[i] != 0) /* Si c'est un nombre (pas zéro) */
        {
            line[j] = line[i]; /* Place le nombre à la position j */
            if (i != j) /* Si on a déplacé le nombre */
                line[i] = 0; /* Efface l'ancienne position */
            j--; /* Prochaine position disponible (vers la gauche) */
        }
    }
    /* Étape 2 : Fusionne les valeurs identiques adjacentes (de droite à gauche) */
    for (i = size - 1; i > 0; i--) /* Parcourt de la fin vers le début */
    {
        if (line[i] != 0 && line[i] == line[i - 1]) /* Si deux voisins identiques */
        {
            line[i] *= 2; /* Double la valeur à droite */
            line[i - 1] = 0; /* Efface celui de gauche */
        }
    }
    /* Étape 3 : Re-glisse pour supprimer les zéros créés par la fusion */
    for (i = size - 1, j = size - 1; i < size; i--) /* Même logique qu'à l'étape 1 */
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
    for (k = 0; k <= j && k < size; k++)
        line[k] = 0;
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
    if (line == NULL || size == 0) /* Vérifie les paramètres invalides */
        return (0); /* Échec : paramètres invalides */
    if (direction == SLIDE_LEFT) /* Si direction vers la gauche */
    {
        slide_left(line, size); /* Glisse vers la gauche */
        return (1); /* Succès */
    }
    else if (direction == SLIDE_RIGHT) /* Si direction vers la droite */
    {
        slide_right(line, size); /* Glisse vers la droite */
        return (1); /* Succès */
    }
    return (0); /* Échec : direction invalide */
}
