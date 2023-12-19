#include "shell.h"

/**
 * get_args - get arguments from terminal input
 * @input: input from terminal
 *
 * Return: pointer that points to the new array
 */
char **get_args(char *input)
{
	int buffsize = 64;
	int index = 0;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token = NULL;

	if (tokens == NULL)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;

		tokens[index] = token;
		index++;

		if (index >= buffsize)
		{
			buffsize += buffsize;
			tokens = realloc(tokens, buffsize * sizeof(char *));
			if (tokens == NULL)
			{
				fprintf(stderr, "reallocation error in split_line: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}
