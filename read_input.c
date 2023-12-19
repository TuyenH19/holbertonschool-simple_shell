#include"shell.h"

/**
 * read_input - read the input
 *
 * Return: the input
*/
char *read_input(void)
{
	char *input = NULL;
	size_t buffer = 0;

	if (getline(&input, &buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("cannot read the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
