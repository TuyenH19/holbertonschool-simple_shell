#include"shell.h"

/**
 * builtin_env - function print environment variables
 * @args: arguments
 * Return: -1 to back to prompt
*/
int builtin_env(char **args)
{
	int index = 0;
	(void)args;

	while (environ[index])
	{
		write(STDOUT_FILENO, environ[index], strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (-1);
}
