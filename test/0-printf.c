#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>

/**
  *printf - function to print the format string, and with respective
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
		return (0);

	ret = strlen(format);

	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			n = 1;
			if (format[i + n] == 'c')
				putchar(va_arg(args, int));
			else if (format[i + n] == 's')
				print_str(va_arg(args, char *));

			i += n;

		}
		else
			putchar(format[i]);
	}
	return (ret);
}

/**
  *print_str - used to print a string within string
  *@ch - string to pring
  *
  *Return: null
*/

void print_str(char *ch)
{
	char *p;

	for(p = ch; *p != '\0'; p++)
		putchar(*p);
}
