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
 * _atoi - convert a string to an integer.
 * @str: the string to convert
 * Return: the converted integer
*/
int _atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (-1);
		}
		res = res * 10 + str[i] - '0';
	}
	return (sign * res);
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
	int status = 0;

	if (argv[1] == NULL)
		exit(0);

    status = _atoi(argv[1]);
    if (status == -1)
	{
		return (2);
    }

    exit(status);
}


/**
 * env - prints environment variables
 *
 * @argv: Arguments
 * @env: Environment variables
 * Return: -1 for Failure
 */
int env(__attribute__((unused)) char **argv, char **env)
{
	int i = 0;

	if (!env)
		return (0);

	while (env[i] != NULL)
	{
		_printf("%s\n", env[i]);
		i++;
	}
	return (0);

}
