#include "shell.h"

/**
 * startSHELL - The shell
 *
 * @Info: The info struct.
 * @argv: The argument pointer.
 *
 * Return: 0 on success otherwise 1.
*/
int startSHELL(info_t *Info, char **argv)
{
	ssize_t r = 0;
	int builtin_RET = 0;

	while (r != -1 && builtin_RET != -2)
	{
		clear_info_list(Info);
		if (interactive(Info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(Info);
		if (r != -1)
		{
			set_info_list(Info, argv);
			builtin_RET = find_builtin(Info);
			if (builtin_RET == -1)
				find_cmd(Info);
		}
		else if (interactive(Info))
			_putchar('\n');
		free_info_list(Info, 0);
	}
	write_history(Info);
	free_info_list(Info, 1);
	if (!interactive(Info) && Info->status)
		exit(Info->status);
	if (builtin_RET == -2)
	{
		if (Info->err_num == -1)
			exit(Info->status);
		exit(Info->err_num);
	}
	return (builtin_RET);
}

/**
 * find_builtin - A function that finds a builtin command.
 *
 * @Info: The info struct.
 *
 * Return: -1 if not built-in, 0 if built-in, 1 if builtin found but
 *         not succesful or -2 if built-in signals exit().
*/
int find_builtin(info_t *Info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _exitshell},
		{"env", _printenv},
		{"help", _help},
		{"history", _history},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(Info->argv[0], builtintbl[i].type) == 0)
		{
			Info->line_count++;
			built_in_ret = builtintbl[i].func(Info);
			break;
		}

	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @Info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *Info)
{
	char *path = NULL;
	int i, k;

	Info->path = Info->argv[0];
	if (Info->linecount_flag == 1)
	{
		Info->line_count++;
		Info->linecount_flag = 0;
	}
	for (i = 0, k = 0; Info->arg[i]; i++)
		if (!is_delim(Info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(Info, _getenv(Info, "PATH="), Info->argv[0]);
	if (path)
	{
		Info->path = path;
		fork_cmd(Info);
	}
	else
	{
		if ((interactive(Info) || _getenv(Info, "PATH=")
			|| Info->argv[0][0] == '/') && is_cmd(Info, Info->argv[0]))
			fork_cmd(Info);
		else if (*(Info->arg) != '\n')
		{
			Info->status = 127;
			print_error(Info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @Info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *Info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(Info->path, Info->argv, get_environ(Info)) == -1)
		{
			free_info_list(Info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(Info->status));
		if (WIFEXITED(Info->status))
		{
			Info->status = WEXITSTATUS(Info->status);
			if (Info->status == 126)
				print_error(Info, "Permission denied\n");
		}
	}
}
