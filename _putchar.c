#include "shell.h"

/**
 * _putchar - A function that writes out a character.
 *
 * @c: A character entered to write to std.
 *
 * Return: 1 if the write was successful otherwise -1.
*/

void _putchar(char c)
{
	write(1, &c, 1);
}
