
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
	int ret, n, i = 0;
	va_list args;
	Buffer *buf;

	if (!isformatvalid(format))
		return (-1);

	buf = new_buffer();
	if (buf == NULL)
		return (-1);

	ret = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_specifier(format[i + 1]))
		{
			/*buf->index++;*/
			n = 1;
			ret += get_specifiers(format[i + n],buf,&args);
			i += n;
		}
		else
		{
			buf->str[buf->index] = format[i];
			if (buf->index == buf->size - 1)
				print_buffer(buf);
			ret++;
		}
		buf->index++;
		i++;
	}
	va_end(args);
	print_buffer(buf);
	free(buf->str);
	free(buf);	
	return (ret);
}

/**
 *print_str - used to print a string within string
 *@list:- list of va_list
 *
 *Return: null
 */

int print_str(Buffer *buf, va_list list)
{
	size_t i;

	char* str = va_arg(list, char*);

	if (!str)
		return print_null(buf,list);

	i = 0;
	while (str[i])
	{
		buf->str[buf->index++] = str[i];
		if (buf->index == buf->size - 1)
			print_buffer(buf);
		i++;
	}
	buf->index--;
	return (i);
}

int print_null(Buffer *buf, va_list v_ls )
{
	char *c = "(null)";
	int i = 0;

	(void) v_ls;
	
	for(; *c != '\0'; c++)
	{
		buf->str[buf->index++] = *c;
		i++;
		if (buf->index == buf->size - 1)
			print_buffer(buf);
	}
	buf->index--;

	return (i);
}


/**
 *print_char - used to print character
 *@list : list of va_list
 *
 *Return: integer value count of char
 */

int print_char(Buffer *buf, va_list list)
{
	char c;

	c = va_arg(list, int);

	buf->str[buf->index] = c;

	if (buf->index == buf->size - 1)
		print_buffer(buf);
	return (1);
}

/**
 *print_percent - function to print %
 *@list: list of va_list
 *
 *Return: integer 1
 */

int print_percent(Buffer *buf, va_list list)
{
	(void) list;

	buf->str[buf->index] = '%';

	if (buf->index == buf->size - 1)
		print_buffer(buf);
	return (1);
}
