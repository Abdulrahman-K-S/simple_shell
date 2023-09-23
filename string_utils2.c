#include "shell.h"

/**
 * _strcpy - copies a string
 * @Destination: the destination
 * @Soruce: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *Destination, char *Soruce)
{
	int i = 0;

	if (Destination == Soruce || Soruce == 0)
		return (Destination);
	while (Soruce[i])
	{
		Destination[i] = Soruce[i];
		i++;
	}
	Destination[i] = 0;
	return (Destination);
}

/**
 * _strdup - duplicates a string
 * @_String: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *_String)
{
	int length = 0;
	char *ret;

	if (_String == NULL)
		return (NULL);
	while (*_String++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--_String;
	return (ret);
}

/**
 *_puts - prints an input string
 *@String: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *String)
{
	int i = 0;

	if (!String)
		return;
	while (String[i] != '\0')
	{
		_putchar(String[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @Character: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char Character)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (Character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (Character != BUF_FLUSH)
		buf[i++] = Character;
	return (1);
}
