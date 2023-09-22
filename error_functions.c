#include "shell.h"

/**
 * _eputs - prints an input string
 *
 * @String: the string to be printed
*/
void _eputs(char *String)
{
	int i = 0;

	if (!String)
		return;

	while (String[i] != '\0')
	{
		_eputchar(String[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 *
 * @Character: The character to be print
 *
 * Return: On success 1.
*/
int _eputchar(char Character)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (Character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (Character != BUF_FLUSH)
		buffer[i++] = Character;

	return (1);
}

/**
 * _putsfd - prints an input string.
 *
 * @String: the string to be printed
 * @File: the file descriptor to write to
 *
 * Return: the number of chars put
*/
int _putsfd(char *String, int File)
{
	int i = 0;

	if (!String)
		return (0);
	while (*String)
	{
		i += _putfd(*String++, File);
	}
	return (i);
}

/**
 * _putfd - writes the character to a given file descriptor.
 *
 * @Character: The character to be print.
 * @File: The file descriptor to write to.
 *
 * Return: On success 1.
*/
int _putfd(char Character, int File)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (Character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(File, buffer, i);
		i = 0;
	}
	if (Character != BUF_FLUSH)
		buffer[i++] = Character;

	return (1);
}

/**
 * print_error - A function that prints an error message.
 *
 * @Info: The info struct.
 * @errorString: The error string.
*/
void print_error(info_t *Info, char *errorString)
{
	_eputs(Info->fname);
	_eputs(": ");
	print_d(Info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(Info->argv[0]);
	_eputs(": ");
	_eputs(errorString);
}
