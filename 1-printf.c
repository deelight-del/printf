#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>
#include  <stddef.h>
#include <limits.h>

/**
 * print_int - function to print integers.
 * @num: numbers to print
 *
 * Return: nothing
 *
int print_int(int num, Buffer *buf)
{
	int len, i;

	if (num < 0)
	{
		buf->str[buf->index] = '-';
		buf->index++;

		if (num == INT_MIN)
		{
			num = INT_MAX;
			len = int_count(num);
			buf->index += (len - 1);
			buf->str[buf->index] = (num % 10) + 49;
			num /= 10;
		}
		else
		{
			num = -num;
			len = int_count(num);
			buf->index += (len - 1);
			buf->str[buf->index] = (num % 10) + 48;
			num /= 10;
			
		}

		for (i = 1; i < len; i++)
		{
			buf->str[buf->index - i] = (num % 10) + 48; 
			num /= 10;
		}
		return (0);

	}

	len = int_count(num);
	buf->index += (len - 1);

	for (i = 0; i < len; i++)
	{
		buf->str[buf->index - i] = (num % 10) + 48; 
		num /= 10;
	}
	return (0);
}
 *   *print_count_int - Function to print and count integer
 *     *@list: list of va_list
 *       *
 *         *Return: Returns the count of integer
 *         */
int print_count_int(Buffer *buf, va_list list)
{
	int num, ret;

	num = va_arg(list, int);
	print_int(num,buf);
	ret = int_count(num);
	return (ret);
}

/**
 *int_count - counting the number of integers present
 *@num: The integer to print
 *
 *Return: The number of int is printed
 */

int int_count(int num)
{
	int i = 1;

	if (num < 0)
	{
		num = -num;
		i++;
	}

	for (; num / 10; i++)
		num /= 10;
	return (i);
}
