#include "main.h"
#include <stdarg.h>
#include <stddef.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf function
 * @format: format specification
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list index;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(index, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = get_width(format, &x, index);
			precision = get_precision(format, &x, index);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, index, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(index);

	return (printed_chars);
}

/**
 * print_buffer - function that prints contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: the length of index at which to add the next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
