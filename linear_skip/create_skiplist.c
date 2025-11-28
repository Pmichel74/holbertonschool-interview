#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * alloc_skiplist_nodes - Alloue les noeuds d'une skip list à partir d'un tableau
 * @array: tableau d'entiers
 * @size: taille du tableau
 *
 * Retourne un pointeur vers la tête de la liste, ou NULL en cas d'échec
 */
skiplist_t *alloc_skiplist_nodes(int *array, size_t size)
{
	skiplist_t *list = NULL;
	skiplist_t *node = NULL;

	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_skiplist(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->express = NULL;
		node->next = list;
		list = node;
	}
	return (list);
}
#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * init_express - Initializes the express lane of the linked list
 * @list: Pointer to the head node of the list
 * @size: Number of nodes in the list
 *
 * Description: Sets the express pointer every sqrt(size) nodes.
 * Allows faster search in the skip list.
 */
void init_express(skiplist_t *list, size_t size)
{
	const size_t step = sqrt(size);
	size_t i;
	skiplist_t *save;

	for (save = list, i = 0; i < size; ++i, list = list->next)
	{
		if (i % step == 0)
		{
			save->express = list;
			save = list;
		}
	}
}

/**
 * create_skiplist - Crée une skip list à partir d'un tableau d'entiers
 * @array: Pointeur vers le tableau d'entiers
 * @size: Taille du tableau
 *
 * Return: Pointeur vers la tête de la liste créée (NULL en cas d'échec)
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;

	list = alloc_skiplist_nodes(array, size);
	if (!list)
		return (NULL);
	init_express(list, size);
	return (list);
}
