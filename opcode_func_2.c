#include "monty.h"

/**
 * _swap - Swaps top two elements on the Stack.
 * @head: Head pointer.
 * @line_number: Line number.
 *
 * Return: None.
 */

void _swap(stack_t **head, unsigned int line_number)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *head;

	for (; temp != NULL; temp = temp->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_gvar();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}

/**
 * _queue - Format DATA to the Queue (FIFO).
 * @head: Head pointer.
 * @line_number: Line-Number.
 *
 * Return: None.
 */

void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	gvar.soq = 0;
}

/**
 * _stack - Format data to the Stack LIFO.
 * @head: Head pointer.
 * @line_number: Line-Number.
 *
 * Return: None.
 */

void _stack(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;

	gvar.soq = 1;
}

/**
 * _add - Adds top TWO elementson the stack;
 * @head: Head pointer.
 * @line_number: Line-Number.
 *
 * Return: None.
 */

void _add(stack_t **head, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = NULL;

	tmp = *head;

	for (; tmp != NULL; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_gvar();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n += (*head)->n;
	_pop(head, line_number);
}

/**
 * _nop - This function doesn't do anything.
 * @head: Head pointer.
 * @line_number: Line number.
 *
 * Return: None.
 */

void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
