#include "shell.h"

/**
 * _printenv - A function that prints the current environment.
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
int _printenv(info_t *Info)
{
	print_list_str(Info->env);
	return (0);
}

/**
 * _getenv - A function that gets the value of an eviron variable.
 *
 * @Info: The info struct.
 * @Name: The env var name to look for.
 *
 * Return: The value if found otherwise NULL.
*/
char *_getenv(info_t *Info, const char *Name)
{
	list_t *Node = Info->env;
	char *ptr;

	while (Node)
	{
		ptr = _strstr(Node->str, Name);

		if (ptr && *ptr)
			return (ptr);
		Node = Node->next;
	}

	return (NULL);
}

/**
 * populate_env_list - A function that populates env linked list
 *
 * @Info: The info struct.
 *
 * Return: Always 0
*/
int populate_env_list(info_t *Info)
{
	list_t *Node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&Node, environ[i], 0);
	Info->env = Node;
	return (0);
}

/**
 * get_environ - A function that returns a string array copy
 *               of the environ in the Info struct.
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
char **get_environ(info_t *Info)
{
	if (!Info->environ || Info->env_changed)
	{
		Info->environ = list_to_strings(Info->env);
		Info->env_changed = 0;
	}

	return (Info->environ);
}
