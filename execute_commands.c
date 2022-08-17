#include "monty.h"

/**
 *
 *
 *
 */

void open_and_read(char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	FILE *fp;
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	ssize_t line_size;
	unsigned int counter = 1;
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_size = getline(&buf, &len, fp)) != -1)
	{
		token = strtok(buf, "\n\t\r ");
		if (*token == '\0')
			continue;
		strcpy(command,token);
		if (found_comment(token, counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL || found_number(token) == -1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", counter);
                		exit(EXIT_FAILURE);
			}
			number = atoi(token);
			p_func = get_op_code(command, counter);
			p_func(&top, counter);
		}
		else
		{
			p_func = get_op_code(command, counter);
                        p_func(&top, counter);
		}
		counter++;
	}
	fclose(fp);
	if(buf != NULL)
		free(buf);
	free(top);
}

/** error handle separate fuctions to create than add error handeler functions here */
/**
 *
 *
 *
 */

int found_number(char *token)
{
	int i = 0;

	if (token == NULL)
		return (-1);
	while (token[i])
	{
		if (token[i] != '-' && isdigit(token[i] == 0))
			return (-1);
		i++;
	
	}
	return (1);
}
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

