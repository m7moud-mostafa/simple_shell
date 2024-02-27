#include "shell.h"

/**
 * main - main functions
 * 
 */
int main(int ac, char **av, char **env)
{
	pid_t pid;
	int status;
	char **argv;

	if (!av || !env)
		return (1);

	if (ac > 1)
	{
		pid = fork();
		if (pid == -1)
			return (EXIT_FAILURE);
		if (pid == 0)
			exec(av + 1, env);
		else
			wait(&status);
	}

	while (1)
	{
		argv = get_user_input();
		if (!argv)
		{
			perror("Invalid Input\n");
			continue;
		}
		if (_strcmp(argv[0], "exit"))
		{
			free_strings_array(argv);
			return (0);
		}

		pid = fork();
		if (pid == -1)
			return (EXIT_FAILURE);
		if (pid == 0)
		{
			exec(argv, env);
			free_strings_array(argv);
		}
		else
		{
			wait(&status);
			_printf("%i\n", status);
			free_strings_array(argv);
		}
	}
}