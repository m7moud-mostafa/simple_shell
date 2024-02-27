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
 * exec - executes a file
 *
 * @argv: array of arguments
 * @env: array of environment variables
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

/**
 * get_env_variable - Get the value of env variable
 * 
 * @var: the variable which its value should be returned
 * @env: Environment variables
 * Return: the value of the variable
 */
char *get_env_variable(char *var, char **env)
{
	int i;
	char **var_value; /* var_value[0] = variable name, var_value[1] = variable value */
	char *value;

	if (!env || !var)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		var_value = string_splitter(env[i], '=');
		if (var_value == NULL)
			return (NULL);

		if (_strcmp(var_value[0], var))
		{
			value = var_value[1];
			free_strings_array(var_value);
			return (value);
		}
		free_strings_array(var_value);
	}
	return (NULL);
}


/**
 * get_command_path - Get the path to command
 *
 * @command: the commend that is being looked for
 * @env: env variables
 * Return: path to command or NULL when failure
 */
char *get_command_path(char *command, char **env)
{
	char *path_value;
	char **paths;
	char *path_to_command;
	int i;
	struct stat statbuf;
	int stat_return;

	path_value = get_env_variable("PATH", env);
	if (!path_value)
		return (NULL);

	paths = string_splitter(path_value,':');

	for (i = 0; paths[i]; i++)
	{
		path_to_command = _strcat(paths[i], command);
		if (!path_to_command)
			return (NULL);

		stat_return = stat(path_to_command, &statbuf);
		if (stat_return == -1)
			free(path_to_command);
		else
			return (path_to_command);
	}
	return (NULL);
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
		while(env[i] != NULL)
		{
			_printf("%s\n", env[i]);
		}
	}
	else
		wait(NULL);
}
