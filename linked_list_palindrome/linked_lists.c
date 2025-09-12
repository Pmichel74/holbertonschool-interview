#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - affiche tous les éléments d'une liste listint_t
 * @h: pointeur vers la tête de la liste
 * Return: nombre de nœuds
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current;  /* Pointeur pour parcourir la liste */
    unsigned int n;            /* Compteur de nœuds */

    current = h;  /* Commencer au début de la liste */
    n = 0;        /* Initialiser le compteur */
    
    /* Parcourir tous les nœuds de la liste */
    while (current != NULL)
    {
        printf("%i\n", current->n);  /* Afficher la valeur du nœud actuel */
        current = current->next;     /* Passer au nœud suivant */
        n++;                         /* Incrémenter le compteur */
    }

    return (n);  /* Retourner le nombre total de nœuds */
}

/**
 * add_nodeint_end - ajoute un nouveau nœud à la fin d'une liste listint_t
 * @head: pointeur vers pointeur du premier nœud de la liste listint_t
 * @n: entier à inclure dans le nouveau nœud
 * Return: adresse du nouvel élément ou NULL si échec
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;      /* Nouveau nœud à créer */
    listint_t *current;  /* Pointeur pour parcourir jusqu'à la fin */

    current = *head;  /* Commencer au début de la liste */

    /* Allouer la mémoire pour le nouveau nœud */
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);  /* Échec d'allocation mémoire */

    /* Initialiser le nouveau nœud */
    new->n = n;         /* Assigner la valeur */
    new->next = NULL;   /* Dernier nœud pointe vers NULL */

    /* Si la liste est vide, le nouveau nœud devient la tête */
    if (*head == NULL)
        *head = new;
    else
    {
        /* Parcourir jusqu'au dernier nœud */
        while (current->next != NULL)
            current = current->next;
        
        /* Connecter le nouveau nœud à la fin */
        current->next = new;
    }

    return (new);  /* Retourner l'adresse du nouveau nœud */
}

/**
 * free_listint - libère une liste listint_t
 * @head: pointeur vers la liste à libérer
 * Return: void
 */
void free_listint(listint_t *head)
{
    listint_t *current;  /* Pointeur temporaire pour le nœud actuel */

    /* Parcourir et libérer chaque nœud */
    while (head != NULL)
    {
        current = head;        /* Sauvegarder le nœud actuel */
        head = head->next;     /* Passer au nœud suivant */
        free(current);         /* Libérer le nœud sauvegardé */
    }
}
