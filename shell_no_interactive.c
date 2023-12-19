#include "shell.h"

/**
 * shell_no_interactive - unix command line interpreter
 *
 */
void shell_no_interactive(void)
{
	char *input = NULL;
	int status = -1;

	do {
		input = read_stream();
		status = run_execute(input);

		free(input);

		if (status >= 0)
			exit(status);

	} while (status == -1);
}
