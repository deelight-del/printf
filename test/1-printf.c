#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
*int_to_string - converts integers to strings
*@integer: int to print
*
*Return: return string
*/

void print_int(int integer)
{
	if (integer < 0)
	{
		putchar('-');
		integer = -integer
	}

	print_int(integer / 10);

	if (

}
