#include"shell.h"

/**
 * create_new_process - create new child process
 * @command: the command input
 * @args: arguments
 *
 * Return: -1 if process finish
*/
int create_new_process(char *command, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		perror("cannot create child process");
	else if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
			perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
