#include "main.h"

/*Printing a Pointer*/
/**
* print_pointer - function that prints the value of a pointer
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: get width
* @precision: specifies the precision
* @size: specifies the size
* Return: number of characters printed
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char additional_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long numb_addrs;
char set_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(size);
UNUSED(width);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

numb_addrs = (unsigned long)addrs;

while (numb_addrs > 0)
{
buffer[ind--] = set_to[numb_addrs % 16];
numb_addrs /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
additional_c = '+', length++;
else if (flags & F_SPACE)
additional_c = ' ', length++;

ind++;

/*return (write(1, &buffer[x], BUFF_SIZE - x - 1));*/
return (write_pointer(buffer, ind, length,
width, flags, padd, additional_c, padd_start));
}

/*Printing a non-printable in base 16*/
/**
* print_non_printable - function that prints ascii codes in
* hexa of non printable chars
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: get width
* @precision: specifies the precision
* @size: specifies the size
* Return: number of characters printed
*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int x = 0, offset = 0;
char *strng = va_arg(types, char *);

UNUSED(width);
UNUSED(precision);
UNUSED(flags);
UNUSED(size);

if (strng == NULL)
return (write(1, "(null)", 6));

while (strng[x] != '\0')
{
if (is_printable(strng[x]))
buffer[x + offset] = strng[x];
else
offset += append_hexa_code(strng[x], buffer, x + offset);

x++;
}

buffer[x + offset] = '\0';

return (write(1, buffer, x + offset));
}

/*Printing in reverse*/
/**
* print_reverse - function that prints string in reverse.
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: get width
* @precision: specifies the precision
* @size: specifies the size
* Return: number of characters printed
*/

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *strng;
int x, count = 0;

UNUSED(flags);
UNUSED(width);
UNUSED(buffer);
UNUSED(size);

strng = va_arg(types, char *);

if (strng == NULL)
{
UNUSED(precision);

strng = ")Null(";
}
for (x = 0; strng[x]; x++)
;

for (x = x - 1; x >= 0; x--)
{
char z = strng[x];

write(1, &z, 1);
count++;
}
return (count);
}
/*Printing a string in Rot13*/
/**
* print_rot13string - function that print a string in rot13.
* @types: list a of arguments
* @buffer: A buffer for array for handling the print
* @flags:  calculates active flags
* @width: get width
* @precision: specifies the precision
* @size: specifies the size
* Return: number of characters printed
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char i;
char *strng;
unsigned int x, y;
int count = 0;
char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

strng = va_arg(types, char *);

UNUSED(buffer);
UNUSED(precision);
UNUSED(size);
UNUSED(flags);
UNUSED(width);

if (strng == NULL)
strng = "(AHYY)";
for (x = 0; strng[x]; x++)
{
for (y = 0; input[y]; y++)
{
if (input[y] == strng[x])
{
i = output[y];
write(1, &i, 1);
count++;
break;
}
}
if (!input[y])
{
i = strng[x];
write(1, &i, 1);
count++;
}
}
return (count);
}
