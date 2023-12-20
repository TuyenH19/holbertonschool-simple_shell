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

void shell_interactive(char *prog_name);
void shell_no_interactive(char *prog_name);

char *read_input(char *prog_name);
char *read_stream(char *prog_name);
char **get_args(char *input);
int create_new_process(char *prog_name, char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int run_execute(char *prog_name, char **args);

char *find_executable(char *program);

#endif
