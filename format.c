#include "main.h"
#include <stdlib.h>

void print_buffer(char buffer[], int *buff_ind);

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
	int index, prd = 0, prd_char = 0;
	int flag, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buff_ind++] = format[index];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
				prd_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flag(format, &index);
			width = get_width(format, &index, list);
			precision = get_precision(format, &index, list);
			size = get_size(format, &index);
			++index;
			prd = handle_print(format, &index, list, buffer,
				flags, width, precision, size);
			if (prd == -1)
				return (-1);
			prd_char += prd;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (prd_char);
}
