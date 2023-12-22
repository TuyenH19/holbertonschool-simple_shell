#include"shell.h"

/**
 * create_new_process - create new child process
 * @prog_name: program name (argv[0])
 * @args: arguments
 *
 * Return: -1 if process finish
*/
int create_new_process(char *prog_name, char **args)
{
	pid_t pid;
	int status;
	char *executable_path;

	pid = fork();
	if (pid < 0)
		perror("cannot create child process");
	else if (pid == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			executable_path = args[0];
		}
		else
		{
			executable_path = find_executable(args[0]);
			if (executable_path == NULL)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
				exit(EXIT_FAILURE);
			}
		}
		if (execve(executable_path, args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: cannot execute the path\n", prog_name, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
