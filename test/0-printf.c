
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
	if (isformatvalid(format))
		return (-1);

	int ret, i, n;
	va_list args;
	Buffer *buf;
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
			ret += get_specifiers(format[buf->index],buf,&args);
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
 *
 *Return: null
 */

int print_str(Buffer *buf ,va_list list)
{
	size_t i;

	char* str = va_arg(list, char*);

	if (!str)
		return print_null(buf,list);

	i = 0;
	while (str[i])
	{
		buf->str[buf->index++] = str[i++];
		if (buf->index == buf->size - 1)
			print_buffer(buf);
	}
	return i;
}

int print_null(Buffer *buf, va_list v_ls )
{
	char c;

	c = va_arg(v_ls, int);
	buf->str[buf->index++] = c;

	if (buf->index == buf->size - 1)
		print_buffer(buf);

	return 1;
}


/**
 *print_char - used to print character
 *@list : list of va_list
 *
 *Return: integer value count of char
 */

int print_char(Buffer *buf,va_list list)
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
 *
 *Return: integer 1
 */

int print_percent(Buffer *buf ,va_list list)
{
	buf->str[buf->index++] = '%';

	if (buf->index == buf->size - 1)
		print_buffer(buf);

	return 1;
}
