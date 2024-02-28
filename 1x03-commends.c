#include "shell.h"

/**
* get_command - Selects the correct function to perform
*				 the command asked by the user.
*
* @s: The command passed as argument.
* Return: A pointer to a function that takes two arrays of strings as arguments
*		   If no matching operation is found,
*		   exec function is returned.
*/
int (*get_command(char *s))(char **, char **)
{
	fun_t commands[] = {
		{"exit", __exit},
		{"env", env},
		{NULL, NULL}
	};
	int i = 0;

	while (commands[i].call != NULL && !_strcmp(commands[i].call, s))
		i++;

	if (commands[i].call == NULL)
		return (exec);

	return (commands[i].f);
}


/**
 * __exit - exits with code
 *
 * @argv: Arguments
 * @env: Environment variables
 * Return: -1 for failure
 */
int __exit(char **argv, __attribute__((unused)) char **env)
{
	if (argv == NULL)
		exit(EXIT_FAILURE);

	if (argv[1] == NULL)
		exit(0);

	exit(atoi(argv[1]));

	return (-1);
}


/**
 * env - prints environment variables
 *
 * @argv: Arguments
 * @env: Environment variables
 * Return: -1 for Failure
 */
int env(char **argv, char **env)
{
	int i = 0;

	if (!argv)
		return (-1);

	if (!env)
		return (0);

	while (env[i] != NULL)
	{
		_printf("%s\n", env[i]);
		i++;
	}
	return (0);

}
