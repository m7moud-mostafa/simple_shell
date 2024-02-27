#include "shell.h"

/**
* get_command - Selects the correct function to perform
*				 the command asked by the user.
*
* @s: The command passed as argument.
* Return: A pointer to a function that takes two arrays of strings as arguments
*		   If no matching operation is found,
*		   NULL is returned.
*/
void (*get_command(char *s))(char **, char **)
{
	fun_t commands[] = {
		{"exit", __exit},
		{"env", env},
		{NULL, NULL}
	};
	int i = 0;

	while (commands[i].call != NULL && *(commands[i].call) != *s)
		i++;

	if (commands[i].call == NULL || s[1] != '\0')
		return (exec);

	return (commands[i].f);
}


/**
 * __exit - exits with code
 *
 * @argv: Arguments
 * @env: Environment variables
 */
void __exit(char **argv, char **env)
{
	if (argv == NULL)
		exit(EXIT_FAILURE);

	if (argv[1] == NULL)
		exit(0);

	exit(atoi(argv[1]));
}


/**
 * env - prints environment variables
 *
 * @argv: Arguments
 * @env: Environment variables
 */
void env(char **argv, char **env)
{
	pid_t pid;
	int i = 0;

	if (!env)
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("error with creating process\n");
		return;
	}

	if (pid == 0)
	{
		while (env[i] != NULL)
		{
			_printf("%s\n", env[i]);
		}
	}
	else
		wait(NULL);
}
