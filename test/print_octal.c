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

	if (num <= 1)
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

int print_octal(unsigned int num)
{
/*	if (num < 0)
*	{
*		putchar('-');
*		num = -num;
*	}
*/

	if (num / 8 != 0)
		print_octal(num / 8);

	putchar((num % 8) + 48);

	return (0);
}

/**
  *print_count_octal - prints and counts the base 8 numbeers
  *@list: va_list kind of list
  *
  *Return: returns the length of the supposed number
*/

int print_count_octal(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int ret = count_octal(num);

	printf("Digit under consideration is %u\n", num);

	print_octal(num);

	return (ret);
}
