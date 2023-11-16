#include "monty.h"

/**
 * _search - Searches for a string.
 * @str: String.
 * @c: Char.
 *
 * Return: (1) if success, (0) if not.
 */

int _search(char *str, char c)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			break;
		}
		count++;
	}
	if (str[count] == c)
		return (1);
	else
		return (0);
}
