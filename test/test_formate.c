#include <stdio.h>
#include "main.h"

int main()
{
	int test;

	test = isformatvalid("%");
	printf("%d\n", test);
	test = isformatvalid("This is a valid format");
	printf("%d\n", test);
	test = isformatvalid(NULL);
	printf("%d\n", test);
	test = isformatvalid("This is %% %c");
	printf("%d\n", test);
	test = isformatvalid("12hfduhhhdsjdkhjdh");
	printf("%d\n", test);

	return(0);
}
