#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 */
void shell_interactive(void)
{
	char *input = NULL;
	char **args = NULL;
	int status = -1;

	do {
		printf("($) ");
		input = read_input();
		args = get_args(input);
		status = run_execute(args);

		free(input);
		free(args);

		if (status == 0)
			exit(EXIT_SUCCESS);

	} while (status == -1);
}
