#include "main.h"

/**
 * _strlen - a function that calculates the length of a string.
 *
 * @str: string
 * Return: length of the string
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * power - calculates base ^ exponent
 *
 * @base: the base
 * @exponent: the exponent
 * Return: int
 */
int power(int base, int exponent)
{
	int result = 1;

	while (exponent > 0)
	{
		result *= base;
		--exponent;
	}
	return (result);
}


/**
 * _strcmp - compares between two strings
 *
 * @str1: first string
 * @str2: second string
 * Return: 0 if they are not the same
 *		   1 if they are the same
 */
char _strcmp(char *str1, char *str2)
{
	char is_same;
	int len1;
	int len2;
	int i;

	if (!str1 || !str2)
		return (0);

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	if (len1 != len2)
		return (0);

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (0);
	}
	return (1);

}


/**
 * _strcat_command - adds str2 to str1
 *
 * @str1: First string
 * @str2: Second string
 * Return: final string (THE RETURNED STRING SHOULD BE FREED)
 */
char *_strcat_command(char *str1, char *str2)
{
	char *full_string;
	int len1;
	int len2;
	int i;
	int j;

	if (!str1)
		return (NULL);

	if (!str2)
		return (str1);

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	full_string = malloc(len1 + len2 + 2);
	if (!full_string)
		return (NULL);

	for (i = 0; i < len1; i++)
		full_string[i] = str1[i];

	full_string[i++] = '/';
	for (j = 0; j <= len2; j++)
		full_string[i + j] = str2[j];
	full_string[len1 + len2 + 1] = '\0';
	return (full_string);
}


/**
 * _strdup - Duplicates the string
 *
 * @str: string
 * Return: duplicated string
 */


char *_strdup(char *str)
{
	int len;
	char *pointer;
	int i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	pointer = malloc(len + 1);

	if (pointer == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		pointer[i] = str[i];

	return (pointer);
}
