#include "monty.h"
/*
 *
 */
void push_stack(stack_t **top, __attribute__ ((unused)) unsigned int line)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		error();

	new->n = number;
	new->prev = NULL;

	if (*top == NULL)
	{
		new->next = NULL;
		*top = new;
	}
	else
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
}


