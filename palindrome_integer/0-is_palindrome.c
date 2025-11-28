#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer
 *                 is a palindrome
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	/* Sauvegarde du nombre original pour la comparaison finale */
	unsigned long original = n;
	/* Variable qui contiendra le nombre inversé */
	unsigned long reversed = 0;

	/* Boucle pour inverser les chiffres du nombre */
	/*
	 * Exemple avec n = 121 :
	 * ┌──────────┬─────────┬─────────┬──────────────────────┬─────────┐
	 * │Itération │ n avant │ n % 10  │ reversed calcul      │ n après │
	 * ├──────────┼─────────┼─────────┼──────────────────────┼─────────┤
	 * │    1     │   121   │    1    │ 0*10 + 1 = 1         │   12    │
	 * │    2     │    12   │    2    │ 1*10 + 2 = 12        │    1    │
	 * │    3     │     1   │    1    │ 12*10 + 1 = 121      │    0    │
	 * └──────────┴─────────┴─────────┴──────────────────────┴─────────┘
	 * Résultat : reversed = 121, original = 121 → Palindrome !
	 */
	while (n > 0)
	{
		/* Décale reversed d'une position et ajoute le dernier chiffre de n */
		reversed = reversed * 10 + (n % 10);
		/* Supprime le dernier chiffre de n */
		n = n / 10;
	}

	/* Compare le nombre original avec le nombre inversé */
	if (original == reversed)
		return (1); /* C'est un palindrome */
	else
		return (0); /* Ce n'est pas un palindrome */
}