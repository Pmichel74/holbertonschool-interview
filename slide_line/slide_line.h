#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

/* Direction pour glisser vers la gauche */
#define SLIDE_LEFT  0
/* Direction pour glisser vers la droite */
#define SLIDE_RIGHT 1

/**
 * slide_line - Glisse et fusionne un tableau d'entiers
 * @line: Pointeur vers le tableau d'entiers
 * @size: Nombre d'éléments dans le tableau
 * @direction: Direction de glissement (SLIDE_LEFT ou SLIDE_RIGHT)
 *
 * Return: 1 en cas de succès, ou 0 en cas d'échec
 */
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
