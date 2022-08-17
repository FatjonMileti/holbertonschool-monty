#include "monty.h"

/**
 *
 *
 *
 *
 */
void _pchar(stack_t **top, unsigned int line)
{
	int num;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	num = (*top)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	putchar((*top)->n);
	putchar('\n');
}
/*
 *
 */
void _pstr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	int str;
	stack_t *tmp;

	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		str = tmp->n;
		if (str <= 0 || str > 127)
			break;
		putchar(str);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 *
 *
 *
 */

void _mul(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n *= (*top)->n;
	pop_stack(top, line_number);
}

/**
 *
 *
 *
 */

void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n %= (*top)->n;
	pop_stack(top, line_number);
}
