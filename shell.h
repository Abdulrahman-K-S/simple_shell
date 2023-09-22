#ifndef SHELL_H
#define SHELL_H

/* The imported libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Defined vars */
#define PROMPT "$ "
#define DELIMETER " \n"
#define ERROR "./shell: No such file or directory\n"

/* For read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct liststr - singly linked list
 *
 * @num: The number field
 * @str: A string
 * @next: points to the next node
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/* ======================== */
/*      list.c Modules      */
/* ======================== */

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
char **list_to_strings(list_t *);
list_t *node_starts_with(list_t *, char *, char);

/* ======================== */
/*      list2.c Modules     */
/* ======================== */

size_t print_list_str(const list_t *);
size_t print_list(const list_t *);
size_t list_len(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
void free_list(list_t **);

/* ==================== */
/* memorytime.c Modules */
/* ==================== */

char *_memset(char *, char, unsigned int);
void freeStrings(char **);
int freeNull(void **);
void *_realloc(void *, unsigned int, unsigned int);

/* =========================== */
/*  error_functions.c Modules  */
/* =========================== */

void _eputs(char *);
int _eputchar(char );
int _putsfd(char *, int);
int _putfd(char , int);

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

char *_strstr(const char *, const char *);
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

/* ======================== */
/*   more_utils.c Modules   */
/* ======================== */

int interactive(info_t *);
int print_d(int, int);
char *conver_number(long int, int, int);
void remove_comments(char *);

#endif
