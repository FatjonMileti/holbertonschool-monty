#include "monty.h"
/**
 * get_op_code - function that will perform the operation
 * @token: operation code
 * @line: line readed
 * Return: void
 */
int get_op_code(char *token,stack_t **top, unsigned int line)
{
	int i;
	instruction_t operation[] = {
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(token, operation[i].opcode) == 0)
		{
			(operation[i].f)(top, line);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}
