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
	int nums = 0;

	if (format != NULL)
	{
		int index;
		va_list input;
		int (*f)(va_list);

		va_start(input, format);
		if (format[0] == '%' && format[1] == '\0')
			return (-1);

		nums = 0;

		while (format[index] != '\0')
		{
			if (format[index] == '%')
			{
				if (format[index + 1] == '%')
				{
					nums += _putchar(format[index]);
					index++;
				}
				else if (format[index + 1] != '\0')
				{
					f = check_func(format[index + 1]);
					nums += (f ? f(input) :  _putchar(format[index])
								+ _putchar(format[index + 1]));
					index++;
				}
			}
			else
				nums += _putchar(format[index]);
			index++;
		}
		va_end(input);
	}

		return (nums);
}

/**
 * print_buffer -function prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
