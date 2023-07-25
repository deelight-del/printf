#include <stdio.h>
#include <stdbool.h>
/**
 * isformatvalid - function to print the format string, and with respective
 * formatting specifier.
 * @format: this is the string containing the format and string to print
 *
 * Return: true for invalid false for valid format
 */
bool isformatvalid(const char *format)
{
	if (format == NULL || format[0] == '\0')
		return (false);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				case 'd':
				case 'i':
				case 'o':
				case 'u':
				case 'x':
				case 'X':
				case 'f':
				case 'e':
				case 'E':
				case 'g':
				case 'G':
				case 'a':
				case 'A':
				case 's':
				case 'p':
				case '%':
				break;
				default:
				return (false);
			}
		}
		format++;
	}
	return (true);
}
