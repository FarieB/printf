#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#ifndef MAIN_H
#define MAIN_H

#define UNUSED(i) (void)(i)
#define BUFF_SIZE 1024

/*Macros defining size*/
#define S_LONG 2
#define S_SHORT 1

/*Macros defining Flags*/
#define F_ZERO 4
#define F_HASH 8
#define F_MINUS 1
#define F_PLUS 2
#define F_SPACE 16

/**
* struct fmt - Struct op
*
* @fmt: format
* @fn: function associated
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - Struct op
* @fmt: format
* @fm_t: function associated
*/
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *x,
va_list index, char buffer[], int flags, int width, int precision, int size);

/*Functions Prototypes*/

/*Func that prints numbers*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_hexa(va_list types, char set_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/*Func that prints a non-printable characters*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Func that print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Func that handle other specifiers*/
int get_flags(const char *format, int *x);
int get_width(const char *format, int *x, va_list index);
int get_precision(const char *format, int *x, va_list index);
int get_size(const char *format, int *x);

/*Func that prints strings in reverse*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Func for width handler*/
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_numb(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char additional_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char additional_c, int padd_start);
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);

int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

/*Func that prints strings in rot 13*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Utils*/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int numb, int size);
long int convert_size_unsgnd(unsigned long int numb, int size);

/*Func that prints characters and strngs*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);

#endif
