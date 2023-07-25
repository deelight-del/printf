#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int int_count(int num);
bool isformatvalid(const char *format);
typedef struct call_buffer
{
	char* str;
	size_t size;
	size_t index;

} Buffer;

Buffer *new_buffer(void);
void inti_buffer();
void print_buffer(Buffer *);

typedef struct spec
{
	char op;
	int (*ptr_func)(Buffer*, va_list);
} spec;
int _printf(const char *format, ...);
int print_str(Buffer *buf, va_list v_ls);
int get_specifiers(char, Buffer *, va_list *);
int print_null(Buffer *buf,va_list list);
int print_percent(Buffer *buf,va_list list);
int print_char(Buffer *buf,va_list list);
int print_count_int(Buffer *, va_list);
void print_int(int num,Buffer*);
#endif

