#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
* struct convert -  func defines a structure for symbols and functions
*
* @st: The operator
* @fn: The function associated
*/

struct convert
{
	char *st;
	int (*fn)(va_list);
};
typedef struct convert conver_t;


int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
int print_octal(va_list list);
int print_string(va_list);
int print_number(va_list);
int print_percent(va_list);
int print_integer(va_list);
int root(va_list);

int print_binary(va_list);
int print_reverse(va_list arg);
int print_heX(va_list list);
int unsigned_integer(va_list);

int print_hex(va_list list);

unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);



#endif
