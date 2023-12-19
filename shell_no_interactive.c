#include "shell.h"

/**
 * shell_no_interactive - unix command line interpreter
 *
 */
void shell_no_interactive(void)
{
	char *input = NULL;
	char **args = NULL;
	int status = -1;

	do {
		input = read_stream();
		args = get_args(input);
		status = run_execute(args);

		free(input);
		free(args);

		if (status >= 0)
			exit(status);

	} while (status == -1);
}
