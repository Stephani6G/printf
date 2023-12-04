#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define F_ZERO 4
#define F_HASH 8
#define F_PLUS 2
#define F_SPACE 16
#define F_MINUS 1

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define S_LONG 2
#define S_SHORT 1

/**
* struct format_operators - function format checker object
* @ch: character flag
* @func: function to check
*/

typedef struct format_operators
{
	char *ch;
	int (*func)(va_list);
} f_ops;

/* putchar*/
int _putchar(char c);
int _printf(const char *format, ...);
int (*check_func(char s))(va_list inputs);
int print_c(va_list inputs);
int print_s(va_list inputs);
int print_d(va_list inputs);
int print_i(va_list inputs);
int print_b(va_list inputs);


#endif
