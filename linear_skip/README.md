PATRICK
pat74200
En ligne



PATRICK
 vient juste d'arriver ! — 31/10/2025 12:10

Fais coucou !
PATRICK — 31/10/2025 12:10
Benjamin Ristord — 31/10/2025 12:10
Contents de te voir, 
enzo
. — 31/10/2025 12:16

Fais coucou !
Benjamin Ristord — 31/10/2025 12:16
Benjamin Ristord — 31/10/2025 12:43
#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
Afficher plus
0-main.c
1 Ko
#include "menger.h"

/**
 * is_empty - Determines if a position should be empty in Menger sponge
 * @row: Row position
 * @col: Column position
Afficher plus
0-menger.c
1 Ko
#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <math.h>
Afficher plus
menger.h
1 Ko
# Éponge de Menger (Menger Sponge)

Ce projet implémente une fonction qui dessine une éponge de Menger en 2D à un niveau spécifié.

## Description
Afficher plus
README.md
7 Ko
Benjamin Ristord — 31/10/2025 13:23
#!/usr/bin/python3
"""
N Queens Problem Solver
Solves the N queens puzzle using backtracking algorithm
"""
import sys
Afficher plus
0-nqueens.py
3 Ko
# Le Problème des N Reines (N Queens)

Ce projet implémente une solution au célèbre problème des N reines en utilisant l'algorithme de backtracking.

## Description
Afficher plus
README.md
10 Ko
enzo — 14/11/2025 11:59
#include "binary_trees.h"

/
 
build_avl_helper - Helper function to recursively build AVL tree
@array: Pointer to the sorted array
@start: Start index of the current subarray
@end: End index of the current subarray
@parent: Pointer to the parent node*
Return: Pointer to the created node, or NULL on failure*/
avl_t build_avl_helper(intarray, int start, int end, avl_t parent)
{
    avl_tnode;
    int mid;

    if (start > end)
        return (NULL);

    mid = start + (end - start) / 2;

    node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);

    node->n = array[mid];
    node->parent = parent;
    node->left = build_avl_helper(array, start, mid - 1, node);
    node->right = build_avl_helper(array, mid + 1, end, node);

    return (node);
}

/
 
sorted_array_to_avl - Builds an AVL tree from a sorted array
@array: Pointer to the first element of the array to be converted
@size: Number of elements in the array*
Return: Pointer to the root node of the created AVL tree, or NULL on failure*/
avl_t sorted_array_to_avl(intarray, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl_helper(array, 0, (int)size - 1, NULL));
}
PATRICK — 14/11/2025 12:00
#include <stdlib.h>
#include "binary_trees.h"

/**
 
sorted_array_to_avl - Builds an AVL tree from a sorted array
@array: Pointer to the first element of the array to be converted
@size: Number of elements in the array*
Return: Pointer to the root node of the created AVL tree, or NULL on failure*/
avl_t sorted_array_to_avl(intarray, size_t size)
{
    avl_t root;
    int middle;

    if (size == 0)
        return (NULL);

    / Allocate memory for new node /
    root = malloc(sizeof(avl_t));

    if (root == NULL)
        return (NULL);

    / Find middle element of the array /
    middle = size / 2;

    / Create root node */
    root->n = array[middle];
    root->left = sorted_array_to_avl(array, middle);
    root->right = sorted_array_to_avl(array + middle + 1, size - middle - 1);
    root->parent = NULL;

    if (root->left != NULL)
        root->left->parent = root;
    if (root->right != NULL)
        root->right->parent = root;

    return (root);
}
#include <stdlib.h>
#include "binary_trees.h"

