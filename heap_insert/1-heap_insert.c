/*
 * ALGORITHME D'INSERTION DANS UN MAX HEAP
 * =======================================
 * 
 * Un Max Heap est un arbre binaire complet où :
 * - Chaque parent ≥ ses enfants (propriété du heap)
 * - Tous les niveaux sont remplis sauf le dernier (structure complète)
 * 
 * STRATÉGIE D'INSERTION EN 3 ÉTAPES :
 * 1. CRÉER le nouveau nœud
 * 2. PLACER à la prochaine position libre (maintient structure complète)
 * 3. REMONTER si nécessaire (maintient propriété max heap)
 * 
 * INDEXATION : Pour un nœud à l'index i
 * - Parent : (i-1)/2
 * - Enfant gauche : 2*i+1  
 * - Enfant droit : 2*i+2
 * 
 * COMPLEXITÉ : O(n) pour node_count + O(log n) pour insertion = O(n)
 */

#include <stdlib.h>
#include "binary_trees.h"

int node_count(const heap_t *tree);
heap_t *ins_max_heap(heap_t *node, heap_t *new_node, int index,
		      int new_node_index);
heap_t *bottom_up_heapify(heap_t *node);

/**
 * heap_insert - Insère une valeur dans un tas maximum (max heap)
 * @root: Double pointeur vers le nœud racine du tas où insérer la valeur
 * @value: Valeur à stocker dans le nœud à insérer
 * Return: Pointeur vers le nœud créé, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int size;
	heap_t *new_node = NULL;

	/* ÉTAPE 1: Vérification de sécurité */
	if (!root)
		return (NULL);

	/* ÉTAPE 2: Création du nouveau nœud avec parent temporaire NULL */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL); /* Échec d'allocation mémoire */

	/* ÉTAPE 3: Calcul de la taille totale après insertion */
	/* La taille détermine l'index exact où placer le nouveau nœud */
	size = node_count(*root) + 1;

	/* ÉTAPE 4: Placement du nœud à la bonne position (structure complète) */
	/* ins_max_heap navigue récursivement pour trouver l'index (size-1) */
	*root = ins_max_heap(*root, new_node, 0, size - 1);

	/* ÉTAPE 5: Remontée du nœud pour respecter la propriété max heap */
	/* bottom_up_heapify fait remonter le nœud si valeur > parent */
	return (bottom_up_heapify(new_node));
}

/**
 * node_count - Compte le nombre total de nœuds dans un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre à compter
 * Return: Le nombre de nœuds dans l'arbre
 */
int node_count(const heap_t *tree)
{
	/* Cas de base: arbre vide */
	if (!tree)
		return (0);
	
	/* Récursion: 1 (nœud actuel) + nœuds gauche + nœuds droite */
	/* Cette fonction parcourt tout l'arbre - Complexité O(n) */
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * ins_max_heap - Place un nouveau nœud à la bonne position dans un tas maximum
 * @node: Pointeur vers le nœud racine du tas où placer le nouveau nœud
 * @new_node: Nouveau nœud à placer dans le tas
 * @index: Indice du nœud actuel
 * @new_node_index: Indice où le nouveau nœud doit être placé
 * Return: Pointeur vers le nœud racine mis à jour, ou NULL en cas d'échec
 */
heap_t *ins_max_heap(heap_t *node, heap_t *new_node,
		      int index, int new_node_index)
{
	/* Cas impossible: on a dépassé l'index cible */
	if (index > new_node_index)
		return (NULL);
	
	/* Cas de base: on a trouvé la position exacte pour le nouveau nœud */
	if (index == new_node_index)
		return (new_node);

	/* Navigation récursive vers l'enfant gauche */
	/* Formule: enfant_gauche = 2 * parent + 1 */
	node->left = ins_max_heap(node->left, new_node,
				  index * 2 + 1, new_node_index);
	/* Établir le lien parent → enfant si un nœud a été placé à gauche */
	if (node->left)
		node->left->parent = node;

	/* Navigation récursive vers l'enfant droit */
	/* Formule: enfant_droit = 2 * parent + 2 */
	node->right = ins_max_heap(node->right, new_node,
				   index * 2 + 2, new_node_index);
	/* Établir le lien parent → enfant si un nœud a été placé à droite */
	if (node->right)
		node->right->parent = node;

	/* Retourner le nœud actuel (structure préservée) */
	return (node);
}

/**
 * bottom_up_heapify - Réorganise un tas binaire maximum de bas en haut
 * @node: Pointeur vers le nœud racine du tas à réorganiser
 * Return: Pointeur vers le nœud racine du tas
 */
heap_t *bottom_up_heapify(heap_t *node)
{
	heap_t *temp = node;    /* Pointeur pour remonter dans l'arbre */
	int temp_n;             /* Variable temporaire pour l'échange */

	/* Boucle de remontée: continuer tant que */
	/* 1. Le nœud a un parent ET */
	/* 2. La valeur du nœud > valeur du parent (violation max heap) */
	while (temp->parent && temp->n > temp->parent->n)
	{
		/* Échange classique des valeurs (pas des pointeurs) */
		/* Ceci préserve la structure de l'arbre */
		temp_n = temp->n;                /* Sauvegarder valeur enfant */
		temp->n = temp->parent->n;       /* Enfant = valeur parent */
		temp->parent->n = temp_n;        /* Parent = valeur enfant */
		
		/* Remonter d'un niveau pour continuer la vérification */
		/* Après échange, la "grande valeur" est maintenant dans le parent */
		temp = temp->parent;
	}
	
	/* Retourner le pointeur vers le nœud où s'est arrêtée la remontée */
	/* Peut être n'importe où dans l'arbre, y compris la nouvelle racine */
	return (temp);
}