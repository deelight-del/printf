#include <stdio.h>
#include "main.h"

/**
  * count_binary - count number of chars that make up
  * @list: list of val_list
  *
  *Return: Count of the binary it is printing
*/

int count_binary(long unsigned int num)
{
	int i = 0;


	if (num <= 1)
		return (1);
	while (num / 2)
	{
		num = num / 2;
		i++;
	}
	i++;

	return (i);
}

/**
  *print_binary - function that prints binary
  *@num: number to print
  *@buf - buf type datatype
  *
  *Return: zero, if true
*/

int print_binary(long unsigned int num, Buffer *buf)
{
	int len, i;

	len = count_binary(num);
	buf->index += (len - 1);

	for (i = 0; i < len; i++)
	{
		buf->str[buf->index - i] = (num % 2) + 48;
		num = num / 2;
	}
	return (0);
}

/**
  *print_count_binary - Function to print and count the binary that is printed
  *@buf - buf type datatype
  *@list: list of va_list
  *
  *Return: length of binary retrieved
*/

int print_count_binary(Buffer *buf, va_list list)
{
	long unsigned int num = va_arg(list, long unsigned int);
	int ret = count_binary(num);

	print_binary(num, buf);

	return (ret);
}
