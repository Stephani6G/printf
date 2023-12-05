#include "main.h"

int hex_check(int, char);

/**
 * hex_check - a functio that  checks
 * which hex function is calling it
 * @num: Number to convert into letter
 *
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */

int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
