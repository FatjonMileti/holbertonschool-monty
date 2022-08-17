#include "monty.h"
/*
 *
 */
void push_stack(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	(void) line_number;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = number;
	newNode->prev = NULL;
	if (*top == NULL)
	{
		newNode->next = NULL;
		*top = newNode;
	}
	else 
	{
	newNode->next = *top;
	(*top)->prev = newNode;
	*top = newNode;
	}
}

/*
 *
 */
void pall_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	(void)line_number;

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

void free_stack(stack_t **top)
{
	stack_t *tmp;
	if (*top == NULL)
		return;

	while(*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}
