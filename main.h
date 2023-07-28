#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
/*int print_str1(va_list list);
int print_char1(va_list list);
void print_int1(int num);*/
int int_count(int num);
int print_count_int1(va_list list);
bool isformatvalid(const char *format);
/*int get_specifiers1(char, va_list);
int print_null1(char *str);
int print_percent1(va_list list);
*/
int count_binary(unsigned int num);
/*int print_binary1(unsigned int num);
int print_count_binary1(va_list list);*/
/*void print_unsigned(unsigned int num);*/
int u_count(unsigned int num);
/*int print_count_u(va_list list);*/
int count_octal(unsigned int num);
/*int print_octal(unsigned int num);
int print_count_octal(va_list list);*/
int count_hex_a(unsigned int num);
/*int print_hex_a(unsigned int num);
int print_count_hexa(va_list list);*/
bool is_specifier(char c);

typedef struct call_buffer
{
	char* str;
	size_t size;
	size_t index;

} Buffer;

Buffer *new_buffer();
void inti_buffer();
void print_buffer(Buffer *);

typedef struct spec
{
	char op;
	int (*ptr_func)(Buffer*, va_list);
} spec;

int print_str(Buffer *buf, va_list v_ls);
int get_specifiers(char, Buffer *, va_list *);
int print_null(Buffer *buf,va_list list);
int print_percent(Buffer *buf,va_list list);
int print_char(Buffer *buf,va_list list);
int print_count_int(Buffer *, va_list);
int print_count_binary(Buffer *buf, va_list list);
int print_binary(unsigned int, Buffer *buf);
void print_unsigned( unsigned int num, Buffer *buf);
int print_count_u(Buffer *buf, va_list list);
int print_octal(unsigned int num, Buffer *buf);
int print_count_octal(Buffer *b, va_list list);
int print_hex_a(unsigned int num, Buffer *buf);
int print_count_hexa(Buffer *buf, va_list list);
int print_count_hexA(Buffer *buf, va_list list);
int print_hex_A(unsigned int num, Buffer *buf);
int print_custom_str1(Buffer *buf, va_list list);

int print_int(int num,Buffer*);
#endif

