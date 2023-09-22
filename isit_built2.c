#include "shell.h"

/**
 * set_alias - A function that sets the alias object.
 *
 * @Info: The info struct.
 * @String: The string alias.
 *
 * Return: 0 on success otherwise 1.
*/
int set_alias(info_t *Info, char *String)
{
	char *ptr;

	ptr = _strchr(String, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(Info, String));

	unset_alias(Info, String);
	return (add_node_end(&(Info->alias), String, 0) == NULL);
}

/**
 * unset_alias - A function that unsets an alias object.
 *
 * @Info: The info struct.
 * @String: The string alias.
 *
 * Return: The ret integer.
*/
int unset_alias(info_t *Info, char *String)
{
	char *ptr, character;
	int ret;

	ptr = _strchr(String, '=');
	if (!ptr)
		return (1);

	character = *ptr;
	*ptr = 0;

	ret = delete_node_at_index(&(Info->alias),
				   get_node_index(Info->alias
			  , node_starts_with(Info->alias, String, -1)));

	*ptr = character;
	return (ret);
}

/**
 * print_alias - A function that prints an alias string.
 *
 * @Node: The alias node.
 *
 * Return: 0 on success otherwise 1
*/
int print_alias(list_t *Node)
{
	char *ptr = NULL, *a = NULL;

	if (Node)
	{
		ptr = _strchr(Node->str, '=');
		for (a = Node->str; a <= ptr; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}

	return (1);
}

/**
 * _alias - A function that mimics the alias builtin
 *
 * @Info: The info struct.
 *
 * Return: Always (0).
*/
int _alias(info_t *Info)
{
	int i = 0;
	char *ptr = NULL;
	list_t *Node = NULL;

	if (Info->argc == 1)
	{
		Node = Info->alias;

		while (Node)
		{
			print_alias(Node);
			Node = Node->next;
		}

		return (0);
	}

	for (i = 1; Info->argv[i]; i++)
	{
		ptr = _strchr(Info->argv[i], '=');
		if (ptr)
			set_alias(Info, Info->argv[i]);
		else
			print_alias(node_starts_with(Info->alias,
						     Info->argv[i], '='));
	}

	return (0);
}
