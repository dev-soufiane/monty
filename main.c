#include "monty.h"

globs gvar;

/**
 * free_gvar - Frees the global variables.
 *
 * Return: None.
 */

void free_gvar(void)
{
	freeList(gvar.head);
	free(gvar.buff);
	fclose(gvar.fd);
}

/**
 * start_gvar - Initializes the global variables.
 * @fd: File descriptor.
 *
 * Return: None.
 */

void start_gvar(FILE *fd)
{
	gvar.soq = 1;
	gvar.cl = 1;
	gvar.param = NULL;
	gvar.head = NULL;
	gvar.fd = fd;
	gvar.buff = NULL;
}

/**
 * main - The entry point.
 * @ac: Number of args.
 * @av: Array of args.
 *
 * Return: Returns (0) on success.
 */

int main(int ac, char *av[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	char *rows[2] = {NULL, NULL};
	ssize_t num_rows = 0;
	size_t size = 256;

	fd = file_check(ac, av);
	start_gvar(fd);
	num_rows = getline(&gvar.buff, &size, fd);
	while (num_rows != -1)
	{
		rows[0] = _strtok(gvar.buff, " \t\n");
		if (rows[0] && rows[0][0] != '#')
		{
			f = find_opcode(rows[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", gvar.cl);
				dprintf(2, "unknown instruction %s\n", rows[0]);
				free_gvar();
				exit(EXIT_FAILURE);
			}
			gvar.param = _strtok(NULL, " \t\n");
			f(&gvar.head, gvar.cl);
		}
		num_rows = getline(&gvar.buff, &size, fd);
		gvar.cl++;
	}
	free_gvar();
	return (0);
}
