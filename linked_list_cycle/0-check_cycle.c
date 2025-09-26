#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    /* If the list is empty or has only one node, there's no cycle */
    if (list == NULL || list->next == NULL)
        return (0);

    /* Initialize slow and fast pointers */
    slow = list;
    fast = list->next;

    while (fast && fast->next)
    {
        /* If slow and fast pointers meet, there's a cycle */
        if (slow == fast)
            return (1);

        /* Move slow pointer one step */
        slow = slow->next;
        /* Move fast pointer two steps */
        fast = fast->next->next;
    }

    /* If we reach here, fast pointer reached the end, so there's no cycle */
    return (0);
}
