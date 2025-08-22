/*
 * EXEMPLES COMMENTÉS - INSERTION DANS UN MAX HEAP
 * ==============================================
 */

#include <stdio.h>
#include "binary_trees.h"

/**
 * exemple_insertion_simple - Démontre l'insertion étape par étape
 */
void exemple_insertion_simple(void)
{
    heap_t *root = NULL;
    heap_t *inserted;

    printf("=== EXEMPLE 1: INSERTION DANS UN HEAP VIDE ===\n");
    
    /* INSERTION 1: Valeur 50 dans heap vide */
    printf("\n1. Insérer 50 dans heap vide\n");
    inserted = heap_insert(&root, 50);
    printf("   - Nouveau nœud créé avec valeur 50\n");
    printf("   - Pas de node_count (heap vide)\n");
    printf("   - size = 0 + 1 = 1\n");
    printf("   - Placement à l'index 0 (racine)\n");
    printf("   - Pas de heapify nécessaire (pas de parent)\n");
    printf("   - Résultat: [50] devient la racine\n");
    
    if (root)
        binary_tree_print(root);

    /* INSERTION 2: Valeur 30 */
    printf("\n2. Insérer 30\n");
    inserted = heap_insert(&root, 30);
    printf("   - node_count = 1, size = 2\n");
    printf("   - Placement à l'index 1 (enfant gauche de 50)\n");
    printf("   - Heapify: 30 < 50 → pas d'échange\n");
    printf("   - Résultat:\n");
    
    if (root)
        binary_tree_print(root);

    /* INSERTION 3: Valeur 20 */  
    printf("\n3. Insérer 20\n");
    inserted = heap_insert(&root, 20);
    printf("   - node_count = 2, size = 3\n");
    printf("   - Placement à l'index 2 (enfant droit de 50)\n");
    printf("   - Heapify: 20 < 50 → pas d'échange\n");
    printf("   - Résultat:\n");
    
    if (root)
        binary_tree_print(root);

    /* INSERTION 4: Valeur 60 (nécessite heapify) */
    printf("\n4. Insérer 60 (va nécessiter heapify)\n");
    inserted = heap_insert(&root, 60);
    printf("   - node_count = 3, size = 4\n");
    printf("   - Placement à l'index 3 (enfant gauche de 30)\n");
    printf("   - État avant heapify:\n");
    printf("        50\n       /  \\\n     30   20\n    /\n   60\n");
    printf("   - Heapify étape 1: 60 > 30 → échange\n");
    printf("   - Heapify étape 2: 60 > 50 → échange\n");
    printf("   - Heapify étape 3: 60 n'a plus de parent → stop\n");
    printf("   - Résultat final:\n");
    
    if (root)
        binary_tree_print(root);
}

/**
 * trace_node_count - Montre le déroulement de node_count
 */
void trace_node_count(void)
{
    printf("\n=== EXEMPLE 2: TRACE DE NODE_COUNT ===\n");
    
    printf("Pour un heap:\n");
    printf("       50\n");
    printf("      /  \\\n");
    printf("    30   20\n");
    printf("   /\n");
    printf("  10\n");
    printf("\nDéroulement de node_count(racine):\n");
    printf("1. node_count(50):\n");
    printf("   └─ return 1 + node_count(30) + node_count(20)\n");
    printf("2. node_count(30):\n");
    printf("   └─ return 1 + node_count(10) + node_count(NULL)\n");
    printf("3. node_count(10):\n");
    printf("   └─ return 1 + node_count(NULL) + node_count(NULL)\n");
    printf("   └─ return 1 + 0 + 0 = 1\n");
    printf("4. Retour node_count(30): 1 + 1 + 0 = 2\n");
    printf("5. node_count(20): return 1 + 0 + 0 = 1\n");
    printf("6. Retour final: 1 + 2 + 1 = 4 nœuds\n");
}

/**
 * trace_ins_max_heap - Montre la navigation récursive
 */
