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
