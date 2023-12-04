#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>


/**
* struct format_operators - function format checker object
* @ch: flag
* @func: function
*/

typedef struct format_operators
{
	char *ch;
	int (*func)(va_list);
} f_ops;


void _puts(char *str);


/*putchar function */
int _putchar(char c);

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int (*check_func(char s))(va_list inputs);
int print_c(va_list inputs);
int print_s(va_list inputs);
int print_d(va_list inputs);
int print_i(va_list inputs);
int print_b(va_list inputs);
int print_p(va_list ap);
int printnumber(int n);

int _strlen(const char *s);


#endif /* MAIN_H */
