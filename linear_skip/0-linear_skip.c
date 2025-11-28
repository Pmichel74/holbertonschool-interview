#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Description: Uses the express lane to jump ahead, then performs
 * linear search in the identified range
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express_node, *prev_express;

	if (list == NULL)
		return (NULL);

	express_node = list;
	prev_express = list;

	/* Use express lane to find the range */
	while (express_node->express != NULL)
	{
		prev_express = express_node;
		express_node = express_node->express;
		printf("Value checked at index [%lu] = [%d]\n",
			express_node->index, express_node->n);

		if (express_node->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				prev_express->index, express_node->index);
			break;
		}
	}

	/* If we've reached the end of express lane, search from last express to end */
	if (express_node->express == NULL && express_node->n < value)
	{
		/* Find the actual last node */
		prev_express = express_node;
		while (express_node->next != NULL)
			express_node = express_node->next;

		printf("Value found between indexes [%lu] and [%lu]\n",
			prev_express->index, express_node->index);
	}


	/**
	 * linear_search_range - Effectue une recherche linéaire dans une plage de skip list
	 * @start: noeud de début
	 * @end: noeud de fin
	 * @value: valeur à chercher
	 *
	 * Return: pointeur vers le noeud trouvé ou NULL
	 */
	static skiplist_t *linear_search_range(skiplist_t *start, skiplist_t *end, int value)
	{
		while (start != NULL && start->index <= end->index)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				start->index, start->n);
			if (start->n == value)
				return (start);
			start = start->next;
		}
		return (NULL);
	}

	skiplist_t *linear_skip(skiplist_t *list, int value)
	{
		skiplist_t *express_node, *prev_express;

		if (list == NULL)
			return (NULL);

		express_node = list;
		prev_express = list;

		/* Use express lane to find the range */
		while (express_node->express != NULL)
		{
			prev_express = express_node;
			express_node = express_node->express;
			printf("Value checked at index [%lu] = [%d]\n",
				express_node->index, express_node->n);

			if (express_node->n >= value)
			{
				printf("Value found between indexes [%lu] and [%lu]\n",
					prev_express->index, express_node->index);
				break;
			}
		}

		/* If we've reached the end of express lane, search from last express to end */
		if (express_node->express == NULL && express_node->n < value)
		{
			/* Find the actual last node */
			prev_express = express_node;
			while (express_node->next != NULL)
				express_node = express_node->next;

			printf("Value found between indexes [%lu] and [%lu]\n",
				prev_express->index, express_node->index);
		}

		/* Linear search in the identified range */
		return linear_search_range(prev_express, express_node, value);
	}

	return (NULL);
}
