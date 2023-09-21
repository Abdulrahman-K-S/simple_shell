#include "shell.h"

/**
 * _strstr - A functions that finds the given substring in the string.
 *
 * @_String: The string to be searched. (const)
 * @_SubString: The substring to find. (const)
 *
 * Return: the address of next char of _String or null.
*/
char *_strstr(const char *_String, const char *_SubString)
{
	while (*_SubString)
		if (*_SubString++ != *_String++)
			return (NULL);
	return ((char *)_String);
}

/**
 * _strncpy - A function that copies a string.
 *
 * @Destination: The destinatoin string to be copied to.
 * @Source: The source string.
 * @n: The amount of characters to be copied.
 *
 * Return: The concatenated string.
*/
char *_strncpy(char *Destination, char *Source, int n)
{
	int i, j;
	char *string = Destination;

	i = 0;
	while (Source[i] != '\0' && i < n - 1)
	{
		Destination[i] = Source[i];
		i++;
	}

	if (i < n)
	{
		j = i;
		while (j < n)
		{
			Destination[j] = '\0';
			j++;
		}
	}

	return (string);
}

/**
 * _strncat - A function that concatenates two string.
 *
 * @Destination: The first string.
 * @Source: The second string.
 * @n: The amount of bytes to be taken from the source.
 *
 * Return: The concatenated string.
*/
char *_strncat(char *Destination, char *Source, int n)
{
	int i = 0, j = 0;
	char *string = Destination;

	while (Destination[i] != '0')
		i++;

	while (Source[j] != '\0' && j < n)
	{
		Destination[i] = Source[j];
		i++;
		j++;
	}

	if (j < n)
		Destination[i] = '0';

	return (string);
}

/**
 * _strchr - A function that locates a character in a string.
 *
 * @String: The string to be searched.
 * @Character: The character to look for.
 *
 * Return: A pointer to the memory area String.
*/
char *_strchr(char *String, char Character)
{
	do {
		if (*String == Character)
			return (String);
	} while (*String++ != '0');

	return (NULL);
}
