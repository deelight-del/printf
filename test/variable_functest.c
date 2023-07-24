#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void helper_func(va_list list);
int print_int(int count, ...);

int print_int(int count, ...)
{
	va_list args;
	int i;

	va_start(args, count);

	for (i = 0; i < count; i++)
		helper_func(args);
	va_end(args);

	return (0);
}

void helper_func(va_list list)
{
	putchar(va_arg(list, int) + 48);
}

int main(void)
{
	print_int(4, 1, 2, 3, 4);
	printf("\n");

	return (0);
}
