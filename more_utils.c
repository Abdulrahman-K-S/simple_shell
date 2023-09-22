#include "shell.h"

/**
 * interactive - A function that returns true if the shell is in
 *               interactive mode.
 *
 * @info: The struct address.
 *
 * Return: 1 if in interactive mode otherwise 0.
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * print_d - A function that prints a decimal number (base 10).
 *
 * @Input: The input to print.
 * @File: The file descriptor to write to.
 *
 * Return: The number of characters printed.
*/
int print_d(int Input, int File)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (File == STDERR_FILENO)
		__putchar = _eputchar;
	if (Input < 0)
	{
		_abs_ = -Input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = Input;
	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - A converter function that converts the number into string.
 *
 * @Number: The number.
 * @Base: The base to be divided on.
 * @Flag: The argument flag.
 *
 * Return: The converted number into a string.
*/
char *convert_number(long int Number, int Base, int Flag)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = Number;

	if (!(Flag & CONVERT_UNSIGNED) && Number < 0)
	{
		n = -Number;
		sign = '-';
	}
	array = Flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % Base];
		n /= Base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - A function that replaces the first instance of
 *                   '#' with a '\0'.
 *
 * @Buffer: The address of the string to be modifed. (aka the input)
*/
void remove_comments(char *Buffer)
{
	int i;

	for (i = 0; Buffer[i] != '\0'; i++)
		if (Buffer[i] == '#' && (!i || Buffer[i - 1] == ' '))
		{
			Buffer[i] = '\0';
			break;
		}
}
