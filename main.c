#include "shell.h"

/**
 * main - UNIX command line interpreter
 *
 * Return: Nothing
*/
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}
	else
	{
		shell_no_interactive();
	}
	return (0);
}
