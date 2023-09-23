#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @Info: the info struct
 * @Path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *Info, char *Path)
{
	struct stat st;

	(void)Info;
	if (!Path || stat(Path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathStr: the PATH string
 * @Start: starting index
 * @Stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathStr, int Start, int Stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = Start; i < Stop; i++)
		if (pathStr[i] != ':')
			buf[k++] = pathStr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @Info: the info struct
 * @pathStr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *Info, char *pathStr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathStr)
		return (NULL);
	if ((_strlen(cmd) > 2) && _strstr(cmd, "./"))
	{
		if (is_cmd(Info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathStr[i] || pathStr[i] == ':')
		{
			path = dup_chars(pathStr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(Info, path))
				return (path);
			if (!pathStr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
