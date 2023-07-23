#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>

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
 * @format: formatting specifier.
 * Return: length of format string
 *
 */
	int _printf(const char *format, ...)
{
	 va_list args;
	 int i, ret, length, ch;

	 ret = 0;

	if (format == NULL || format[0] == '\0')
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);

	va_start(args, format);

	length = strlen(format);

	for (i = 0; i < length; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (i >= length)
				break;

			else if (format[i] == 'i' || format[i] == 'd')
			{
				ch = va_arg(args, int);
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
	return (ret);
}
