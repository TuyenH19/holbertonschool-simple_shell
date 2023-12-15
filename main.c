#include "shell.h"

char *read_line(void);
int create_new_process(char *command, char **args);

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
		printf("#cisfun$ ");
		line = read_line();
		command = strtok(line, "\n");
		status = create_new_process(command, argv);

		free(line);
		if (status > 0)
			exit(status);
	} while (status == -1);
	return (0);
}

/**
 * read_line - read the line input
 *
 * Return: the line
*/
char *read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;

	if (getline(&line, &buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("cannot read the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

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
