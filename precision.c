#include "main.h"

/**
* get_precision - function that calculates the precision for printing
* @format: the formatted string to print arguments
* @i: argument list to be printed
* @list: argument list
* Return: Precision
*/

int get_precision(const char *format, int *i, va_list list)
{
int c_i = *i + 1;
int precision = -1;

if (format[c_i] != '.')
return (precision);

precision = 0;

for (c_i += 1; format[c_i] != '\0'; c_i++)
{
if (is_digit(format[c_i]))
{
precision *= 10;
precision += format[c_i] - '0';
}
else if (format[c_i] == '*')
{
c_i++;
precision = va_arg(list, int);
break;
}
else
break;
}

*i = c_i - 1;

return (precision);
}
