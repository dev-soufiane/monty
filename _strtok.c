#include "monty.h"

/**
 * _strtok - Splits a string into tokens.
 * @str: String.
 * @d: Delimiter.
 *
 * Return: First part of the string.
 */

char *_strtok(char *str, char *d)
{
	static char *x;
	int i = 0, j = 0;

	if (!str)
		str = x;
	while (str[i] != '\0')
	{
		if (_search(d, str[i]) == 0 && str[i + 1] == '\0')
		{
			x = str + i + 1;
			*x = '\0';
			str = str + j;
			return (str);
		}
		else if (_search(d, str[i]) == 0 && _search(d, str[i + 1]) == 0)
			i++;
		else if (_search(d, str[i]) == 0 && _search(d, str[i + 1]) == 1)
		{
			x = str + i + 1;
			*x = '\0';
			x++;
			str = str + j;
			return (str);
		}
		else if (_search(d, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
