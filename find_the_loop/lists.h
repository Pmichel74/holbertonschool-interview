#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stddef.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

size_t print_listint_safe(const listint_t *head);
listint_t *add_nodeint(listint_t **head, const int n);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */
