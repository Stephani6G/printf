#include "main.h"
#include <stdlib.h>
/**
* _printf - a function that produces
*		output according to a format
* @format: parameters of a character string
*		whose format is to be checked and printed
* Return: the number of characters printed
*		excluding the null byte used
*/
int _printf(const char *format, ...)
{
	int count = 0;
	int j = 0;
	int index = 0;
	va_list con;
	pt_t types[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"%", print_p},
		{"i", print_d},
		{NULL, NULL},
	};
	if (format == NULL)
		return (-1);
	va_start(con, format);
	index = 0;
	while (format != NULL && format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == '\0')
			{
				return (-1);
			}
			j = 0;
			while (types[j].fs != NULL)
			{
				if (*(types[j].fs) == format[index])
					count += types[j].f(con);
				j++;
			}
			index++;
		}
		if (format[index] != '%' && format[index] != '\0')
		{
			count += _putchar(format[index]);
			index++;
		}
	}
	va_end(con);
	return (count);
}
