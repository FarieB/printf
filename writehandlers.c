#include "main.h"

/*Writing a handle */

/**
 * handle_write_char - function that prints a string
 * @c: character types.
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: specifies the precision
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	char padd = ' ';
	int x = 0;

	UNUSED(size);
	UNUSED(precision);


	if (flags & F_ZERO)
		padd = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/*Writing a number */

/**
 * write_number - function that prints a string
 * @is_negative: List of arguments
 * @ind: character types.
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: specifies the precision
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_numb(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_numb - function that writes a number using a bufffer
 * @ind: the Index where the number starts on the buffer
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @width: get width
 * @prec: specifies the precision
 * @length: length of the number
 * @padd: Padding character
 * @additional_c: additional character
 *
 * Return: Number of printed chars.
 */
int write_numb(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char additional_c)
{
	int x, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (additional_c != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (additional_c)
				buffer[--ind] = additional_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (additional_c)
				buffer[--ind] = additional_c;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (additional_c)
				buffer[--padd_start] = additional_c;
			return (write(1, &buffer[padd_start], x - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (additional_c)
		buffer[--ind] = additional_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - function that writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: the Index where the number starts on the buffer
 * @buffer: A buffer for array for handling the print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: specifies the precision
 * @size: Size specifier
 *
 * Return: Number of written characters.
 */

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, x = 0;
	char padd = ' ';

	UNUSED(size);
	UNUSED(is_negative);


	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = padd;

		buffer[x] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - function that writes a memory address
 * @buffer: Arrays of characters
 * @ind: the Index where the number starts on the buffer
 * @length: the length of number
 * @flags:  calculates active flags
 * @width: get width
 * @padd: padding character
 * @additional_c: additional character
 * @padd_start: the index where padding starts
 *
 * Return: Number of written characters.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char additional_c, int padd_start)
{
	int x;

	if (width > length)
	{
		for (x = 3; x < width - length + 3; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (additional_c)
				buffer[--ind] = additional_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (additional_c)
				buffer[--ind] = additional_c;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (additional_c)
				buffer[--padd_start] = additional_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], x - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (additional_c)
		buffer[--ind] = additional_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
