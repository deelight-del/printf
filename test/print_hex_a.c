#include <stdio.h>
#include "main.h"

/**
  * count_hex_a - count number of chars that make up
  * @num: nuber to count
  *
  *Return: Count of the binary it is printing
*/

int count_hex_a(unsigned int num)
{
	int i = 0;

	if (num <= 1)
		return (1);
	while (num / 16)
	{
		num = num / 16;
		i++;
	}
	i++;

	return (i);
}

/**
  *print_hex_a - function to print octal base nums
  *@num: number to print
  *
  *Return: 0, if successful
*/

int print_hex_a(unsigned int num)
{
/*	if (num < 0)
*	{
*		putchar('-');
*		num = -num;
*	}
*/

	if (num / 16 != 0)
		print_hex_a(num / 16);

	if ((num % 16) < 10)
		putchar((num % 16) + 48);
	else
	{
		putchar((num % 16) + 87);
	}

	return (0);
}

/**
  *print_count_hex_a - prints and counts the base 16 numbers
  *@list: va_list kind of list
  *
  *Return: returns the length of the supposed number
*/

int print_count_hexa(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int ret = count_hex_a(num);

	printf("Digit under consideration is %u\n", num);

	print_octal(num);

	return (ret);
}
