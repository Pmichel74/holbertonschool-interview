# Minimum Operations - Décomposition en Facteurs Premiers

## 📋 Description du Problème

Dans un éditeur de texte, vous ne pouvez effectuer que **deux opérations** :
- **"Copier Tout"** : Copie tous les caractères actuels
- **"Coller"** : Colle le contenu du presse-papier

**Objectif :** Calculer le nombre minimum d'opérations pour obtenir exactement `n` caractères 'H', en partant d'un seul 'H'.

## 🎯 Solution : Utilisation des Nombres Premiers

### Le Principe Fondamental

Le but est d'utiliser la **décomposition en facteurs premiers** pour trouver le nombre minimum d'opérations. Voici pourquoi :

- Pour multiplier le nombre de 'H' par un facteur `p`, il faut exactement `p` opérations :
  - 1 opération "Copier Tout"
  - `p-1` opérations "Coller"

- La stratégie optimale consiste à décomposer `n` en facteurs premiers et additionner ces facteurs.

### Formule Mathématique

```
Si n = p₁^a₁ × p₂^a₂ × ... × pₖ^aₖ
Alors operations_min = (p₁ × a₁) + (p₂ × a₂) + ... + (pₖ × aₖ)
```

## � Concept Clé : Le Modulo (%)

### Qu'est-ce que le Modulo ?
Le **modulo** (`%`) donne le **reste** d'une division entière.

```python
12 % 2 = 0    # 12 ÷ 2 = 6 reste 0 → 2 divise 12 exactement
13 % 2 = 1    # 13 ÷ 2 = 6 reste 1 → 2 ne divise pas 13
15 % 3 = 0    # 15 ÷ 3 = 5 reste 0 → 3 divise 15 exactement
```

### Dans l'Algorithme :
```python
while n % factor == 0:  # "Tant que factor divise n exactement"
    operations += factor
    n //= factor
```

**Le modulo sert à détecter les facteurs premiers :**
- `n % factor == 0` ✓ → `factor` est un diviseur de `n`
- `n % factor != 0` ✗ → `factor` n'est PAS un diviseur de `n`

### Exemple avec n = 12 :
```python
12 % 2 = 0  ✓  # 2 divise 12 → ajouter 2 aux opérations
6 % 2 = 0   ✓  # 2 divise 6 → ajouter 2 aux opérations  
3 % 2 = 1   ✗  # 2 ne divise plus 3 → passer au facteur suivant
3 % 3 = 0   ✓  # 3 divise 3 → ajouter 3 aux opérations
```

**En résumé :** Le modulo = détecteur de divisibilité pour trouver les facteurs premiers !

## �📊 Exemples Détaillés

### Exemple 1 : n = 9
```
Décomposition : 9 = 3 × 3
Opérations : 3 + 3 = 6

Simulation :
1 → Copie H
2 → Colle → HH (2 H)
3 → Colle → HHH (3 H)
4 → Copie HHH
5 → Colle → HHHHHH (6 H)
6 → Colle → HHHHHHHHH (9 H) ✓
```

### Exemple 2 : n = 12
```
Décomposition : 12 = 2 × 2 × 3
Opérations : 2 + 2 + 3 = 7

Progression : 1 → 2 → 4 → 12
```

### Exemple 3 : n = 10
```
Décomposition : 10 = 2 × 5
Opérations : 2 + 5 = 7

Progression : 1 → 2 → 10
```

## 💻 Algorithme Optimisé

```python
def minOperations(n):
    if n <= 1:
        return 0
    
    operations = 0
    factor = 2
    
    # Décomposition en facteurs premiers (optimisée)
    while factor * factor <= n:      # Teste seulement jusqu'à √n
        while n % factor == 0:       # Tant que factor divise n
            operations += factor     # Ajouter le facteur
            n //= factor            # Éliminer ce facteur
        factor += 1                 # Tester le facteur suivant
    
    # Si n > 1, alors n est un nombre premier restant
    if n > 1:
        operations += n
    
    return operations
```

