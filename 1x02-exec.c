#include "shell.h"

/**
 * exec - executes a file
 *
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: -1 when failure
 *		   status when success
 */
int exec(char **argv, char **env)
{
	int is_executed;
	char *path_command;
	pid_t pid;
	int status;

	if (!argv)
		return (-1);

	if (!argv[0])
		return (-1);

	path_command = get_command_path(argv[0], env);
	if (!path_command)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		free(path_command);
		return (-1);
	}

	if (pid == 0)
	{
		is_executed = execve(path_command, argv, env);
		if (is_executed == -1)
		{
			free(path_command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(path_command);
		if (status == EXIT_FAILURE)
			return (-1);

		return (status);
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
	char **var_value; /** var_value[0] = variable name,
						* var_value[1] = variable value
						*/
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
			value = _strdup(var_value[1]);
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
 *		   THE RETURNED VALUE SHOULD BE FREED
 */
char *get_command_path(char *command, char **env)
{
	char *path_value;
	char **paths;
	char *path_to_command;
	int i;
	struct stat statbuf;
	int stat_return;

	if (!env || !command)
		return (NULL);

	stat_return = stat(command, &statbuf);
	if (stat_return != -1)
	{
		path_to_command = _strdup(command);
		if (!path_to_command)
			return (NULL);

		return (path_to_command);
	}

	path_value = get_env_variable("PATH", env);
	if (!path_value)
		return (NULL);

	paths = string_splitter(path_value, ':');
	free(path_value);

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
