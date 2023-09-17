#ifndef MAIN_H
#define MAIN_H

/* Defined vars */
#define PROMPT "$ "
#define DELIMETER " \n"
#define ERROR "./shell: No such file or directory\n"

/* The imported libraries */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * direcotories - a linked list storing all the
 * directories in the $PATH variable
*/
struct directories
{
    char *dir;
    struct directories *next;
};

/*                printers.c Modules                    */

/*   The printers for the shell                         */
void _putchar(char c);
void _puts(char *s);

/*             input_parsing.c Modules                  */

/*   The input manipulators so the shell can understand */
/*   what the user is typing                            */
int getNumberofTokens(char *lineptr);
void storeTokens(char **argv, char *lineptr);

/*             string_utils.c Modules                   */
/*   The functions that manipulate the string to get    */
/*   certain outputs from them                          */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *first, char *second);

/*                    path handlers                     */
struct directories *path_parse(void);
char *path_finder(char* command);
int free_list(struct directories *direcs);

/*   execution function   */
int exec(char **argv, char **env);

#endif
