#include "shell.h"

/**
 * exec - executes the arguments through system calls
 * execve, fork and wait
 * @argv: arguments inserted
 * @env: The enviroment variable.
 * Return: 0 on success and -1 on failure
*/
int exec(char **argv, char **env)
{
	pid_t pid;
	int status;
	char *command;

	pid = fork();
	if (pid < 0)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		command = path_finder(argv[0]);
		if (command)
			argv[0] = command;

		if (execve(argv[0], argv, env) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
