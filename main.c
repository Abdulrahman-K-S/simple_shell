#include "shell.h"

/**
 * main - The starting point for the shell project
 *
 * @ac: Number of comandline arguments.
 * @argv: Pointer to an array of command line arguments.
 *
 * Return: 1 indicating a success. -1 if there was an error.
*/
int main(int ac, char **argv)
{
	char *lineptr, *first, *second;
	size_t n = 0;
	int numOFtokens, status;

	(void)ac;
	second = _strdup(argv[0]);
	status = 1;
	while (status)
	{
		/* Print off the prompt before the user input */
		_puts(PROMPT);
		/* Check if getline failed or CTRL+D was pressed */
		if (getline(&lineptr, &n, stdin) == -1)
		{
			_putchar('\n');
			status = 0;
			break;
		}
		else
		{
			if (is_empty(lineptr) == 0)
				continue;

			numOFtokens = getNumberofTokens(lineptr);
			argv = malloc(sizeof(char *) * numOFtokens);
			storeTokens(argv, lineptr);
		    first = _strdup(argv[0]);
			if (is_built(argv, lineptr) == 1)
			{
				if (exec(argv, NULL) == -1)
				{
					_puts(second);
					_puts(": 1: ");
					_puts(first);
					_puts(": not found\n");
				}
			}
		}
	}
	return (1);
}







