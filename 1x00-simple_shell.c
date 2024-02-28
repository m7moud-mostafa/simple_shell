#include "shell.h"

/**
 * main - main functions
 * @ac: number of arguments
 * @av: arguments vector
 * @env: environment variables
 * Return: EXIT_FAILURE
 */
int main(int ac, char **av, char **env)
{
	int status;
	char **argv;
	int (*command)(char **, char**);
	int i = 1;

	if (!av || !env)
	{
		perror("av or env inside tha main are NULL\n");
		return (EXIT_FAILURE);
	}
	if (ac > 1)
	{
		command = get_command(av[1]);
		status = (command)(av + 1, env);
		if (status == -1)
		{
			_printf("%s: %i: %s: not found\n", av[0], i, av[1]);
			status = 127;
		}
		i++;
	}
	while (1)
	{
		argv = get_user_input();
		if (!argv)
		{
			perror("argv inside the main is NULL\n");
			return (EXIT_FAILURE);
		}
		command = get_command(argv[0]);
		status = command(argv, env);
		if (status == -1)
		{
			_printf("%s: %i: %s: not found\n", av[0], i, argv[0]);
			status = 127;
		}
		free_strings_array(argv);
		i++;
	}
}
