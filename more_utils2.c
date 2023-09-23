#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @String: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *String)
{
	int i = 0;
	unsigned long int result = 0;

	if (*String == '+')
		String++;  /* TODO: why does this make main return 255? */
	for (i = 0;  String[i] != '\0'; i++)
	{
		if (String[i] >= '0' && String[i] <= '9')
		{
			result *= 10;
			result += (String[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @Info: the parameter & return Info struct
 * @errStr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *Info, char *errStr)
{
	_eputs(Info->fname);
	_eputs(": ");
	print_d(Info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(Info->argv[0]);
	_eputs(": ");
	_eputs(errStr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fileDes: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fileDes)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fileDes == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
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
 * convert_number - converter function, a clone of itoa
 * @Number: number
 * @Base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int Number, int Base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = Number;

	if (!(flags & CONVERT_UNSIGNED) && Number < 0)
	{
		n = -Number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % Base];
		n /= Base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @Buffer: address of the string to modify
 *
 * Return: Always 0;
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
