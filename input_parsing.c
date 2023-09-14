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

	token = strtok(lineptr_cpy, DELIMETER);

	while (token != NULL)
	{
		num_of_tokens++;
		token = strtok(NULL, DELIMETER);
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

	token = strtok(lineptr_copy, DELIMETER);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);

		token = strtok(NULL, DELIMETER);
	}

	argv[i] = NULL;

	free(lineptr_cpy);
}
