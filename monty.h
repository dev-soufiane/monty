#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - Structure for global variables.
 * @soq: Stack or Queue.
 * @cl: Current Line.
 * @param: Second parameter.
 * @head: Head node.
 * @fd: File descriptor.
 * @buff: Buffer.
 */

typedef struct globals
{
	int soq;
	unsigned int cl;
	char  *param;
	stack_t *head;
	FILE *fd;
	char *buff;
} globs;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern globs gvar;

/* OPCODE FUNCTIONS PROTOTYPES */
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);

FILE *file_check(int ac, char *av[]);
void (*find_opcode(char *opc))(stack_t **stack, unsigned int line_number);

/* FREE GLOBAL VARIABLES FUNCTION */
void free_gvar(void);


/* STRING FUNCTIONS PROTOTYPES */
int _search(char *s, char c);
char *_strtok(char *str, char *d);
int _strcmp(char *s1, char *s2);

/* LNKED LIST FUNCTION PROTOTYPES */
stack_t *appendNode(stack_t **head, const int n);
stack_t *prependNode(stack_t **head, const int n);
void freeList(stack_t *head);

#endif
