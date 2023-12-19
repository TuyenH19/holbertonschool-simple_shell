#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 */
void shell_interactive(void)
{
	char *input = NULL;
	int status = -1;

	do {
		printf("($) ");
		input = read_input();
		status = run_execute(input);

		free(input);

		if (status >= 0)
			exit(status);

	} while (status == -1);
}
