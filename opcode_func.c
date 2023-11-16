#include "monty.h"

/**
 * _push - Adds an element to the Stack.
 * @head: Head pointer.
 * @line_number: Line number.
 *
 * Return: None
 */

void _push(stack_t **head, unsigned int line_number)
{
	int num, i;

	if (!gvar.param)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}
	for (i = 0; gvar.param[i] != '\0'; i++)
	{
		if (!isdigit(gvar.param[i]) && gvar.param[i] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_gvar();
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(gvar.param);

	if (gvar.soq == 1)
		prependNode(head, num);
	else
		appendNode(head, num);
}

/**
 * _pall - Prints all Stack values.
 * @head: Head pointer.
 * @line_number: Line number.
 *
 * Return: None
 */

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - Prints the first Stack's value.
 * @head: Head pointer.
 * @line_number: line number.
 *
 * Return: None.
 */

void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
	(void)line_number;
}

/**
 * _pop - Deletes the first Stack's element.
 * @head: Head pointer.
 * @line_number: Line number.
 *
 * Return: None.
 */

void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_gvar();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
