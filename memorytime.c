#include "shell.h"

/**
 * _memset - A function that fills the memory with a constant byte.
 *
 * @String: The pointer to the memory area.
 * @Byte: The byte to fill the string with.
 * @n: The amount of bytes to be files.
 *
 * Return: A pointer to the memory area of String.
*/
char *_memset(char *String, char Byte, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		String[i] = Byte;
	return (String);
}

/**
 * freeStrings - A function that frees a string of strings
 *
 * @Strings: The string of strings.
*/
void freeStrings(char **Strings)
{
	char **begin = Strings;

	if (!Strings)
		return;

	while (*Strings)
		free(*Strings++);
	free(begin);
}

/**
 * freeNull - A function that frees a pointer and NULLs the address.
 *
 * @Ptr: The pointer to be freed.
 *
 * Return: 1 if freed otherwise 0.
*/
int freeNull(void **Ptr)
{
	if (Ptr && *Ptr)
	{
		free(*Ptr);
		*Ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 * _realloc - A function that reallocates a block of memory
 *
 * @Ptr: The pointer to previous malloc'ated block.
 * @oldSize: The byte size of previous block.
 * @newSize: The byte size of new block.
 *
 * Return: A pointer to the new allocated block.
 */
void *_realloc(void *Ptr, unsigned int oldSize, unsigned int newSize)
{
	char *ptr;

	if (!Ptr)
		return (malloc(newSize));
	if (!newSize)
		return (free(Ptr), NULL);
	if (newSize == oldSize)
		return (Ptr);

	ptr = malloc(newSize);
	if (!ptr)
		return (NULL);

	oldSize = oldSize < newSize ? oldSize : newSize;
	while (oldSize--)
		ptr[oldSize] = ((char *)Ptr)[oldSize];

	free(Ptr);
	return (ptr);
}
