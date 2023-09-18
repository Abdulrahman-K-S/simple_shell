#include "shell.h"

/**
 * main - The starting point for the shell project
 *
 * @ac: Number of comandline arguments.
 * @argv: Pointer to an array of command line arguments.
 * @env: The enviroment variable.
 *
 * Return: 1 indicating a success. -1 if there was an error.
*/
int main(int ac, char **argv, char **env)
{
	char *command;
	char *lineptr;
	size_t n = 0;
	int numOFtokens, i;

	(void)ac;

	while (1)
	{
		/* Print off the prompt before the user input */
		_puts(PROMPT);

		/* Check if getline failed or CTRL+D was pressed */
		if (getline(&lineptr, &n, stdin) == -1)
		{
			_putchar('\n');
			return (-1);
		}

		numOFtokens = getNumberofTokens(lineptr);

		argv = malloc(sizeof(char *) * numOFtokens);
		storeTokens(argv, lineptr);

		command = path_finder(argv[0]);
		if (command)
			argv[0] = command;
		else
		{
			_puts(ERROR);
			continue;
		}

		if (exec(argv, env) == -1)
			_puts(ERROR);


		/* Frees the pointer after the operations are done for reuse */
		i = 0;
		while (argv[i] != NULL)
		{
			if (argv[i])
				free(argv[i]);
			i++;
		}
		free(argv);
		free(lineptr);
		free(command);
	}

	return (1);
}
