#include"shell.h"

int _get_builtin_index(char *command);

/**
 * run_execute - to execute the program
 * @input: input from terminal
 *
 * Return: status
*/
int run_execute(char *input)
{
	char **args = get_args(input);

	int (*builtin_func[])(char **) = {
		&builtin_exit,
		&builtin_env
	};
	int index = 0;
	char *command = args[0];

	if (command == NULL)
		return (-1);

	index = _get_builtin_index(command);
	if (index != -1)
		return ((*builtin_func[index])(args));
	else
		return (create_new_process(args));
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

	for (index = 0; index < sizeof(builtin_list) / sizeof(char *); index++)
	{
		if (strcmp(command, builtin_list[index]) == 0)
			return (index);
	}
	return (-1);
}
