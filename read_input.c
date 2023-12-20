#include"shell.h"

/**
 * read_input - read the input
 * @prog_name: program name (argv[0])
 * Return: the input
*/
char *read_input(char *prog_name)
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
			fprintf(stderr, "%s: 1: cannot read the line from stdin\n", prog_name);
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
