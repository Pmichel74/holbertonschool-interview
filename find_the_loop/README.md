# 0. Find the loop

Écrire une fonction qui détecte et retourne le début d'une boucle dans une
liste chaînée.

- Prototype: `listint_t *find_listint_loop(listint_t *head);`
- Retour: l'adresse du noeud où commence la boucle, ou `NULL` s'il n'y a pas
  de boucle.
- Interdictions: pas d'utilisation de `malloc`, `free` ou de tableaux.
- Variable limit: vous ne pouvez déclarer au maximum que deux variables dans
  la fonction.

Compilation et tests locaux:

```sh
cd holbertonschool-interview/find_the_loop
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-find_loop.c lib.c -o test_find_loop && ./test_find_loop
gcc -Wall -Werror -Wextra -pedantic test.c 0-find_loop.c -o test_custom && ./test_custom
```

Le dossier contient un header local `lists.h` déclarant la structure
`listint_t` et les prototypes nécessaires pour compiler les tests fournis.
