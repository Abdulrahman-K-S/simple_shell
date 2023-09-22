#include "shell.h"

/**
 * _exit - A function that exits the shell.
 *
 * @Info: The info struct.
 *
 * Return: Exits with a given exit status
 *         (0) if info.argv[0] != "exit"
*/
int _exitshell(info_t *Info)
{
	int exitCheck;

	if (Info->argv[1])
	{
		exitCheck = _erratoi(Info->argv[1]);

		if (exitCheck == -1)
		{
			Info->status = 2;
			print_error(Info, "Illegal number: ");
			_eputs(Info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		Info->err_num = _erratoi(Info->argv[1]);
		return (-2);
	}

	Info->err_num = -1;
	return (-2);
}

/**
 * _cd - A function that changes current working directory.
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
int _cd(info_t *Info)
{
	char *String, *Dir, Buffer[1024];
	int chdir_ret;

	String = getcwd(Buffer, 1024);
	if (!String)
		print_error(Info, "No such file or directory\n");
	if (!Info->argv[1])
	{
		Dir = _getenv(Info, "Home=");
		if (!Dir)
			chdir_ret = chdir((Dir = _getenv(Info, "PWD=")) ?
					  Dir : "/");
		else
			chdir_ret = chdir(Dir);
	}
	else if (_strcmp(Info->argv[1], "-") == 0)
	{
		if (!_getenv(Info, "OLDPWD="))
		{
			_puts(String);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(Info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((Dir = _getenv(Info, "OLDPWD=")) ? Dir : "/");
	}
	else
		chdir_ret = chdir(Info->argv[1]);

	if (chdir_ret == -1)
	{
		print_error(Info, "can't cd to ");
		_eputs(Info->argv[1]), _eputchar('\n');
	}
	else
	{
		__setenv(Info, "OLDPWD", _getenv(Info, "PWD="));
		__setenv(Info, "PWD", getcwd(Buffer, 1024));
	}
	return (0);
}

/**
 * _help - A function that displayes a helping message.
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
int _help(info_t *Info)
{
	char **argvArray;

	argvArray = Info->argv;
	_puts("Help call works. Function not yet implemented\n");
	if (0)
		_puts(*argvArray);
	return (0);
}

/**
 * _history - A function that displayes the history list.
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
int _history(info_t *Info)
{
	print_list(Info->history);
	return (0);
}
