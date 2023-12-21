#include "shell.h"

char *_getenv(const char *name);

/**
 * find_executable - find the full path of an executable
 * @program: the name of the program to find
 *
 * Return: full path of the executable or NULL if not found
 */
char *find_executable(char *program)
{
	char *path = _getenv("PATH");
	char *path_copy = strdup(path);
	char *directory = strtok(path_copy, ":");
	char *full_path = malloc(1024 * sizeof(char));

	if (full_path == NULL)
	{
		free(path_copy);
		return (NULL);
	}

	while (directory != NULL)
	{
		sprintf(full_path, "%s/%s", directory, program);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		directory = strtok(NULL, ":");
	}
	free(path_copy);
	free(full_path);

	return (NULL);
}

/**
 * _getenv - get the environment variable
 * @name: path name
 *
 * Return: environement
*/
char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *token;

	i = 0;
	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}
