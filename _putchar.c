#include "shell.h"

/**
 * _putchar - A function that writes out a character.
 *
 * @c: A character entered to write to std.
*/

void _putchar(char c)
{
	write(1, &c, 1);
}
