#ifndef SHELL_H
#define SHELL_H

/* Defined vars */
#define PROMPT "$ "
#define DELIMETER " \n"
#define ERROR "./shell: No such file or directory\n"

/* For read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

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

/* ==================== */
/* memorytime.c Modules */
/* ==================== */

char *_memset(char *, char, unsigned int);
void freeStrings(char **);
int freeNull(void **);
void *_realloc(void *, unsigned int, unsigned int);

/* ==================== */
/*  printers.c Modules  */
/* ==================== */

int _putchar(char);
void _puts(char *);


/* ====================== */
/* string_utils.c Modules */
/* ====================== */

int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);

/* ======================= */
/* string_utils2.c Modules */
/* ======================= */

char *strstr(const char *, const char *);
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);

/* ======================= */
/* string_utils3.c Modules */
/* ======================= */

int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _erratoi(char *);
char **_strtok(char *, char *);

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
