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
void print_int(int num)
{
	int ch;

	if (num < 0)
	{
		putchar('-');
		num = -num;
	}

	if (num / 10)
		print_int(num / 10);
	ch = (num % 10) + 48;
	putchar(ch);
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

/**
  *print_count_int - Function to print and count integer
  *@va_list: list of va_list
  *
  *Return: Returns the count of integer
*/

int print_count_int(va_list list)
{
	int num = va_arg(list, int);
	int ret;

	print_int(num);
	ret = int_count(num);

	return (ret);
}
