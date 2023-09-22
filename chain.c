#include "shell.h"

/**
 * is_chain - A function that tests if current char in buffer
 *            is a chain delimeter
 *
 * @Info: The info struct.
 * @Buffer: The buffer.
 * @ptr: address of current position in buf.
 *
 * Return: 1 if chain delimeter, 0 otherwise
*/
int is_chain(info_t *Info, char *Buffer, size_t *ptr)
{
	size_t j = *ptr;

	if (Buffer[j] == '|' && Buffer[j + 1] == '|')
	{
		Buffer[j] = 0;
		j++;
		Info->cmd_buf_type = CMD_OR;
	}
	else if (Buffer[j] == '|' && Buffer[j + 1] == '&')
	{
		Buffer[j] = 0;
		j++;
		Info->cmd_buf_type = CMD_AND;
	}
	else if (Buffer[j] == ';')
	{
		Buffer[j] = 0;
		Info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);

	*ptr = j;
	return (1);
}

/**
 * check_chain - A function that checks if we should continue chaining
 *               based on last status
 *
 * @Info: The input struct
 * @Buffer: The char buffer
 * @Ptr: Address of current position in buf
 * @i: Starting position in buf
 * @len: Length of buf
*/
void check_chain(info_t *Info, char *Buffer, size_t *Ptr, size_t i, size_t len)
{
	size_t j = *Ptr;

	if (Info->cmd_buf_type == CMD_AND)
	{
		if (Info->status)
		{
			Buffer[i] = 0;
			j = len;
		}
	}
	if (Info->cmd_buf_type == CMD_OR)
	{
		if (!Info->status)
		{
			Buffer[i] = 0;
			j = len;
		}
	}

	*Ptr = j;
}

/**
 * replace_alias - A function that replaces an aliases in the tokenized string
 *
 * @Info: The info struct
 *
 * Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *Info)
{
	int i;
	list_t *Node;
	char *Ptr;

	for (i = 0; i < 10; i++)
	{
		Node = node_starts_with(Info->alias, Info->argv[0], '=');

		if (!Node)
			return (0);
		free(Info->argv[0]);
		Ptr = _strchr(Node->str, '=');
		if (!Ptr)
			return (0);

		Ptr = _strdup(Ptr + 1);
		if (!Ptr)
			return (0);
		Info->argv[0] = Ptr;
	}

	return (1);
}

/**
 * replace_vars - A function that replaces vars in the tokenized string
 *
 * @Info: The info struct
 *
 * Return: 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *Info)
{
	int i = 0;
	list_t *Node;

	for (i = 0; Info->argv[i]; i++)
	{
		if (Info->argv[i][0] != '$' || !Info->argv[i][1])
			continue;

		if (!_strcmp(Info->argv[i], "$?"))
		{
			replace_string(&(Info->argv[i]),
				 _strdup(convert_number(Info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(Info->argv[i], "$$"))
		{
			replace_string(&(Info->argv[i]),
				 _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		Node = node_starts_with(Info->env, &Info->argv[i][1], '=');
		if (Node)
		{
			replace_string(&(Info->argv[i]),
				_strdup(_strchr(Node->str, '=') + 1));
			continue;
		}
		replace_string(&Info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - A function that replaces 2 strings.
 *
 * @Old: Address of old string
 * @New: The neew string
 *
 * Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **Old, char *New)
{
	free(*Old);
	*Old = New;
	return (1);
}
