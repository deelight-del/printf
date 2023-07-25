#include <stdio.h>
#include "main.h"

/**
  * count_binary - count number of chars that make up
  * @list: list of val_list
  *
  *Return: Count of the binary it is printing
*/

int count_binary(unsigned int num)
{
	int i = 0;

/*	if (num < 0)
		num = -num;
		*/
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
  *
  *Return: zero, if true
*/

int print_binary(unsigned int num)
{
/*	if (num < 0)
	{
		putchar('-');
		num = -num;
	}
	*/

	if (num / 2 != 0)
		print_binary(num / 2);

	putchar((num % 2) + 48);

	return (0);
}

/**
  *print_count_binary - Function to print and count the binary that is printed
  *@list: list of va_list
  *
  *Return: length of binary retrieved
*/

int print_count_binary(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int ret = count_binary(num);

	printf("Digit under consideration is %u\n", num);

	print_binary(num);

	return (ret);
}
