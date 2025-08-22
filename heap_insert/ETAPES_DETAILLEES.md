# 📋 ÉTAPES DÉTAILLÉES - SCRIPT D'INSERTION HEAP MAXIMUM

## 🎯 VUE D'ENSEMBLE DU PROCESSUS

```
ENTRÉE: heap_insert(&root, value)
   ↓
ÉTAPES: 1→2→3→4→5→6→7→8
   ↓
SORTIE: Pointeur vers nouveau nœud créé
```

---

## 🚀 ÉTAPE 1 : INITIALISATION DE LA FONCTION

### **Code :**
```c
heap_t *heap_insert(heap_t **root, int value)
{
    int size;
    heap_t *new_node = NULL;
```

### **Actions :**
1. **Recevoir les paramètres :**
   - `**root` : Double pointeur vers la racine
   - `value` : Valeur à insérer

2. **Déclarer les variables locales :**
   - `size` : Taille du heap après insertion
   - `new_node` : Pointeur vers le nouveau nœud

### **État mémoire :**
```
Stack Frame heap_insert:
├─ root = &heap_racine
├─ value = [valeur_utilisateur]
├─ size = [non_initialisé]
└─ new_node = NULL
```

---

## 🛡️ ÉTAPE 2 : VÉRIFICATION DE SÉCURITÉ

### **Code :**
```c
if (!root)
    return (NULL);
```

### **Actions :**
1. **Vérifier si `root` est valide**
2. **Si NULL → Arrêt immédiat avec échec**

### **Cas d'échec :**
```c
heap_insert(NULL, 42);  // root = NULL
// Retourne NULL immédiatement
```

### **Cas normal :**
```c
heap_t *my_heap = NULL;
heap_insert(&my_heap, 42);  // root = adresse de my_heap ✅
```

---

## 📦 ÉTAPE 3 : CRÉATION DU NOUVEAU NŒUD

### **Code :**
```c
new_node = binary_tree_node(NULL, value);
if (!new_node)
    return (NULL);
```

### **Actions :**
1. **Appeler `binary_tree_node(NULL, value)` :**
   - Allouer mémoire pour le nœud
   - Initialiser `n = value`
   - Initialiser `parent = NULL` (temporaire)
   - Initialiser `left = NULL`
   - Initialiser `right = NULL`

2. **Vérifier l'allocation**
3. **Si échec malloc → Retourner NULL**

### **Détail de `binary_tree_node` :**
```c
// Dans binary_tree_node(NULL, 42) :
new_node = malloc(sizeof(binary_tree_t));
new_node->n = 42;
new_node->parent = NULL;  // Sera défini plus tard
new_node->left = NULL;
new_node->right = NULL;
return new_node;
```

### **État mémoire après création :**
```
Heap Memory:
[new_node] → ┌─────────┐
             │ n: 42   │
             │ parent: NULL │
             │ left:   NULL │
             │ right:  NULL │
             └─────────┘
```

---

## 📊 ÉTAPE 4 : CALCUL DE LA POSITION D'INSERTION

### **Code :**
```c
size = node_count(*root) + 1;
```

### **Actions :**
1. **Appeler `node_count(*root)` - Fonction récursive :**

```c
// Pseudo-exécution pour un heap à 3 nœuds
node_count(racine_98)
├─ if (!tree) → false
├─ return 1 + node_count(left) + node_count(right)
├─ node_count(nœud_50)
│  ├─ return 1 + node_count(NULL) + node_count(NULL)
│  └─ return 1 + 0 + 0 = 1
├─ node_count(nœud_47)  
│  └─ return 1 + 0 + 0 = 1
└─ return 1 + 1 + 1 = 3
```

2. **Ajouter 1 pour le nouveau nœud :**
   - `size = 3 + 1 = 4`

3. **Déterminer l'index du nouveau nœud :**
   - Index cible = `size - 1 = 3`

### **Correspondance index → position :**
```
size = 4, index cible = 3

       [0]
      /   \
   [1]     [2]
   /
 [3] ← Position du nouveau nœud
```

---

## 🎯 ÉTAPE 5 : PLACEMENT DU NŒUD DANS L'ARBRE

### **Code :**
```c
*root = ins_max_heap(*root, new_node, 0, size - 1);
```

### **Actions :**
1. **Appeler fonction récursive :**
   - `ins_max_heap(racine, new_node, 0, 3)`

2. **Navigation récursive détaillée :**

