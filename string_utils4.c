#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok(char *String, char *Delimiter)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (String == NULL || String[0] == 0)
		return (NULL);
	if (!Delimiter)
		Delimiter = " ";
	for (i = 0; String[i] != '\0'; i++)
		if (!is_delim(String[i], Delimiter) && (is_delim(String[i + 1], Delimiter) || !String[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(String[i], Delimiter))
			i++;
		k = 0;
		while (!is_delim(String[i + k], Delimiter) && String[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = String[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **_strtok2(char *String, char Destination)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (String == NULL || String[0] == 0)
		return (NULL);
	for (i = 0; String[i] != '\0'; i++)
		if ((String[i] != Destination && String[i + 1] == Destination) ||
		    (String[i] != Destination && !String[i + 1]) || String[i + 1] == Destination)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (String[i] == Destination && String[i] != Destination)
			i++;
		k = 0;
		while (String[i + k] != Destination && String[i + k] && String[i + k] != Destination)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = String[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
