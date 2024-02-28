#include "shell.h"

/**
 * get_user_input - A function that asks a user to give command
 *					  and split it and put it in an array.
 *
 * Return: If Success - array of input strings that ends with NULL pointer
 *		   If Failure - NULL if failed.
 */
char **get_user_input()
{
	char *command_string = NULL;
	char *command_prompt = "($) ";
	size_t n = 0;
	ssize_t n_chars;
	char **arguments;

	_printf(command_prompt);

	n_chars = getline(&command_string, &n, stdin);
	if (n_chars == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			free(command_string);
			_printf("\n");
			exit(0);
		}
		else
		{
			free(command_string);
			return (NULL);
		}
	}
	arguments = string_splitter(command_string, ' ');
	if (!arguments)
	{
		free(command_string);
		perror("string splitter error");
		return (NULL);
	}
	free(command_string);
	return (arguments);
}


/**
 * string_splitter - A function that splits a string
 *
 * @str: The string to be splitted
 * @sep: The separator that is used for splitting
 * Return: array of strings (splitted)
 */

char **string_splitter(char *str, char sep)
{
	int i;
	int word_num = -1;
	int n_separator = 0;
	int string_length = 0;
	char **strings_array;
	char *s;

	if (!str)
		return (NULL);

	while (str[string_length] != '\0')
	{
		if (str[string_length] == sep)
			n_separator++;
		string_length++;
	}

	strings_array = malloc(sizeof(char *) * (n_separator + 2));
	if (!strings_array)
		return (NULL);

	for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
	{
		if (str[i] != sep)
		{
			word_num++;
			s = extract_word(str, &i, sep);
			if (!s)
			{
				free_strings_array(strings_array);
				return (NULL);
			}

			strings_array[word_num] = s;
		}
	}

	strings_array[word_num + 1] = NULL;
	return (strings_array);
}


/**
 * extract_word - extracts the individual words from spring
 *
 * @str: The long string
 * @i: Pointer to the Counter
 * @sep: The separator that is used for splitting
 * Return: The extracted word
 */

char *extract_word(char *str, int *i, char sep)
{
	int s_l = 0;
	char *s;
	int j;

	while (str[s_l + *i] != sep && str[s_l + *i] != '\n' && str[s_l + *i] != '\0')
		s_l++;

	s = malloc(sizeof(char) * (s_l + 1));
	if (!s)
		return (NULL);

	for (j = 0; j < s_l; j++)
	{
		s[j] = str[*i];
		(*i)++;
	}
	s[s_l] = '\0';
	return (s);
}


/**
 * free_strings_array - A function that frees an array of strings
 *
 * @strings_array: The array of strings to be freed
 */
void free_strings_array(char **strings_array)
{
	int i = 0;

	while (strings_array[i] != NULL)
	{
		free(strings_array[i]);
		i++;
	}

	free(strings_array);
}
