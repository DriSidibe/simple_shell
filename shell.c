#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "printf.h"
#include "printf_.h"
#include "functions.h"

/**
 * main - check the code
 * @argc: the number of argument
 * @argv: the list of argument
 *
 * Return: Always 0.
 */
int main(void)
{

	char *cmd;
	char *newargv[] = {"exe_cmd", NULL, NULL};
	FILE *stream = stdin;
	int isLaunched = 0;
	pid_t pid;
	size_t cmd_len = 255;
	char *envp[] = {NULL};

	while (isLaunched == 0)
	{
		_printf("#cisfun$ ");
		pid = fork();

		if (pid == -1)
			return (1);
		else if (pid != 0)
			wait(NULL);
		else
		{
			if (getline(&cmd, &cmd_len, stream) != _strlen(cmd))
				return (1);

			newargv[1] = cmd;

			if (execve(newargv[0], newargv, envp) == -1)
				return (1);
		}
	}
	return (0);
}
