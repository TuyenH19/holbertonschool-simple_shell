#include "shell.h"

int _get_builtin_index(char *command);

/**
 * main - UNIX command line interpreter
 * @ac: number of arguments
 * @argv: arguments
 *
 * Return: Nothing
*/
int main(int ac, char **argv)
{
	int (*builtin_func[])(char **) = {
		&builtin_exit,
		&builtin_env
	};

	char *line;
	char *command;
	int status = -1;
	int index;

	(void)ac;

	do {
		printf("$$ ");
		line = read_line();
		command = strtok(line, "\n");
		index = _get_builtin_index(command);
		if (index != -1)
			status = ((*builtin_func[index])(argv));
		else
			status = create_new_process(command, argv);

		free(line);
		if (status > 0)
			exit(status);
	} while (status == -1);
	return (0);
}

/**
 * _get_builtin_index - get index of builtin_list
 * @command: the command input
 *
 * Return: -1 if the command is not in builtin_list
*/
int _get_builtin_index(char *command)
{
	char *builtin_list[] = {
		"exit",
		"env"
	};

	unsigned int index;

	for (index = 0; index < sizeof(builtin_list); index++)
	{
		if (strcmp(command, builtin_list[index]) == 0)
			return (index);
	}
	return (-1);
}
