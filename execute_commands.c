#include "monty.h"

/**
 *
 *
 *
 */

void open_&_read(char **argv)
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
		open_error(argv);
	while ((line_size = getline(&buf, &len, fp)) != EOF)
	{
		token = strtok(buf, "\n\t\r ");
		if (!token)
			continue;
		strcpy(command,token);
		if (found_comment(token, counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL || found_number(token) == EOF)
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
		if token[i] != '-' && isdigit(token[i] == 0)
			i++;
		return (-1);
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

