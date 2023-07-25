#include "main.h"

/**
 * get_size - function that calculates the size to cast the argument
 * @format: the formatted string to print the argument
 * @x: argument list to be printed
 * Return: Precision
 */

int get_size(const char *format, int *x)
{
	int c_x = *x + 1;
	int size = 0;

	if (format[c_x] == 'l')
		size = S_LONG;
	else if (format[c_x] == 'h')
		size = S_SHORT;

	if (size == 0)
		*x = c_x - 1;
	else
		*x = c_x;

	return (size);
}
