#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "printf.h"
#include "printf_.h"

/**
 * main - check the code
 * @argc: the number of argument
 * @argv: the list of argument
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int nbr_wrd = _count_word(argv[1]);
	char **newargv = malloc(sizeof(char) * _strlen(argv[1]));
	char *str = malloc(_strlen(argv[1]) * sizeof(char));
	int i, cursor = 0;

	for (i = 0; i < nbr_wrd; i++)
	{
		newargv[i] = _get_first_word(argv[1], str, cursor);
		cursor += _strlen(newargv[i]) + 1;
		str = malloc(_strlen(argv[1]) * sizeof(char));
	}

	newargv[nbr_wrd] = NULL;

	if (access(newargv[0], X_OK) == 0)
	{
		if (execve(newargv[0], newargv, NULL) == -1)
		{
			perror("in execve");
			return (1);
		}
	}
	else
	{
		free(str);
		perror("file not exist");
	}

	free(str);
	return (0);
}
