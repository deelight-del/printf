#include <stdio.h>
#include "main.h"

/**
 *get_specifiers - get respective function for individual specifier
 * @s: specifier of character
 * @list: list of va_list type
 *
 * Return: an integer to return the specifier
 */

int get_specifiers(char s, Buffer *buf, va_list *list)
{
	int i, ret = 0;
	spec spec_ar[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_count_int},
		{'S', print_custom_str1},
		{'i', print_count_int},	
		{'%', print_percent},
		{'b', print_count_binary},
		{'u', print_count_u},
		{'o', print_count_octal},
		{'x', print_count_hexa},
		{'X', print_count_hexA},
		{'\0', NULL}
	};
	for (i = 0; spec_ar[i].op != '\0'; i++)
	{
		if (s == spec_ar[i].op)
		{
			ret += spec_ar[i].ptr_func(buf, *list);
			break;
		}
	}

	return ret;
}
