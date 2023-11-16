#include "monty.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: (0) if s1 and s2 are equals,(-1) if not.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
