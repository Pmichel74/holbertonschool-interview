#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * test_palindrome - teste si une liste est un palindrome et affiche le résultat
 * @head: pointeur vers la tête de liste
 * @test_name: nom du test
 * @expected: résultat attendu
 */
void test_palindrome(listint_t **head, char *test_name, int expected)
{
    printf("\n=== %s ===\n", test_name);
    printf("Liste: ");
    print_listint(*head);
    
    int result = is_palindrome(head);
    printf("Résultat: %d (attendu: %d) ", result, expected);
    
    if (result == expected)
        printf("✓ SUCCÈS\n");
    else
        printf("❌ ÉCHEC\n");
}

int main(void)
{
    listint_t *head;

    printf("🧪 TESTS COMPLETS DU PALINDROME\n");
    printf("================================\n");

    /* Test 1: Liste vide */
    head = NULL;
    test_palindrome(&head, "Liste vide", 1);

    /* Test 2: Un seul élément */
    head = NULL;
    add_nodeint_end(&head, 42);
    test_palindrome(&head, "Un élément [42]", 1);
    free_listint(head);

    /* Test 3: Deux éléments identiques */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 1);
    test_palindrome(&head, "Deux identiques [1,1]", 1);
    free_listint(head);

    /* Test 4: Deux éléments différents */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    test_palindrome(&head, "Deux différents [1,2]", 0);
    free_listint(head);

    /* Test 5: Palindrome impair */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 1);
    test_palindrome(&head, "Palindrome impair [1,2,1]", 1);
    free_listint(head);

    /* Test 6: Non-palindrome impair */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    test_palindrome(&head, "Non-palindrome impair [1,2,3]", 0);
    free_listint(head);

    /* Test 7: Palindrome pair */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 1);
    test_palindrome(&head, "Palindrome pair [1,2,2,1]", 1);
    free_listint(head);

    /* Test 8: Palindrome long */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 1);
    test_palindrome(&head, "Palindrome long [1,2,3,2,1]", 1);
    free_listint(head);

    /* Test 9: Test de Holberton */
    head = NULL;
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 1);
    test_palindrome(&head, "Test Holberton [1,17,972,50,98,98,50,972,17,1]", 1);
    free_listint(head);

    printf("\n🎯 TESTS TERMINÉS !\n");
    return (0);
}