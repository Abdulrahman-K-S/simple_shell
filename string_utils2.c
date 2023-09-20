#include "shell.h"

/**
 * ayto - checks if the chracter is the delimeter (Are You The One)
 * @z: char being matched
 * @delim: input string
 * Return: 1 if character matches delimeter
 */
int ayto(char z, const char *delim)
{
	while (*delim && delim)
	{
		if (z == *delim)
		{
			return (1);
		}
		++delim;
	}
	return (0);
}

/**
 * _strtok - creates an array of tokens
 * @input: input string
 * @delim: delimater " "
 * Return: pointer to head of list PATH
*/
char *_strtok(char *input, const char *delim)
{
	static char *w;
	static unsigned int v;
	char *tokens = NULL;
	int control = 0;

	if (input)
	{
		w = input;
		for (v = 0; w[v]; v++)
		{
			if (ayto(w[v], delim))
				w[v] = '\0';
		}
	}

	if (w == NULL || *w == '\0')
		return (NULL);
	tokens = w;
	v = _strlen(w);
	if (w[v] == '\0' && _strlen(w) > 0)
		control = 1;
	w = w + _strlen(w) + control;
	return (tokens);
}
