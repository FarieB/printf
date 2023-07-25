#include "main.h"

/**
* is_printable - function that evaluates if a character is printable
* @c: Character to be evaluated.
*
* Return: 1 if c is printable & 0 if otherwise
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
* append_hexa_code - function that append ascci in hexadecimal code to buffer
* @x: the index where appending starts
* @buffer: Array of characters.
* @ascii_code: ASSCI CODE
* Return: Always 3
*/
int append_hexa_code(char ascii_code, char buffer[], int x)
{
char set_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;

buffer[x++] = '\\';
buffer[x++] = 'x';

buffer[x++] = set_to[ascii_code / 16];
buffer[x] = set_to[ascii_code % 16];

return (3);
}

/**
* is_digit - function that verifies if a character is a digit
* @c: Character to be evaluated
*
* Return: 1 if c is a digit,
* Return: 0 if otherwise
*/
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
* convert_size_number - function that casts a number to the specified size
* @numb: number to be casted.
* @size: number indicating the type to be casted.
*
* Return: casted value of numbers
*/
long int convert_size_number(long int numb, int size)
{
if (size == S_LONG)
return (numb);
else if (size == S_SHORT)
return ((short)numb);

return ((int)numb);
}

/**
* convert_size_unsgnd - function that casts a unsigned
* number to the specified size
* @numb: unsigned number to be casted
* @size: number indicating the size to be casted
*
* Return: casted value of numb
*/
long int convert_size_unsgnd(unsigned long int numb, int size)
{
if (size == S_LONG)
return (numb);
else if (size == S_SHORT)
return ((unsigned short)numb);

return ((unsigned int)numb);
}
