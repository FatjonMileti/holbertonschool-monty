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

/*
 *
 */
void pall_stack(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;
	
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/*
 *
 */
void pint_stack(stack_t **top, __attribute__((unused)) unsigned int line)
{
	if (*top != NULL)
		printf("%d\n", (*top)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
}

/*
 *
 */

void pop_stack(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
