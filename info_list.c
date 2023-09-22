#include "shell.h"

/**
 * set_info_list - Initializes the info list given in the parameter
 *
 * @Info: The info struct.
 * @argv: The argument pointer.
*/
void set_info_list(info_t *Info, char **argv)
{
	int i;

	/* Sets the name of the program */
	Info->fname = argv[0];
	if (Info->arg)
	{
		Info->argv = _strtok(Info->arg, " \t");
		if (!Info->argv)
		{
			Info->argv = malloc(sizeof(char *) * 2);
			if (Info->argv)
			{
				Info->argv[0] = _strdup(Info->arg);
				Info->argv[1] = NULL;
			}
		}

		for (i = 0; Info->argv && Info->argv[i]; i++)
			;
		Info->argc = i;

		replace_alias(Info);
		replace_vars(Info);
	}
}

/**
 * clear_info_list - A function that clears the info struct
 *
 * @Info: The info struct.
*/
void clear_info_list(info_t *Info)
{
	Info->arg = NULL;
	Info->argv = NULL;
	Info->path = NULL;
	Info->argc = 0;
}

/**
 * free_info_list - A function that frees the entire info struct.
 *
 * @Info: The info struct.
 * @ALL: Specifing whether to clear all or not.
*/
void free_info_list(info_t *Info, int ALL)
{
	freeStrings(Info->argv);

	Info->argv = NULL;
	Info->path = NULL;

	if (ALL)
	{
		if (!Info->cmd_buf)
			free(Info->arg);
		if (Info->env)
			free_list(&(Info->env));
		if (Info->history)
			free_list(&(Info->history));
		if (Info->alias)
			free_list(&(Info->alias));

		freeStrings(Info->environ);
		Info->environ = NULL;
		freeNull((void **)Info->cmd_buf);

		if (Info->readfd > 2)
			close(Info->readfd);
		_putchar(BUF_FLUSH);
	}
}
