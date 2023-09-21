#include "shell.h"

/**
 * _strlen - A functions that returns the length of a string.
 *
 * @String: The string whose lenght to be checked.
 *
 * Return: integer lenght of the string.
*/
int _strlen(char *String)
{
	int i = 0;

	if (!String)
		return (0);

	while (*String++)
		i++;
	return (i);
}

/**
 * _strcmp - A function that performs lexicogarphic comparison of two strings.
 *
 * @Str1: The first string.
 * @Str2: The second string.
 *
 * Return: Negative if s1 < s2, Positive if s1 > s2, Zero if s1 == s2.
*/
int _strcmp(char *Str1, char *Str2)
{
	while (*Str1 && *Str2)
	{
		if (*Str1 != *Str2)
			return (*Str1 - *Str2);

		Str1++;
		Str2++;
	}

	if (*Str1 == *Str2)
		return (0);
	else
		return (*Str1 < *Str2 ? -1 : 1);
}

/**
 * _strcat - A function that concatenates two strings.
 *
 * @Destination: The destination buffer.
 * @Source: The source buffer
 *
 * Return: Pointer to destination buffer
*/
char *_strcat(char *Destination, char *Source)
{
	char *retrn = Destination;

	while (*Destination)
		Destination++;
	while (*Source)
		*Destination = *Source++;

	*Destination = *Source;
	return (retrn);
}

/**
 * _strcpy - A function that copes a string.
 *
 * @Destination: The destination to be copied to.
 * @Source: The source of the string copied.
 *
 * Return: Pointer to the destination.
*/
char *_strcpy(char *Destination, char *Source)
{
	int i = 0;

	if (Destination == Source || Source == 0)
		return (Destination);

	while (Source[i])
	{
		Destination[i] = Source[i];
		i++;
	}

	Destination[i] = 0;
	return (Destination);
}

/**
 * _strdup - A function that duplicates a string.
 *
 * @_String: The string to be duplicated. (const)
 *
 * Return: The pointer to the duplicated string.
*/
char *_strdup(const char *_String)
{
	int length = 0;
	char *retrn;

	if (_String == NULL)
		return (NULL);

	while (*_String++)
		length++;

	retrn = malloc(sizeof(char) * (length + 1));
	if (!retrn)
		return (NULL);

	for (length++; length--;)
		retrn[length] = *--_String;

	return (retrn);
}
