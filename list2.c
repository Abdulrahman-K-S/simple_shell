#include "shell.h"

/**
 * print_list_str - A function that prints the strings of the linked list.
 *
 * @Head: The head pointer.
 *
 * Return: The size of the list.
*/
size_t print_list_str(const list_t *Head)
{
	size_t i = 0;

	while (Head)
	{
		_puts(Head->str ? Head->str : "(nil)");
		_puts("\n");
		Head = Head->next;
		i++;
	}

	return (i);
}

/**
 * print_list - A function that prints all the elements of the linked list.
 *
 * @Head: The head pointer of the linked list.
 *
 * Return: The size of the list.
*/
size_t print_list(const list_t *Head)
{
	size_t i = 0;

	while (Head)
	{
		_puts(convert_number(Head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(Head->str ? Head->str : "(nil)");
		_puts("\n");
		Head = Head->next;
		i++;
	}

	return (i);
}

/**
 * list_len - A function that returns the length of the list.
 *
 * @Head: The head pointer of the linked list.
 *
 * Return: The size of the list.
*/
size_t list_len(const list_t *Head)
{
	size_t i = 0;

	while (Head)
	{
		Head = Head->next;
		i++;
	}

	return (i);
}

/**
 * get_node_index - A function that gets the node's index
 *
 * @Head: The head pointer of the linked list.
 * @Node: The node to get it's index.
 *
 * Return: The index of node or -1 if not found.
*/
ssize_t get_node_index(list_t *Head, list_t *Node)
{
	size_t i = 0;

	while (Head)
	{
		if (Head == Node)
			return (i);
		Head = Head->next;
		i++;
	}

	return (-1);
}

/**
 * free_list - A function that frees all the nodes of the list.
 *
 * @HeadPtr: The head address of the linked list.
*/
void free_list(list_t **HeadPtr)
{
	list_t *node, *nextNode, *Head;

	if (!HeadPtr || !*HeadPtr)
		return;

	Head = *HeadPtr;
	node = Head;

	while (node)
	{
		nextNode = node->next;
		free(node->str);
		free(node);
		node = nextNode;
	}

	*HeadPtr = NULL;
}
