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

	if (!isformatvalid(format))
		return (-1);
	ret = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		/*if (format[i] = '%' && format[i + 1] == ' ')*/

		if (format[i] == '%')
		{
			n = 1;
			if (format[i + n] == 'c')
			{
				ret += print_char(va_arg(args, int));
			}
			else if (format[i + n] == 's')
				ret += print_str(va_arg(args, char *));
			else if (format[i + n] == '%')
			{
				ret += 1;
				putchar('%');
			}
			else
			{
				putchar(format[i]);
				ret += 1;
			}
			i += n;

		}
		else
		{
			putchar(format[i]);
			ret += 1;
		}
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
	int len;
	char *p = str;

	if (str == NULL)
	{
		len = print_str("(null)");
		return (len);
	}

	else if (str[0] == '\0')
	{
		return (0);
	}

	for (; *p != '\0'; p++)
		putchar (*p);
	len = strlen(str);
	return (len);
}


/**
  *print_char - used to print character
  *@ch: character to print
  *
  *Return: integer value count of char
*/

int print_char(int ch)
{
	putchar(ch);

	if (ch == 0)
		return (0);
	return (1);
}
