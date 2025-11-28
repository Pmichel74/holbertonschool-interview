# Menger Sponge 2D

## Description

Programme en C qui dessine une représentation 2D de l'**éponge de Menger**, une fractale mathématique créée par Karl Menger en 1926.

## Principe de l'éponge de Menger

L'éponge de Menger est à l'origine une **fractale 3D** (un cube avec des trous). Dans ce projet, nous travaillons avec sa **projection 2D** : une vue de face qui montre le motif sur une seule face du cube.

### Pourquoi 2D ?

- **Éponge 3D réelle** : Un cube divisé en 27 petits cubes (3×3×3), avec le cube central et les 6 cubes au centre de chaque face retirés
- **Version 2D (ce projet)** : Vue de dessus/face qui montre uniquement le motif sur un plan

L'éponge est construite récursivement en divisant chaque carré en une grille 3×3 et en retirant le carré central.

### Progression par niveau

| Niveau | Taille | Rendu |
|--------|--------|-------|
| 0 | 1×1 | `#` |
| 1 | 3×3 | Grille 3×3 avec centre vide |
| 2 | 9×9 | 9 carrés de niveau 1 arrangés en 3×3 |
| N | 3^N × 3^N | Répétition récursive du motif |

### Exemples visuels

**Niveau 0** (3^0 = 1) :
```
#
```

**Niveau 1** (3^1 = 3) :
```
###
# #
###
```

**Niveau 2** (3^2 = 9) :
```
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

## Structure du projet

```
menger/
├── menger.h      - Header avec les prototypes
├── 0-menger.c    - Implémentation de menger()
└── 0-main.c      - Programme de test
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-menger.c -lm -o 0-menger
```

**Note** : Le flag `-lm` est nécessaire pour lier la bibliothèque mathématique (`pow()`).

## Utilisation

```bash
./0-menger <level>
```

- `level` >= 0 : Dessine l'éponge du niveau spécifié
- `level` < 0 : Aucune sortie

## Comment le code génère la 2D

La fonction `menger()` parcourt chaque position (row, col) comme des **coordonnées sur un plan** :

```c
for (row = 0; row < size; row++)      // Parcourt les lignes (axe Y)
{
    for (col = 0; col < size; col++)  // Parcourt les colonnes (axe X)
    {
        if (is_empty(row, col))       // Ce pixel est-il vide ?
            printf(" ");               // → Espace (trou)
        else
            printf("#");               // → Rempli (matière)
    }
    printf("\n");                      // Nouvelle ligne
}
```

**Visualisation du parcours pour niveau 1 (3×3)** :
```
Position (0,0) (0,1) (0,2)  →  ###
Position (1,0) (1,1) (1,2)  →  # #  ← (1,1) est vide !
Position (2,0) (2,1) (2,2)  →  ###
```

Chaque `printf("#")` ou `printf(" ")` dessine **un pixel** du motif 2D.

## Algorithme

### Fonction `is_empty(row, col)`

Détermine si une position doit être vide en vérifiant si elle est au centre d'une grille 3×3 à n'importe quel niveau.

**Logique** :
```c
while (row > 0 || col > 0)
{
    if (row % 3 == 1 && col % 3 == 1)  // Centre ?
        return (1);                     // → Vide
    row /= 3;                           // Niveau supérieur
    col /= 3;
}
return (0);                             // → Rempli
```

**Explication** :
- `row % 3 == 1 && col % 3 == 1` : détecte le centre d'une grille 3×3
- Division par 3 : monte au niveau supérieur de la fractale
- Si un centre est trouvé à n'importe quel niveau → espace
- Sinon → `#`

### Fonction `menger(level)`

```c
1. Vérifier level >= 0
2. Calculer size = 3^level
3. Pour chaque position (row, col) :
   - if (is_empty(row, col)) → afficher ' '
   - else → afficher '#'
4. Nouvelle ligne après chaque rangée
```

## Concepts clés

### Puissance de 3
```c
size = (int)pow(3, level);
```
- Niveau 0 : 3^0 = 1
- Niveau 1 : 3^1 = 3
- Niveau 2 : 3^2 = 9
- Niveau 3 : 3^3 = 27

### Modulo 3
```c
n % 3  // Position dans une grille 3×3 (0, 1, ou 2)
```
- 0 : Gauche/Haut
- 1 : Centre
- 2 : Droite/Bas

Exemple :
```
Positions 0-8 dans une grille 9×9 :
0%3=0, 1%3=1, 2%3=2, 3%3=0, 4%3=1, 5%3=2, 6%3=0, 7%3=1, 8%3=2
```

### Division entière
```c
n /= 3  // Monte au niveau supérieur
```
- 0/3 = 0
- 1/3 = 0
- 2/3 = 0
- 3/3 = 1
- 4/3 = 1

## Complexité

- **Temps** : O(3^(2N)) — on parcourt (3^N)² pixels
- **Espace** : O(N) — profondeur maximale de la boucle dans `is_empty()`

## Norme Betty

Code conforme à la norme Betty de Holberton School :
- Indentation avec tabulations
- Maximum 80 caractères par ligne
- Documentation complète
- Pas d'espace après les noms de fonction

## Auteur

Projet réalisé dans le cadre du programme **Holberton School**.
