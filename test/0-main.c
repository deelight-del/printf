#include "main.h"
#include <stdio.h>

/**
  *main - To test our printf function is doing as we wish
  *
  *Return: void
  */

int main(void)
{
	_printf("This is format specifier for char - \\%c", 'd');
	_printf("", "good", "bad\n");
	_printf(" \n", 2, 6, "ALX\n");
	_printf("This is a %s/%s boy%c\n", "good", "bad", 's');
	_printf("Africa leadership is abbrev as %c%c%c\n", 'A', 'L', 'X');
	_printf("%c\n", 'A');
	return (0);
}
