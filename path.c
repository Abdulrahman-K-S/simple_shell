#include "shell.h"

/**
 * find_path - A function that finds the cmd in the path string.
 *
 * @Info: The info struct.
 * @PathSTRING: The PATH string.
 * @cmd: The cmd to find.
 *
 * Return: The full path of cmd if found otherwise NULL.
*/
char *find_path(info_t *Info, char *PathSTRING, char *cmd)
{
	int i = 0, currentPosition = 0;
	char *PATH;

	if (!PathSTRING)
		return (NULL);
	if ((_strlen(cmd) > 2) && _strstr(cmd, './'))
	{
		if (is_cmd(Info, cmd))
			return (cmd);
	}

	while (1)
	{
		if (!PathSTRING[i] || PathSTRING[i] == ':')
		{
			PATH = dup_chars(PathSTRING, currentPosition, i);
			if (!*PATH)
				_strcat(PATH, cmd);
			else
			{
				_strcat(PATH, "/");
				_strcat(PATH, cmd);
			}
			if (is_cmd(Info, PATH))
				return (PATH);
			if (!PathSTRING[i])
				break;

			currentPosition = i;
		}

		i++;
	}
	return (NULL);
}

/**
 * is_cmd - A function that determines if a file is an exectuable command
 *          or not.
 *
 * @Info: The info struct.
 * @Path: The path string.
 *
 * Return: 1 if true otherwise 0.
*/
int is_cmd(info_t *Info, char *Path)
{
	struct stat st;

	(void)Info;
	if (!Path || stat(Path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
		return (1);

	return (0);
}

/**
 * dup_chars - A function that duplicates characters.
 *
 * @PathSTRING: The path string.
 * @Start: The starting index.
 * @Stop: The stopping index.
 *
 * Return: Pointer to a new buffer.
*/
char *dup_chars(char *PathSTRING, int Start, int Stop)
{
	static char Buffer[1024];
	int i = 0, k = 0;

	for (k = 0, i = Start; i < Stop; i++)
		if (PathSTRING[i] != ':')
			Buffer[k++] = PathSTRING[i];

	Buffer[k] = 0;
	return (Buffer);
}
