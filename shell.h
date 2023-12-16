#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;
char *read_line(void);
int create_new_process(char *command, char **args);
int builtin_exit(char **args);
int builtin_env(char **args);

#endif