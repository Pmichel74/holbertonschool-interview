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

## 📊 Exemples Détaillés

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

## 💻 Algorithme

```python
def minOperations(n):
    if n <= 1:
        return 0
    
    operations = 0
    divisor = 2
    
    # Décomposition en facteurs premiers
    while n > 1:
        while n % divisor == 0:  # Tant que divisor divise n
            operations += divisor  # Ajouter le facteur
            n //= divisor         # Éliminer ce facteur
        divisor += 1             # Tester le diviseur suivant
    
    return operations
```

## 🔍 Pourquoi Cette Approche Fonctionne ?

### 1. **Optimalité**
- Chaque facteur premier représente la façon la plus efficace de multiplier
- Aucune autre décomposition ne peut donner moins d'opérations

### 2. **Exhaustivité**
- L'algorithme teste tous les diviseurs possibles de 2 à √n
- Garantit de trouver tous les facteurs premiers

### 3. **Efficacité**
- Complexité temporelle : O(√n)
- Complexité spatiale : O(1)

## 📈 Tableau de Résultats

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

## ✅ Cas Particuliers

### Nombres Premiers
- Si `n` est premier → `operations = n`
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