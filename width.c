#include "main.h"

/**
* get_width - function that calculates the printing width
* @format: The formatted string to print the arguments
* @x: the list of arguments to be printed
* @index: argument list
*
* Return: width.
*/
int get_width(const char *format, int *x, va_list index)
{
int c_x;
int width = 0;

for (c_x = *x + 1; format[c_x] != '\0'; c_x++)
{
if (is_digit(format[c_x]))
{
width *= 10;
width += format[c_x] - '0';
}
else if (format[c_x] == '*')
{
c_x++;
width = va_arg(index, int);
break;
}
else
break;
}

*x = c_x - 1;

return (width);
}
