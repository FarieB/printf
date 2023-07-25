#include "main.h"

/**
* get_precision - function that calculates the precision for printing
* @format: the formatted string to print arguments
* @x: argument list to be printed
* @index: argument list
* Return: Precision
*/

int get_precision(const char *format, int *x, va_list index)
{
int c_x = *x + 1;
int precision = -1;

if (format[c_x] != '.')
return (precision);

precision = 0;

for (c_x += 1; format[c_x] != '\0'; c_x++)
{
if (is_digit(format[c_x]))
{
precision *= 10;
precision += format[c_x] - '0';
}
else if (format[c_x] == '*')
{
c_x++;
precision = va_arg(index, int);
break;
}
else
break;
}

*x = c_x - 1;

return (precision);
}
