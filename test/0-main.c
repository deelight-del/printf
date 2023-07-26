#include <stdio.h>
#include "main.h"
/**
  *main - To test our printf function is doing as we wish
  *
  *Return: void
  */

int main(void)
{
	int len;

	printf("Testing for strings, note printf first\n");
	len = printf("great, %s\n", "man");
	printf("%d\n", len);
	len = _printf("great, %s\n", "man");
	printf("%d\n", len);


	printf("Testing for chars\n");
	len = printf("Africa LX is given as, %c%c%c\n", 'A', 'L', 'X');
	printf("%d\n", len);
	len = _printf("Africa LX is given as, %c%c%c\n", 'A', 'L', 'X');
	printf("%d\n", len);
	
	printf("Testing for ints and digits\n");
	len = printf(" 2 + 2 is the same as %d or %i\n", 4, 1234);
	printf("%d\n", len);
	len = _printf(" 2 + 2 is the same as %d or %i\n", 4, 1234);
	printf("%d\n", len);


	printf("Testing for unsigned int\n");
	len = printf(" 2 + 2 is the same as %u or %u\n", 4, 40004);
	printf("%d\n", len);
	len = _printf(" 2 + 2 is the same as %u or %i\n", 4, 40004);
	printf("%d\n", len);


	printf("Testing for binary\n");
	len = printf(" The binary for the digit %d is %b\n", 78, 78);
	printf("%d\n", len);
	len = _printf(" The binary for the digit %d is %b\n", 78, 78);
	printf("%d\n", len);
	return (0);


}
