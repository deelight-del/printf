#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int print_str(va_list list);
int print_char(va_list list);
void print_int(int num);
int int_count(int num);
int print_count_int(va_list list);
bool isformatvalid(const char *format);
int get_specifiers(char, va_list);

typedef struct spec
{
	char op;
	int (*ptr_func)(va_list);
} spec;
#endif
