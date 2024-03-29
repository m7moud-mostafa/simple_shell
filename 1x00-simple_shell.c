#include "shell.h"

/**
 * main - main functions
 * @ac: number of arguments
 * @av: arguments vector
 * @env: environment variables
 * Return: EXIT_FAILURE when failure
 *		   0 when success
 */
int main(int ac, char **av, char **env)
{
	if (isatty(STDIN_FILENO))
		interactive_mode(ac, av, env);
	else
		non_interactive_mode(av, env);
	return (0);
}

/**
 * interactive_mode - Handles the shell in interactive mode
 * @ac: number of arguments
 * @av: arguments vector
 * @env: environment variables
 */
void interactive_mode(int ac, char **av, char **env)
{
	int status;
	char **argv;
	int (*command)(char **, char**);
	int i = 1;

	if (!av || !env)
		exit(EXIT_FAILURE);
	if (ac > 1)
	{
		command = get_command(av[1]);
		status = (command)(av + 1, env);
		if (status == -1)
		{
			_printf("%s: %i: %s: not found\n", av[0], i, av[1]);
			status = 127;
		}
		else if (status == 2)
			_printf("%s: %i:exit: Illegal number: %s\n", av[0], i, av[2]);
		i++;
	}
	while (1)
	{
		argv = get_user_input();
		if (!argv)
			exit(EXIT_FAILURE);

		command = get_command(argv[0]);
		status = command(argv, env);
		if (status == -1)
		{
			_printf("%s: %i: %s: not found\n", av[0], i, argv[0]);
			status = 127;
		}
		else if (status == 2)
			_printf("%s: %i:exit: Illegal number: %s\n", av[0], i, argv[1]);

		free_strings_array(argv);
		i++;
	}
}

/**
 * non_interactive_mode - Handles the shell in non-interactive mode
 * @av: arguments vector
 * @env: environment variables
 */
void non_interactive_mode(char **av, char **env)
{
	char *command_string = NULL;
	size_t n = 0;
	ssize_t n_chars = 0;
	char **argv;
	int i = 1;
	int (*command)(char **, char**);
	int status;

	while ((n_chars = getline(&command_string, &n, stdin)) != -1)
	{

		argv = string_splitter(command_string, ' ');
		if (!argv)
		{
			free(command_string);
			exit(EXIT_FAILURE);
		}

		command = get_command(argv[0]);
		status = command(argv, env);
		if (status == -1)
		{
			_printf("%s: %i: %s: not found\n", av[0], i, argv[0]);
			status = 127;
		}

		else if (status == 2)
			_printf("%s: %i:exit: Illegal number: %s\n", av[0], i, argv[1]);
		free_strings_array(argv);
		i++;
	}
	free(command_string);
	exit(status);
}
