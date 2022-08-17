#include "monty.h"

/**
 * _pchar - Function that prints character at the top of stack
 * @top: top element
 * @line: line number
 * Return: no return
 *
 */
void _pchar(stack_t **top, unsigned int line)
{
	int num;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	num = (*top)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar('\n');
}
/**
 * _pstr - Function that prints the string at the top of stack
 * @top: pointer to the top of stack
 * @line: line nummber(unused in this case) but neccessary as a second func par
 * Return: no return
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
 * _mul - function that multiplies the top element of stack with the second top
 * @top: top element
 * @line_number: number of lines
 * Return: no return
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
 * _mod - Function that gives the module off the second top element from the
 * first top
 * element of the stack
 * @top: top element
 * @line_number: number of lines
 * Return: no return
 */

void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || ((*top)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*top)->next;
	temp->n %= (*top)->n;
	pop_stack(top, line_number);
}
