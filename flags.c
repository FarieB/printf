#include "main.h"

/**
 * get_flags - function that calculates active flags
 * @format: the formatted string to print arguments
 * @x: stipulates the parameter.
 * Return: flags
 */

int get_flags(const char *format, int *x)
{
	int y, c_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */

	for (c_x = *x + 1; format[c_x] != '\0'; c_x++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[c_x] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*x = c_x - 1;

	return (flags);
}
