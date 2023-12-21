#include "shell.h"

/**
 * shell_no_interactive - unix command line interpreter
 * @prog_name: program name (argv[0])
 *
 * Return: Nothing
 */
void shell_no_interactive(char *prog_name)
{
	char *input = NULL;
	char **args = NULL;
	int status = -1;

	do {
		input = read_stream(prog_name);
		args = get_args(input);
		status = run_execute(prog_name, args);

		free(input);
		free(args);

		if (status == 0)
			exit(EXIT_SUCCESS);

	} while (status == -1);
}
