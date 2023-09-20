#ifndef SHELL_H
#define SHELL_H

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
 * struct directories - a linked list storing all the
 *                      directories in the $PATH variable.
 *
 * @dir: The string of the directory.
 * @next: The node to the next directory.
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

/* ==================================================== */
/* ==================================================== */

/*             input_parsing.c Modules                  */

/*   The input manipulators so the shell can understand */
/*   what the user is typing                            */

int getNumberofTokens(char *lineptr);
void storeTokens(char **argv, char *lineptr);
int is_empty(char *lineptr);

/* ==================================================== */
/* ==================================================== */

/*             string_utils.c Modules                   */
/*   The functions that manipulate the string to get    */
/*   certain outputs from them                          */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *first, char *second);
char *_strdup(const char *String);
int _strcmp(const char *First, const char *Second);

/* ==================================================== */
/* ==================================================== */

/*                    path handlers                     */

extern char **environ;
struct directories *path_parse(void);
char *path_finder(char *command);
int free_list(struct directories *direcs);
char *_getenv(const char *name);

/* ==================================================== */
/* ==================================================== */

/*                  execution function                  */

int exec(char **argv, char **env);

/* ==================================================== */
/* ==================================================== */

/*                isit_built.c Modules                  */
/* The functions that represent the built-in functions  */
/* that the shell should have                           */

int is_built(char **argv, char *lineptr);
void exit_shell(char **argv, char *lineptr);
void print_enviroment(void);

#endif
