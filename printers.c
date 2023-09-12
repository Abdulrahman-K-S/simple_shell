#include "shell.h"

/**
 * _puts - prints a string
 *
 * @s: string input
*/

void _puts(char *s)
{
	while (*s)
		_putchar(*s++);
}

/**
 * _putchar - A function that writes out a character.
 *
 * @c: A character entered to write to std.
*/

void _putchar(char c)
{
	write(1, &c, 1);
}
