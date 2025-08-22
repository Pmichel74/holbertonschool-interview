#!/bin/bash

# Script de test pour heap_insert

echo "=== COMPILATION ==="
make clean
make

if [ $? -eq 0 ]; then
    echo "✅ Compilation réussie"
else
    echo "❌ Erreur de compilation"
    exit 1
fi

echo ""
echo "=== EXÉCUTION DU PROGRAMME ==="
./heap_insert

echo ""
echo "=== VÉRIFICATION AVEC VALGRIND (si disponible) ==="
if command -v valgrind &> /dev/null; then
    echo "Vérification des fuites mémoire..."
    valgrind --leak-check=full --show-leak-kinds=all ./heap_insert
else
    echo "Valgrind non installé, pas de vérification mémoire"
fi

echo ""
echo "=== NETTOYAGE ==="
make clean
echo "✅ Test terminé"
