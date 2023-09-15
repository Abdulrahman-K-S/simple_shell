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
	char *lineptr;
	size_t n = 0;
	int numOFtokens;

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

		/* Prints how many tokens are there */
		/* printf("The number of words got are: %d\n", numOFtokens); */

		argv = malloc(sizeof(char *) * numOFtokens);
		storeTokens(argv, lineptr);

		/* Prints the words stored */
		/* for (counter = 0; counter < numOFtokens - 1; counter++)
		 *{
		 *	_puts(argv[counter]);
		 *	putchar('\n');
		 *}
		*/

		if (exec(argv) == -1)
			_puts(ERROR);

		/* Frees the pointer after the operations are done for reuse */
		free(argv);
		free(lineptr);
	}

	return (1);
}
