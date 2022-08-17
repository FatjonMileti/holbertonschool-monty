#include "monty.h"

/**
 *
 *
 *
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
		fprintf(stderr, "Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	counter = 0;
	while ((line_size = getline(&buf, &len, fp)) != -1)
	{
		counter++;
		token = strtok(buf, "\n\t\r ");

		/*strcpy(command,token);*/
		if (found_comment(token, counter) == 1)
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
	if(buf != NULL)
		free(buf);
	free_stack(&top);
}

/** error handle separate fuctions to create than add error handeler functions here */
/**
 *
 *
 *
 */

/**int found_number(char *token)
{
	int i;

	if (token == NULL)
	{
		fprintf (stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; token[i]; i++)
	{
		if (token[0] != '-' && i == 0)
			continue;
		if (isdigit(token[i]) == 0)
		{
			fprintf (stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	
	}
	return (1);
}
*/
/**
 *
 *
 *
 */
int found_comment(char *token, int counter)
{
	if (token == NULL || token[0] == '#')
	{
		counter++;
		return (1);
	}
	return (-1);
}

