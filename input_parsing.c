#include "shell.h"

/**
 * getNumberofTokens - A function that divides the inputed string and returns
 *                     how many words are in it. (Including the '\0')
 *
 * @lineptr: Char pointer.
 *
 * Return: The number of words/tokens in @lineptr.
*/
int getNumberofTokens(char *lineptr)
{
	int num_of_tokens = 0;
	char *token, *lineptr_cpy = malloc(sizeof(char) * _strlen(lineptr));

	_strcpy(lineptr_cpy, lineptr);

	token = _strtok(lineptr_cpy, DELIMETER);

	while (token != NULL)
	{
		num_of_tokens++;
		token = _strtok(NULL, DELIMETER);
	}
	num_of_tokens++;

	free(lineptr_cpy);

	return (num_of_tokens);
}

/**
 * storeTokens - A function that takes the inputed command and
 *               breaks it down to tokens and place those tokens into
 *               the argument pointer.
 *
 * @argv: The argument pointer.
 * @lineptr: The command the user inputed.
*/
void storeTokens(char **argv, char *lineptr)
{
	int i;
	char *token, *lineptr_cpy = malloc(sizeof(char) * _strlen(lineptr));

	_strcpy(lineptr_cpy, lineptr);

	token = _strtok(lineptr_cpy, DELIMETER);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);

		token = _strtok(NULL, DELIMETER);
	}

	argv[i] = NULL;

	free(lineptr_cpy);
}

/**
 * is_empty - checks to see if given user input is empty or not
 * and returns 0 if empty or just spaces are used
 * @lineptr: user input
 *
 * Return: 0 if nothing is entered and if something is entered
*/
int is_empty(char *lineptr)
{
	int i = 0;
	int pos = 0;

	if (_strlen(lineptr) == 0 || lineptr[0] == '\n')
		return (0);

	while (lineptr[i])
	{
		if (lineptr[i] > 32)
			pos++;
		i++;
	}

	if (pos > 0)
		return (1);

	return (0);
}
