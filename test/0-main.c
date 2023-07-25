#include "main.h"
#include <stdio.h>

/**
  *main - To test our printf function is doing as we wish
  *
  *Return: void
  */

int main(void)
{
	int len;

	len = _printf("great, %s\n", "");
	printf("%d\n", len);
	len = _printf("great, %s\n", NULL);
	printf("%d\n", len);
	len = _printf("", "good", "bad\n");
	printf("%d\n", len);
	len = _printf(" \n", 2, 6, "ALX\n");
	printf("%d\n", len);
	len = printf("This is a %s/%s boy%c\n", "good", "bad", 's');
	printf("%d\n", len);
	len = printf("Africa leadership is abbrev as %c%c%c", 'A', 'L', 'X');
	printf("%d\n", len);
	len = printf("%c\n", 'A');
	printf("%d\n", len);
	len = printf("great, %s\n", "");
	printf("%d\n", len);
	len = _printf("This %k is a %s/%s boy%c\n", "good", "bad", 's');
	printf("%d\n", len);
        len = _printf("Africa leadership is abbrev as %c%c%c%", 'A', 'L', 'X');
	printf("%d\n", len);
	len = _printf("%c\n", 'A');
	printf("%d", len);
	return (0);
}
