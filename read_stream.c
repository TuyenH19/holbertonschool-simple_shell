#include"shell.h"
/**
 * read_stream - read the input from a stream
 * @prog_name: program name (argv[0])
 * Return: input from terminal
*/
char *read_stream(char *prog_name)
{
	int bufsize = 1024, i = 0, character;
	char *input = malloc(sizeof(char) * bufsize);

	if (input == NULL)
	{
		fprintf(stderr, "%s: 1: allocation error in read_stream\n", prog_name);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();
		if (character == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
			input[i] = character;
		i++;

		if (i >= bufsize)
		{
			bufsize *= 2;
			input = realloc(input, bufsize * sizeof(char));
			if (input == NULL)
			{
				fprintf(stderr, "%s: 1: reallocation error in read_stream\n", prog_name);
				exit(EXIT_FAILURE);
			}
		}
	}
}
