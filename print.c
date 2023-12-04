#include "main.h"

/**
* _printf - function to print to standard output
* stdout
* @format: params  to be checked and printed
* Return: count of params printed
*/

int _printf(const char *format, ...)
{
	int printed_char;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", root},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	printed_char = parser(format, f_list, arg_list);
	va_end(arg_list);

	return (printed_char);
}
