#include "monty.h"

/**
 *
 *
 *
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
 *
 *
 *
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
 *
 *
 *
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
 *
 *
 *
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
 *
 *
 *
 */

void _nop(__attribute__((unused))stack_t **top, __attribute__((unused))unsigned int line_number)
{

}
