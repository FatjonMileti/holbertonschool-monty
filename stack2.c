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

