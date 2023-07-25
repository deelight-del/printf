#include <stdio.h>
#include "main.h"


void call_var(int n, ...);

void call_var(int n, ...)
{
	va_list list;
	int len, i;

	va_start(list, n);

	for (i = 0; i < n; i++)
	{
		len = print_count_binary(list);
		printf("\n");
		printf("The length of above printed number is given as: %d\n", len);
		printf("\n");
	}
}

int main(void)
{
	call_var(1, 1234);
	call_var(6, 0, 5, -5, -8, -10, -200);

	return (0);
}
