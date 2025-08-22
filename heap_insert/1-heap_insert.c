/*
 * File: 1-heap_insert.c
 * Description: Max heap insertion implementation
 */

#include <stdlib.h>
#include "binary_trees.h"

int node_count(const heap_t *tree);
heap_t *ins_max_heap(heap_t *node, heap_t *new_node, int index,
		      int new_node_index);
heap_t *bottom_up_heapify(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int size;
	heap_t *new_node = NULL;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	size = node_count(*root) + 1;
	*root = ins_max_heap(*root, new_node, 0, size - 1);

	return (bottom_up_heapify(new_node));
}

/**
 * node_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count
 * Return: The number of nodes in the tree
 */
int node_count(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * ins_max_heap - Places a new node at the correct position in a max heap
 * @node: Pointer to the root node of the heap
 * @new_node: New node to place in the heap
 * @index: Index of the current node
 * @new_node_index: Index where the new node should be placed
 * Return: Pointer to the updated root node, or NULL on failure
 */
heap_t *ins_max_heap(heap_t *node, heap_t *new_node,
		      int index, int new_node_index)
{
	if (index > new_node_index)
		return (NULL);

	if (index == new_node_index)
		return (new_node);

	node->left = ins_max_heap(node->left, new_node,
				  index * 2 + 1, new_node_index);
	if (node->left)
		node->left->parent = node;

	node->right = ins_max_heap(node->right, new_node,
				   index * 2 + 2, new_node_index);
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * bottom_up_heapify - Reorganizes a max binary heap from bottom to top
 * @node: Pointer to the node to heapify from
 * Return: Pointer to the root of the heap
 */
heap_t *bottom_up_heapify(heap_t *node)
{
	heap_t *temp = node;
	int temp_n;

	while (temp->parent && temp->n > temp->parent->n)
	{
		temp_n = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = temp_n;
		temp = temp->parent;
	}

	return (temp);
}