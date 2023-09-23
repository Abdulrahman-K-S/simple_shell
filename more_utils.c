#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @Info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *Info)
{
	return (isatty(STDIN_FILENO) && Info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @Character: the char to check
 * @Delimiter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char Character, char *Delimiter)
{
	while (*Delimiter)
		if (*Delimiter++ == Character)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@Character: The character to input
 *Return: 1 if Character is alphabetic, 0 otherwise
 */

int _isalpha(int Character)
{
	if ((Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@String: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *String)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  String[i] != '\0' && flag != 2; i++)
	{
		if (String[i] == '-')
			sign *= -1;

		if (String[i] >= '0' && String[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (String[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
