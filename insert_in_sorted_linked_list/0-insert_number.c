
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the head of the list
 * @number: number to insert
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *current;


    /* Check if head pointer is valid */
    if (head == NULL)
        return (NULL);


    /* Create new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = number;


    /*
     * If the list is empty OR the value to insert is smaller than the first value,
     * insert at the beginning
     */
    if (*head == NULL || (*head)->n > number)
    {
        /* The new node points to the old first node (or NULL if the list was empty) */
        new_node->next = *head;
        /* Update the head to point to the new node */
        *head = new_node;
        /* Return the address of the new node */
        return (new_node);
    }


    current = *head;
    while (current->next != NULL && current->next->n < number)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
