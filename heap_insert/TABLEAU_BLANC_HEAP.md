# 🎯 TABLEAU BLANC - INSERTION DANS UN HEAP MAXIMUM

## 📋 DÉFINITION : QU'EST-CE QU'UN MAX HEAP ?

```
Un MAX HEAP est un arbre binaire complet où :
✅ Chaque parent ≥ ses enfants (propriété du heap)
✅ Tous les niveaux sont remplis sauf le dernier (rempli de gauche à droite)
```

---

## 🔢 INDEXATION - COMMENT NAVIGUER DANS L'ARBRE

```
Pour un nœud à l'index i :
📍 Parent    : (i - 1) / 2
📍 Enfant G  : 2 * i + 1  
📍 Enfant D  : 2 * i + 2

Exemple d'indexation :
       [0]
      /   \
   [1]     [2]
  /  \    /  \
[3]  [4] [5]  [6]
```

---

## 🚀 ALGORITHME D'INSERTION - 3 ÉTAPES

### ⭐ ÉTAPE 1 : CRÉATION DU NOUVEAU NŒUD
```c
new_node = binary_tree_node(NULL, value);
```
**Résultat :** Nœud créé en mémoire avec la valeur

---

### ⭐ ÉTAPE 2 : PLACEMENT À LA BONNE POSITION
```c
size = node_count(*root) + 1;               // Compter les nœuds
*root = ins_max_heap(*root, new_node, 0, size-1);  // Placer le nœud
```
**Objectif :** Maintenir la structure complète (pas les valeurs encore)

---

### ⭐ ÉTAPE 3 : HEAPIFY (REMONTÉE)
```c
return bottom_up_heapify(new_node);
```
**Objectif :** Remonter le nœud jusqu'à respecter parent ≥ enfants
**Pourquoi ≥ ?** Pour gérer les doublons (valeurs identiques autorisées)

---

## 📚 EXEMPLE COMPLET : INSÉRER 35

### 🏁 ÉTAT INITIAL
```
       98
      /  \
    50    47
   / \   /
  25 12 33
```
**Indices :** 0=98, 1=50, 2=47, 3=25, 4=12, 5=33
**Prochaine position :** Index 6

---

### 🔧 ÉTAPE 1 : CRÉATION
```
✅ Nouveau nœud créé : [35]
```

---

### 🔧 ÉTAPE 2 : PLACEMENT
```
Index cible : 6
Parent de 6 : (6-1)/2 = 2 (nœud 47)
Position : Enfant droit de 47

       98
      /  \
    50    47
   / \   / \
  25 12 33 35  ← Nouveau nœud placé
```

---

### 🔧 ÉTAPE 3 : HEAPIFY
```
Comparaison : 35 vs parent 47
35 < 47 → PAS D'ÉCHANGE → FINI !

Résultat final :
       98
      /  \
    50    47
   / \   / \
  25 12 33 35
```

---

## 🔥 EXEMPLE AVEC HEAPIFY : INSÉRER 60

### 🏁 HEAP AVANT INSERTION
```
       98
      /  \
    50    47
   / \   / \
  25 12 33 35
```

---

### 🔧 PLACEMENT À L'INDEX 7
```
       98
      /  \
    50    47
   / \   / \
  25 12 33 35
 /
60  ← Nouveau nœud placé
```

---

### 🔧 HEAPIFY - REMONTÉE ÉTAPE PAR ÉTAPE

#### 🔄 Remontée 1 : 60 vs 25
```
60 > 25 → ÉCHANGE !

       98
      /  \
    50    47
   / \   / \
  60 12 33 35
 /
25
```

#### 🔄 Remontée 2 : 60 vs 50
```
60 > 50 → ÉCHANGE !

       98
      /  \
    60    47
   / \   / \
  50 12 33 35
 /
25
```

#### 🔄 Remontée 3 : 60 vs 98
```
60 < 98 → PAS D'ÉCHANGE → FINI !

RÉSULTAT FINAL :
       98
      /  \
    60    47
   / \   / \
  50 12 33 35
 /
25
```

---

## 📊 RÉCAPITULATIF DES FONCTIONS

| 🎯 Fonction | 🔧 Rôle | ⏱️ Complexité |
|-------------|---------|---------------|
| `heap_insert()` | Orchestrer les 3 étapes | O(log n) |
| `binary_tree_node()` | Créer un nouveau nœud | O(1) |
| `node_count()` | Compter les nœuds existants | O(n) |
| `ins_max_heap()` | Placer à la bonne position | O(log n) |
| `bottom_up_heapify()` | Remonter pour respecter la propriété | O(log n) |

---

## ⚡ POINTS CLÉS À RETENIR

### ✅ PROPRIÉTÉS MAINTENUES
1. **Structure complète** → Arbre équilibré
2. **Parent ≥ Enfants** → Propriété du max heap (≥ permet les doublons)
3. **Liens corrects** → Navigation possible

### 🎯 AVANTAGES
- **Insertion rapide :** O(log n)
- **Structure équilibrée** automatiquement
- **Maximum toujours à la racine**

### 🔍 CAS D'USAGE
- **Priority queues** (files de priorité)
- **Tri par tas** (heap sort)
- **Algorithmes de graphes** (Dijkstra, etc.)

---

## 🧪 TESTEZ VOTRE COMPRÉHENSION

### 💡 Question 1
```
Heap initial:    [50]
                /    \
             [30]    [20]
            /
         [10]

Insérer 40 : Où sera-t-il placé d'abord ?
A) Enfant droit de 30
B) Enfant droit de 20  
C) Enfant gauche de 10

Réponse : B (index 4, enfant droit de 20 à l'index 2)
```

### 💡 Question 2
```
Après placement de 40 sous 20, y aura-t-il heapify ?
A) Oui, 40 > 20
B) Non, 40 < 50

Réponse : A → 40 remontera à la place de 20
```

---

## 🎨 SCHÉMA MENTAL À RETENIR

```
INSERTION = PLACEMENT + REMONTÉE

1. 📦 CRÉER le nœud
2. 📍 PLACER à la prochaine position libre (structure)  
3. ⬆️  REMONTER si nécessaire (propriété heap)

   Nouveau → Bas de l'arbre → Remonte si trop grand
```

---

## 🔗 LIENS AVEC D'AUTRES CONCEPTS

```
MAX HEAP ←→ MIN HEAP (inverse : parent ≤ enfants)
MAX HEAP ←→ HEAP SORT (tri O(n log n))
MAX HEAP ←→ PRIORITY QUEUE (structure de données)
MAX HEAP ←→ BINARY SEARCH TREE (différent : pas d'ordre gauche/droite)
```

---

**💪 MAINTENANT VOUS ÊTES PRÊTS À EXPLIQUER LES HEAPS !**
