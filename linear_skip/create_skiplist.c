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
 * create_skiplist - Creates a single linked list (skip list)
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 *
 * Description: Allocates nodes for each array element, links them,
 * and initializes the express lanes for fast traversal.
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list = NULL;
	skiplist_t *node = NULL;
	size_t save_size = size;

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
	init_express(list, save_size);
	return (list);
}
