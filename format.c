#include "main.h"

/**
* _printf - function to print to standard output
* @format: params  to be checked and printed
* Return: count of params that are printed
*/

int _printf(const char *format, ...)
{
	int nums = 0;

	if (format != NULL)
	{
		int j;
		va_list inputs;
		int (*f)(va_list);

		va_start(inputs, format);
		if (format[0] == '%' && format[1] == '\0')
			return (-1);

		nums = 0;

		while (format[j] != '\0')
		{
			if (format[j] == '%')
			{
				if (format[j + 1] == '%')
				{
					nums += _putchar(format[j]);
					j++;
				}
				else if (format[j + 1] != '\0')
				{
					f = check_func(format[j + 1]);
					nums += (f ? f(inputs) :  _putchar(format[j]) + _putchar(format[j + 1]));
					j++;
				}
			}
			else
				nums += _putchar(format[j]);
			j++;
		}
		va_end(inputs);
	}

		return (nums);
}
