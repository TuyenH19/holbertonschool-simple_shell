#include"shell.h"

/**
 * run_execute - to execute the program
 * @args: arguments from terminal
 *
 * Return: status
*/
int run_execute(char **args)
{
	char *builtin_func_list[] = {
		"exit",
		"env"
	};
	int (*builtin_func[])(char **) = {
		&builtin_exit,
		&builtin_env
	};
	unsigned int i = 0;

	if (args[0] == NULL)
		return (-1);
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_func_list[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (create_new_process(args));
}
