#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{	

	int islaunched = 0;

	char *cmd, _exit[] = "exit";
	char *const *argv[3][1];
	FILE *stream = stdin;
	size_t cmd_len = 255;
	int pid;

	while (islaunched == 0)
	{

		_printf("#cisfun ");


		if ((cmd = malloc(sizeof(char) * cmd_len)) == NULL)
		{
			_printf("error cmd");
			return (1);
		}

		if (getline(&cmd, &cmd_len, stream) != _strlen(cmd))
		{
			_printf("error getline");
			return (1);
		}

		if (_strcmp(cmd, _exit) == 0)
			return (0);

		pid = fork();

		if (pid == -1)
		{
			_printf("error fork");
			return (1);
		}
		else if (pid == 0) 
		{
			free(cmd);
			wait(NULL);
		}
		else
		{
			argv[0][0] = _get_first_word(cmd);
			argv[1][0] = _format_split(cmd);
			argv[2][0] = NULL;

			if (execve(_get_first_word(cmd), argv[1][0], NULL) == -1)
			{
				_printf("error execve");
				return (1);
			}
		}
	}

	return (0);
}
