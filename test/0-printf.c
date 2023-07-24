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
		if (format[i] == '%')
		{
			n = 1;
			ret += get_specifiers(format[i + n], args);
			if (format[i + n] == '%')
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
  *@list:- list of va_list
  *
  *Return: null
*/

int print_str(va_list list)
{
	char *str = va_arg(list, char *);
	int len;
	char *p;

	if (str == NULL)
	{	
		len = print_str("(null)");
		return (len);
	}

	else if (str[0] == '\0')
	{
		return(0);
	}

	for (p = str; *p != '\0'; p++)
		putchar (*p);
	len = strlen(str);
	return (len);
}


/**
  *print_char - used to print character
  *@list : list of va_list
  *
  *Return: integer value count of char
*/

int print_char(va_list list)
{
	int ch = va_arg(list, int);

	putchar(ch);

	if (ch == 0)
		return (0);
	return(1);
}
