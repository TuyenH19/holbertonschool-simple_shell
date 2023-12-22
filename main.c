#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @ac: number of arguments
 * @argv: arguments
 *
 * Return: 0 on success
*/
int main(int ac, char *argv[])
{
	(void)ac;

	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive(argv[0]);
	}
	else
	{
		shell_no_interactive(argv[0]);
	}
	return (0);
}
