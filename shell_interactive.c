#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 */
void shell_interactive(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = -1;

	do {
		printf("$ ");
		line = read_line();
		args = split_line(line)
		status = execute_args(args);

		free(line);
		free(args);

		if (status >= 0)
			exit(status);

	} while (status == -1);
}
