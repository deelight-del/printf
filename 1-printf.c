#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>

/**
 * print_Str - function to print the format string, and with respective formatting specifier.
 * @str: this is the string containing the format and string to print
 * Return: length of format string
 */

	void
print_Str (const char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}
/**
 * print_int - function to print integers.
 * @num: numbers to print
 *
 * Return: nothing
 */
	void
print_int (int num)
{
	if (num < 0)
	{
		putchar('-');
		num = -num;
	}

	if (num / 10)
		print_int(num / 10);

	putchar(num % 10 + '0');
}
/**
 *_printf - function to print integers
 * formatting specifier.
 * 
 * Return: length of format string
 *        
 */
	int
_printf (const char *format, ...)
{
	 va_list args;
	 int i, ret, length;

	 ret = 0;

	if (format == NULL)
		return 0;

	va_start(args, format);

	length = strlen(format);

	for (i = 0; i < length; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (i >= length)
				break;

			if (format[i] == 's')
			{

				const char *str = va_arg(args, const char *);
				print_Str(str);
				ret++;
			}
			else if (format[i] == 'c')
			{
				int ch = va_arg(args, int);
				putchar(ch);
				ret++;
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				int ch = va_arg(args, int);
				print_int(ch);
				ret++;
			}
		}
		else
		{
			putchar(format[i]);
		}
	}

	va_end(args);

	return(ret);
}
