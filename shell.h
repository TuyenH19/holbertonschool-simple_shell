#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define TOK_DELIM " \n"
extern char **environ;

void shell_interactive(void);
void shell_no_interactive(void);

char *read_input(void);
char *read_stream(void);
char **get_args(char *input);
int create_new_process(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int run_execute(char **args);

char *find_executable(char *program);

#endif
