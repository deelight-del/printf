#include <stdio.h>
#include "main.h"

/**
  * count_binary - count number of chars that make up
  * @list: list of val_list
  *
  *Return: Count of the binary it is printing
*/

int count_octal(unsigned int num)
{
	int i = 0;

	if (num <= 7)
		return (1);
	while (num / 8)
	{
		num = num / 8;
		i++;
	}
	i++;

	return (i);
}

/**
  *print_octal - function to print octal base nums
  *@num: number to print
  *
  *Return: 0, if successful
*/

int print_octal(unsigned int num, Buffer *buf)
{
	int len, i;

	len = count_octal(num);
	buf->index += (len - 1);

	for (i = 0; i < len; i++)
	{
		buf->str[buf->index - i] = (num % 8) + 48;
		num = num / 8;
	}

	return (0);
}

/**
  *print_count_octal - prints and counts the base 8 numbeers
  *@list: va_list kind of list
  *
  *Return: returns the length of the supposed number
*/

int print_count_octal(Buffer *buf, va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int ret = count_octal(num);

	print_octal(num, buf);

	return (ret);
}
