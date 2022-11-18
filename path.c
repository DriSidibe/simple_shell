#include <stdlib.h>
#include <unistd.h>
#include "printf_.h"
#include "printf.h"
#include "functions.h"
#include "path.h"

/**
 * _get_path - geth the path variable
 * @env: the env
 * Return: ...
*/
char *_get_path(char *env)
{

	char *str = malloc(sizeof(char) * _strlen(env));
	int i;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (env[i] == '=')
		{
			if (_strcmp(str, "PATH") == 0)
				return (env);
		}
		str[i] =  env[i];
	}
	return (NULL);
}

/**
 * _count_slash - count the number of slash in a string
 * @s: the string
 *
 * Return: the number of slash
 */
int _count_slash(char *s)
{
	int count = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '/')
			count++;
	}
	return (count);
}

/**
 * _strcct - concatanate two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: the new string
 */
char *_strcct(char *s1, char *s2)
{
	int i, j;
	char *res = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2)));

	_strcpy(s1, res);
	j = _strlen(res);

	for (i = 0; s2[i] != '\0'; i++)
	{
		res[j] = s2[i];
		j++;
	}

	return (res);
}

/**
 * _test_path_exist - test if the path exist
 * @cmd: ..
 * @path: ..
 *
 * Return: ..
 */
char *_test_path_exist(char *cmd, char *path)
{
	char *scmd = malloc(_strlen(cmd) * sizeof(char));
	char *str = NULL;
	char *str2 = NULL;
	char *str3 = NULL;
	int nbr_wrd, cursor, i;

	scmd = _strcct("/", cmd);
	nbr_wrd = _count_word(path, ':');
	cursor = 0;
	for (i = 0; i < nbr_wrd; i++)
	{
		str = malloc(_strlen(path) * sizeof(char));
		str2 = malloc(_strlen(path) * sizeof(char));
		str3 = malloc(_strlen(path) * sizeof(char));
		str3 = _get_first_word(path, str2, ':', cursor);
		str = _strcct(str3, scmd);

		if (access(str, X_OK) == 0)
			return (str);
		cursor += _strlen(str3) + 1;
	}

	return (cmd);
}
