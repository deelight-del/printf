#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
int _printf(const char *format, ...);
int print_str(char *ch);
int print_char(int ch);
void print_int(int num);
int int_count(int num);
int print_count_int(int num);
bool isformatvalid(const char *format);
#endif
