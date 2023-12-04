#include "main.h"

/**
 * printnumber - a function that prints number
 *		followed by a new line.
 *
 * @n: number parsed into string
 *
 * Return: 1 always success
 */

int printnumber(int n)
{
	int count = 0;
	unsigned int num;
	unsigned int digit;
	unsigned int index;
	unsigned int long_num;

	long_num = n;
	if (n < 0)
	{
		counter++;
		long_num = long_num * -1;
		_putchar('-');
	}

	if (long_num == 0)
	{
		counter++;
		_putchar('0');
		return (counter);
	}

	index = 1;
	while ((long_num / index) > 9)
	{
		index = index * 10;
	}
	while (index > 0)
	{
		num = long_num / index;
		digit = num % 10;
		counter++;
		_putchar(digit + '0');
		index = (index / 10);
	}
	return (counter);
}

/**
 * print_c - a function that
 *		prints characters
 *
 * @ap: argument params of the function
 * Return: 1 always success
 */

int  print_c(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}

/**
 * print_s - a function that
 *		prints strings
 *
 * @ap: params for the function
 *
 * Return: i (index)
 */

int print_s(va_list ap)
{
	char *str;
	int index;

	str = (va_arg(ap, char*));
	if (str == NULL)
		str = "(null)";
	for (index = 0; str[index]; index++)
		_putchar(str[index]);

	return (index);
}

/**
 * print_p - a function that prints %
 *
 * @ap: params for the function
 *
 * Return: 1 always success
 */

int print_p(va_list ap)
{
	(void)ap;
	_putchar('%');
	return (1);
}

/**
 * print_d - a function that
 *		prints decimals and integers.
 *
 * @ap: params of the function
 * Return: 1 always success
 */

int print_d(va_list ap)
{
	int output;
	int counter;

	output = va_arg(ap, int);
	counter = printnumber(output);
	return (counter);
}
