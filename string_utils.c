#include "shell.h"

/**
 * _strlen - A function that returns the size of the
 *           inputed string
 *
 * @s: char pointer
 *
 * Return: The size of the inputed string
*/
int _strlen(char *s)
{
	int size = 0;

	while (*s != '\0')
	{
		size++;
		s++;
	}

	return (size);
}

/**
 * _strcpy - A function that copies the string pointed to by src,
 *            including the terminating null byte (\0),
 *            to the buffer pointed to by dest.
 *
 * @dest: char pointer
 * @src: char pointer
 *
 * Return: The (dest) pointer that houses a copy of src.
*/
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @f: first string to be concatenated
 * @s: second string to be concatenated
 *
 * Return: a string combining both strings
*/
char *_strcat(char *f, char *s)
{
	char *combined;
	int i = 0, j = 0;

	combined = malloc(sizeof(char *) * (_strlen(f) + _strlen(s)) + 1);
	if (!combined)
	{
		return (NULL);
	}

	while (f[i])
	{
		combined[i] = f[i];
		i++;
	}
	while (s[j])
	{
		combined[i] = s[j];
		i++;
		j++;
	}
	combined[i] = '\0';

	return (combined);
}

/**
 * _strdup - A function that duplicates the string parameter
 *
 * @String: The string to be duplicated.
 *
 * Return: A duplicate of the parameter.
*/
char *_strdup(const char *String)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * strlen(String) + 1);
	if (!str)
		return (NULL);

	while (String[i])
	{
		str[i] = String[i];
		i++;
	}

	str[i] = '\0';
	return (str);
}

/**
 * _strcmp - A function that compares two strings.
 *
 * @First: 1st string.
 * @Second: 2nd string.
 *
 * Return: 0 if they're equal otherwise the difference between them.
*/
int _strcmp(const char *First, const char *Second)
{
	while ((*First != '\0' && *Second != '\0') && (*First == *Second))
	{
		First++;
		Second++;
	}

	if (*First == '\0' && *Second == '\0')
		return (0);
	else
		return ((int)(*First - *Second));
}
