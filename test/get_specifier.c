#include <stdio.h>
#include "main.h"

/**
  *
*/

int get_specifiers(char s, va_list list)
{
	int i, ret = 0;
	spec spec_ar[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_count_int},
		{'i', print_count_int},
		{NULL, NULL}
	};

	for(i = 0; spec_ar[i].op != NULL; i++)
		if(s == spec_ar[i].op)
		{
			ret += spec_ar[i].ptr_func(list);
			break;
		}
	return (ret);
}

