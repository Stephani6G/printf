#include "main.h"

/**
 * parser - Receives the main string and all the  params to
 * print a formated string
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions
 *
 * @arg_list:  listof all the arguments
 * Return: Total count of the char printed
 */


int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_char;

	printed_char = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_char += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_char = printed_char + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed_char++;
		}
	}
	return (printed_char);
}
