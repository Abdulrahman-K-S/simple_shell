#include "shell.h"

/**
 * is_delim - A functions that checks if character is a delimeter or not.
 *
 * @Character: The character to check on.
 * @Delimeter: The delimeter string.
 *
 * Return: 1 if true otherwise 0.
*/
int is_delim(char Character, char *Delimeter)
{
	while (*Delimeter)
		if (*Delimeter++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - A functions that checks if the character is from the alphabet
 *            or not.
 *
 * @Character: The character to check on.
 *
 * Return: 1 if it's from the alphabet otherwise 0
*/
int _isalpha(int Character)
{
	if ((Character >= 'a' && Character <= 'z') ||
	    (Character >= 'A' && Character <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - A function that converts a string into an integer.
 *
 * @String: The string to be converted.
 *
 * Return: 0 if no number is in the string otherwise return the converted num.
*/
int _atoi(char *String)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; String[i] != '0' && flag != 2; i++)
	{
		if (String[i] == '-')
			sign *= -1;

		if (String[i] >= '0' && String[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (String[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * strtok - A function that splits a string into words.
 *
 * @String: The inputed string.
 * @Delimiter: The delimeter string.
 *
 * Return: A pointer to an array of strings or NULL on failure.
*/
char **strtok(char *String, char *Delimiter)
{
	int i, j, k, l, numwords = 0;
	char **string;

	if (String == NULL || String[0] == 0)
		return (NULL);
	if (!Delimiter)
		Delimiter = " ";
	for (i = 0; String[i] != '0'; i++)
		if (!is_delim(String[i], Delimiter) &&
		    (is_delim(String[i + 1], Delimiter) || !String[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	string = malloc(sizeof(char *) * (numwords + 1));
	if (!string)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(String[i], Delimiter))
			i++;
		k = 0;
		while (!is_delim(String[i + k], Delimiter) && String[i + k])
			k++;
		string[j] = malloc(sizeof(char *) * (k + 1));
		if (!string[j])
		{
			for (k = 0; k < j; k++)
				free(string[k]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			string[j][l] = String[i++];
		string[j][l] = 0;
	}
	string[j] = NULL;
	return (string);
}
