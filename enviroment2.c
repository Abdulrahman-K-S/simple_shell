#include "shell.h"

/**
 * _setenv - A function that initializes a new environment variable or
 *            modify an existing one.
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
int _setenv(info_t *Info)
{
	if (Info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (__setenv(Info, Info->argv[1], Info->argv[2]))
		return (0);
	return (1);
}

/**
 * __setenv - A function that initializes a new environment variable or
 *            modify an existing one.
 *
 * @Info: The info struct.
 * @Var: The string env var property.
 * @Val: The string env var value.
 *
 * Return: Always (0).
*/
int __setenv(info_t *Info, char *Var, char *Val)
{
	char *Buffer = NULL;
	list_t *Node;
	char *ptr;

	if (!Var || !Val)
		return (0);

	Buffer = malloc(_strlen(Var) + _strlen(Val) + 2);
	if (!Buffer)
		return (1);

	_strcpy(Buffer, Var);
	_Strcat(Buffer, "=");
	_strcat(Buffer, Val);

	Node = Info->env;
	while (Node)
	{
		ptr = _strstr(Node->str, Var);
		if (ptr && *ptr == '=')
		{
			free(Node->str);
			Node->str = Buffer;
			Info->env_changed = 1;
			return (0);
		}

		Node = Node->next;
	}

	add_node_end(&(Info->env), Buffer, 0);
	free(Buffer);
	Info->env_changed = 1;

	return (0);
}

/**
 * _unsetenv - A function that removes an environment variable.
 *
 * @Info: The info struct.
 *
 * Return: (0) indicating a succes or (1) indicating a fail.
 */
int _unsetenv(info_t *Info)
{
	int i = 1;

	if (Info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}

	for (; i <= Info->argc; i++)
		__unsetenv(Info, Info->argv[i]);
	return (0);
}

/**
 * __unsetenv - A function that removes an environment variable.
 *
 * @Info: The info struct.
 * @Var: The string env var properties.
 *
 * Return: Always (0).
*/
int __unsetenv(info_t *Info, char *Var)
{
	list_t *Node = Info->env;
	size_t i = 0;
	char *ptr;

	if (!Node || !Var)
		return (0);

	while (Node)
	{
		ptr = _strstr(Node->str, Var);
		if (ptr && *ptr == '=')
		{
			Info->env_changed = delete_node_at_index(&(Info->env), i);
			i = 0;
			Node = Info->env;
			continue;
		}

		Node = Node->next;
		i++;
	}

	return (Info->env_changed);
}
