#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>     /* For fflush, getline, perror */
#include <stdlib.h>    /* For malloc, free, exit */
#include <unistd.h>    /* For access, chdir, close, execve, _exit, fork, getcwd, getpid, isatty, read, write */
#include <sys/types.h> /* For open, stat, lstat, fstat, wait, waitpid, wait3, wait4 */
#include <sys/stat.h>  /* For stat, lstat, fstat */
#include <fcntl.h>     /* For open */
#include <dirent.h>    /* For opendir, readdir, closedir */
#include <signal.h>    /* For signal, kill */
#include <string.h>    /* For strtok */
#include <sys/wait.h>  /* For wait, waitpid, wait3, wait4 */
#include "main.h"      /* For _printf */


/**
 * struct function - A structure that connects the function name with
 *					 it's string
 *
 * @call: The String with which the function get called
 * @f: The function associated
 */
typedef struct function
{
	char *call;
	int (*f)(char **, char **);
} fun_t;

char **get_user_input();
char **string_splitter(char *string, char separator);
void free_strings_array(char **strings_array);
char *extract_word(char *str, int *i, char sep);

void exec(char **argv, char **env);
void __exit(char **argv, char **env);
void (*get_command(char *s))(char **, char **);
void env(char **argv, char **env);
char *get_env_variable(char *var, char **env);
char *get_command_path(char *command, char **env);
#endif
