#include <stdio.h>
#include <ctype.h>
/**
 *isformat_valid - function to print the format string, and with respective
 * formatting specifier.
 * @format: this is the string containing the format and string to print
 *
 * Return: 0 for invalid 1 for valid format
 */
int isformat_valid(const char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				format++;
				continue;
			}
			if (!*format)
			{
				return (0);
			}
			if (strchr("diouxXfeEgGcsnp", *format))
			{
				format++;
				continue;
			}
			if (*format == '*')
			{
				format++;
				while (isdigit(*format))
				{
					format++;
				}
				continue;
			}
			return (0);
		}
		format++;
	}
	return (1);
}
