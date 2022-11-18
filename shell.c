#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "printf.h"
#include "path.h"
#include "printf_.h"
#include "functions.h"

/**
 * main - check the code
 * @argc: the number of argument
 * @argv: the list of argument
 * @env: environment variables
 *
 * Return: Always 0.
 */
int main(int argc, __attribute__((unused)) char **argv, char *env[])
{

	char *cmd;
	char *newargv[] = {"exe_cmd", NULL, NULL};
	FILE *stream = stdin;
	int isLaunched = 0;
	pid_t pid;
	size_t cmd_len = 255;
	char *envp[] = {NULL, NULL};
	int i;

	argc = argc;
	for (i = 0; i != -1; i++)
	{
		envp[0] = _get_path(env[i]);
		if (envp[0] != NULL)
			break;
	}

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
			if (_strcmp(cmd, "exit") == 0)
				return (0);
			newargv[1] = cmd;
			if (execve(newargv[0], newargv, envp) == -1)
				return (1);
		}
	}
	return (-1);
}
