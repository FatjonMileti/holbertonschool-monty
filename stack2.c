#include "monty.h"

/**
 * _swap - Function that swaps the fist 2 elements os a stack
 * @top: top element
 * @line_number: number of lines
 * Return: no return
 */

void _swap(stack_t **top, unsigned int line_number)
{
	int nr;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	nr = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = nr;
}

/**
 * _add - Function that adds 2 top elements of the stack
 * @top: top element
 * @line_number: number of lines
 * Return: no return
 */

void _add(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n += (*top)->n;
	pop_stack(top, line_number);
}

/**
 * _sub - Function that substacts the firt top element form the second top
 * @top: top element
 * @line_number: number of lines
 * Return: no return
 */

void _sub(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n -= (*top)->n;
	pop_stack(top, line_number);
}

/**
 * _div - Function that devides the first top element of stack by second
 * @top: top element
 * @line_number: number oof lines
 * Return: no return
 */

void _div(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n /= (*top)->n;
	pop_stack(top, line_number);
}

/**
 * _nop - Function that does nothing
 * @top: top element unused
 * @line_number: number of lines unused
 * Return: no return
 */

void _nop(__attribute__((unused))stack_t **top, unsigned int line_number)
{
	(void)line_number;
}
