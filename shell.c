#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "printf.h"
#include "path.h"
#include "printf_.h"
#include "functions.h"

/**
 * _rest_sh - check the code
 * @tmp_s2: the list of argument
 * @cmd: environment variables
 * @newargv: ...
 * @command: ...
 *
 * Return: Always 0.
 */
int _rest_sh(char *tmp_s2, char *cmd, char **newargv, char *command)
{
	char *tmp_s3 = NULL;
	char *tmp_s1 = NULL;
	pid_t pid;

	if (_strcmp(tmp_s2, command) != 0 || access(tmp_s2, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		else if (pid != 0)
			wait(NULL);
		else
		{
			tmp_s1 = malloc(sizeof(char) * _strlen(cmd));
			tmp_s3 = malloc(sizeof(char) * _strlen(cmd));
			tmp_s3 = _get_first_word(cmd, tmp_s1, ' ', _strlen(command) + 1);
			newargv[1] = _strcct(_strcct(tmp_s2, " "), tmp_s3);
			if (execve(newargv[0], newargv, NULL) == -1)
				return (1);
		}
	}
	else
		_printf("command not found\n");

	return (0);
}

/**
 * _print_env - print environment viriables
 * @env: ...
 */
void _print_env(char **env)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		_printf("%s\n", env[i]);
	}
}

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
	int is_launched = 0, i;
	FILE *stream = stdin;
	size_t cmd_len = 255;
	char *path[] = {NULL};
	char *tmp_s1, *tmp_s2;
	char *command = NULL;
	char *newargv[] = {"exe_cmd", NULL, NULL};

	argc = argc;
	for (i = 0; i != -1; i++)
	{
		path[0] = _get_path(env[i]);
		if (path[0] != NULL)
			break;
	}
	tmp_s1 = malloc(sizeof(char) * _strlen(path[0]));
	path[0] = _get_first_word(path[0], tmp_s1, '\0', 5);
	while (is_launched == 0)
	{
		_printf("#cisfun$ ");
		if (getline(&cmd, &cmd_len, stream) != _strlen(cmd))
			return (1);
		if (_strcmp(cmd, "exit\n") == 0)
			return (0);

		if (_strcmp(cmd, "env\n") == 0)
			_print_env(env);
		tmp_s1 = malloc(sizeof(char) * _strlen(cmd));
		tmp_s2 = malloc(sizeof(char) * _strlen(path[0]));
		command = malloc(sizeof(char) * _strlen(cmd));
		command = _get_first_word(cmd, tmp_s1, ' ', 0);
		tmp_s2 = _test_path_exist(command, path[0]);
		_rest_sh(tmp_s2, cmd, newargv, command);
	}
	return (0);
}
