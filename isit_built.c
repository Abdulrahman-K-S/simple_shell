#include "shell.h"

/**
 * is_built - A functions that checks whether the inputed tokens
 *            a built-in function or not.
 *
 * @argv: Argument pointer.
 * @lineptr: The inputed string.
 *
 * Return: 0 if it's a built-in function. 1 otherwise.
*/
int is_built(char **argv, char *lineptr)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit_shell(argv, lineptr);
		return (0);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_enviroment();
		return (0);
	}

	return (1);
}

/**
 * exit_shell - A function that clears all the allocated variables
 *              and exits the shell.
 *
 * @argv: Argument pointer.
 * @lineptr: The inputed string.
*/
void exit_shell(char **argv, char *lineptr)
{
	unsigned int i = 0;

	if (lineptr)
		free(lineptr);

	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);

			i++;
		}

		free(argv);
	}

	exit(0);
}

/**
 * print_enviroment - A function that prints the enviroment.
*/
void print_enviroment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}
}
