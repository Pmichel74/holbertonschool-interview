# 📊 Log Parsing Project

[![Python](https://img.shields.io/badge/Python-3.8+-blue.svg)](https://www.python.org/)
[![PEP8](https://img.shields.io/badge/code%20style-PEP8-green.svg)](https://www.python.org/dev/peps/pep-0008/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

> 🚀 Un projet Python pour analyser et traiter les logs HTTP en temps réel

## 📋 Table des matières

- [📝 Description du projet](#-description-du-projet)
- [✨ Fonctionnalités](#-fonctionnalités)
- [🔍 Spécifications](#-spécifications)
- [🏗️ Architecture](#️-architecture)
- [🚀 Installation](#-installation)
- [📖 Utilisation](#-utilisation)
- [📊 Format des logs](#-format-des-logs)
- [🧪 Tests](#-tests)
- [📈 Exemples](#-exemples)
- [🤝 Contribution](#-contribution)
- [📄 Licence](#-licence)

## 📝 Description du projet

**0. Log parsing** - *mandatory*  
**Score: 100.00%** (Checks completed: 100.00%)

Ce projet consiste à développer un script Python qui lit et analyse des logs HTTP ligne par ligne depuis l'entrée standard (stdin) et calcule des métriques en temps réel. Le script doit afficher périodiquement des statistiques sur les codes de statut HTTP et la taille totale des fichiers traités.

### 🎯 Objectif principal

Créer un outil d'analyse de logs capable de :
- Traiter des logs au format spécifique
- Calculer la taille totale des fichiers
- Compter les occurrences de chaque code de statut HTTP
- Afficher les statistiques périodiquement

## 🔍 Spécifications

### 📥 Format d'entrée

Le script traite des logs au format suivant :
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

**⚠️ Important :** Si le format n'est pas exactement celui-ci, la ligne doit être ignorée.

### 📤 Format de sortie

Après **chaque 10 lignes** et/ou une **interruption clavier** (CTRL + C), le script affiche ces statistiques depuis le début :

#### Taille totale des fichiers
```
File size: <total size>
```
Où `<total size>` est la somme de tous les `<file size>` précédents.

#### Nombre de lignes par code de statut
Codes de statut possibles : **200, 301, 400, 401, 403, 404, 405 et 500**

Format :
```
<status code>: <number>
```

**Règles importantes :**
- ❌ Si un code de statut n'apparaît pas ou n'est pas un entier, ne rien afficher pour ce code
- 📈 Les codes de statut doivent être affichés **dans l'ordre croissant**
- 🚫 Le code ne doit pas s'exécuter lors d'un import (utiliser `if __name__ == "__main__":`)

### 🎲 Générateur de test fourni

```python
#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    sys.stdout.write("{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n".format(
        random.randint(1, 255), random.randint(1, 255), random.randint(1, 255), random.randint(1, 255),
        datetime.datetime.now(),
        random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        random.randint(1, 1024)
    ))
    sys.stdout.flush()
```

### 📊 Exemple d'exécution

```bash
alexa@ubuntu:~/log_parsing$ ./0-generator.py | ./0-stats.py 
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
File size: 16305
200: 3
301: 3
400: 4
401: 2
403: 5
404: 5
405: 4
500: 4
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
Traceback (most recent call last):
  File "./0-stats.py", line 15, in <module>
Traceback (most recent call last):
  File "./0-generator.py", line 8, in <module>
    for line in sys.stdin:
KeyboardInterrupt
    sleep(random.random())
KeyboardInterrupt
alexa@ubuntu:~$
```

**ℹ️ Note :** Dans cet exemple, vous aurez des valeurs aléatoires - il est normal de ne pas avoir la même sortie.

## ✨ Fonctionnalités

- 🔍 **Parsing en temps réel** : Analyse les logs HTTP ligne par ligne depuis stdin
- 📊 **Statistiques détaillées** : Compte les codes de statut HTTP et calcule la taille totale
- ⏰ **Rapports périodiques** : Affiche les statistiques toutes les 10 lignes
- 🛑 **Gestion des interruptions** : Affiche les statistiques lors d'une interruption clavier (CTRL + C)
- 🎯 **Codes de statut supportés** : 200, 301, 400, 401, 403, 404, 405, 500
- 🛡️ **Gestion d'erreurs** : Ignore les lignes mal formatées
- 🔄 **Importable** : Le code ne s'exécute pas lors d'un import

## 🏗️ Architecture

```
log_parsing/
├── 0-stats.py          # Script principal de parsing des logs
├── 0-generator.py      # Générateur de logs de test
└── README.md          # Documentation du projet
```

## 🚀 Installation

### Prérequis

- 🐍 **Python 3.8+**
- 📦 Aucun package externe requis (utilise uniquement la bibliothèque standard)

### Installation

1. **Clonez le repository** :
   ```bash
   git clone https://github.com/Pmichel74/holbertonschool-interview.git
   cd holbertonschool-interview/log_parsing
   ```

2. **Rendez les scripts exécutables** :
   ```bash
   chmod +x 0-stats.py
   chmod +x 0-generator.py
   ```

3. **Vérifiez l'installation** :
   ```bash
   python3 --version
   ```

## 📖 Utilisation

### 🔧 Scripts disponibles

#### 📊 0-stats.py - Analyseur de logs

Lit les logs depuis stdin et affiche les statistiques en temps réel.

```bash
# Utilisation basique
cat access.log | ./0-stats.py

# Avec un générateur de logs
./0-generator.py | ./0-stats.py

# Avec des logs en temps réel
tail -f /var/log/nginx/access.log | ./0-stats.py
```

#### 🎲 0-generator.py - Générateur de logs

Génère des logs HTTP aléatoires pour les tests.

```bash
# Générer des logs de test
./0-generator.py

# Rediriger vers un fichier
./0-generator.py > test_logs.txt

# Utiliser avec l'analyseur
./0-generator.py | ./0-stats.py
```

## 📊 Format des logs

Le script supporte le format de logs spécifique :

```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

### Exemple de ligne de log valide :
```
192.168.1.100 - [26/Sep/2025:10:30:45 +0000] "GET /projects/260 HTTP/1.1" 200 512
```

### Champs analysés :
- **IP_ADDRESS** : Adresse IP du client
- **DATE_TIME** : Date et heure de la requête
- **STATUS_CODE** : Code de statut HTTP (doit être un des codes supportés)
- **FILE_SIZE** : Taille du fichier en octets (doit être un entier)

## 🧪 Tests

### Test avec le générateur intégré

```bash
# Test complet : génération + analyse
./0-generator.py | ./0-stats.py
```

### Test avec des données manuelles

```bash
# Utilisation avec des données manuelles
echo '192.168.1.1 - [26/Sep/2025:10:00:00 +0000] "GET /projects/260 HTTP/1.1" 200 1024' | ./0-stats.py
echo '192.168.1.2 - [26/Sep/2025:10:01:00 +0000] "GET /projects/260 HTTP/1.1" 404 512' | ./0-stats.py
```

### Vérification du style de code

```bash
# Vérifier la conformité PEP8
pycodestyle 0-stats.py
pycodestyle 0-generator.py
```

## 📈 Exemples

### Exemple d'exécution

```bash
$ ./0-generator.py | ./0-stats.py
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
```

### Analyse détaillée

- **File size** : Taille totale cumulée de tous les fichiers servis
- **200** : Nombre de requêtes réussies (OK)
- **301** : Nombre de redirections permanentes
- **400** : Nombre d'erreurs de requête du client
- **401** : Nombre d'erreurs d'authentification
- **403** : Nombre d'accès interdits
- **404** : Nombre de ressources non trouvées
- **405** : Nombre de méthodes non autorisées
- **500** : Nombre d'erreurs serveur internes



## 🤝 Contribution

Les contributions sont les bienvenues ! 🎉

1. **Fork** le projet
2. **Créez** une branche pour votre fonctionnalité (`git checkout -b feature/AmazingFeature`)
3. **Committez** vos changements (`git commit -m 'Add some AmazingFeature'`)
4. **Poussez** vers la branche (`git push origin feature/AmazingFeature`)
5. **Ouvrez** une Pull Request

### Standards de code

- 📏 Respect des conventions PEP8
- 🧪 Tests des nouvelles fonctionnalités
- 📚 Documentation claire des fonctions
- 🔄 Compatibilité avec Python 3.8+

## 📄 Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE](../LICENSE) pour plus de détails.

---

<div align="center">

**Créé avec ❤️ pour Holberton School**

⭐ Si ce projet vous plaît, n'hésitez pas à lui donner une étoile !

[⬆️ Retour en haut](#-log-parsing-project)

</div>
