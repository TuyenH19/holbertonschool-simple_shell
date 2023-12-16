#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @ac: number of arguments
 * @argv: arguments
 *
 * Return: Nothing
*/
int main(int ac, char **argv)
{
	char *line;
	char *command;
	int status = -1;

	(void)ac;

	do {
		printf("$$ ");
		line = read_line();
		command = strtok(line, "\n");
		status = create_new_process(command, argv);

		free(line);
		if (status > 0)
			exit(status);
	} while (status == -1);
	return (0);
}
