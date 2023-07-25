#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 *_printf - function to print the format string, and with respective
 *formatting specifier.
 *@format: this is the string containing the format and string to print
 *@args: arguments
 *Return: length of format string
 */

int _printf(const char *format, ...)
{
	va_list args;
	int ret;

	Buffer *buf;

	if (!isformatvalid(format))
		return (-1);

	buf = new_buffer();
	if (!buf)
		return (-1);

	ret = 0;

	va_start(args, format);
	while (format && format[buf->index])
	{
		if (format[buf->index] == '%')
		{
			buf->index++;
			ret += get_specifiers(format[buf->index], buf, &args);
			buf->index++;
		}
		else
		{
			buf->str[buf->index++] = format[ret];
			if (buf->index == buf->size - 1)
				print_buffer(buf);
			ret++;
		}
	}
	va_end(args);
	print_buffer(buf);
	ret += buf->index;
	free(buf->str);
	free(buf);
	return (ret);
}

/**
 *print_str - used to print a string within string
 *@list:- list of va_list
 *@buf: buffer to be printed
 *Return: null
 */

int print_str(Buffer *buf, va_list list)
{
	size_t i;

	char *str = va_arg(list, char*);

	if (!str)
		str = "(nill)";
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] == 'n')
		{
			buf->str[buf->index++] = '\n';
			i += 2;
		}
		else if (str[i] == '\\' && str[i + 1] == '\\')
		{
			buf->str[buf->index++] = '\\';
			i += 2;
		}
		buf->str[buf->index++] = str[i++];
		if (buf->index == buf->size - 1)
			print_buffer(buf);
	}
	return (i);
}
/**
 *print_null - function to print %
 *@v_ls: list of va_list
 *@buf: buffer to be printed
 *Return: integer 1
 */

int print_null(Buffer *buf, va_list v_ls)
{
	int c;

	c = va_arg(v_ls, int);

	buf->str[buf->index++] = c;

	if (buf->index == buf->size - 1)
		print_buffer(buf);

	return (1);
}


/**
 *print_char - used to print character
 *@list : list of va_list
 *@buf: buffer to be printed
 *Return: integer value count of char
 */

int print_char(Buffer *buf, va_list list)
{
	char c;

	c = va_arg(list, int);

	buf->str[buf->index++] = c;

	if (buf->index == buf->size - 1)
		print_buffer(buf);

	return (1);
}

/**
 *print_percent - function to print %
 *@list: list of va_list
 *@buf: buffer to be printed
 *Return: integer 1
 */

int print_percent(Buffer *buf, va_list list)
{
	(void) list;

	buf->str[buf->index++] = '%';

	if (buf->index == buf->size - 1)
		print_buffer(buf);

	return (1);
}
