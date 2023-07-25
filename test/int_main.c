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
		len = print_count_u(list);
		printf("\n");
		printf("%d", len);
		printf("\n");
	}
}

int main(void)
{
	call_var(1, 1234);
	call_var(4, 0, -0, -90, 10000);

	return (0);
}
