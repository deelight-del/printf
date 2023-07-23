#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>

/**
  *_printf - function to print the format string, and with respective
  *formatting specifier.
  *@format: this is the string containing the format and string to print
  *
  *Return: length of format string
*/

int _printf(const char *format, ...)
{
	int ret, i, n;
	va_list args;

	if (format == NULL || format[0] == '\0')
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);

	ret = strlen(format);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		/*if (format[i] = '%' && format[i + 1] == ' ')*/

		if (format[i] == '%')
		{
			n = 1;
			if (format[i + n] == 'c')
				putchar(va_arg(args, int));
			else if (format[i + n] == 's')
				print_str(va_arg(args, char *));
			else if (format[i + n] == '%')
				putchar('%');
			else if (format[i + n] == ' ')
				return (-1);

			i += n;

		}
		else
			putchar(format[i]);
	}
	va_end(args);
	return (ret);
}

/**
  *print_str - used to print a string within string
  *@str:- string to print
  *
  *Return: null
*/

int print_str(char *str)
{
	char *p = str;

	if (str == NULL)
	{	
		print_str("(nil)");
		return (1);
	}

	else if (str[0] == '\0')
	{
		return(1);
	}

	for (; *p != '\0'; p++)
		putchar (*p);
	return (1);
}
