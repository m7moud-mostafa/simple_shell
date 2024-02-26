#include "main.h"

/**
 * handle_specifier - this function choses the appropriate specifier handler
 *
 * @specifier: the character after the % sign
 * @args: va_list arguments
 * @len: length character
 */
void handle_specifier(char specifier, va_list args, int *len)
{
	switch (specifier)
	{	case 'c':
			c_handler(va_arg(args, int), len);
			break;
		case 's':
			s_handler(va_arg(args, char *), len);
			break;
		case '%':
			c_handler('%', len);
			break;
		case 'd':
		case 'i':
			i_handler(va_arg(args, int), len);
			break;
		case 'u':
			u_handler(va_arg(args, int), len);
			break;
		default:
			c_handler('%', len);
			c_handler(specifier, len);
			break;
	}
}


/**
 * c_handler - handles the c specifier inside (_printf) function
 *			   and print single characters
 *
 * @c: character to be printed
 * @len: the printed length counter
 */
void c_handler(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

/**
 * s_handler - handles the s specifier inside
 *			   (_printf) function (prints strings)
 *
 * @str: string to be printed
 * @len: the printed length counter
 */
void s_handler(char *str, int *len)
{
	int string_len;

	if (str == NULL)
		str = "(null)";
	string_len = _strlen(str);
	write(1, str, string_len);
	(*len) += string_len;
}

/**
 * i_handler - handles the i and d specifier
 *
 * @num: the integer to be printed
 * @len: the printed length counter
 */
void i_handler(int num, int *len)
{
	int i;
	long tmp_num;
	int condition;
	int is_started = 0;
	char c;
	int level;

	tmp_num = num;

	if (num == 0)
	{
		c_handler('0', len);
		return;
	}
	if (num < 0)
	{
		c_handler('-', len);
		tmp_num *= -1;
	}

	for (i = 9; i >= 0; i--)
	{
		level = power(10, i);
		condition = tmp_num / level;
		tmp_num -= condition * level;

		if (condition || is_started)
		{
			is_started = 1;
			c = condition + '0';
			c_handler(c, len);
		}
	}

}

/**
 * u_handler - handles the u specifier
 *
 * @num: the integer to be printed
 * @len: the printed length counter
 */
void u_handler(unsigned int num, int *len)
{
	int i;
	unsigned int tmp_num;
	unsigned int condition;
	int is_started = 0;
	char c;
	int level;

	tmp_num = num;

	if (num == 0)
	{
		c_handler('0', len);
		return;
	}

	for (i = 9; i >= 0; i--)
	{
		level = power(10, i);
		condition = tmp_num / level;
		tmp_num -= condition * level;

		if (condition || is_started)
		{
			is_started = 1;
			c = condition + '0';
			c_handler(c, len);
		}
	}

}
