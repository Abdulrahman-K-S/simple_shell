#include "shell.h"

/**
 **_strncpy - copies a string
 *@Destination: the destination string to be copied to
 *@Source: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *Destination, char *Source, int n)
{
	int i, j;
	char *s = Destination;

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
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@Destination: the first string
 *@Source: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *Destination, char *Source, int n)
{
	int i, j;
	char *s = Destination;

	i = 0;
	j = 0;
	while (Destination[i] != '\0')
		i++;
	while (Source[j] != '\0' && j < n)
	{
		Destination[i] = Source[j];
		i++;
		j++;
	}
	if (j < n)
		Destination[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@String: the string to be parsed
 *@Character: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *String, char Character)
{
	do {
		if (*String == Character)
			return (String);
	} while (*String++ != '\0');

	return (NULL);
}
