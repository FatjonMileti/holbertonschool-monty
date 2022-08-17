#include "monty.h"

/**
 * open_and_read - function that opens, reads & executes given commands
 * @argv: arguments received
 * Return: no return
 */

void open_and_read(char **argv)
{
	FILE *fp;
	char *buf = NULL, *token = NULL, *n;
	size_t len = 0;
	ssize_t line_size;
	unsigned int counter;
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	counter = 0;
	while ((line_size = getline(&buf, &len, fp)) != -1)
	{
		counter++;
		token = strtok(buf, "\n\t\r ");

		if (token == NULL || strncmp(token, "#", 1) == 0)
			continue;
		if (strcmp(token, "push") == 0)
		{
			n = strtok(NULL, "\n\t\r ");
			push_stack(&top, counter, n);
		}
		else
			get_op_code(token, &top, counter);
	}
	fclose(fp);
	if (buf != NULL)
		free(buf);
	free_stack(&top);
}
