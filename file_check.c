#include "monty.h"

/**
 * file_check - checks if the file exists and if the file can
 * be opened.
 * @ac: Number of params
 * @av: Array of params
 *
 * Return: file struct
 */

FILE *file_check(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
