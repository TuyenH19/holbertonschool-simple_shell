#include"shell.h"
/**
 * read_stream - read the input from a stream
 *
 * Return: input from terminal
*/
char *read_stream(void)
{
	int bufsize = 1024, i = 0, character;
	char *input = malloc(sizeof(char) * bufsize);

	if (input == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
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
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
