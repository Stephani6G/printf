#include "main.h"

/**
 * print_char -  a function that prints character
 * @list: list of arguments
 * Return: number of characters printed.
 */

int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string -a funvction that prints a string
 * @list: list of arguments to be parsed
 * Return: number of characters printed.
 */

int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments parsed into function
 * Return: number of characters printed.
 */

int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - a function that prints an integer
 * @list: list of arguments parsed
 * Return: number of characters printed.
 */

int print_integer(va_list list)
{
	int num_len;

	num_len = print_number(list);
	return (num_len);
}

/**
 * unsigned_integer -  function that prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int unsigned_integer(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}
