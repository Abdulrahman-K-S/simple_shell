#include "shell.h"

/**
 * _putchar - A function that writes the character to stdout.
 *
 * @Character: The character to be printed.
 *
 * Return: On sucess 1.
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

/**
 * _puts - A function that prints an input string.
 *
 * @String: The string to be printed.
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
