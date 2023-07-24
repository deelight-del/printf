#include <stdio.h>
#include "main.h"

int main(void)
{
	int len;

	len = print_count_int(1234);
	print_count_int(len);
	printf("\n");
	printf("%d\n", len);

	len = print_count_int(0);
	print_count_int(len);
	printf("\n");
	printf("%d\n", len);

	len = print_count_int(-1234);
	print_count_int(len);
	printf("\n");
	printf("%d\n", len);

	return (0);
}
