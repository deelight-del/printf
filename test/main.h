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
int print_null(char *str);
int print_percent(va_list list);
int count_binary(unsigned int num);
int print_binary(unsigned int num);
int print_count_binary(va_list list);
void print_unsigned(unsigned int num);
int u_count(int num);
int print_count_u(va_list list);
int count_octal(unsigned int num);
int print_octal(unsigned int num);
int print_count_octal(va_list list);
int count_hex_a(unsigned int num);
int print_hex_a(unsigned int num);
int print_count_hexa(va_list list);

typedef struct spec
{
	char op;
	int (*ptr_func)(va_list);
} spec;
#endif
