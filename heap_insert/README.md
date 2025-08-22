# Heap Insert - Insertion dans un Tas Maximum

## Description

Ce projet implémente l'insertion d'éléments dans un **tas maximum** (max heap), une structure de données arborescente où :
- Chaque nœud parent a une valeur **supérieure ou égale** à ses enfants
- L'arbre est **complet** (tous les niveaux remplis sauf le dernier, rempli de gauche à droite)

## Fichiers

| Fichier | Description |
|---------|------------|
| `binary_trees.h` | Header contenant les structures et prototypes |
| `0-binary_tree_node.c` | Fonction pour créer un nouveau nœud |
| `1-heap_insert.c` | Fonction principale d'insertion dans le heap |
| `binary_tree_print.c` | Fonction d'affichage de l'arbre (utilitaire) |
| `1-main.c` | Programme de test |
| `Makefile` | Script de compilation |
| `test.sh` | Script de test automatisé |

## Algorithme d'Insertion

L'insertion se fait en **3 étapes** :

### 1. Création du nouveau nœud
```c
new_node = binary_tree_node(NULL, value);
```

### 2. Placement à la bonne position
```c
size = node_count(*root) + 1;
*root = ins_max_heap(*root, new_node, 0, size - 1);
```
- Maintient la structure complète de l'arbre
- Utilise l'indexation : parent=(i-1)/2, gauche=2*i+1, droite=2*i+2

### 3. Heapify (remontée)
```c
return (bottom_up_heapify(new_node));
```
- Fait remonter le nœud jusqu'à respecter la propriété du max heap
- Échange avec le parent si valeur_nœud > valeur_parent

## Compilation et Exécution

### Compilation simple
```bash
make
```

### Test complet
```bash
make test
# ou
./test.sh
```

### Nettoyage
```bash
make clean
```

## Exemple d'Utilisation

```c
heap_t *root = NULL;
heap_t *node;

node = heap_insert(&root, 98);   // Insert 98
node = heap_insert(&root, 402);  // Insert 402
node = heap_insert(&root, 12);   // Insert 12
```

## Exemple de Sortie

```
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)
```

## Complexité

- **Temps :** O(log n) - hauteur de l'arbre
- **Espace :** O(1) - insertion en place

## Fonctions Principales

| Fonction | Rôle |
|----------|------|
| `heap_insert()` | Fonction principale d'insertion |
| `binary_tree_node()` | Création d'un nouveau nœud |
| `node_count()` | Compte les nœuds dans l'arbre |
| `ins_max_heap()` | Place le nœud à la bonne position |
| `bottom_up_heapify()` | Remontée pour respecter la propriété heap |

## Propriétés Maintenues

1. **Structure complète :** Tous les niveaux remplis sauf le dernier
2. **Propriété du max heap :** parent ≥ enfants
3. **Liens parent-enfant :** Correctement établis

## Tests

Le programme teste l'insertion séquentielle des valeurs :
98, 402, 12, 46, 128, 256, 512, 50

Chaque insertion affiche l'arbre résultant pour vérifier visuellement la correctitude.
