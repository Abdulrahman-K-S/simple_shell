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

    path = getenv("PATH");

    if (path == NULL) 
    {
        return NULL;
    }

    token = strtok(path,delimiter);
   
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
char *path_finder(char* command)
{
    struct directories *direcs;
    char *primary;
    char *full_directory;
    struct stat st;

    if(stat(command, &st) == 0)
        return (command);

    direcs = path_parse();
    
    while (direcs)
    {
        primary = _strcat("/", command);
        full_directory =_strcat(direcs->dir ,primary);

        if (stat(full_directory, &st) == 0)
        {
            break;
        }
        direcs = direcs->next;
    }
    free(command);
    
    if (!direcs)
    {
        free_list(direcs);
        return (NULL);
    }
    printf("%s\n", full_directory);
    free_list(direcs);
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

    while (direcs)
    {
        tmp = direcs->next;
        free(direcs);
        direcs = tmp;
    }
    return (0);
}
