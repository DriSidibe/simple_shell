#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "printf.h"
#include "printf_.h"

/**
 * _get_first_word - get the first word of a string
 * @s: the string
 * @str: ...
 * @j: the cursor
 *
 * Return: a pointer to the word
 */
char *_get_first_word(char *s, char *str, int j)
{
	int i, k = 0;

	if (str != NULL)
	{
		for (i = j; s[i] != '\0'; i++)
		{
			str[k] = s[i];
			if (s[i + 1] == ' ' || s[i + 1] == '\0' || s[i + 1] == '\n')
				return (str);
			k++;
		}
	}
	else
	{
		_printf("error get_first_word");
		return (NULL);
	}
	return (str);
}

/**
 * _count_word - count the number of word
 * @s: the string to format
 *
 * Return: the number of word
 */
int _count_word(char *s)
{
	int nbr_wrd = 0;
	int i;

	for (i = 0; i < _strlen(s) - 2; i++)
	{
		if (s[i] != ' ' && s[i + 1] == ' ')
			if (s[i + 2] != ' ')
				nbr_wrd++;
	}
	return (nbr_wrd + 1);
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
