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
			/*	case 'c':
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
				break;*/
				case ' ':
					return (false);
				case '\0':
					return (false);
				default:
					break;
			}
		}
		format++;
	}
	return (true);
}
		

/**
 * isspecifier - function determine if a next word is a specifier
 * formatting specifier.
 * @c: char to test
 *
*/

bool is_specifier(char c)
{
	switch (c)
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
		case 'b':
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

	return (true);
}
