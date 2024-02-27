#include "shell.h"

/**
 * 
 * 
 */
void exec(char **argv, char **env)
{
	int is_executed;
	if (!argv)
		exit(EXIT_FAILURE);

	is_executed = execve(argv[0], argv, env);

	if (is_executed == -1)
	{
		_printf("%s: No such file or directory\n", argv[0]);
		exit(EXIT_FAILURE);
	}
}