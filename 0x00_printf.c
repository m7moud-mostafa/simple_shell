#include "main.h"


/**
 * _printf - write output to stdout, the standard output stream.
 * @format: creates the string that will be printed and formatted
 * Return: the number of characters printed (excluding the null byte
 *			used to end output to strings)
 */

int _printf(const char *format, ...)
{	va_list args;
	int len = 0;
	int i;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{	i++;
			while (format[i] == ' ' && format[i] != '\0')
				i++;
			if (format[i] == '\0')
				return (-1);
			handle_specifier(format[i], args, &len);
		}
		else
			c_handler(format[i], &len);
	}
	va_end(args);
	return (len); }
