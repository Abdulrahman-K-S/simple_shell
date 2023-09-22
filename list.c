#include "shell.h"

/**
 * add_node - A function that adds a node to the start of the list.
 *
 * @Head: The head of the linked list.
 * @String: The string to add into the node.
 * @num: The integer to add into the node.
 *
 * Return: A pointer to the new node added.
*/
list_t *add_node(list_t **Head, const char *String, int num)
{
	list_t *new_head;

	if (!Head)
		return (NULL);

	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);

	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;

	if (String)
	{
		new_head->str = _strdup(String);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}

	new_head->next = *Head;
	*Head = new_head;

	return (new_head);
}

/**
 * add_node_end - A function that adds a node at the end of the list.
 *
 * @Head: Address of the head pointer.
 * @String: The string to add into the node.
 * @num: The number to add into the node.
 *
 * Return: Pointer to the new node.
*/
list_t *add_node_end(list_t **Head, const char *String, int num)
{
	list_t *newNode, *node;

	if (!Head)
		return (NULL);

	node = *Head;
	newNode = malloc(sizeof(list_t));
	if (!newNode)
		return (NULL);

	_memset((void *)newNode, 0, sizeof(list_t));
	newNode->num = num;
	if (String)
	{
		newNode->str = _strdup(String);
		if (!newNode->str)
		{
			free(newNode);
			return (NULL);
		}
	}

	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newNode;
	}
	else
		*Head = newNode;

	return (newNode);
}

/**
 * delete_node_at_index - A function that deletes a node at a specific index.
 *
 * @Head: The head of the linked list.
 * @Index: The index node to delete.
 *
 * Return: 1 on success, 0 if there's an error.
*/
int delete_node_at_index(list_t **Head, unsigned int Index)
{
	list_t *node, *prevNode;
	unsigned int i = 0;

	if (!Head || !*Head)
		return (0);

	if (!Index)
	{
		node = *Head;
		*Head = (*Head)->next;
		free(node->str);
		free(node);
		return (1);
	}

	node = *Head;
	while (node)
	{
		if (i == Index)
		{
			prevNode->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prevNode = node;
		node = node->next;
	}

	return (0);
}

/**
 * list_to_strings - A function that returns an array of strings from the
 *                   linked list.
 *
 * @Head: The head of the linked list.
 *
 * Return: An array of strings.
*/
char **list_to_strings(list_t *Head)
{
	list_t *node = Head;
	size_t i = list_len(Head), j;
	char **Strings, *String;

	if (!Head || !i)
		return (NULL);

	Strings = malloc(sizeof(char *) * (i + 1));
	if (!Strings)
		return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
		String = malloc(_strlen(node->str) + 1);
		if (!String)
		{
			for (j = 0; j < i; j++)
				free(Strings[j]);
			free(Strings);
			return (NULL);
		}

		String = _strcpy(String, node->str);
		Strings[i] = String;
	}

	Strings[i] = NULL;
	return (Strings);
}

/**
 * node_starts_with - A function that returns the node that has a string
 *                    with the entered prefex.
 *
 * @Head: The head pointer of the linked list.
 * @Prefex: The string to match.
 * @Character: The next character after the prefex to match.
 *
 * Return: The node if found otherwise NULL.
*/
list_t *node_starts_with(list_t *Head, char *Prefex, char Character)
{
	char *ptr = NULL;

	while (Head)
	{
		ptr = _strstr(Head->str, Prefex);

		if (ptr && ((Character == -1) || (*ptr == Character)))
			return (Head);
		Head = Head->next;
	}

	return (NULL);
}
