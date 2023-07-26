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
void print_int(int num, Buffer *buf)
{
	int ch;
	if (num < 0)
	{
		buf->str[buf->index++] = '-';
		num = -num;
	}
	if (num / 10)
		print_int(num / 10, buf);
	ch = (num % 10) + 48;
	buf->str[buf->index++] = ch;
}
/**
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
