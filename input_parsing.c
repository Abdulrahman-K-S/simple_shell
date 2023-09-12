#include "shell.h"

/**
 * getNumberofTokens - A function that divides the inputed string and returns
 *                     how many words are in it. (Including the '\0')
 *
 * @lineptr: Char pointer.
 *
 * Return: The number of words/tokens in @lineptr.
*/

int getNumberofTokens(const char *lineptr)
{
	int num_of_tokens = 0;
	char *token, *lineptr_cpy = malloc(sizeof(char) * strlen(lineptr));

	strcpy(lineptr_cpy, lineptr);

	token = strtok(lineptr_cpy, DELIMETER);

	while (token != NULL)
	{
		num_of_tokens++;
		token = strtok(NULL, DELIMETER);
	}
	num_of_tokens++;

	return (num_of_tokens);
}
