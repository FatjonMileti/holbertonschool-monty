#include "monty.h"
/**
 * push_stack - Function that adds a node at the top of a list
 * @top: top element
 * @line_number: number of lines
 * @token: character used to devide
 * Return: no return
 */

void push_stack(stack_t **top, unsigned int line_number, char *token)
{
	stack_t *newNode;
	int i;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-' && i == 0)
			continue;
		if (isdigit(token[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(token);
	newNode->prev = NULL;
	newNode->next = NULL;
	if (*top != NULL)
	{
		newNode->next = *top;
		(*top)->prev = newNode;
	}
	*top = newNode;
}

/**
 * pall_stack - function that prints all elements of a stack
 * @top: top element
 * @line_number: number of lines
 * Return: no return
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

/**
 * pint_stack - Function that prints top element of the stack
 * @top: first element
 * @line: number of lines
 * Return: no return
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

/**
 * pop_stack - Function that deletes the first element of the stack
 * @top: top element
 * @line: number of lines, unused in this case
 * Return: no return
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

/**
 * free_stack - Function that frees the given list
 * @top: first element of stack also known as head
 * Return: no return
 */
void free_stack(stack_t **top)
{
	stack_t *tmp;

	if (*top == NULL)
		return;

	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}
