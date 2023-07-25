#include <stdio.h>
#include "main.h"
/**
 *get_specifiers - get respective function for individual specifier
 * @c: specifier of character
 * @args: list of va_list type
 * @buf: Buffer to be printed
 * Return: an integer to return the specifier
 */
int get_specifiers(char c, Buffer *buf, va_list *args)
{
	int ret = 0;

	switch (c)
	{
		case 's':
			ret += print_str(buf, *args);
			break;
		case 'c':
			ret += print_char(buf, *args);
			break;
		case 'd':
		case 'i':
			ret += print_count_int(buf, *args);
			break;
		case '%':
			ret += print_percent(buf, *args);
			break;
		default:
			buf->str[buf->index++] = '%';
			buf->str[buf->index++] = c;
			if (buf->index == buf->size - 1)
				print_buffer(buf);
			ret += 2;
	}
	return (ret);
}
