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
void print_unsigned(unsigned int num)
{
	int ch;

	if (num / 10)
		print_unsigned(num / 10);
	ch = (num % 10) + 48;
	putchar(ch);
}

/**
  *u_count - counting the number of integers present
  *@num: The integer to print
  *
  *Return: The number of int is printed
*/

int u_count(int num)
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

int print_count_u(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int ret;

	print_unsigned(num);
	ret = u_count(num);

	return (ret);
}
