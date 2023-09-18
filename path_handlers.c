#include "shell.h"

/**
 * path_parse - parses the environment variable
 * PATH into a linked list
 *
 * Return: a linked list of all the directories
*/
struct directories *path_parse(void)
{

	char *path;
	char *delimiter = ":";
	char *token;
	struct directories *head = NULL;
	struct directories *new_dir;

	path = _getenv("PATH");

	if (path == NULL)
	{
		return (NULL);
	}

	token = strtok(path, delimiter);

	while (token != NULL)
	{
		new_dir = malloc(sizeof(struct directories));
		if (!new_dir)
		{
			return (NULL);
		}

		new_dir->dir = token;
		new_dir->next = head;
		head = new_dir;
		token = strtok(NULL, delimiter);
	}

	return (head);
}

/**
 * path_finder - finds out if a given command exists in
 * the directories of the path or not
 * @command: given command in the terminal(first argument)
 *
 * Return: the full path if found or Null if not found
*/
char *path_finder(char *command)
{
	struct directories *head;
	struct directories *direcs;
	/* primary is the concatenation of the '/' character */
	/* and the command given */
	char *primary;
	char *full_directory;
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);

	direcs = path_parse();
	head = direcs;
	while (direcs)
	{
		primary = _strcat("/", command);
		full_directory = _strcat(direcs->dir, primary);

		if (stat(full_directory, &st) == 0)
		{
			break;
		}
		direcs = direcs->next;
	}
	free(command);

	if (!direcs)
	{
		free_list(head);
		return (NULL);
	}
	free_list(head);
	return (full_directory);
}

/**
 * free_list - frees a linked list of directories
 * @direcs: linked list of directories as input
 *
 * Return: Always 0
*/
int free_list(struct directories *direcs)
{
	struct directories *tmp;

	if (!direcs)
		return (0);

	while (direcs != NULL)
	{
		tmp = direcs->next;
		free(direcs);
		direcs = tmp;
	}
	return (0);
}

/**
 * _getenv - gets environment variable from the environment
 * @name: name of the variable to get
 * Return: environment variable string
*/
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var = malloc(sizeof(char *) * 100);

	if (!env_var)
	{
		return (NULL);
	}

	while (environ[i] != NULL)
	{
		env_var = _strdup(environ[i]);
		env_var = strtok(env_var, "=");
		if (_strcmp(env_var, name) == 0)
		{
			env_var = strtok(NULL, "=");
			return (env_var);
		}
		else
			i++;
	}
	free(env_var);
	return (NULL);
}
