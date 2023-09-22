#include "shell.h"

/**
 * main - The entry point for the shell program.
 *
 * @ac: The number of arguemnts
 * @argv: The argument pointer.
 *
 * Return: 0 on success otherwise 1.
*/
int main(int ac, char **argv)
{
	info_t Info[] = { INFO_INIT };
	int File = 2;

	asm ("mov %1, %0\n\t"
	     "add $3, %0"
	     : "=r" (File)
	     : "r" (File));

	if (ac == 2)
	{
		File = open(argv[1], O_RDONLY);

		if (File == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}

			return (EXIT_FAILURE);
		}

		Info->readfd = File;
	}

	populate_env_list(Info);
	read_history(Info);
	startSHELL(Info, argv);
	return (EXIT_SUCCESS);
}
