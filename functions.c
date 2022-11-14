#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

/**
 * _strlen - calculate the lenght of a str
 * @s: the string
 * Return: the lenght og s
*/
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _print_char - print a character
 * @c: the char to printed
 * @i: ...
 * Return: ...
*/
int _print_char(char c, int i)
{
	write(1, &c, 1);

	return (i);
}

/**
 * _print_str - print a string
 * @s: the string to print
 * Return: the lenght of s
*/
char *_print_str(char *s)
{
	int i;

	for (i = 0; i < _strlen(s); i++)
	{
		_print_char(s[i], 0);
	}

	return (s);
}

/**
 * _int_len - calculate the lenght of a integer
 * @i: the integer
 * Return: the lenght of i
*/
int _int_len(int i)
{
	int len = 0, j = i;

	while (j != 0)
	{
		j = (int)(j / 10);
		len++;
	}

	if (i < 0)
		len++;

	return (len);
}

/**
 *_print_int - check the code
 *@c: the parameter
 */
void _print_int(int c)
{
	unsigned int i = c;

	if (c < 0)
	{
		_print_char('-', 0);
		i = -i;
	}
	if ((i / 10) > 0)
		_print_int(i / 10);

	 _print_char((i % 10) + '0', 0);
}

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

/**
 * _get_first_word - get the first word of a string
 * @s: the string
 *
 * Return: a pointer to the word
 */
const char *_get_first_word(char *s)
{
	char *str = malloc(_strlen(s) * sizeof(char)), i;

	if (str != NULL)
	{

		for (i = 0; s[i] != '\0'; i++)
		{
			str[i] = s[i];

			if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
				return (str);
		}
	}
	else
	{
		_printf("error get_first_word");
		return (NULL);
	}
}

/**
 * _format_split - format a string
 * @s: the string to format
 *
 * Reurn: the formated string
 */
char *const *_format_split(char *s)
{
	char *str = malloc(sizeof(s) * _strlen(s));
	int i, j = 0;

	if (str != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == ' ' && s[i + 1] != ' ')
			{
				for (i = i + 1; s[i] != '\0'; i++)
				{
					*(str + j) = s[i];
					j++;
				}
				return (str);
			}
		}
	}
	else
	{
		_printf("error format_split");
		return (NULL);
	}
}

/**
 * _strcmp - compare 2 string
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}
