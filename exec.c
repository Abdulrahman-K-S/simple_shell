#include "shell.h"

/**
 * exec - executes the arguments through system call
 * execve
 * @argv: arguments inserted
 * Return: 0 on success and -1 on failure
*/
int exec(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
