#ifndef _MONTY_H
#define _MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int number;

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

void open_and_read(char **argv);
int found_number(char *token);
int found_comment(char *token, int counter);
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int);
void push_stack(stack_t **top, unsigned int line);
void pall_stack(stack_t **top, unsigned int line);
void pint_stack(stack_t **top, unsigned int line);
void pop_stack(stack_t **top, unsigned int line);
void free_stack(stack_t **top);
void _swap(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);

#endif
