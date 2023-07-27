#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>

/**
 * print_unsigned - function to print unsigned integers.
 * @num: numbers to print
 *
 * Return: nothing
 */
void print_unsigned(unsigned int num, Buffer *buf)
{
	int len, i;

	len = u_count(num);
	buf->index += (len - 1);

	for (i = 0; i < len; i++)
	{
		buf->str[buf->index - i] = (num % 10) + 48;
		num = num / 10;
	}
}

/**
  *u_count - counting the number of integers present
  *@num: The integer to print
  *
  *Return: The number of int is printed
*/

int u_count(unsigned int num)
{
	int i = 1;

	for (; num / 10; i++)
		num /= 10;
	return (i);
}

/**
  *print_count_u - Function to print and count integer
  *@list: list of va_list
  *
  *Return: Returns the count of integer
*/

int print_count_u(Buffer *buf, va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int ret;

	print_unsigned(num, buf);
	ret = u_count(num);

	return (ret);
}
