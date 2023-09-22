#include "shell.h"

/**
 * input_buffer - A function that buffers chained commands.
 *
 * @Info: The info struct.
 * @Buffer: The address of the buffer.
 * @Len: The address of the len.
 *
 * Return: The bytes read.
*/
ssize_t input_buffer(info_t *Info, char **Buffer, size_t *Len)
{
	ssize_t read = 0;
	size_t lenPtr = 0;

	if (!*Len)
	{
		free(*Buffer);
		*Buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		read = getline(Buffer, &lenPtr, stdin);
#else
		read = _getline(Info, Buffer, &lenPtr);
#endif
		if (read > 0)
		{
			if ((*Buffer)[read - 1] == '\n')
			{
				(*Buffer)[read - 1] = '\0';
				read--;
			}

			Info->linecount_flag = 1;
			remove_comments(*Buffer);
			build_history(Info, *Buffer, Info->histcount++);
			*Len = read;
			Info->cmd_buf = Buffer;
		}
	}

	return (read);
}

/**
 * get_input - A function that gets the input. (exculding the newline)
 *
 * @Info: The info parameter.
 *
 * Return: The bytes read.
*/
ssize_t get_input(info_t *Info)
{
	static char *Buffer;
	static size_t i, j, len;
	ssize_t read = 0;
	char **BufferPtr = &(Info->arg), *ptr;

	_putchar(BUF_FLUSH);
	read = input_buffer(Info, &Buffer, &len);
	if (read == -1)
		return (-1);
	if (len)
	{
		j = i;
		ptr = Buffer + i;

		check_chain(Info, Buffer, &j, i, len);
		while (j < len)
		{
			if (is_chain(Info, Buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			Info->cmd_buf_type = CMD_NORM;
		}

		*BufferPtr = ptr;
		return (_strlen(ptr));
	}

	*BufferPtr = Buffer;
	return (read);
}

/**
 * read_buffer - A function that reads a buffer
 *
 * @Info: The info struct.
 * @Buffer: The address of the buffer.
 * @i: The size of the buffer.
 *
 * Return: read
*/
ssize_t read_buffer(info_t *Info, char *Buffer, size_t *i)
{
	ssize_t readint = 0;

	if (*i)
		return (0);

	readint = read(Info->readfd, Buffer, READ_BUF_SIZE);
	if (readint >= 0)
		*i = readint;
	return (readint);
}

/**
 * _getline - A function that gets the next line input from STDIN.
 *
 * @Info: The info struct.
 * @Ptr: The address of the buffer.
 * @length: The size of the pre-allocated buffer.
 *
 * Return: The input.
*/
int _getline(info_t *Info, char **Ptr, size_t *length)
{
	static char Buffer[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t read = 0, s = 0;
	char *ptr = NULL, *newPtr = NULL, *Character;

	ptr = *Ptr;
	if (ptr && length)
		s = *length;
	if (i == len)
		i = len = 0;

	read = read_buffer(Info, Buffer, &len);
	if (read == -1 || (read == 0 && len == 0))
		return (-1);

	Character = _strchr(Buffer + i, '\n');
	k = Character ? 1 + (unsigned int)(Character - Buffer) : len;
	newPtr = _realloc(ptr, s, s ? s + k : k + 1);
	if (!newPtr) /* MALLOC FAILURE! */
		return (ptr ? free(ptr), -1 : -1);

	if (s)
		_strncat(newPtr, Buffer + i, k - i);
	else
		_strncpy(newPtr, Buffer + i, k - i + 1);

	s += k - i;
	i = k;
	ptr = newPtr;

	if (length)
		*length = s;
	*Ptr = ptr;
	return (s);
}

/**
 * sigintHandler - A function that blocks ctrl+C
 *
 * @sig_num: The signal number.
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
