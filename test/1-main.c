#include <stdio.h>
int len;
len = printf("Hello World, %c after null\n", NULL);
printf("%d", len);
