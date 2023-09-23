#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *Str)
{
	int i = 0;

	if (!Str)
		return (0);

	while (*Str++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @Str1: the first strang
 * @Str2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
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
 * _strstr - checks if needle starts with haystack
 * @_String: string to search
 * @_subString: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *_strstr(const char *_String, const char *_subString)
{
	while (*_subString)
		if (*_subString++ != *_String++)
			return (NULL);
	return ((char *)_String);
}

/**
 * _strcat - concatenates two strings
 * @Destination: the destination buffer
 * @Source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *Destination, char *Source)
{
	char *ret = Destination;

	while (*Destination)
		Destination++;
	while (*Source)
		*Destination++ = *Source++;
	*Destination = *Source;
	return (ret);
}