/**
 
sorted_array_to_avl - Builds an AVL tree from a sorted array
@array: Pointer to the first element of the array to be converted
@size: Number of elements in the array*
Return: Pointer to the root node of the created AVL tree, or NULL on failure*/
avl_t sorted_array_to_avl(intarray, size_t size)
{
    avl_t root;
    int middle;

    if (size == 0)
        return (NULL);

    / Allocate memory for new node /
    root = malloc(sizeof(avl_t));

    if (root == NULL)
        return (NULL);

    / Find middle element of the array /
    middle = (size - 1) / 2;

    / Create root node */
    root->n = array[middle];
    root->left = sorted_array_to_avl(array, middle);
    root->right = sorted_array_to_avl(array + middle + 1, size - middle - 1);
    root->parent = NULL;

    if (root->left != NULL)
        root->left->parent = root;
    if (root->right != NULL)
        root->right->parent = root;

    return (root);
}
Benjamin Ristord — 14/11/2025 12:08
#include "binary_trees.h"

/
 
create_node - Creates a new AVL tree node
@parent: Pointer to the parent node
@value: Value to store in the node*
Return: Pointer to the new node, or NULL on failure*/
avl_t create_node(avl_tparent, int value)
{
    avl_t *new_node;

    new_node = malloc(sizeof(avl_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/
 
build_avl - Recursively builds an AVL tree from a sorted array
@array: Pointer to the first element of the array
@start: Starting index of the current subarray
@end: Ending index of the current subarray
@parent: Pointer to the parent node*
Return: Pointer to the root node of the subtree, or NULL on failure*/
avl_t build_avl(intarray, int start, int end, avl_t parent)
{
    avl_tnode;
    int mid;

    if (start > end)
        return (NULL);

    mid = start + (end - start) / 2;

    node = create_node(parent, array[mid]);
    if (!node)
        return (NULL);

    node->left = build_avl(array, start, mid - 1, node);
    node->right = build_avl(array, mid + 1, end, node);

    return (node);
}

/**
 
sorted_array_to_avl - Builds an AVL tree from a sorted array
@array: Pointer to the first element of the array to be converted
@size: Number of elements in the array*
Return: Pointer to the root node of the created AVL tree, or NULL on failure*/
avl_t sorted_array_to_avl(intarray, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl(array, 0, size - 1, NULL));
}
PATRICK — 14/11/2025 20:56
https://www.facebook.com/share/p/1CUB26G6dM/
Log in or sign up to view
See posts, photos and more on Facebook.
Image
PATRICK — Hier à 17:57
https://www.facebook.com/share/r/167WMEgNmm/?mibextid=wwXIfr
Log in or sign up to view
See posts, photos and more on Facebook.
Benjamin Ristord — Hier à 17:59
poulet vapeur ca va pas nan
Benjamin Ristord — 11:58
#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);
skiplist_t *linear_skip(skiplist_t *head, int value);

#endif /* _SEARCH_H_ */
Réduire
search.h
1 Ko
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
Afficher plus
0-linear_skip.c
2 Ko
#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
Afficher plus
0-main.c
1 Ko
#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * init_express - Initializes the express lane of the linked list
 *
 * @list: Pointer to the head node of the list
 * @size: Number of nodes in the list
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
 * create_skiplist - Create a single linked list
 *
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;
	skiplist_t *node;
	size_t save_size;

	list = NULL;
	save_size = size;
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
Réduire
create_skiplist.c
2 Ko
#include <stdlib.h>
#include "search.h"

/**
 * free_skiplist - Deallocates a singly linked list
 *
Afficher plus
free_skiplist.c
1 Ko
#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * print_skiplist - dump the content of a skiplist_t
 *
 * @list: Pointer to the head of the list
 *
 * Return: void
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *node;

	printf("List :\n");
	for (node = list; node; node = node->next)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	}
	printf("\nExpress lane :\n");
	for (node = list; node; node = node->express)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	}
	printf("\n");
}
Réduire
print_skiplist.c
1 Ko
# Linear Skip - Recherche dans une Skip List

## Description

Ce projet implémente un algorithme de recherche optimisé dans une **skip list** (liste chaînée avec voie express). Une skip list est une structure de données qui améliore les performances de recherche dans une liste chaînée en ajoutant une "voie express" permettant de sauter plusieurs éléments à la fois.
Afficher plus
README.md
4 Ko
Benjamin Ristord — 12:25
#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
Afficher plus
0-starwars_characters.js
2 Ko
# API Star Wars

## Description

Ce projet contient un script qui affiche tous les personnages d'un film Star Wars en utilisant l'API Star Wars (SWAPI).
Afficher plus
README.md
3 Ko
PATRICK — 12:27
J’arrive pour venir vous corriger les algo !
Benjamin Ristord — 12:27
﻿
# Linear Skip - Recherche dans une Skip List

## Description

Ce projet implémente un algorithme de recherche optimisé dans une **skip list** (liste chaînée avec voie express). Une skip list est une structure de données qui améliore les performances de recherche dans une liste chaînée en ajoutant une "voie express" permettant de sauter plusieurs éléments à la fois.

## Concept

Une skip list possède deux niveaux de pointeurs :
- **next** : pointe vers l'élément suivant (liste normale)
- **express** : pointe vers un élément plus loin dans la liste (voie express)

Dans ce projet, un nœud de la voie express est placé à chaque indice qui est un multiple de la racine carrée de la taille de la liste.

### Exemple avec 16 éléments (√16 = 4)
```
Liste normale : 0 → 1 → 2 → 3 → 4 → 7 → 12 → 15 → 18 → 19 → 23 → 53 → 61 → 62 → 76 → 99
Voie express  : 0 ⇒⇒⇒⇒⇒⇒⇒⇒⇒ 4 ⇒⇒⇒⇒⇒⇒⇒⇒⇒ 8 ⇒⇒⇒⇒⇒⇒⇒⇒⇒ 12
```

## Algorithme

L'algorithme `linear_skip` fonctionne en deux étapes :

1. **Parcours de la voie express** : Sauter rapidement à travers la liste en utilisant les pointeurs `express` jusqu'à trouver un nœud dont la valeur est supérieure ou égale à la valeur recherchée.

2. **Recherche linéaire** : Une fois la plage identifiée, effectuer une recherche linéaire classique entre le nœud précédent et le nœud actuel de la voie express.

## Structure de données

```c
typedef struct skiplist_s
{
    int n;                      /* Valeur stockée */
    size_t index;               /* Index dans la liste */
    struct skiplist_s *next;    /* Pointeur vers le prochain nœud */
    struct skiplist_s *express; /* Pointeur vers le prochain nœud express */
} skiplist_t;
```

## Fichiers

- **search.h** : Fichier d'en-tête contenant la structure et les prototypes
- **0-linear_skip.c** : Implémentation de la fonction de recherche
- **0-main.c** : Fichier de test principal
- **create_skiplist.c** : Fonction auxiliaire pour créer une skip list
- **print_skiplist.c** : Fonction auxiliaire pour afficher une skip list
- **free_skiplist.c** : Fonction auxiliaire pour libérer la mémoire

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c create_skiplist.c print_skiplist.c free_skiplist.c -lm -o 0-linear_skip
```

## Utilisation

```bash
./0-linear_skip
```

## Exemple de sortie

```
List :
Index[0] = [0]
Index[1] = [1]
...
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11
```

## Complexité

- **Meilleur cas** : O(1) - la valeur est au premier nœud
- **Cas moyen** : O(√n) - grâce à la voie express
- **Pire cas** : O(n) - la valeur est à la fin ou n'existe pas

Sans la voie express, une liste chaînée classique aurait une complexité de O(n) dans tous les cas.

## Auteur

Projet Holberton School - Interview Preparation

## Exigences

- Éditeurs autorisés : `vi`, `vim`, `emacs`
- Compilation sur Ubuntu 14.04 LTS
- Compilateur : `gcc 4.8.4`
- Flags de compilation : `-Wall -Werror -Wextra -pedantic`
- Style de code : Betty
- Maximum 5 fonctions par fichier
- Tous les fichiers doivent se terminer par une nouvelle ligne
- Tous les fichiers d'en-tête doivent avoir des gardes d'inclusion
