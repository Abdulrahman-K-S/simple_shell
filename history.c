#include "shell.h"

/**
 * build_history - A function that adds an entry to the history linked list.
 * 
 * @Info: The info struct.
 * @Buffer: The buffer.
 * @lineCount: The history lincount. (aka histcount)
 *
 * Return: Always (0);
*/
int build_history(info_t *Info, char *Buffer, int lineCount)
{
    list_t *Node = NULL;

    if (Info->history)
        Node = Info->history;
    add_node_end(&Node, Buffer, lineCount);

    if (!Info->history)
        Info->history = Node;
    return (0);
}

/**
 * get_history_file - A function that gets the history file.
 *
 * @Info: The info struct.
 *
 * Return: A pointer string containing the history file.
*/
char *get_history_file(info_t *Info)
{
    char *Buffer, *Directory;

    Directory = _getenv(Info, "Home=");
    if (!Directory)
        return (NULL);
    
    Buffer = malloc(sizeof(char) * (_strlen(Directory) +
     _strlen(HIST_FILE) + 2));
    if (!Buffer)
        return (NULL);
    
    Buffer[0] = 0;
    _strcpy(Buffer, Directory);
    _strcat(Buffer, "/");
    _strcat(Buffer, HIST_FILE);
    
    return (Buffer);
}

/**
 * write_history - A function that creates a file or append to an existing one.
 *
 * @Info: The info struct
 *
 * Return: 1 on success otherwise -1.
*/
int write_history(info_t *Info)
{
    ssize_t File;
    char *fileName = get_history_file(Info);
    list_t *Node = NULL;

    if (!fileName)
        return (-1);

    File = open(fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(fileName);

    if (File == -1)
        return (-1);
    for (Node = Info->history; Node; Node = Node->next)
    {
        _putsfd(Node->str, File);
        _putfd('\n', File);
    }

    _putfd(BUF_FLUSH, File);
    close(File);
    
    return (1);
}

/**
 * read_history - A function that reads the history from the file.
 *
 * @Info: The info struct
 *
 * Return: The histcount on success otherwise 0.
*/
int read_history(info_t *Info)
{
    int i, last = 0, lineCount = 0;
    ssize_t File, Readlen, fSize = 0;
    struct stat st;
    char *Buffer = NULL, *fileName = get_history_file(Info);

    if (!fileName)
        return (0);

    File = open(fileName, O_RDONLY);
    free(fileName);
    if (File == -1)
        return (0);
    if (!fstat(File, &st))
        fSize = st.st_size;
    if (fSize < 2)
        return (0);
    Buffer = malloc(sizeof(char) * (fSize + 1));
    if (!Buffer)
        return (0);
    Readlen = read(File, Buffer, fSize);
    Buffer[fSize] = 0;
    if (Readlen <= 0)
        return (free(Buffer), 0);
    close (File);
    for (i = 0; i < fSize; i++)
        if (Buffer[i] == '\n')
        {
            Buffer[i] = 0;
            build_history(Info, Buffer + last, lineCount++);
            last = i + 1;
        }
    if (last != i)
        build_history(Info, Buffer + last, lineCount++);
    free(Buffer);
    Info->histcount = lineCount;
    while (Info->histcount-- >= HIST_MAX)
        delete_node_at_index(&(Info->history), 0);
    renumber_history(Info);
    return (Info->histcount);
}

/**
 * renumber_history - A function that renumbers the history linked list
 *                    after the changes.
 *
 * @Info: The info struct.
 *
 * Return: The new histcount.
*/
int renumber_history(info_t *Info)
{
    list_t *Node = Info->history;
    int i = 0;

    while (Node)
    {
        Node->num = i++;
        Node = Node->next;
    }

    return (Info->histcount = i);
}
