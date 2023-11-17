#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * appendNode - Appends a new node at the end of the doubly link list.
 * @head: Head pointer.
 * @n: Integer.
 *
 * Return: Pointer to the newly appended node.
 */

stack_t *appendNode(stack_t **head, const int n)
{
	stack_t *new_node, *last_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	new_node->next = last_node->next;
	new_node->prev = last_node;
	last_node->next = new_node;
	return (last_node->next);
}

/**
 * prependNode - Prepends a new node with the given data at
 * the beginning of the doubly linked list.
 * @head: Head pointer.
 * @n: Integer.
 *
 * Return: Pointer to the newly prepended node.
 */

stack_t *prependNode(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_gvar();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	(*head)->prev = new_node;
	new_node->next = (*head);
	new_node->prev = NULL;
	*head = new_node;
	return (*head);
}

/**
 * freeList - Frees a doubly linked list.
 * @head: Head pointer.
 *
 * Return: None
 */

void freeList(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
