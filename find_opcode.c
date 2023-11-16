#include "monty.h"

/**
 * find_opcode - Locates and returns the function
 * corresponding to the provided opcode.
 * @opcode: The opcode passed as a string.
 *
 * Return: Pointer to the function that executes the specified opcode.
 */

void (*find_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (_strcmp(instructions[i].opcode, opcode) == 0)
			break;
	}
	return (instructions[i].f);
}
