#include"shell.h"

/**
 * read_line - read the line input
 *
 * Return: the line
*/
char *read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;

	if (getline(&line, &buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("cannot read the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