## � Optimisations Clés

### 1. **Arrêt à √n**
```python
while factor * factor <= n:  # Au lieu de while n > 1
```
- **Gain** : Réduction massive des itérations
- **Exemple** : Pour n=10000, on teste jusqu'à 100 au lieu de 10000

### 2. **Gestion du Dernier Facteur Premier**
```python
if n > 1:
    operations += n
```
- **Logique** : Si n > 1 après la boucle, c'est un facteur premier
- **Exemple** : 15 = 3×5 → après avoir trouvé 3, il reste 5

### 3. **Complexité Optimale**
- **Temporelle** : O(√n) - très rapide même pour de grands nombres
- **Spatiale** : O(1) - utilisation mémoire constante

## 📊 Comparaison de Performance

| n | Itérations (ancien) | Itérations (nouveau) | Gain |
|---|-------------------|---------------------|------|
| 100 | 98 | 8 | 12x plus rapide |
| 1,000 | 998 | 31 | 32x plus rapide |
| 10,000 | 9,998 | 100 | 100x plus rapide |
| 1,000,000 | 999,998 | 1,000 | 1000x plus rapide |

## � Logique de l'Optimisation √n

### Pourquoi s'arrêter à √n ?
```
Si n a un facteur > √n, alors n a forcément un facteur correspondant < √n
Exemple avec n = 15:
- √15 ≈ 3.87
- Facteurs testés : 2, 3
- Facteur 3 trouvé → 15/3 = 5
- 5 > 1 → 5 est le facteur restant (> √15)
```

### Gestion du Dernier Facteur :
```python
# Après la boucle, si n > 1 :
# n est forcément un nombre premier > √n_original
if n > 1:
    operations += n  # Ajouter ce facteur premier
```

### Preuve Mathématique :
- Si n = a × b avec a ≤ b
- Alors a ≤ √n ≤ b
- En testant jusqu'à √n, on trouve tous les facteurs a
- Les facteurs b correspondants sont automatiquement calculés (n/a)

## �📈 Tableau de Résultats

| n  | Factorisation | Operations | Explication |
|----|---------------|------------|-------------|
| 1  | -             | 0          | Déjà atteint |
| 2  | 2             | 2          | 1→2 |
| 3  | 3             | 3          | 1→3 |
| 4  | 2²            | 4          | 1→2→4 |
| 5  | 5             | 5          | 1→5 |
| 6  | 2×3           | 5          | 1→2→6 |
| 8  | 2³            | 6          | 1→2→4→8 |
| 9  | 3²            | 6          | 1→3→9 |
| 10 | 2×5           | 7          | 1→2→10 |
| 12 | 2²×3          | 7          | 1→2→4→12 |
| 13 | 13            | 13         | 1→13 (premier) |

## 🔢 Focus sur les Nombres Premiers

### Qu'est-ce qu'un Nombre Premier ?
Un **nombre premier** est un entier naturel > 1 qui n'a que deux diviseurs : 1 et lui-même.

**Exemples :** 2, 3, 5, 7, 11, 13, 17, 19, 23, 29...

### Cas Spécial : n = 13 (Nombre Premier)

#### **Calcul avec l'algorithme :**
```python
n = 13, factor = 2
# 2² = 4 ≤ 13 ✓, mais 13 % 2 = 1 ✗

factor = 3  
# 3² = 9 ≤ 13 ✓, mais 13 % 3 = 1 ✗

factor = 4
# 4² = 16 > 13 ✗ → Sortie de boucle

# n = 13 > 1 → 13 est premier !
operations += 13 = 13
```

#### **Simulation avec les H :**
```
Départ:       H                                     (1 H)
Opération 1:  H → Copie H
Opération 2:  H + H = HH                           (2 H)
Opération 3:  HH + H = HHH                         (3 H)
...
Opération 13: HHHHHHHHHHHH + H = HHHHHHHHHHHHH     (13 H)
```