```c
APPEL 1: ins_max_heap(racine_98, new_node, 0, 3)
├─ if (0 > 3) → false
├─ if (0 == 3) → false  
├─ node->left = ins_max_heap(nœud_50, new_node, 1, 3)
│
│  APPEL 2: ins_max_heap(nœud_50, new_node, 1, 3)
│  ├─ if (1 > 3) → false
│  ├─ if (1 == 3) → false
│  ├─ node->left = ins_max_heap(NULL, new_node, 3, 3)
│  │
│  │  APPEL 3: ins_max_heap(NULL, new_node, 3, 3)
│  │  ├─ if (3 > 3) → false
│  │  ├─ if (3 == 3) → true ✅
│  │  └─ return new_node
│  │
│  ├─ nœud_50->left = new_node
│  ├─ if (new_node) → true
│  ├─ new_node->parent = nœud_50  ← LIEN ÉTABLI !
│  └─ return nœud_50
│
├─ node->right = ins_max_heap(nœud_47, new_node, 2, 3)
│  └─ return NULL (2*2+1 = 5 > 3)
└─ return racine_98
```

### **État après placement :**
```
       98
      /  \
    50    47
   /
  42 ← new_node maintenant connecté !
     parent = 50
```

---

## 📈 ÉTAPE 6 : HEAPIFY - REMONTÉE DU NOUVEAU NŒUD

### **Code :**
```c
return (bottom_up_heapify(new_node));
```

### **Actions :**
1. **Initialisation :**
```c
heap_t *temp = new_node;  // temp pointe vers nœud [42]
int temp_n;
```

2. **Boucle de remontée :**
```c
while (temp->parent && temp->n > temp->parent->n)
```

### **Exécution détaillée - Exemple avec valeur 60 :**

```
État initial :
       98
      /  \
    50    47
   /
  60 ← new_node (temp)

ITÉRATION 1:
├─ temp->parent ? 50 ✅
├─ temp->n (60) > temp->parent->n (50) ? ✅
├─ ÉCHANGE:
│  ├─ temp_n = 60
│  ├─ temp->n = 50  (nœud devient [50])
│  ├─ temp->parent->n = 60  (parent devient [60])
│  └─ temp = temp->parent  (temp pointe vers ex-parent)
└─ État après échange:
       98
      /  \
    60    47  ← temp pointe ici
   /
  50

ITÉRATION 2:
├─ temp->parent ? 98 ✅  
├─ temp->n (60) > temp->parent->n (98) ? ❌
└─ ARRÊT de la boucle

RÉSULTAT:
return temp;  // Pointeur vers nœud contenant 60
```

---

## 🔚 ÉTAPE 7 : RETOUR DE LA FONCTION

### **Code :**
```c
return (bottom_up_heapify(new_node));
```

### **Valeur de retour :**
- **Pointeur vers le nœud** où s'est arrêtée la remontée
- **Peut être n'importe où** dans l'arbre après heapify
- **Permet au code appelant** de savoir où est le nouveau nœud

### **Exemples de retour :**
```c
// Cas 1: Pas de remontée
heap_t *result = heap_insert(&root, 10);
// result pointe vers la feuille contenant 10

// Cas 2: Remontée jusqu'à la racine  
heap_t *result = heap_insert(&root, 999);
// result pointe vers la nouvelle racine contenant 999
```

---

## 📋 ÉTAPE 8 : NETTOYAGE ET FINALISATION

### **Actions automatiques :**
1. **Variables locales libérées :**
   - `size` disparaît de la stack
   - `new_node` disparaît (mais le nœud reste en heap)

2. **État final du heap :**
   - Structure complète maintenue ✅
   - Propriété max heap respectée ✅
   - Liens parent-enfant corrects ✅

3. **Retour au code appelant :**
```c
// Dans le main :
heap_t *inserted_node = heap_insert(&root, 42);
// inserted_node contient l'adresse du nœud final
```

---

## 🎯 RÉCAPITULATIF COMPLET

### **Flow d'exécution :**
```
1. 🛡️  Vérifications de sécurité
2. 📦  Création du nouveau nœud  
3. 📊  Calcul de la position (index)
4. 🎯  Navigation et placement
5. 🔗  Établissement des liens parent-enfant
6. 📈  Remontée et échanges (heapify)
7. 🔚  Retour du pointeur final
8. 📋  Nettoyage de la stack
```

### **Invariants maintenus :**
- ✅ **Structure complète** (arbre équilibré)
- ✅ **Propriété heap** (parent ≥ enfants)  
- ✅ **Liens bidirectionnels** (parent ↔ enfant)
- ✅ **Intégrité mémoire** (pas de fuites)

### **Complexité finale :**
- **Temps :** O(n) pour node_count + O(log n) pour placement + O(log n) pour heapify = **O(n)**
- **Espace :** O(log n) pour la pile de récursion = **O(log n)**

**🎉 INSERTION COMPLÈTE ET HEAP VALIDE !**
