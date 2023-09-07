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
    ssize_t n_read;

    (void)ac; (void)argv;

    while (1)
    {
        /* Print off the prompt before the user input */
        _puts(PROMPT);

        /* Check if getline failed or CTRL+D was pressed */
        n_read = getline(&lineptr, &n, stdin);
        if (n_read == -1)
            return (-1);

        _puts(lineptr);

        /* Frees the pointer after the operations are done for reuse */
        free(lineptr);
    }

	return (1);
}
