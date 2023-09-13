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
