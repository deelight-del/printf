#include "main.h"
#include <stdio.h>
#include "limits.h"

/**
  *main - To test our printf function is doing as we wish
  *
  *Return: void
  */

int main(void)
{
	int len;
	long unsigned int digit;

	printf("Testing for strings, note printf first\n");
	len = printf("great, %s of God with %s blemishe%c\n", "man", NULL, 's');
	printf("%d\n", len);
	len = _printf("great, %s of God with %s blemishe%c\n", "man", NULL, 's');
	printf("%d\n", len);


	printf("Testing for chars\n");
	len = printf("Africa LX is given as, %c%c%c\n", 'A', 'L', 'X');
	printf("%d\n", len);
	len = _printf("Africa LX is given as, %c%c%c\n", 'A', 'L', 'X');
	printf("%d\n", len);
	
	printf("Testing for ints and digits\n");
	len = printf("Minumum %d or %i\n", INT_MIN, INT_MIN);
	printf("%d\n", len);
	len = _printf("Minimum %d or %i\n", INT_MIN, INT_MIN);
	printf("%d\n", len);

	printf("2nd Testing for ints and digits\n");
	len = printf("Minumum %d or %i\n", -12345, -12345);
	printf("%d\n", len);
	len = _printf("Minimum %d or %i\n", -12345, -12345);
	printf("%d\n", len);


	printf("Testing for unsigned int\n");
	len = printf(" 2 + 2 is the same as %u or %u\n", 4, 40004);
	printf("%d\n", len);
	len = _printf(" 2 + 2 is the same as %u or %i\n", 4, 40004);
	printf("%d\n", len);


	printf("Testing for binary\n");
	/*len = printf("%b", 1024);
	printf("%d\n", len);*/

	len = _printf("%b", 1024);
	printf("The length of binary string is%d\n", len);
	
	digit = 0;
	printf("Digit to test is: %lu\n", digit);
	len = _printf("%b\n", digit);
	printf("The length of binary string is%d\n", len);
	digit = UINT_MAX;
	printf("Digit to test is: %lu\n", UINT_MAX);
	len = _printf("%b\n", digit);
	printf("The length of binary string is%d\n", len);
	digit = UINT_MAX + 1024;
	printf("Digit to test is: %lu\n", (UINT_MAX + 1024));
	len = _printf("%b\n", (UINT_MAX + 1024));
	printf("The length of binary string is%d\n", len);
	_printf("There is %b bytes in %b KB\n", 1024, 1);

	_printf("%u - %u = %u\n", 2048, 1024, 1024);
	_printf("%o\n", UINT_MAX);
	_printf("%X\n", UINT_MAX);

	return (0);

}
