#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "printf.h"
#include "printf_.h"

/**
 * _printf - print a string according to a format
 * @format: the format
 * Return: the lenght of the output
*/
int _printf(const char *format, ...)
{
	int i = 0, outputLen = _strlen(format), tmp_nbr;
	va_list args;

	va_start(args, format);
	while (i < _strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')
				outputLen += _strlen(_print_str(va_arg(args, char *))) - 2;
			else if (format[i + 1] == 'c')
				outputLen -= _print_char(va_arg(args, int), 1);
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				tmp_nbr = va_arg(args, int);
				_print_int(tmp_nbr);
				outputLen += _int_len(tmp_nbr) - 2;
			}
			else if (format[i + 1] == '%')
				outputLen -= _print_char('%', 1);
			else
			{
				_print_char(format[i], 0);
				_print_char(format[i + 1], 0);
			}
			i += 2;
			continue;
		}
		_print_char(format[i], 0);
		i++;
	}
	va_end(args);

	return (outputLen);
}