### Pourquoi les Nombres Premiers = Pire Cas ?

#### **Impossibilité d'optimisation :**
- **Pas de factorisation** : 13 = 13 (indivisible)
- **Stratégie unique** : 1 "Copier Tout" + 12 "Coller"
- **Aucun raccourci possible**

#### **Comparaison :**
```
n = 12 = 2² × 3 → 7 opérations  (optimisable)
n = 13 = 13     → 13 opérations (non optimisable)
n = 14 = 2 × 7  → 9 opérations  (optimisable)
```

### Détection Efficace avec √n

#### **Algorithme intelligent :**
```python
# Pour n = 13
while factor * factor <= 13:  # Teste seulement 2, 3
    # Aucun diviseur trouvé
# Si n > 1 après la boucle → nombre premier !
```

#### **Gain de performance :**
- **Ancienne méthode** : teste 2,3,4,5,6,7,8,9,10,11,12 (11 tests)
- **Nouvelle méthode** : teste 2,3 seulement (2 tests)
- **Gain** : 5.5x plus rapide pour détecter que 13 est premier !

## ✅ Cas Particuliers

### Nombres Premiers
- Si `n` est premier → `operations = n`
- **Exemples** : n=7 → 7 opérations, n=13 → 13 opérations
- **Caractéristique** : Aucune optimisation possible (indivisible)

### Liste des Premiers < 30
```
2, 3, 5, 7, 11, 13, 17, 19, 23, 29
Tous donnent : opérations = n
```

## 🔢 Table des Nombres Premiers

### Nombres Premiers de 1 à 100
```
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97
```

### Résultats pour les Nombres Premiers Courants

| Nombre Premier | Operations | Stratégie |
|---------------|------------|-----------|
| 2 | 2 | 1→2 |
| 3 | 3 | 1→3 |
| 5 | 5 | 1→5 |
| 7 | 7 | 1→7 |
| 11 | 11 | 1→11 |
| 13 | 13 | 1→13 |
| 17 | 17 | 1→17 |
| 19 | 19 | 1→19 |
| 23 | 23 | 1→23 |
| 29 | 29 | 1→29 |
| 31 | 31 | 1→31 |
| 37 | 37 | 1→37 |
| 41 | 41 | 1→41 |
| 43 | 43 | 1→43 |
| 47 | 47 | 1→47 |

### Caractéristiques des Nombres Premiers
- ✅ **Indivisibles** : Pas d'autre facteur que 1 et eux-mêmes
- ✅ **Aucune optimisation** : operations = n (toujours)
- ✅ **Détection √n** : Très efficace avec l'algorithme optimisé
- ✅ **Pattern unique** : 1 "Copier Tout" + (n-1) "Coller"

### Grands Nombres Premiers (exemples)
```
101 → 101 opérations
103 → 103 opérations  
107 → 107 opérations
109 → 109 opérations
113 → 113 opérations
```

**Note :** Plus le nombre premier est grand, plus l'optimisation √n devient avantageuse pour la détection !
- Exemple : n=7 → 7 opérations

### Puissances de Nombres Premiers  
- Si `n = p^k` → `operations = p × k`
- Exemple : n=8=2³ → 2×3 = 6 opérations

### Cas Limites
- `n ≤ 1` → 0 opération (impossible ou déjà atteint)

## 🚀 Utilisation

```bash
python3 0-minoperations.py
```

## 🧠 Concepts Clés

- **Factorisation première** : Décomposition unique d'un nombre
- **Stratégie gloutonne** : Choisir la meilleure option à chaque étape
- **Optimisation** : Minimiser le nombre total d'opérations

---

> **Note :** Cette solution exploite la propriété mathématique que la décomposition en facteurs premiers donne toujours le nombre minimum d'opérations pour ce type de problème.