void trace_ins_max_heap(void)
{
    printf("\n=== EXEMPLE 3: TRACE DE INS_MAX_HEAP ===\n");
    
    printf("Insérer dans heap existant, size = 5, index cible = 4\n");
    printf("       50 (0)\n");
    printf("      /     \\\n");
    printf("   30(1)   20(2)\n");
    printf("   /\n");
    printf(" 10(3)\n");
    printf("\nNouveau nœud va à l'index 4\n");
    printf("Parent de 4: (4-1)/2 = 1 → nœud 30\n");
    printf("Position: enfant droit de 30\n\n");
    
    printf("Navigation ins_max_heap(racine, new_node, 0, 4):\n");
    printf("APPEL 1: ins_max_heap(50, new_node, 0, 4)\n");
    printf("├─ 0 ≠ 4 → continuer\n");
    printf("├─ left: ins_max_heap(30, new_node, 1, 4)\n");
    printf("│  APPEL 2: ins_max_heap(30, new_node, 1, 4)\n");
    printf("│  ├─ 1 ≠ 4 → continuer\n");
    printf("│  ├─ left: ins_max_heap(10, new_node, 3, 4)\n");
    printf("│  │  └─ 3 ≠ 4 → return NULL\n");
    printf("│  ├─ right: ins_max_heap(NULL, new_node, 4, 4)\n");
    printf("│  │  └─ 4 = 4 ✅ return new_node\n");
    printf("│  ├─ 30->right = new_node\n");
    printf("│  ├─ new_node->parent = 30\n");
    printf("│  └─ return 30\n");
    printf("└─ right: ins_max_heap(20, new_node, 2, 4)\n");
    printf("   └─ 5 > 4 → return NULL\n");
    printf("\nRésultat: nouveau nœud placé comme enfant droit de 30\n");
}

/**
 * trace_bottom_up_heapify - Montre le processus de remontée
 */
void trace_bottom_up_heapify(void)
{
    printf("\n=== EXEMPLE 4: TRACE DE BOTTOM_UP_HEAPIFY ===\n");
    
    printf("Après placement de 60 à l'index 4:\n");
    printf("       50\n");
    printf("      /  \\\n");
    printf("    30   20\n");
    printf("   /  \\\n");
    printf("  10  60 ← nouveau nœud (temp)\n\n");
    
    printf("bottom_up_heapify(nouveau_nœud_60):\n");
    printf("temp = nœud contenant 60\n\n");
    
    printf("ITÉRATION 1:\n");
    printf("├─ temp->parent ? 30 ✅\n");
    printf("├─ temp->n (60) > temp->parent->n (30) ? ✅\n");
    printf("├─ ÉCHANGE:\n");
    printf("│  ├─ temp_n = 60\n");
    printf("│  ├─ nœud_60 devient nœud_30\n");
    printf("│  ├─ nœud_30 devient nœud_60\n");
    printf("│  └─ temp = ancien parent (maintenant 60)\n");
    printf("└─ État: temp pointe vers le nœud qui contient 60\n");
    printf("       50\n");
    printf("      /  \\\n");
    printf("    60   20 ← temp ici\n");
    printf("   /  \\\n");
    printf("  10  30\n\n");
    
    printf("ITÉRATION 2:\n");
    printf("├─ temp->parent ? 50 ✅\n");
    printf("├─ temp->n (60) > temp->parent->n (50) ? ✅\n");
    printf("├─ ÉCHANGE:\n");
    printf("│  └─ temp = racine (maintenant 60)\n");
    printf("└─ État:\n");
    printf("       60 ← temp ici (nouvelle racine)\n");
    printf("      /  \\\n");
    printf("    50   20\n");
    printf("   /  \\\n");
    printf("  10  30\n\n");
    
    printf("ITÉRATION 3:\n");
    printf("├─ temp->parent ? NULL ❌\n");
    printf("└─ ARRÊT → return temp (pointeur vers racine 60)\n");
}

/**
 * main - Programme de démonstration avec traces
 */
int main(void)
{
    printf("DÉMONSTRATION COMPLÈTE - INSERTION HEAP MAXIMUM\n");
    printf("==============================================\n");
    
    exemple_insertion_simple();
    trace_node_count();
    trace_ins_max_heap();
    trace_bottom_up_heapify();
    
    printf("\n🎯 POINTS CLÉS À RETENIR:\n");
    printf("1. Structure complète = position déterminée par la taille\n");
    printf("2. Placement = navigation récursive avec indexation mathématique\n");
    printf("3. Heapify = remontée par échange de valeurs (pas de pointeurs)\n");
    printf("4. Complexité = O(n) pour compter + O(log n) pour insérer\n");
    
    return (0);
}
